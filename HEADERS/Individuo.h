#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <string>

using namespace std;

class Individuo 
{
  private:
  int id;
  string name;

  public:
  // Constructor y destructor de la clase Individuo.

  /**
  Constructor de la clase Individuo.
  */
  Individuo(string, int);
  /**
  Destructor de la clase Individuo.
  */
  ~Individuo();
  
  // Getters de la clase Individuo.
  
  // Setters de la clase Individuo.
  
  // Métodos de la clase Individuo.
  
};

#else 
class Individuo;
#endif