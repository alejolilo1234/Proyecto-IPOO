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

#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <string>

using namespace std;

class Individuo 
{
  private:
  string name;
  string command;
  Individuo * food;
  bool canMoveBoat;

  public:
  // Constructor y destructor de la clase Individuo.

  /**
  Constructor de la clase Individuo.
  */
  Individuo(string);

  Individuo(string, bool);

  Individuo(string, Individuo *);
  /**
  Destructor de la clase Individuo.
  */
  ~Individuo();
  
  // Getters de la clase Individuo.

  string getName();

  string getCommand();  

  bool getIfItCanMoveBoat();

  Individuo * getPrey();

  // Setters de la clase Individuo.

  void setName(string);

  void setCommand(string);
  
  // Métodos de la clase Individuo.

  // bool hasCommand(string);
  
};

#else 
class Individuo;
#endif