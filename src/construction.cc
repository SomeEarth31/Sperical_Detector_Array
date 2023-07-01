#include "construction.hh"
#include "CADMesh.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
	detecColor = new G4VisAttributes(G4Colour(0., 0., 0.75));
	plasColor = new G4VisAttributes(G4Colour(0.75, 0., 0.));
}

MyDetectorConstruction::~MyDetectorConstruction()
{
}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	//-------------------WORLD-----------------------------//
	// This is used to define a material
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

	// This is the process to define volume, there are three volume types that are required#
	G4Box *solidWorld = new G4Box("solidWorld", 2.5 * m, 2.5 * m, 2.5 * m); // default unit of length is meters, so multiplying by m will put it in meter

	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	G4VPhysicalVolume *physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "physWorld", nullptr, false, 0, true);

	//-------------------CRYSTAL-----------------------------//

	G4Material *NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");

	G4VSolid *solidDetec = new G4Sphere("solidDetec", 100.*mm, 163.5*mm, 0. , 360.*deg, 0., 360.*deg);
	G4LogicalVolume *logicDetec = new G4LogicalVolume(solidDetec, NaI, "logicaDetec");
	G4VPhysicalVolume *physDetec = new G4PVPlacement(nullptr, G4ThreeVector(0* cm, 0 * cm, 0 * cm), logicDetec, "physDetec", logicWorld, false, 0, true);
	logicDetec->SetVisAttributes(detecColor);

	fScoringVolume = logicDetec;

	//-------------------Plastic-----------------------------//

	G4Material *Plastic = new G4Material("Plsatic", 1.032 * g / cm3, 2);
	Plastic->AddElement(nist->FindOrBuildElement("C"), 50. * perCent);
	Plastic->AddElement(nist->FindOrBuildElement("H"), 50. * perCent);

	G4VSolid *solidPlas = new G4Tubs("solidPlas", 0. * cm, 1.27 * cm, 3., 0. * deg, 360. * deg); // crustal
	G4LogicalVolume *logicPlas = new G4LogicalVolume(solidPlas, Plastic, "logicPlas");
	G4VPhysicalVolume *physPlas = new G4PVPlacement(nullptr, G4ThreeVector(0., 0., -2.), logicPlas, "physPlas", logicWorld, false, 0, true);
	logicPlas->SetVisAttributes(plasColor);
	// return physDetec;

	return physWorld;
}
