#include "step.hh"
#include "construction.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{}

SteppingAction::~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) {
    const MyDetectorConstruction* detConstruction = static_cast<const MyDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction()); //method to get the DetectorConstruction pointer
    fScoringVolume = detConstruction->GetScoringVolume();
  }

  // get volume of the current step
  G4LogicalVolume* volume
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();

  // check if we are in scoring volume
  if (volume != fScoringVolume) return;
  
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);
  
  //ths funciton basically only detects energy in specified scoring volume
}

