/*
  Archivo: main.cpp
  Autores: 
* Jhon Abril <jhon.abril@correounivalle.edu.co>
* Deisy Catalina Melo <deisy.melo@correounivalle.edu.co>
* Luisa María Cardenas <cardenas.luisa@correounivalle.edu.co>
  Fecha creación: 2021-09-12
  Fecha última modificación: 2021-09-12
  Licencia: GNU-GPL
*/

#include "../HEADERS/Individuo.h"

// Constructor y destructor de la clase Individuo.

Individuo::Individuo(string _name, Individuo *_food, bool _canMoveBoat) : food(_food), canMoveBoat(_canMoveBoat)
{
  string Name;
  for(int posicion = 0;posicion < _name.size(); posicion++)
    Name += toupper(_name[posicion]);
  this -> name = Name;
  this -> setCommand(_name);
}

Individuo::Individuo(string _name, Individuo *_food) : name(_name), food(_food), canMoveBoat(false)
{
  string Name;
  for(int posicion = 0;posicion < _name.size(); posicion++)
    Name += toupper(_name[posicion]);
  this -> name = Name;
  this -> setCommand(_name);
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

string Individuo::getCommand()
{
  return this -> command;
}

bool Individuo::getIfItCanMoveBoat()
{
  return this -> canMoveBoat;
}
  
// Setters de la clase Individuo.

void Individuo::setCommand(string _command)
{
  this -> command = toupper(_command.front());
}

// Métodos de la clase Individuo.