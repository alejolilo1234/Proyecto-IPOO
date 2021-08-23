// #include "../HEADERS/INCLUDES.h"
#include "../HEADERS/Lugar.h"

// Constructor y destructor de la clase Lugar.

Lugar::Lugar(string _name)
{
  this -> name = _name;
}

Lugar::~Lugar()
{
  // 
}

// Getters de la clase Lugar.

int Lugar::getId()
{
  return this -> id;
}

string Lugar::getName()
{
  return this -> name;
}

// Setters de la clase Lugar.

void Lugar::setId(int _id)
{
  this -> id = _id;
}

void Lugar::setName(string _name)
{
  this -> name = _name;
}

// Métodos de la clase Lugar.