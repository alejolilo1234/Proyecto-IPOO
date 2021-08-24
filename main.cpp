#include "./HEADERS/Jugador.h"
#include "./HEADERS/Lugar.h"
#include "./HEADERS/EXTENDS FROM LUGAR/Barca.h"
#include "./HEADERS/EXTENDS FROM LUGAR/Orilla.h"

int main() 
{
  Jugador player;
  player.introducePlace(new Orilla("IZQUIERDA",4,1));
  player.introducePlace(new Barca("BARCA",2,2));
  player.introducePlace(new Lugar("",0));
  player.introducePlace(new Orilla("DERECHA",4,4));
  // Introducir Individuo en primera fila
  player.introduceCharacter(1, new Individuo("ROBOT", 3));
  player.introduceCharacter(1, new Individuo("", 0));
  player.introduceCharacter(1, new Individuo("", 0));
  player.introduceCharacter(1, new Individuo("", 20));
  // Introducir Individuo en segunda fila
  player.introduceCharacter(2, new Individuo("ZORRO", 4));
  player.introduceCharacter(2, new Individuo("", 0));
  player.introduceCharacter(2, new Individuo("", 0));
  player.introduceCharacter(2, new Individuo("", 20));
  // Introducir Individuo en tercera fila
  player.introduceCharacter(3, new Individuo("CONEJO", 5));
  player.introduceCharacter(3, new Individuo("", 0));
  player.introduceCharacter(3, new Individuo("", 0));
  player.introduceCharacter(3, new Individuo("", 20));
  // Introducir Individuo en cuarta fila
  player.introduceCharacter(4, new Individuo("LECHUGA", 6));
  player.introduceCharacter(4, new Individuo("", 0));
  player.introduceCharacter(4, new Individuo("", 0));
  player.introduceCharacter(4, new Individuo("", 20));
  // Juego
  player.start(true);
  player.playersName();
  player.showInstructions();
  player.createInterface();
  return 0;
}