#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>



#include "stats.hpp"
#include "utilTool.hpp"
#include "gnuplot-iostream.h"



/******************************************
 *
 * print_nbPts_vs_time : affiche le nombre de points des objets en fonction du temps et sauvegarde l'image
 * input : values of computation time (time[]), nomber of points per object (nbPts[]), the size of arrays (size)
 * the name of the image save, without the extension .png (filename) 
 *
 *****************************************/
void print_nbPts_vs_time(float *time, int *nbPts, int size, std::string filename)
{

  Gnuplot gp;
 
  std::vector<std::pair<double, double> > xy_pts;

  int maxNbPts, minNbPts;
  float maxTime, minTime;

  /*les "+1000" "+1" sont pour ne pas avoir les points du graphes colles aux bords*/
  maxNbPts = maxInt(nbPts, size)+1000;
  maxTime = maxFloat(time, size)+1;
  
  minNbPts = minInt(nbPts, size)-1000;
  minTime = minFloat(time, size)-1;
  
  for(int i=0; i<size; i++) {
    xy_pts.push_back(std::make_pair(nbPts[i], time[i]));
  }



  gp << "set xrange [" << minNbPts << ":" << maxNbPts <<"]\nset yrange [" << minTime << ":" << maxTime << "]\n";
  gp << "set terminal png\n";
  gp << "set output '" << filename << ".png'\n";
  gp << "set title 'Number of points vs computation time'\n";
  gp << "set xlabel 'Number of points'\n";
  gp << "set ylabel 'Computation time (seconds)'\n";
  gp << "set key below \n";
  gp << "plot" << gp.file1d(xy_pts) << "t 'Experimental values' ," << gp.file1d(xy_pts) << "u 1:2 smooth unique " << "t 'Interpolation'" << std::endl;

}

/******************************************
 *
 * print_MULTI_nbPts_vs_time : affiche le nombre de points des objets en fonction du temps et sauvegarde l'image
 * On peut avoir plusieurs temps pour le meme nombre de points, tout sera afficher sur le meme graphique
 * input : array of arrays containing values of computation time (time[][]), nomber of points per object (nbPts[]), 
 * the size of arrays (size), the name of the image save, without the extension .png (filename) 
 *
 *****************************************/
void print_MULTI_nbPts_vs_time(float **time, int *nbPts, int size, std::string filename)
{

  Gnuplot gp;
 
  std::vector<std::pair<double, double> > xy_pts;

  int maxNbPts, minNbPts;
  float maxTime, maxTime_tmp, minTime, minTime_tmp;

  int i,j;

  /*les "+-1000" "+-1" sont pour ne pas avoir les points du graphes colles aux bords*/

  maxNbPts = maxInt(nbPts, size)+1000;
  minNbPts = minInt(nbPts, size)-1000;

  maxTime = maxFloat(time[0], size);
  minTime = minFloat(time[0], size);
  for(j = 1; j < size; j++)
    {
      maxTime_tmp = maxFloat(time[j], size);
      if(maxTime_tmp > maxTime)
	maxTime = maxTime_tmp;

      minTime_tmp = minFloat(time[j], size);
      if(minTime_tmp < minTime)
	minTime = minTime_tmp;
    }
  
  maxTime += 1;
  minTime -= 1;


      gp << "set xrange [" << minNbPts << ":" << maxNbPts <<"]\nset yrange [" << minTime << ":" << maxTime << "]\n";
      gp << "set terminal png\n";
      gp << "set output '" << filename << ".png'\n";
      gp << "set title 'Number of points vs computation time'\n";
      gp << "set xlabel 'Number of points'\n";
      gp << "set ylabel 'Computation time (seconds)'\n";
      gp << "set key off \n";
      gp << "plot";
      
  for(j = 0; j < size; j++)
    {
  
      for(i=0; i<size; i++) {
	xy_pts.push_back(std::make_pair(nbPts[i], time[j][i]));
      }

      if(j == size -1)
	gp << gp.file1d(xy_pts) <<  "t 'Experimental values' ,"  << gp.file1d(xy_pts) << "u 1:2 smooth unique " << "t '" << " Interpolation'" ;
      else
	gp << gp.file1d(xy_pts) << "t 'Experimental values' ," << gp.file1d(xy_pts) << "u 1:2 smooth unique t 'Experimental values'" << ",";

      xy_pts.erase(xy_pts.begin(),xy_pts.begin()+size);

    }
  gp << std::endl;

}
