#include <stdio.h>
#include <math.h>

#include "secondDeriv.hpp"



//SecondDeriv constructors
SecondDeriv::SecondDeriv ()
  {
    dx = 0;
    dy = 0;
    z = 0;
    init_val = false;
    this->normGrad = 0;
    this->arctan = 0;
    this->arctandx = 0;
    this->arctandy = 0;
  }

SecondDeriv::SecondDeriv(float dx, float dy, float z)
{
  this->dx = dx;
  this->dy = dy;
  this->z = z;
  this->init_val = true;
  this->normGrad = sqrt(dx*dx + dy*dy);
  if(dx != 0.0)
    {
      this->arctan = atan(dy/dx);
    }
  else
    {
      this->arctan = atan(dy/0.00001);
    }
  this->arctandx = atan(dx);
  this->arctandy = atan(dy);
}

void SecondDeriv::getArrayDx (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getdx();
    }
}

void SecondDeriv::getArrayDy (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getdy();
    }
}

void SecondDeriv::getArrayZ (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getz();
    }
}

void SecondDeriv::getArrayNorm (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getnorm();
    }
}

void SecondDeriv::getArrayArctan (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctan();
    }
}

void SecondDeriv::getArrayArctandx (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctandx();
    }
}

void SecondDeriv::getArrayArctandy (SecondDeriv *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctandy();
    }
}

void SecondDeriv::setSecondDeriv (float dx, float dy, float z)
{
  this->dx = dx;
  this->dy = dy;
  this->z = z;
  this->init_val = true;

  this->normGrad = sqrt(dx*dx + dy*dy);
    if(dx != 0.0)
    {
      this->arctan = atan(dy/dx);
    }
  else
    {
      this->arctan = atan(dy/0.00001);
    }
  this->arctandx = atan(dx);
  this->arctandy = atan(dy);
}

/*fonctions sensibles car on ne modifie pas la norm ou atan*/
void SecondDeriv::setdx(float dx)
{
  this->dx = dx;
}

void SecondDeriv::setdy(float dy)
{
  this->dy = dy;
}
