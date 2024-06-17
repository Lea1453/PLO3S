#!/bin/bash


#Number of object of the dataset
nb_object=$1


#Compute WKS
./WKS/WKS_script_off.sh 
octave ./WKS/WKS_main.m 


#Copy the needed files to the next folder projections
cp ./WKS/out/* ./projections/in/
cp ./WKS/in/*off ./projections/in/


#Compute the projection on the 2D space
./projection/EDTSurf ${nb_object}


#Copy the needed files to the next folder triangulation
cp ./projections/out/* ./triangulation/in/


#Compute the triangulation
./triangulation/triangulation.sh

#Copy the needed files to the next folder comparison
cp ./triangulation/out/*asc ./comparison/in/

#Compare proteins
./comparison/scorePWSKMMView.sh
