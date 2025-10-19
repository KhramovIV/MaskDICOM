#ifndef MyDetectorConstruction_h
#define MyDetectorConstruction_h 1

#include "MyDetectorMessenger.hh"
#include "G4ThreeVector.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4GenericMessenger.hh"
#include "G4Tubs.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class MyDetectorMessenger;

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        MyDetectorConstruction();
        ~MyDetectorConstruction() override;

        G4VPhysicalVolume* Construct() override;

        G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

        void SetDetectorZ(G4double z);

        void SetDetectorPosition(G4double pos);
    
    protected:
        G4LogicalVolume* fScoringVolume = nullptr;
        G4double fDetectorZ = 0;
        MyDetectorMessenger* fMessenger;
        G4GenericMessenger* gMessenger;

        G4Tubs* outer_chamber;
        G4Tubs* inner_chamber;
        G4LogicalVolume* logic_outer_chamber;
        G4LogicalVolume* logic_inner_chamber;
        G4VPhysicalVolume* phys_chamber;

        G4double water_x;
};

#endif