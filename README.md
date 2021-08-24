# Proyecto IPOO

## Integrantes:
- Jhon Abril
- Catalina Melo

## Estructura de la clase

```cpp
#ifndef NOMBRE_CLASE_H
#define NOMBRE_CLASE_H

#include "./INCLUDES.h"

class Nombre_clase {
  private:
  public:
  // Constructor y destructor
  /**
  Constructor de la clase Nombre_clase.
  */
  Nombre_clase();
  /**
  Destructor de la clase Nombre_clase.
  */
  ~Nombre_clase();
  // Getters de la clase Nombre_clase.
  
  // Setters de la clase Nombre_clase.
  
  // Métodos de la clase Nombre_clase.
  
};

#else 
class Nombre_clase;
#endif
```

## Modelo entidad relación

## Modelo relacional

## Documentación

```cpp
string matrix[5][4] =
    {
    {this -> lugar[0] -> getName(),
     lugar[2] -> neighborOfWho(lugar[0] -> getId()),
     lugar[2] -> neighborOfWho(lugar[1] -> getId()),
     this -> lugar[1] -> getName()},

     {if(2 == 2) lugar[2] -> printCharacter(0, 0),
      lugar[2] -> printCharacter(0, 2),
      "",
      ""},

     {"Zorro",
      "",
      "",
      ""},

    {"Conejo","","",""},
    {"Lechuga","","",""}
    };

    for(int i = 0; i < 5; i++)
    {
        cout << "| ";
        for(int j = 0; j < 4; j++)
        {
            if(matrix[i][j].length() < 9)
            {
                int espacios = 9 - matrix[i][j].length(); cout << matrix[i][j];

                for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
            }
            else cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
```

```cpp
// Fila uno
  cout << this -> lugar[0] -> getName() << " | ";
  if(lugar[2] -> getNeighbor() == lugar[0] -> getId()){
    cout << lugar[2] -> getName() << " |           ";
  } else {
      cout << "            | " << lugar[2] -> getName() << " ";
  }
  cout << this -> lugar[1] -> getName() << "\n";

  // Fila dos
  cout << lugar[0] -> printCharacter(0) << " ";
  cout << " |            |             |";
```


```cpp
else if(mover[0] == 'L')
  {
    if(places[1]->getCharactersSize() < places[1]->getCapacity())
    {
      Individuo *aux = charactersRowFour[0];
      charactersRowFour[0] = charactersRowFour[1];
      charactersRowFour[1] = aux;
      places[1] -> introduceCharacter(charactersRowFour[1]);
    }
    else
    {
      Individuo *aux = charactersRowFour[0];
      charactersRowFour[0] = charactersRowFour[1];
      charactersRowFour[1] = aux;
      places[1] -> takeOutCharacter();
    }
    this -> clear();
  }
```