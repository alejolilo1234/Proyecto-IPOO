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
#include<map>

class Jugador 
{
  private:
  string name;
  bool play;
  bool commands;
  int interfaceSize;
  int characterSizeInInterface;
  vector <Lugar *> interfaceOfPlaces;
  vector <Individuo *> principalCharacters;
  vector <Individuo *> nameAndCommand;
  vector <Individuo *> predators;
  int lengthOfNames;
  map <int, string> capacities; 

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

  void setNameAndCommand();

  void setLengthOfNames();

  void setUniqueCommands();

  void setPredators();
  
  // Métodos de la clase Jugador.

  void showInstructions(bool);

  void showCommands();

  void symbolsForPlaces(int,string,string);

  void symbolsForCharacters(int,int,string,string,bool,string);

  void symbolsForTop_BottomRows(bool);

  int createInterface(bool,bool);

  void introducePlaces(Lugar *);

  void introduceCharacter(Lugar *, Individuo *);

  void takeCharacter(Lugar *, Individuo *);

  int whatDoYouWantToMove();

  bool isDuplicated(string, vector <string>);

  void deleteCommand(string, vector <string> &);

  bool searchIfHasCommand(string);

  void start(bool);
};

#else 
class Jugador;
#endif