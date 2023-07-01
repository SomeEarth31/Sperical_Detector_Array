# Sperical_Detector_Array
Spherical_Detector_Array_GEANT4

This repository contains an example CERN-GEANT4 simulation utilizing the CERN-ROOT toolkit. It is a template for anyone using GEANT4 for scientific purposes.
If you are new to GEANT4, I recommend you first go through the following to get an idea of its basics:
  1. https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/index.html
  2. https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/index.html
  3. https://youtu.be/RuyMUswYaWo
If you are new to ROOT, I recommend you check out the following:
  1. https://youtu.be/sgKiwdLrLfc
  2. https://root.cern/doc/master/
You can simulate without having ROOT installed on your machine, but that would require basic knowledge of the GEANT4 code structure, as you would have to go into the files and comment out the ROOT-specific lines. This is a simple task, but a basic understanding is required nonetheless.

This repo is to be used with CMAKE, as is the standard. It includes a NaI detector array in the shape of a spherical shell. It is configured to measure the energies of any gamma rays that hit the shot and output them to files titled 'output.root' and 'output.txt.' Using standard root commands, you can then output a histogram from the .root file. The .txt file is used for a more accurate reading. One can also(and usually does) create another script to calculate the total counts for specific energy levels and total rays hit, thus being able to calculate the efficiency of the detector in quesiton. 

I set it up so that all commands to be input in GEANT4 can be done before running the simulation using the in.mac macros. I have used a general particle source and have currently defined a Co-60 ion. Other(commented-out) lines include a definition for a monoenergetic gamma ray. 

I hope this help! Happy scienc-ing!
