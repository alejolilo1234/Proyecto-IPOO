#include "../HEADERS/Jugador.h"
#include "../HEADERS/EXTENDS FROM LUGAR/Orilla.h"
#include "../HEADERS/EXTENDS FROM LUGAR/Barca.h"

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
  //
  this -> start(true);
  this -> playersName();
  this -> showInstructions();
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
  cout << "Tu nombre campeon: ";
  getline(cin,this -> name);
  if(this -> name == ""){
    this -> name = "Jugador 1";
  } 
}

void Jugador::showInstructions()
{
  cout << "\n¡Bienvenido " << this -> name <<  "!\n\nEres un Robot y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la barca solo caben dos individuos, y uno de ellos debes ser tú, para pilotarla. Las órdenes que puedes dar son:\n\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte\n\n";
}