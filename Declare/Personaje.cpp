#include"../Headers/Personaje.h"

Personaje::Personaje(string _name)
{
  this -> nombre = _name;
}

string Personaje::suNombre()
{
  return nombre;
}