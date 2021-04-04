#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<iostream>
#include<string.h>

using namespace std;

class Personaje
{
  protected:
  string nombre;

  public:
  /**
  Constructor.
  */
  Personaje(string);
  /**
  Nos dice su nombre.
  */
  string suNombre();
};

#else
class Personaje;
#endif