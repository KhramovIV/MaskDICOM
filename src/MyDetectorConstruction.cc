#include "MyDetectorConstruction.hh"
#include "MyDetectorMessenger.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4RotationMatrix.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4GenericMessenger.hh"


MyDetectorConstruction::MyDetectorConstruction() {
    fMessenger = new MyDetectorMessenger(this);
}

MyDetectorConstruction::~MyDetectorConstruction() {
    delete fMessenger;
}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{   
    auto nist = G4NistManager::Instance();
    //----- Build world
    G4double worldXDimension = 1. * m;
    G4double worldYDimension = 1. * m;
    G4double worldZDimension = 1. * m;
    auto fAir = nist->FindOrBuildMaterial("G4_AIR");

    G4Box *fWorld_solid = new G4Box("WorldSolid", worldXDimension, worldYDimension, worldZDimension);

    G4LogicalVolume *fWorld_logic = new G4LogicalVolume(fWorld_solid, fAir, "WorldLogical", 0, 0, 0);

    auto fWorld_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), "World", fWorld_logic, 0, false, 0);
    
    //fWorld_logic->SetVisAttributes(G4VisAttributes::GetInvisible());
    
    //
    //  Задаём твёрдую воду
    //
    
    G4Material* Polystyrene = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  
    G4Element* Ti = nist->FindOrBuildElement("Ti");
    G4Element* O = nist->FindOrBuildElement("O");

    G4double density = 4.23 * g / cm3;
    G4String name = "TiO2";

    G4Material* TiO2 = new G4Material(name, density, 2);
    TiO2->AddElement(Ti, 1);
    TiO2->AddElement(O, 2);

    G4Material* solid_water = new G4Material("SP34", 1.045 * g/cm3, 2);
    solid_water->AddMaterial(Polystyrene, 0.978);
    solid_water->AddMaterial(TiO2, 0.022);
  
    //  G4Material* detectorMaterial = G4NistManager::Instance()->FindOrBuildMaterial("G4_Water");
    water_x = 15 * CLHEP::cm;

    G4Box* solidWater = new G4Box("Solid Water", water_x, 15 * CLHEP::cm, 15     * CLHEP::cm);
    
    G4LogicalVolume* logicWater = new G4LogicalVolume(solidWater, solid_water, "Solid Water");
    
    auto physWater = new G4PVPlacement(nullptr, G4ThreeVector(0, 0, 0), logicWater, "Solid Water", fWorld_logic, false, 0, false);
    
    //
    //  Задаём детектор
    //
    // Размеры камеры
    
    G4double outer_radius = 3.1 * CLHEP::mm;   // Половина диаметра внешнего электрода (6.2 мм)
    G4double inner_radius = 0.5 * CLHEP::mm;   // Половина диаметра внутреннего электрода (1.0 мм)
    G4double chamber_length = 20.0 * CLHEP::mm; // Длина камеры

    // Материал камеры (сталь, например)
    G4Material* steel = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    // Создание внешнего цилиндра (стенки камеры)
    outer_chamber = new G4Tubs("OuterChamber", 0., outer_radius, chamber_length / 2., 0., 360.0 * CLHEP::deg);
    logic_outer_chamber = new G4LogicalVolume(outer_chamber, steel, "OuterChamber");

    // Внутренний цилиндр (внутренний электрод)
    inner_chamber = new G4Tubs("InnerChamber", 0., inner_radius, chamber_length / 2., 0., 360.0 * CLHEP::deg);
    logic_inner_chamber = new G4LogicalVolume(inner_chamber, air, "InnerChamber");

    auto rotation_matrix = new G4RotationMatrix();
    rotation_matrix->rotateX(90*CLHEP::deg);
    // Создание физического расположения (внешний цилиндр)
    G4cout << "[Construct] fDetectorZ = " << fDetectorZ/mm << " mm" << G4endl;
    phys_chamber = new G4PVPlacement(rotation_matrix, G4ThreeVector(water_x, 0, 0), logic_outer_chamber, "OuterChamber", logicWater, 0, false, 0);
    
    // Вставляем внутренний электрод (внутренний цилиндр)
    new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logic_inner_chamber, "InnerChamber", logic_outer_chamber, false, 0);

    // Теперь создаем сенситивный объем
    /*G4SDManager* SDman = G4SDManager::GetSDMpointer();
    IonizationChamberSD* chamberSD = new IonizationChamberSD("/detector/FC65");
    SDman->AddNewDetector(chamberSD);
s
    logic_inner_chamber->SetSensitiveDetector(chamberSD); */

    //fScoringVolume = logic_inner_chamber; 

    gMessenger = new G4GenericMessenger(this, "/detector/", "Detector control commands");
    gMessenger->DeclareMethod("setPos", &MyDetectorConstruction::SetDetectorPosition, "Set_pos");

    return fWorld_phys;
}

void MyDetectorConstruction::SetDetectorPosition(G4double newPos) {
    G4double fDetectorPosition = newPos;
    if(phys_chamber) {
    phys_chamber->SetTranslation(G4ThreeVector(water_x - newPos * cm - 3.1 * CLHEP::mm, 0, 0));
    G4RunManager::GetRunManager()->GeometryHasBeenModified();
    }
    G4cout << "Detector position set to: " << fDetectorPosition << G4endl;

    G4RunManager* runManager = G4RunManager::GetRunManager();
    runManager->GeometryHasBeenModified();
    runManager->ReinitializeGeometry();

    auto ui = G4UImanager::GetUIpointer();
    if (ui) {
        ui->ApplyCommand("/vis/viewer/flush");
        ui->ApplyCommand("/vis/scene/notifyHandlers");
    }
}

// Это не нужно, потом удалить
void MyDetectorConstruction::SetDetectorZ(G4double z)
{
    fDetectorZ = z;
    G4cout << "[SetDetectorZ] new Z = " << fDetectorZ/mm << " mm" << G4endl;

    // Вариант 1 (безопасный, гарантированно вызывает Construct()):
    auto* rm = G4RunManager::GetRunManager();
    rm->DefineWorldVolume(Construct(), true); // принудительно заменит мир и вызовет Construct()

    // Обновить визуализацию (если используется vis manager)
    auto ui = G4UImanager::GetUIpointer();
    if (ui) {
        ui->ApplyCommand("/vis/viewer/flush");
        ui->ApplyCommand("/vis/scene/notifyHandlers");
    }
    auto pvStore = G4PhysicalVolumeStore::GetInstance();
    for (auto pv : *pvStore) {
        if (pv->GetName() == "OuterChamber") {
            G4cout << "[Check] OuterChamber global Z = " 
                << pv->GetTranslation().z()/mm << " mm" << G4endl;
        }
}
}

