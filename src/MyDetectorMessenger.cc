#include "MyDetectorMessenger.hh"
#include "MyDetectorConstruction.hh"    
    
MyDetectorMessenger::MyDetectorMessenger(MyDetectorConstruction* det) : fDetector(det) 
{
    fSetZCmd = new G4UIcmdWithADoubleAndUnit("/mydetector/setZ", this);
    fSetZCmd->SetGuidance("Set Z position of detector");
    fSetZCmd->SetUnitCategory("Length");
}

MyDetectorMessenger::~MyDetectorMessenger() 
{
    delete fSetZCmd;
}

void MyDetectorMessenger::SetNewValue(G4UIcommand* cmd, G4String val)
{
   if (cmd == fSetZCmd){
        fDetector->SetDetectorZ(fSetZCmd->GetNewDoubleValue(val));
        G4cout << "SetNewValue is done" << fSetZCmd->GetNewDoubleValue(val) << G4endl;
   }
}