/*
  Archivo: main.cpp
  Autores: 
* Jhon Abril <jhon.abril@correounivalle.edu.co>
* Deisy Catalina Melo <deisy.melo@correounivalle.edu.co>
* Luisa María Cardenas <cardenas.luisa@correounivalle.edu.co>
  Fecha creación: 2021-09-12
  Fecha última modificación: 2021-09-12
  Licencia: GNU-GPL
*/

/*
  HISTORIA: 
  El juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.
*/

#include "./HEADERS/Jugador.h"
#include "./HEADERS/Lugar.h"
#include "./HEADERS/EXTENDS FROM LUGAR/Barca.h"
#include "./HEADERS/EXTENDS FROM LUGAR/Orilla.h"

int main()
{
  Jugador player;
  Orilla left("izquierda",nullptr,nullptr);
  Orilla right("derecha",nullptr,nullptr);
  Barca boat("varquita",&left,&right);

  right.setNextNeighbor(&boat);
  left.setNeighbor(&boat);
  // left.setNextNeighbor(&boat);
  // right.setNeighbor(&boat);

  player.introducePlaces(&left);
  player.introducePlaces(&boat);
  player.introducePlaces(&right);
  // Personajes
  Individuo lectuse("rechuga",nullptr);
  Individuo rabbit("konejo",&lectuse);
  Individuo fox("sorro",&rabbit);
  Individuo robot("lobot",nullptr,true);
  player.introduceCharacter(&left,&robot);
  player.introduceCharacter(&left,&fox);
  player.introduceCharacter(&left,&rabbit);
  player.introduceCharacter(&left,&lectuse);
  player.start(true);
  return 0;
}