#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4AnalysisManager.hh"
//#include "G4root.hh"


class RunAction : public G4UserRunAction
{
public:
	RunAction();
	~RunAction();

	virtual void BeginOfRunAction(const G4Run*);
    	virtual void EndOfRunAction(const G4Run*);
	
	void AddEdep (G4double edep);
	
	
private:
    G4Accumulable<G4double> fEdep = 0.;
};

#endif

