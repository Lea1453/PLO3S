#ifndef _ARRDERIV_H_
#define _ARRDERIV_H_

#include "gradient.hpp"
#include "secondDeriv.hpp"

class ArrDeriv{

  Gradient *g;
  SecondDeriv *sd;
  int sizeX, sizeY;

public:
  ArrDeriv();
  ArrDeriv(int sizeX, int sizeY);
  
  void initDerivArr(int sizeX, int sizeY);
  
  int getsizeX () { return this->sizeX; }
  int getsizeY () { return this->sizeY; }
  float getgx(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getgx(); }
  float getgy(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getgy(); }
  float getdx(int posi, int posj) {return ((this->sd)[posj*this->sizeX + posi]).getdx(); }
  float getdy(int posi, int posj) {return ((this->sd)[posj*this->sizeX + posi]).getdy(); }
  float getarctan(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getarctan(); }
  Gradient* getGradient() { return this->g; }
  SecondDeriv* getDeriv() { return this->sd; }
  
  void setgx(float gx, int posi, int posj);
  void setgy(float gy, int posi, int posj);
  void setGradient(Gradient grad, int posi, int posj);
  void setGradient(float gx, float gy, int posi, int posj);
  void setGradient(float gx, float gy, float z, int posi, int posj);
  void setArrGradient(float *gx, float *gy, int sizeX, int sizeY);
  void setdx(float dx, int posi, int posj);
  void setdy(float dy, int posi, int posj);
  void setSecondDeriv(SecondDeriv sDeriv, int posi, int posj);
  void setSecondDeriv(float dx, float dy, int posi, int posj);
  void setSecondDeriv(float dx, float dy, float z, int posi, int posj);
  void setArrSecondDeriv(float *dx, float *dy, int sizeX, int sizeY);
  void setDeriv(Gradient g, SecondDeriv sDeriv, int posi, int posj);
  void setDeriv(float gx, float gy, float dx, float dy, int posi, int posj);
  void setDeriv(float gx, float gy, float dx, float dy, float z, int posi, int posj);
  void setArrDeriv(float *gx, float *gy, float *dx, float *dy, int sizeX, int sizeY);
  void setsizeX(int sizeX);
  void setsizeY(int sizeY);

  ~ArrDeriv() {delete[] g; delete[] sd;}
};

#endif
