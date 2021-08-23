#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "./Individuo.h"
#include "./Lugar.h"

class Jugador 
{
  private:
  int id = 1;
  string name;
  vector <Lugar *> lugar;
  vector <Individuo *> individuo;
  bool play;

  public:
  // Constructor y destructor de la clase Jugador.

  /**
  Constructor de la clase Jugador.
  */
  Jugador();
  /**
  Destructor de la clase Jugador.
  */
  ~Jugador();

  // Getters de la clase Jugador.
  
  // Setters de la clase Jugador.
  
  // Métodos de la clase Jugador.

  /**
  Método que inicia el juego.
  */
  void start(bool);
  /**
  Método para pedirle el nombre al jugador.
  */
  void playersName();
};

#else 
class Jugador;
#endif