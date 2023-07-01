#ifndef STEP__HH
#define STEP_HH

#include "G4UserSteppingAction.hh"
#include "event.hh"
#include "G4Step.hh"

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction();

    virtual void UserSteppingAction(const G4Step*);

  private:
    EventAction* fEventAction = nullptr;
    G4LogicalVolume* fScoringVolume = nullptr;
};

#endif
