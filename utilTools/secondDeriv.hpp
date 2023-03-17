#ifndef _SECONDDERIV_H_
#define _SECONDDERIV_H_

class SecondDeriv {
  float dx,dy;
  float z;
  float normGrad;
  float arctan;
  float arctandx;
  float arctandy;
  bool init_val;


  
public:
  SecondDeriv ();
  SecondDeriv(float dx, float dy, float z);
  
  static void getArrayDx (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayDy (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayZ (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayNorm (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayArctan (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayArctandx (SecondDeriv *arrG, float *arrF, int size);
  static void getArrayArctandy (SecondDeriv *arrG, float *arrF, int size);
  
  float getdx () { return this->dx; }
  float getdy () { return this->dy; }
  float getz () {return this->z;}
  float getnorm () { return this->normGrad; }
  float getarctan () {return this->arctan;}
  float getarctandx () {return this->arctandx;}
  float getarctandy () {return this->arctandy;}
  bool getinitval() {return this->init_val;}
  
  void setSecondDeriv (float dx,float dy, float z);
  void setdx(float dx);
  void setdy(float dy);


  
};

#endif
