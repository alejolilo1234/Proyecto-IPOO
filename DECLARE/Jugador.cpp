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

#include "../HEADERS/Jugador.h"
#include <stdio.h>

// Constructor y destructor de la clase Jugador.

Jugador::Jugador() : play(false), principalCharacter(nullptr)
{
  // 
}

Jugador::~Jugador()
{
  // 
}

// Getters de la clase Jugador.

// Setters de la clase Jugador.

void Jugador::setName()
{
  string _name;
  cout << "Nombre: ";
  getline(cin,_name);
  if(_name == "")
    this -> name = "Jugador";
  else
    this -> name = _name;
}

// Métodos de la clase Jugador.

void Jugador::showInstructions()
{
  system("clear");
  string _response;
  cout << this -> name << ", ¿quieres ver las instrucciones del juego? [S/N] ";
  getline(cin,_response);
  _response = toupper(_response[0]);
  if(_response == "S")
  {
    system("clear");
    cout << "¡Bienvenido " << this -> name <<  "!\n\nEres un " << this -> principalCharacter -> getName() << " y tu misión es llevar todos los individuos a la otra orilla usando la " << this -> interfaceOfPlaces[1] -> getName() << ". No puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la " << this -> interfaceOfPlaces[1] -> getName() << " solo caben " << this -> interfaceOfPlaces[1] -> getCapacity() << " individuos, y uno de ellos debes ser tú, para pilotarla.\n\n";
  }
  else
    system("clear");
}

void Jugador::showCommands()
{
  string _response;
  cout << this -> name << ", ¿quieres ver comandos en el juego? [S/N] ";
  getline(cin,_response);
  _response = toupper(_response[0]);
  if(_response == "S")
  {
    system("clear");
    this -> commands = true;
  }
  else
    system("clear");
    this -> commands = false;
}

void Jugador::commandsText()
{
  // cout << endl;
  cout << "× (" << interfaceOfPlaces[1] -> getCommand() << ") = " << interfaceOfPlaces[1] -> getName() << endl;
  for(int cual = 0; cual < this -> characterSizeInInterface; cual++)
  {
    if(interfaceOfPlaces[0] -> getSizeOfCharacters() == 0)
    {
      cout << "× (" << interfaceOfPlaces[2] -> getCharacter(cual) -> getCommand() << ") = " << interfaceOfPlaces[2] -> getCharacter(cual) -> getName() << endl;
    }
    else
    {
      cout << "× (" << interfaceOfPlaces[0] -> getCharacter(cual) -> getCommand() << ") = " << interfaceOfPlaces[0] -> getCharacter(cual) -> getName() << endl;
    }
  }
  cout << "× (I) = INSTRUCCIONES" << endl;
  cout << "× (Q) = RENDIRTE" << endl;
}

void Jugador::symbolsForPlaces(int _index, string _symbol, string _separatedBy)
{
  if(interfaceOfPlaces[_index]->getName().length() < 9)
  {
    int symbol = 9 - interfaceOfPlaces[_index] -> getName().length(); 
    cout << interfaceOfPlaces[_index] -> getName();
    for(int i = 0;i < symbol; i++)
      cout << _symbol; 
    cout << _separatedBy;
  } 
  else 
    cout << interfaceOfPlaces[_index] -> getName() << _separatedBy;
}

void Jugador::symbolsForCharacters(int _index, int _character, string _symbol, string _separatedBy, bool _preSymbols, string _preSymbol)
{
  if(interfaceOfPlaces[_index]->getCharacter(_character) == nullptr)
  {
    if(_preSymbols)
      cout << _preSymbol;
    cout << "...";
    for(int i = 0;i < 6; i++)
      cout << _symbol; 
    cout << _separatedBy;
  } 
  else
  {
    if(interfaceOfPlaces[_index]->getCharacter(_character)->getName().length() < 9)
    {
      if(_preSymbols)
        cout << _preSymbol;
      int symbol = 9 - interfaceOfPlaces[_index]->getCharacter(_character)->getName().length();
      cout << interfaceOfPlaces[_index] -> getCharacter(_character)->getName();
      for(int i = 0;i < symbol; i++)
        cout << _symbol; 
      cout << _separatedBy;
    }
    else
    {
      if(_preSymbols)
        cout << _preSymbol;
      cout << interfaceOfPlaces[_index] -> getCharacter(_character)->getName() << _separatedBy;
    }
  }
}

void Jugador::symbolsForTop_BottomRows(bool _state)
{
  if(_state)
    cout << "\n+";
  else
    cout << "+";
  for(int i = 0; i < 47; i++) 
    cout << "-"; 
  cout << "+\n";
}

