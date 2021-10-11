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

#include "../HEADERS/Lugar.h"
#include <string.h>

// Constructor y destructor de la clase Lugar.

Lugar::Lugar(string _name, Lugar * _neighbor, Lugar * _nextNeighbor)
{
  string Name;
  for(int posicion = 0;posicion < _name.size(); posicion++)
    Name += toupper(_name[posicion]);
  this -> name = Name;
  this -> neighbor = _neighbor;
  this -> nextNeighbor = _nextNeighbor;
  this -> setPrincipalCharacters();
  this -> setPreys();
}

Lugar::~Lugar()
{
  // if(!this -> characters.empty())
  // {
  //   for(int i = 0; i < characters.size(); i++)
  //   {
      
  //   }
  // }
}

// Getters de la clase Lugar.

string Lugar::getName()
{
  return this -> name;
}

int Lugar::getCapacity()
{
  return this -> capacity;
}

int Lugar::getSizeOfCharacters()
{
  return this -> characters.size();
}

Individuo * Lugar::getCharacter(int _index)
{
  if(!characters.empty())
    if(_index < characters.size())
      return this -> characters[_index];
  return nullptr;
}

Individuo * Lugar::getCharacter(string _charater)
{
  for(int which = 0; which < this -> characters.size(); which++)
  {
    if(characters[which] -> getCommand() == _charater)
      return characters[which];
  }
  return nullptr;
}

string Lugar::getCommand()
{
  return this -> command;
}

// Setters de la clase Lugar.

void Lugar::setNeighbor(Lugar * _neighbor)
{
  this -> neighbor = _neighbor;
}

void Lugar::setNextNeighbor(Lugar * _nextNeighbor)
{
  this -> nextNeighbor = _nextNeighbor;
}

void Lugar::setCapacity(int _capacity)
{
  this -> capacity = _capacity;
}

void Lugar::setCommand(string _command)
{
  this -> command = _command;
}

void Lugar::setPrincipalCharacters()
{
  for(int i = 0; i < characters.size(); i++)
    if(characters[i]->getIfItCanMoveBoat())
      principalCharacters.push_back(characters[i]);
}

void Lugar::setPreys()
{
  for(int i = 0; i < characters.size(); i++)
    if(characters[i]->getPrey() != nullptr)
      preys.push_back(characters[i]->getPrey());
}


// Métodos de la clase Lugar.

bool Lugar::haveNeighbor(Lugar * _place)
{
  if(_place == this -> neighbor)
    return true;
  return false;
}

void Lugar::introduceCharacter(Individuo *_character)
{
  if(this -> characters.size() < this -> capacity)
    this -> characters.push_back(_character);
}

void Lugar::takeCharacter(Individuo *_character)
{
  for(int which = 0; which < characters.size(); which++)
    if(characters[which] == _character)
      this -> characters.erase(characters.begin() + which);
}

bool Lugar::canMove()
{
  return false;
}

bool Lugar::wasEaten()
{
  for(int i = 0; i < characters.size(); i++)
  {
    if(characters[i] -> getIfItCanMoveBoat())
      return false;
  }
  for(int i = 0; i < characters.size(); i++)
  {
    if(characters[i] -> getPrey() != nullptr && (characters[i] -> getPrey() == characters[i + 1] || characters[i] -> getPrey() == characters[i - 1]) && characters.size() > 1)
      return true;
  }
  return false;
}

