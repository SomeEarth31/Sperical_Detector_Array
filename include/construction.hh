#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Polyhedra.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4Sphere.hh"
#include "G4VisCommandsTouchable.hh"
#include "G4Tubs.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();

	virtual G4VPhysicalVolume *Construct();
	G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; } // called in step function

	std::vector<G4String> GetPositionInWorld(const G4String &) const;

private:
	G4LogicalVolume *fScoringVolume = nullptr; // used to keep track of detector volume
	G4VisAttributes *detecColor, *plasColor;
};

#endif