void Jugador::createInterface(bool _state)
{
  do{
    if(this -> commands)
      this -> commandsText();

    this -> symbolsForTop_BottomRows(false);

    // Para Lugares

    cout << "| ";
    for(int which = 0; which < this -> interfaceSize; which++)
    {
      switch(which)
      {
        case 0:
          this -> symbolsForPlaces(which,"⇝"," | ");
          break;
        case 1:
          if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr))
          {
            this -> symbolsForPlaces(which,"∿"," | ");
            cout << "∿∿∿∿∿∿∿∿∿ | ";
          }
          else 
          {
            cout << "∿∿∿∿∿∿∿∿∿ | ";
            this -> symbolsForPlaces(which,"∿"," | ");
          }
          break;
        case 2:
          this -> symbolsForPlaces(which,"⇝"," | ");
          break;
      }
    }

    // Para personajes

    for(int whichCharacter = 0; whichCharacter < this -> characterSizeInInterface; whichCharacter++)
    {
      cout << "\n| ";

      // Para primera fila

      this -> symbolsForCharacters(0,whichCharacter,"⇝"," | ",false,"");

      if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr))
      {
        this -> symbolsForCharacters(1,whichCharacter,"∿"," | ∿∿∿∿∿∿∿∿∿ | ",false,"");
      } 
      else 
      {
        this -> symbolsForCharacters(1,whichCharacter,"∿"," | ",true,"∿∿∿∿∿∿∿∿∿ | ");
      }

      // Para cuarta fila

      this -> symbolsForCharacters(2,whichCharacter,"⇝"," | ",false,"");
    }

    this -> symbolsForTop_BottomRows(true);

    if(_state == true)
      this -> whatDoYouWantToMove();
  } while(this -> play == true);
}

void Jugador::introducePlaces(Lugar *_place)
{
  this -> interfaceOfPlaces.push_back(_place);
}

void Jugador::introduceCharacter(Lugar *_insertInto, Individuo * _character)
{
  _insertInto -> introduceCharacter(_character);
}

void Jugador::takeCharacter(Lugar *_takeFrom, Individuo * _character)
{
  _takeFrom -> takeCharacter(_character);
}

void Jugador::whatDoYouWantToMove()
{
  string move;
  cout << "\n¿Que deseas mover " << this -> name << "? "; 
  getline(cin,move);
  move = toupper(move[0]);

  if(move == "B")
  {
    if(interfaceOfPlaces[2] -> haveNeighbor(nullptr))
    {
      interfaceOfPlaces[1] -> setNeighbor(interfaceOfPlaces[2]);
      interfaceOfPlaces[1] -> setNextNeighbor(interfaceOfPlaces[0]);
      interfaceOfPlaces[0] -> setNeighbor(nullptr);
      interfaceOfPlaces[0] -> setNextNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[2] -> setNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[2] -> setNextNeighbor(nullptr);
    }
    else 
    {
      interfaceOfPlaces[1] -> setNeighbor(interfaceOfPlaces[0]);
      interfaceOfPlaces[1] -> setNextNeighbor(interfaceOfPlaces[2]);
      interfaceOfPlaces[0] -> setNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[0] -> setNextNeighbor(nullptr);
      interfaceOfPlaces[2] -> setNeighbor(nullptr);
      interfaceOfPlaces[2] -> setNextNeighbor(interfaceOfPlaces[1]);
    }
  }
  else if(move == "R")
  {
    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr))
    {
      if(interfaceOfPlaces[0] -> getCharacter("ROBOT") != nullptr)
      {
        this -> introduceCharacter(interfaceOfPlaces[1], interfaceOfPlaces[0] -> getCharacter("ROBOT"));
        this -> interfaceOfPlaces[0] -> takeCharacter(interfaceOfPlaces[0] -> getCharacter("ROBOT"));
      }
    }
    else if(1 == 1)
    {

    }
    else if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[2]) && interfaceOfPlaces[0] -> haveNeighbor(nullptr) && interfaceOfPlaces[2] -> haveNeighbor(interfaceOfPlaces[1]))
    {
      this -> interfaceOfPlaces[0] -> takeCharacter(interfaceOfPlaces[0] -> getCharacter("ROBOT"));
      this -> play = false;
      cout << "El ROBOT se ahogo.";
    }
  }
  else if(move == "Q")
  {
    system("clear");
    cout << "Gracias por jugar :D" << endl;
    this -> play = false;
  }
}

void Jugador::start(bool _state)
{
  this -> play = _state;
  this -> interfaceSize = interfaceOfPlaces.size();
  if(interfaceOfPlaces[0] -> getSizeOfCharacters() > interfaceOfPlaces[2] -> getSizeOfCharacters())
    this -> characterSizeInInterface = interfaceOfPlaces[0] -> getSizeOfCharacters();
  else
    this -> characterSizeInInterface = interfaceOfPlaces[2] -> getSizeOfCharacters();
  this -> setName();
  this -> setPrincipalCharacter();
  this -> showInstructions();
  this -> showCommands();
  this -> createInterface(true);
}

void Jugador::setPrincipalCharacter()
{
  for(int i = 0; i < interfaceOfPlaces.size(); i++)
    for(int whichCharacter = 0; whichCharacter < interfaceOfPlaces[i]->getSizeOfCharacters(); whichCharacter++)
      if(interfaceOfPlaces[i]->getCharacter(whichCharacter)->getIfItCanMoveBoat())
        this -> principalCharacter = interfaceOfPlaces[i]->getCharacter(whichCharacter);
}