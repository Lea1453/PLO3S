#include "arrGradient.hpp"
#include <stdio.h>
ArrGradient::ArrGradient()
{
  this->g = 0;
  this->sizeX = 0;
  this->sizeY = 0;
}

ArrGradient::ArrGradient(int sizeX, int sizeY)
{
  this->g = new Gradient[sizeX*sizeY];
  this->sizeX = sizeX;
  this->sizeY = sizeY;
}

void ArrGradient::initGradientArr(int sizeX, int sizeY)
{

  this->g = new Gradient[sizeX*sizeY];
  this->sizeX = sizeX;
  this->sizeY = sizeY;

  
}

void ArrGradient::setgx(float gx, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setgx(gx);
}
void ArrGradient::setgy(float gy, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setgy(gy);
}
void ArrGradient::setGradient(Gradient grad, int posi, int posj)
{
  (this->g)[posj*this->sizeX + posi] = grad;
}
void ArrGradient::setGradient(float gx, float gy, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,0);
}
void ArrGradient::setGradient(float gx, float gy, float z, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,z);
}
void ArrGradient::setArrGradient(float *gx, float *gy, int sizeX, int sizeY)
{
  int i;

  this->sizeX = sizeX;
  this->sizeY = sizeY;

  for(i = 0; i < sizeX*sizeY; i++)
    {
      ((this->g)[i]).setGradient(gx[i], gy[i], 0);
    }
    
}
void ArrGradient::setsizeX(int sizeX)
{
  this->sizeX = sizeX;
}
void ArrGradient::setsizeY(int sizeY)
{
  this->sizeY = sizeY;
}

