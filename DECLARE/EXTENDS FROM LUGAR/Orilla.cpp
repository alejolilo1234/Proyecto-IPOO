#include <string>
#include "../../HEADERS/Lugar.h"
#include "../../HEADERS/EXTENDS FROM LUGAR/Orilla.h"

// Constructor y destructor de la clase Orilla.

Orilla::Orilla(string _name, int _capacity, int _id) : Lugar(_name,_capacity)
{
  this -> setId(_id);
}

Orilla::~Orilla()
{
  // 
}

// Getters de la clase Orilla.
  
// Setters de la clase Orilla.

// Métodos de la clase Orilla.