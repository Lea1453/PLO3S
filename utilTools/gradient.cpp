#include <stdio.h>
#include <math.h>

#include "gradient.hpp"



//Gradient constructors
Gradient::Gradient ()
  {
    gx = 0;
    gy = 0;
    z = 0;
    init_val = false;
    this->normGrad = 0;
    this->arctan = 0;
    this->arctangx = 0;
    this->arctangy = 0;
  }

Gradient::Gradient(float gx, float gy, float z)
{
  this->gx = gx;
  this->gy = gy;
  this->z = z;
  this->init_val = true;
  this->normGrad = sqrt(gx*gx + gy*gy);
  if(gx != 0.0)
    {
      this->arctan = atan(gy/gx);
    }
  else
    {
      this->arctan = atan(gy/0.00001);
    }
  this->arctangx = atan(gx);
  this->arctangy = atan(gy);
}

void Gradient::getArrayGx (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getgx();
    }
}

void Gradient::getArrayGy (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getgy();
    }
}

void Gradient::getArrayZ (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getz();
    }
}

void Gradient::getArrayNorm (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getnorm();
    }
}

void Gradient::getArrayArctan (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctan();
    }
}

void Gradient::getArrayArctangx (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctangx();
    }
}

void Gradient::getArrayArctangy (Gradient *arrG, float *arrF, int size)
{
  int i;
    
  for (i = 0; i < size; i++)
    {
      arrF[i] = arrG[i].getarctangy();
    }
}

void Gradient::setGradient (float gx, float gy, float z)
{
  this->gx = gx;
  this->gy = gy;
  this->z = z;
  this->init_val = true;

  this->normGrad = sqrt(gx*gx + gy*gy);
    if(gx != 0.0)
    {
      this->arctan = atan(gy/gx);
    }
  else
    {
      this->arctan = atan(gy/0.00001);
    }
  this->arctangx = atan(gx);
  this->arctangy = atan(gy);
}

/*fonctions sensibles car on ne modifie pas la norm ou atan*/
void Gradient::setgx(float gx)
{
  this->gx = gx;
}

void Gradient::setgy(float gy)
{
  this->gy = gy;
}
