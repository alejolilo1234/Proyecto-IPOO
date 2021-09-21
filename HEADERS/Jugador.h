/*
  Archivo: Concursante.h
  Autores: 
* Jhon Abril <jhon.abril@correounivalle.edu.co>
* Deisy Catalina Melo <deisy.melo@correounivalle.edu.co>
* Luisa María Cardenas <cardenas.luisa@correounivalle.edu.co>
  Fecha creación: 2021-09-12
  Fecha última modificación: 2021-09-12
  Licencia: GNU-GPL
*/

/**
  CLASE:
  INTENCIÓN:
  RELACIONES:
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "./Individuo.h"
#include "./Lugar.h"
#include <vector>

class Jugador 
{
  private:
  string name;
  Individuo * principalCharacter;
  bool play;
  bool commands;
  int interfaceSize;
  int characterSizeInInterface;
  vector <Lugar *> interfaceOfPlaces;
  
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

  void setName();

  void setPrincipalCharacter();

  // void setOnlyOnePrincipalCharacter();
  
  // Métodos de la clase Jugador.

  void showInstructions();

  void showCommands();

  void commandsText();

  void symbolsForPlaces(int,string,string);

  void symbolsForCharacters(int,int,string,string,bool,string);

  void symbolsForTop_BottomRows(bool);

  void createInterface(bool);

  void introducePlaces(Lugar *);

  void introduceCharacter(Lugar *, Individuo *);

  void takeCharacter(Lugar *, Individuo *);

  void whatDoYouWantToMove();

  void start(bool);
  
  void imprimirIndividuosMover();
};

#else 
class Jugador;
#endif