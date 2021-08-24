#include "../HEADERS/Individuo.h"

// Constructor y destructor de la clase Individuo.

Individuo::Individuo(string _name, int _id)
{
  this -> name = _name;
  this -> id = _id;
}

Individuo::~Individuo()
{
  // 
}

// Getters de la clase Individuo.

string Individuo::getName()
{
  return this -> name;
}

int Individuo::getId()
{
  return this -> id;
}
  
// Setters de la clase Individuo.

// Métodos de la clase Individuo.