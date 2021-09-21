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

#ifndef ORILLA_H
#define ORILLA_H

class Orilla : public Lugar
{
  private:

  public:
  // Constructor y destructor de la clase Orilla.
  
  /**
  Constructor de la clase Orilla.
  */
  Orilla(string, Lugar *, Lugar *);
  /**
  Destructor de la clase Orilla.
  */
  ~Orilla();

  // Getters de la clase Orilla.
  
  // Setters de la clase Orilla.
  
  // Métodos de la clase Orilla.
  
};

#else 
class Orilla;
#endif