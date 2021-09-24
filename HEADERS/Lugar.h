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

#ifndef LUGAR_H
#define LUGAR_H

#include <vector>
#include "./Individuo.h"

class Lugar 
{
  protected:
  string name;
  string command;
  vector <Individuo *> principalCharacters;
  vector <Individuo *> characters;
  vector <Individuo *> preys;
  int capacity;
  Lugar * neighbor;
  Lugar * nextNeighbor;
  

  public:
  // Constructor y destructor de la clase Lugar.

  /**
  Constructor de la clase Lugar.
  */
  Lugar(string,Lugar *, Lugar *);
  /**
  Destructor de la clase Lugar.
  */
  ~Lugar();

  // Getters de la clase Lugar.

  string getName();

  int getCapacity();

  int getSizeOfCharacters();

  Individuo * getCharacter(int);

  Individuo * getCharacter(string);

  string getCommand();

  // Setters de la clase Lugar.

  void setNeighbor(Lugar *);

  void setNextNeighbor(Lugar *);

  void setCapacity(int);

  void setCommand(string);

  void setPrincipalCharacters();

  void setPreys();

  // Métodos de la clase Lugar.

  bool haveNeighbor(Lugar *);

  void introduceCharacter(Individuo *);

  void takeCharacter(Individuo *);
  
  virtual bool canMove();

  bool wasEaten();

};

#else 
class Lugar;
#endif