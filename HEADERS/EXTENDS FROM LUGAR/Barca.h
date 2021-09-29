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

#ifndef BARCA_H
#define BARCA_H

class Barca : public Lugar
{
  private:

  public:
  // Constructor y destructor de la clase Orilla.

  /**
  Constructor de la clase Barca.
  */
  Barca(string, Lugar *, Lugar *);
  /**
  Destructor de la clase Barca.
  */
  ~Barca();

  // Getters de la clase Barca.
  
  // Setters de la clase Barca.
  
  // Métodos de la clase Barca.

  bool canMove();

};

#else 
class Barca;
#endif