#include "event.hh"

EventAction::EventAction(RunAction *runAction)
    : fRunAction(runAction)
{
  myfile.open("output.txt", std::ios::out | std::ios::trunc);
  myfile.close();
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *)
{
  fEdep = 0.;
  myfile.open("output.txt", std::ios::app);
}

void EventAction::EndOfEventAction(const G4Event *)
{
  fRunAction->AddEdep(fEdep);

  if (fEdep)
  {
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleDColumn(0, fEdep / CLHEP::keV);
    man->AddNtupleRow();

    if (myfile)
    {
      myfile << fEdep / CLHEP::keV << std::endl;
    }
    else
      G4cout << "Unable to open file" << std::endl;
  }

  myfile.close();
}
