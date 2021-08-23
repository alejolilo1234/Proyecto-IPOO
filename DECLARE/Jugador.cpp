#include "../HEADERS/INCLUDES.h"

// Constructor y destructor de la clase Jugador.

Jugador::Jugador()
{
  // 
}

Jugador::~Jugador()
{
  // 
}

// Getters de la clase Jugador.
  
// Setters de la clase Jugador.
  
// Métodos de la clase Jugador.

void Jugador::start(bool _state)
{
  this -> play = _state;
}

void Jugador::playersName()
{
  string name;
  cout << "Tu nombre campeon: ";
  getline(cin,this -> name);
}