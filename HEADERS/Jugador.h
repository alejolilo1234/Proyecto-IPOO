#ifndef JUGADOR_H
#define JUGADOR_H

#include "./INCLUDES.h"

class Jugador 
{
  private:
  int id = 1;
  Orilla *orillaUno = new Orilla("Orilla Uno", 2);
  Orilla *orillaDos = new Orilla("Orilla Dos", 3);
  Barca *barca = new Barca("Barca", 4);
  Individuo *robot = new Individuo("Robot", 5);
  Individuo *zorro = new Individuo("Zorro", 6);
  Individuo *conejo = new Individuo("Conejo", 7);
  Individuo *lechuga = new Individuo("Lechuga", 8);
  bool play;
  string name;

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