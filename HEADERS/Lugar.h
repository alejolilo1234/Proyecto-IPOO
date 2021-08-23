#ifndef LUGAR_H
#define LUGAR_H

#include "./INCLUDES.h"

class Lugar 
{
  private:
  int id;
  string name;

  public:
  // Constructor y destructor de la clase Lugar.

  /**
  Constructor de la clase Lugar.
  */
  Lugar(string);
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
  
};

#else 
class Lugar;
#endif