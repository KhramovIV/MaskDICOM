// DetectorMessenger.hh
#ifndef MyDetectorMessenger_h 
#define MyDetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "MyDetectorConstruction.hh"

class MyDetectorConstruction;

class MyDetectorMessenger : public G4UImessenger {
    public:
        MyDetectorMessenger(MyDetectorConstruction* det);
        ~MyDetectorMessenger() override;
        void SetNewValue(G4UIcommand* cmd, G4String val) override;

    private:
        MyDetectorConstruction* fDetector;
        G4UIcmdWithADoubleAndUnit* fSetZCmd;
};

#endif