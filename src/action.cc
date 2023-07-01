#include "action.hh"
#include "generator.hh"
#include "run.hh"
#include "event.hh"
#include "step.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const
{
	MyPrimaryGenerator *generator = new MyPrimaryGenerator();
  	SetUserAction(generator);
  	
  	RunAction *runAction = new RunAction();
  	SetUserAction(runAction);

	EventAction *eventAction = new EventAction(runAction);
	SetUserAction(eventAction);

	SteppingAction *steppingAction = new SteppingAction(eventAction);
	SetUserAction(steppingAction);
}






