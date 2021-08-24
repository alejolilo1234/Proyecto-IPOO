#ifndef LUGAR_H
#define LUGAR_H

#include <vector>
#include "./Individuo.h"

class Lugar 
{
  protected:
  int id;
  string name;
  vector <Individuo *> characters;
  int capacity;

  public:
  // Constructor y destructor de la clase Lugar.

  /**
  Constructor de la clase Lugar.
  */
  Lugar(string,int);
  /**
  Destructor de la clase Lugar.
  */
  ~Lugar();

  // Getters de la clase Lugar.

  /**
  Obtiene el id del Lugar.
  */
  int getId();
  /**
  Obtiene el nombre del Lugar.
  */
  string getName();
  int getCapacity();
  int getCharactersSize();

  // Setters de la clase Lugar.

  /**
  Reemplaza id del Lugar.
  */
  void setId(int);
  /**
  Reemplaza nombre del Lugar.
  */
  void setName(string);

  // Métodos de la clase Lugar.

  void introduceCharacter(Individuo *);
  void takeOutCharacter();

  

  
};

#else 
class Lugar;
#endif