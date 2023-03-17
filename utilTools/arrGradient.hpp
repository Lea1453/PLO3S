#ifndef _ARRGRADIENT_H_
#define _ARRGRADIENT_H_

#include "gradient.hpp"

class ArrGradient {

  Gradient *g;
  int sizeX, sizeY;

public:
  ArrGradient();
  ArrGradient(int sizeX, int sizeY);
  
  void initGradientArr(int sizeX, int sizeY);
  
  int getsizeX () { return this->sizeX; }
  int getsizeY () { return this->sizeY; }
  float getgx(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getgx(); }
  float getgy(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getgy(); }
  float getarctan(int posi, int posj) {return ((this->g)[posj*this->sizeX + posi]).getarctan(); }
  Gradient* getGradient() { return this->g; }

  void setgx(float gx, int posi, int posj);
  void setgy(float gy, int posi, int posj);
  void setGradient(Gradient grad, int posi, int posj);
  void setGradient(float gx, float gy, int posi, int posj);
  void setGradient(float gx, float gy, float z, int posi, int posj);
  void setArrGradient(float *gx, float *gy, int sizeX, int sizeY);
  void setsizeX(int sizeX);
  void setsizeY(int sizeY);

  ~ArrGradient() {delete[] g;}
};

#endif
