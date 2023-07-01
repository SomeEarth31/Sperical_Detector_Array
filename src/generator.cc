#include "generator.hh"


MyPrimaryGenerator::MyPrimaryGenerator()
 : G4VUserPrimaryGeneratorAction(),
   fParticleGun(0)
{
	fParticleGun = new G4GeneralParticleSource();

}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
	fParticleGun->GeneratePrimaryVertex(anEvent);
}


