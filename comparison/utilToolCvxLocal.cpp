#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

void loadFile_localClass(char *filenameGrpClass, int *aClass, int size)
{
  int i,k, kdeb;
  std::string line;
  std::ifstream fileClass;

  
  fileClass.open(filenameGrpClass,std::ios::in);

  if(fileClass.is_open())
    {
      std::getline(fileClass, line);
      
      k = 0;
      kdeb = 0;

      for(i = 0; i < line.size(); i++)
	{
		 
	  if(line[i] == ' ')
	    {
	     aClass[k] = std::stoi(line.substr(kdeb));
	     kdeb = i+1;
	     k++;
	    }

	}
      /*pour le dernier car il n y a pas despace a la fin */
      aClass[k] = std::stoi(line.substr(kdeb));
    }
  else
    {
      std::cout << "(loadFile_localClass) doesn't open files " <<  filenameGrpClass << " \n";
    }
}
