#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

#include"./Headers/Personaje.h"
#include"./Headers/Personajes/Conejo.h"

int main()
{
  
  cout << "Eres un Robot y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la barca solo caben dos individuos, y uno de ellos debes ser tú, para pilotarla. Las órdenes que puedes dar son:\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte" << endl << endl;

  string columna;

  string interfaz[5][4] = {
                          {"IZQUIERDA","BARCA","","DERECHA"},
                          {"Robot","","",""},
                          {"Zorro","","",""},
                          {"Conejo","","",""},
                          {"Lechuga","","",""}
                          };

  for(int i = 0; i < 5; i++)
  {
    cout << "| ";
    for(int j = 0; j < 4; j++)
    {
      if(interfaz[i][j].length() < 9)
      {
        int espacios = 9 - interfaz[i][j].length();
        cout << interfaz[i][j];
        for(int i = 0;i < espacios; i++)
        {
          cout << " ";
        }
        cout << " | ";
      } 
      else
      {
        cout << interfaz[i][j] << " | ";
      }
    }
    cout << endl;
  }

  // cout << endl;
  cout << "\n¿Que desea mover? "; getline(cin,columna);

  if(columna == "B" || columna == "b")
  {
    cout << "Se movio la barca\n";
  }

  return 0;
}


  //Contar palabras de cada posición

  // for(int i = 0; i < 5; i++)
  // {
  //   for(int j = 0; j < 4; j++)
  //   {
  //     cout << interfaz[i][j].length() << " ";
  //   }
  //   cout << endl;
  // }


  // for(int i = 0; i < 5;i++)
  // {
  //   cout<<endl;
  //   for(int j = 0;j < 5; j++)
  //   {
  //     cout << "|            ";
  //   }
  // }