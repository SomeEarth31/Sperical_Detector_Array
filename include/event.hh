#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "run.hh"
#include "G4Event.hh"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction* runAction);
    ~EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }

  private:
    RunAction* fRunAction = nullptr;
    G4double   fEdep = 0.;
    std::fstream myfile;
};

#endif
