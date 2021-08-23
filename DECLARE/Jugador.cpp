#include "../HEADERS/INCLUDES.h"

// Constructor y destructor de la clase Jugador.

Jugador::Jugador()
{
  // Lugares
  this -> lugar.push_back(new Orilla("Orilla Uno", 2));
  this -> lugar.push_back(new Orilla("Orilla Dos", 3));
  this -> lugar.push_back(new Barca("Barca", 4));
  // Individuos
  this -> individuo.push_back(new Individuo("Robot", 5));
  this -> individuo.push_back(new Individuo("Zorro", 6));
  this -> individuo.push_back(new Individuo("Conejo", 7));
  this -> individuo.push_back(new Individuo("Lechuga", 8));
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