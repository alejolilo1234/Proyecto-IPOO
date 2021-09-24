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

#include <string>
#include "../../HEADERS/Lugar.h"
#include "../../HEADERS/EXTENDS FROM LUGAR/Orilla.h"

// Constructor y destructor de la clase Orilla.

Orilla::Orilla(string _name, Lugar * _neighbor, Lugar * _nextNeighbor) : Lugar(_name,_neighbor,_nextNeighbor)
{
  // Lugar::setCapacity(4);
  Lugar::setCommand("*");
}

Orilla::~Orilla()
{
  // 
}

// Getters de la clase Orilla.
  
// Setters de la clase Orilla.

// Métodos de la clase Orilla.

bool Orilla::canMove()
{
  for(int i = 0; i < characters.size(); i++)
    if(this -> characters[i]->getIfItCanMoveBoat())
      return true;
  return false;
}