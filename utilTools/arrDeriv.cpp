#include "arrDeriv.hpp"
#include <stdio.h>

ArrDeriv::ArrDeriv()
{
  this->g = 0;
  this->sd = 0;
  this->sizeX = 0;
  this->sizeY = 0;
}

ArrDeriv::ArrDeriv(int sizeX, int sizeY)
{
  this->g = new Gradient[sizeX*sizeY];
  this->sd = new SecondDeriv[sizeX*sizeY];
  this->sizeX = sizeX;
  this->sizeY = sizeY;
}

void ArrDeriv::initDerivArr(int sizeX, int sizeY)
{

  this->g = new Gradient[sizeX*sizeY];
  this->sd = new SecondDeriv[sizeX*sizeY];
  this->sizeX = sizeX;
  this->sizeY = sizeY;
  
}

void ArrDeriv::setgx(float gx, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setgx(gx);
}
void ArrDeriv::setgy(float gy, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setgy(gy);
}
void ArrDeriv::setGradient(Gradient grad, int posi, int posj)
{
  (this->g)[posj*this->sizeX + posi] = grad;
}
void ArrDeriv::setGradient(float gx, float gy, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,0);
}
void ArrDeriv::setGradient(float gx, float gy, float z, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,z);
}
void ArrDeriv::setArrGradient(float *gx, float *gy, int sizeX, int sizeY)
{
  int i;

  this->sizeX = sizeX;
  this->sizeY = sizeY;

  for(i = 0; i < sizeX*sizeY; i++)
    {
      ((this->g)[i]).setGradient(gx[i], gy[i], 0);
    }
    
}
void ArrDeriv::setdx(float dx, int posi, int posj)
{
  ((this->sd)[posj*this->sizeX + posi]).setdx(dx);
}
void ArrDeriv::setdy(float dy, int posi, int posj)
{
  ((this->sd)[posj*this->sizeX + posi]).setdy(dy);
}
void ArrDeriv::setSecondDeriv(SecondDeriv sDeriv, int posi, int posj)
{
  (this->sd)[posj*this->sizeX + posi] = sDeriv;
}
void ArrDeriv::setSecondDeriv(float dx, float dy, int posi, int posj)
{
  ((this->sd)[posj*this->sizeX + posi]).setSecondDeriv(dx,dy,0);
}
void ArrDeriv::setSecondDeriv(float dx, float dy, float z, int posi, int posj)
{
  ((this->sd)[posj*this->sizeX + posi]).setSecondDeriv(dx,dy,z);
}
void ArrDeriv::setArrSecondDeriv(float *dx, float *dy, int sizeX, int sizeY)
{
  int i;

  this->sizeX = sizeX;
  this->sizeY = sizeY;

  for(i = 0; i < sizeX*sizeY; i++)
    {
      ((this->sd)[i]).setSecondDeriv(dx[i], dy[i], 0);
    }
    
}
void ArrDeriv::setDeriv(Gradient grad, SecondDeriv sDeriv, int posi, int posj)
{
  (this->g)[posj*this->sizeX + posi] = grad;
  (this->sd)[posj*this->sizeX + posi] = sDeriv;
}
void ArrDeriv::setDeriv(float gx, float gy, float dx, float dy, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,0);
  ((this->sd)[posj*this->sizeX + posi]).setSecondDeriv(dx,dy,0);
}
void ArrDeriv::setDeriv(float gx, float gy, float dx, float dy, float z, int posi, int posj)
{
  ((this->g)[posj*this->sizeX + posi]).setGradient(gx,gy,z);
  ((this->sd)[posj*this->sizeX + posi]).setSecondDeriv(dx,dy,z);
}
void ArrDeriv::setArrDeriv(float *gx, float *gy, float *dx, float *dy, int sizeX, int sizeY)
{
  int i;

  this->sizeX = sizeX;
  this->sizeY = sizeY;

  for(i = 0; i < sizeX*sizeY; i++)
    {
      ((this->g)[i]).setGradient(gx[i], gy[i], 0);
      ((this->sd)[i]).setSecondDeriv(dx[i], dy[i], 0);
    }
    
}
void ArrDeriv::setsizeX(int sizeX)
{
  this->sizeX = sizeX;
}
void ArrDeriv::setsizeY(int sizeY)
{
  this->sizeY = sizeY;
}

