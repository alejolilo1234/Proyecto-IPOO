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

Individuo::Individuo(string _name) : canMoveBoat(false), food(nullptr)
{
  this -> setName(_name);
  this -> setCommand(_name);
}

Individuo::Individuo(string _name, bool _canMoveBoat) : canMoveBoat(_canMoveBoat), food(nullptr)
{
  this -> setName(_name);
  this -> setCommand(_name);
}

Individuo::Individuo(string _name, Individuo *_food) : name(_name), food(_food), canMoveBoat(false)
{
  this -> setName(_name);
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

Individuo * Individuo::getPrey()
{
  return this -> food;
}

// Setters de la clase Individuo.

void Individuo::setName(string _name)
{
  string aux;
  for(int posicion = 0;posicion < _name.size(); posicion++)
    aux += toupper(_name[posicion]);
  this -> name = aux;
}

void Individuo::setCommand(string _command)
{
  this -> command = toupper(_command.front());
}

// Métodos de la clase Individuo.

// bool Individuo::hasCommand(string _command)
// {
//   for(int posicion = 0;posicion < _name.size(); posicion++)
//     aux += toupper(_name[posicion]);
//   return false;
// }