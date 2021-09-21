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
#include "../../HEADERS/EXTENDS FROM LUGAR/Barca.h"

// Constructor y destructor de la clase Barca.

Barca::Barca(string _name, Lugar * _neighbor, Lugar * _nextNeighbor) : Lugar(_name,_neighbor,_nextNeighbor)
{
  Lugar::setCapacity(2);
  Lugar::setCommand("B");
}

Barca::~Barca()
{
  // 
}

// Getters de la clase Barca.
  
// Setters de la clase Barca.

// Métodos de la clase Barca.