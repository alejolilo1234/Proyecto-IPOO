#include "../HEADERS/Lugar.h"

// Constructor y destructor de la clase Lugar.

Lugar::Lugar(string _name,int _capacity)
{
  this -> name = _name;
  this -> capacity = _capacity;
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

int Lugar::getCapacity()
{
  return this -> capacity;
}

int Lugar::getCharactersSize()
{
  return this -> characters.size();
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

void Lugar::introduceCharacter(Individuo *_character)
{
  this -> characters.push_back(_character);
}

void Lugar::takeOutCharacter()
{
  this -> characters.pop_back();
}