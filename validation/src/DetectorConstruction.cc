//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1/src/DetectorConstruction.cc
/// \brief Implementation of the B1::DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Trd.hh"
#include "G4RotationMatrix.hh"
#include "G4GenericMessenger.hh"
#include "G4RunManager.hh"
#include "G4VisManager.hh"
#include "G4UImanager.hh"

namespace B1
{

DetectorConstruction::DetectorConstruction(): z(100)
{
  messenger = new G4GenericMessenger(this, "/geom/", "Geometry control");
  messenger->DeclareMethodWithUnit("z", "mm", &DetectorConstruction::SetZ,  "Wide of solid water skin [mm]");
}

// Меняем толщину пластины твердой воды
void DetectorConstruction::SetZ(G4double val)
{
    z = val;
    G4cout << "Geometry changed to z: " << z << " mm" << G4endl;

    auto rm = G4RunManager::GetRunManager();
    rm->GeometryHasBeenModified();
    rm->ReinitializeGeometry(true);

    // Нужно затем сделать /run/initialize и /vis/scene/add/volume World и всё работает!

    auto ui = G4UImanager::GetUIpointer();
    ui->ApplyCommand("/vis/geometry/rebuild");
}

void DetectorConstruction::CreateSolidWaterMaterial()
{
  //  Твёрдая вода
  if (!G4Material::GetMaterial("SP34"))
  {
    G4Material* polystyrene = G4NistManager::Instance()->FindOrBuildMaterial("G4_POLYSTYRENE");
    G4Element* Ti = G4NistManager::Instance()->FindOrBuildElement("Ti");
    G4Element* O = G4NistManager::Instance()->FindOrBuildElement("O");
    G4double density = 4.23 * g / cm3;
    G4String name = "TiO2";

    G4Material* TiO2 = new G4Material(name, density, 2);
    TiO2->AddElement(Ti, 1);
    TiO2->AddElement(O, 2);

    solid_water = new G4Material("SP34", 1.045 * g/cm3, 2);
    solid_water->AddMaterial(polystyrene, 0.978);
    solid_water->AddMaterial(TiO2, 0.022);

    G4cout << G4Material::GetMaterial("SP34") << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// Деллаем Ионизационную камеру
G4LogicalVolume* DetectorConstruction::ConstructChamber()
{
  G4Material* air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");
  G4Material* graphite = G4NistManager::Instance()->FindOrBuildMaterial("G4_GRAPHITE");
  G4Material* aluminium = G4NistManager::Instance()->FindOrBuildMaterial("G4_Al");

  //  Внешняя электрод камеры
  G4double inner_outer_wall_radius = 3.1 * CLHEP::mm;
  G4double outer_outer_wall_radius = 3.3 * CLHEP::mm;
  G4double half_len_z = 11.5 * CLHEP::mm;

  G4Tubs* solidOuterWall = new G4Tubs("OuterWall", 0, outer_outer_wall_radius, half_len_z, 0, 360 * CLHEP::deg);
  G4LogicalVolume* logicOuterWall = new G4LogicalVolume(solidOuterWall, graphite, "OuterWall");

  //  Воздушная полость
  G4double electrode_radius = 0.5 * CLHEP::mm;
  
  G4Tubs* solidCavity = new G4Tubs("Cavity", 0, inner_outer_wall_radius, half_len_z, 0, 360 * CLHEP::deg);
  logicCavity = new G4LogicalVolume(solidCavity, air, "Cavity");

  //  Внутренний электрод
  G4Tubs* solidInnerElectrode = new G4Tubs("Electrode", 0, electrode_radius, half_len_z, 0, 360 * CLHEP::deg);
  G4LogicalVolume* logicInnerElectrode = new G4LogicalVolume(solidInnerElectrode, aluminium, "Electrode");

  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicCavity, "Cavity", logicOuterWall, false, 0, true);
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicInnerElectrode, "InnerElectrode", logicCavity, false, 0, true);

  return logicOuterWall;
}

// Делаем плиту с детекотром
G4LogicalVolume* DetectorConstruction::ConstructPhantom()
{ 
  // Плита где это всё мерится:
  G4Material* air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");
  G4double half_x = 150 * CLHEP::mm;
  G4double half_y = 150 * CLHEP::mm;

  G4Box* solidPlateDet = new G4Box("PlateIonChamber", half_x, half_y, 10 * CLHEP::mm);
  G4LogicalVolume* logicPlateDet = new G4LogicalVolume(solidPlateDet, solid_water, "PlaterIonChamber");
  G4Tubs* solidHole = new G4Tubs("Hole", 0, 10 * CLHEP::mm, half_x, 0, 360 * CLHEP::deg);
  G4LogicalVolume* logicHole = new G4LogicalVolume(solidHole, air, "Hole");
  auto rotation = new G4RotationMatrix();
  rotation->rotateX(90*CLHEP::deg);
  new G4PVPlacement(rotation, G4ThreeVector(), logicHole, "Hole", logicPlateDet, false, 0, false);
  G4LogicalVolume* ion_chamber = this->ConstructChamber();
  new G4PVPlacement(nullptr, G4ThreeVector(), ion_chamber, "Chamber", logicHole, false, 0, false);

  return logicPlateDet;
}

G4LogicalVolume* DetectorConstruction::ConstructSolidWaterCube(G4double wide)
{
  // Сами плиты
  G4double half_x = 150 * CLHEP::mm;
  G4double half_y = 150 * CLHEP::mm;
  G4Box* solidPlate = new G4Box("PlateIonChamber", half_x, half_y, wide / 2 * CLHEP::mm);
  G4LogicalVolume* logicPlate = new G4LogicalVolume(solidPlate, solid_water, "PlaterIonChamber");

  return logicPlate;
}

G4double DetectorConstruction::GetMass() const
{
  return logicCavity->GetMass(true, true); 
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4cout << "DETECTOR CONSTRUCTION";
  // Get nist material manager
  this->CreateSolidWaterMaterial(); 
  G4NistManager* nist = G4NistManager::Instance();

  // Envelope parameters
  G4bool checkOverlaps = true;
  // Задаём мир
  G4double world_sizeXY = 2 * CLHEP::m;
  G4double world_sizeZ = 2 * CLHEP::m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  auto solidWorld = new G4Box("World",  0.5 * world_sizeXY, 0.5 * world_sizeXY, 0.5 * world_sizeZ);  
  auto logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World");  
  auto physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World", nullptr, false, 0, checkOverlaps);

  // Строим плиты (плита которая, перед детектором будет как одна просто большая плита, а не как много маленьких)
  auto logicDetector = this->ConstructPhantom();
  auto logicPlateBack = this->ConstructSolidWaterCube(50);
  auto logicPlate = this->ConstructSolidWaterCube(z);
  
  std::cout << z << " WIDE CHANGE\n";
  // Пластина перед детектором
  G4double z_water = -(double)z / 2.0 * CLHEP::mm;
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, z_water), logicPlate, "Plate", logicWorld, false, 0, false);
  // Пластина детектора
  G4double z_detector = - (2.0 * z + 20.0) / 2.0 * CLHEP::mm;
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, z_detector), logicDetector, "Detector", logicWorld, false, 0, false);
  // Пластина за детектором (5 см)
  G4double z_plate_back = z_detector - (10.0 + 25.0) * CLHEP::mm;
  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, z_plate_back), logicPlateBack, "PlateBack", logicWorld, false, 0, false);
  fScoringVolume = logicCavity;

  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}  // namespace B1
