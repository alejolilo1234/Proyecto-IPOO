#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "./Individuo.h"
#include "./Lugar.h"
#include <vector>

class Jugador 
{
  private:
  // int id = 1;
  string name;
  vector <Lugar *> places;
  vector <Individuo *> charactersRowOne;
  vector <Individuo *> charactersRowTwo;
  vector <Individuo *> charactersRowThree;
  vector <Individuo *> charactersRowFour;
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
  /**
  Método para mostrar instrucciones.
  */
  void showInstructions();

  void printPlaceRow(vector <Lugar *> &);
  void printCharacterRow(vector <Individuo *> &);
  /**
  Método para crear interfaz.
  */
  void createInterface(bool);
  /**
  Método para preguntar a usuario que desea mover.
  */
  void whatDoYouWantToMove();

  void introducePlace(Lugar *);
  void introduceCharacter(int, Individuo *);
  void clear();
};

#else 
class Jugador;
#endif