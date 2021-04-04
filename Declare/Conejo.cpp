#include"../Headers/Personajes/Conejo.h"

Conejo::Conejo(string _nombre) : Personaje(_nombre)
{
  this -> nombre = _nombre;
}

string Conejo::suNombre()
{
  return Personaje::suNombre();
}