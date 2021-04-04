#ifndef CONEJO_H
#define CONEJO_H

#include<iostream>
#include<string.h>
#include"../Personaje.h"

using namespace std;

class Conejo : public Personaje
{
  protected:
  // string nombre;

  public:
  /**
  Constructor.
  */
  Conejo(string);
  /**
  Nos dice su nombre.
  */
  string suNombre();
};

#else
class Conejo;
#endif