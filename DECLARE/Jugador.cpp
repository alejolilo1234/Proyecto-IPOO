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
#include<stdlib.h>
#include<time.h>

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

void Jugador::setPrincipalCharacter()
{
  for(int i = 0; i < interfaceOfPlaces.size(); i++)
    for(int whichCharacter = 0; whichCharacter < interfaceOfPlaces[i]->getSizeOfCharacters(); whichCharacter++)
      if(interfaceOfPlaces[i]->getCharacter(whichCharacter)->getIfItCanMoveBoat())
        this -> principalCharacter = interfaceOfPlaces[i]->getCharacter(whichCharacter);
}

void Jugador::setLengthOfNames()
{
  int lengthOfName = 0;
  for(int cual = 0; cual < interfaceOfPlaces.size(); cual++)
    if(lengthOfName < interfaceOfPlaces[cual]->getName().size())
      lengthOfName = interfaceOfPlaces[cual]->getName().size();
  for(int i = 0; i < interfaceOfPlaces.size(); i++)
    for(int whichCharacter = 0; whichCharacter < interfaceOfPlaces[i]->getSizeOfCharacters(); whichCharacter++)
      if(lengthOfName < interfaceOfPlaces[i]->getCharacter(whichCharacter)->getName().size())
        lengthOfName = interfaceOfPlaces[i]->getCharacter(whichCharacter)->getName().size();        

  this -> lengthOfNames = lengthOfName;
}

void Jugador::setNameAndCommand()
{
  for(int i = 0; i < interfaceOfPlaces.size(); i++)
    for(int whichCharacter = 0; whichCharacter < interfaceOfPlaces[i]->getSizeOfCharacters(); whichCharacter++)
      if(interfaceOfPlaces[i]->getCharacter(whichCharacter) != nullptr)
        this -> nameAndCommand.push_back(interfaceOfPlaces[i]->getCharacter(whichCharacter));
}

void Jugador::setUniqueCommands()
{
  srand(time(NULL));
  
  vector <string> stringCommands;
  vector <string> availableCommands = {
    "A","C","D","E","F","G","H","J","K","M","N","O","P","S","T","U","V","W","X","Y"
  };

  for(int i = 0; i < interfaceOfPlaces.size(); i++)
    for(int whichCharacter = 0; whichCharacter < interfaceOfPlaces[i]->getSizeOfCharacters(); whichCharacter++)
    {
      if(this -> isDuplicated(this -> interfaceOfPlaces[i]->getCharacter(whichCharacter)->getCommand(),stringCommands))
      {
        this -> deleteCommand(this -> interfaceOfPlaces[i]->getCharacter(whichCharacter)->getCommand(),availableCommands);
        string newCommand = availableCommands[rand() % availableCommands.size() + 1];
        this -> interfaceOfPlaces[i]->getCharacter(whichCharacter)->setCommand(newCommand);
      }
      stringCommands.push_back(this -> interfaceOfPlaces[i]->getCharacter(whichCharacter)->getCommand());
    }
}

bool Jugador::isDuplicated(string _char, vector <string> _vector)
{
  for(int i = 0; i < _vector.size();i++)
    if(_char == _vector[i])
      return true;
  return false;
}

void Jugador::deleteCommand(string _char,vector <string> &_vector)
{
  for(int i = 0; i < _vector.size();i++)
    if(_char == _vector[i])
      _vector.erase(_vector.begin() + i);
}

void Jugador::setPredators()
{
  for(int i = 0; i < this -> nameAndCommand.size();i++)
  {
    if(nameAndCommand[i]->getPrey() != nullptr)
    {
      this -> predators.push_back(nameAndCommand[i]);
    }
  }
}

// Métodos de la clase Jugador.

void Jugador::showInstructions(bool _state)
{
  system("clear");
  string _response;
  if(_state)
  {
    cout << this -> name << ", ¿quieres ver las instrucciones del juego? [S/N] ";
    getline(cin,_response);
    _response = toupper(_response[0]);
  }
  else 
    _response = "S";
  if(_response == "S")
  {
    system("clear");
    if(_state)
      cout << "¡Bienvenido " << this -> name <<  "!\n\n";
    cout << "Eres un " << this -> principalCharacter -> getName() << " y tu misión es llevar todos los individuos a la otra orilla usando " << this -> interfaceOfPlaces[1] -> getName() << ". No puedes dejar solos al"; 
    // cout << " al zorro con el conejo, ni al conejo con la lechuga,";
    for(int i = 0; i < predators.size(); i++)
    {
      if(i >= 1)
        cout << " o";
      cout << " " << predators[i]->getName() << " con " << predators[i]->getPrey()->getName();
    }
    cout << " porque el primero se devoraría al segundo. En la " << this -> interfaceOfPlaces[1] -> getName() << " solo caben " << this -> interfaceOfPlaces[1] -> getCapacity() << " individuos, y uno de ellos debes ser tú para pilotarla.\n\n";
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
  {
    system("clear");
    this -> commands = false;
  }
}

void Jugador::symbolsForPlaces(int _index, string _symbol, string _separatedBy)
{
  if(interfaceOfPlaces[_index]->getName().length() < this -> lengthOfNames)
  {
    int symbol = this -> lengthOfNames - interfaceOfPlaces[_index] -> getName().length(); 
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
    cout << _preSymbol;
    for(int i = 0; i < this -> lengthOfNames; i++)
      cout << _symbol; 
    cout << _separatedBy;
  } 
  else
  {
    if(interfaceOfPlaces[_index]->getCharacter(_character)->getName().length() < 9)
    {
      if(_preSymbols)
        cout << _preSymbol;
      int symbol = this -> lengthOfNames - interfaceOfPlaces[_index]->getCharacter(_character)->getName().length();
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

void Jugador::symbolsForTop_BottomRows(bool _print)
{
  if(_print)
    cout << "\n+";
  else
    cout << "+";
  for(int i = 0; i < this -> lengthOfNames * 4 + 11; i++) 
    cout << "-"; 
  cout << "+\n";
}

void Jugador::createInterface(bool _state,bool _printCommands)
{
  do{
    if(this -> commands && _printCommands)
    {
      cout << "× (" << interfaceOfPlaces[1]->getCommand() << ") = " << interfaceOfPlaces[1]->getName() << endl;
      for(int i = 0; i < this -> nameAndCommand.size(); i++)
      {
        cout << "× (" << nameAndCommand[i]->getCommand() << ") = " << nameAndCommand[i] -> getName() << endl;
      }
      cout << "× (I) = INSTRUCCIONES" << endl;
      cout << "× (Q) = RENDIRTE" << endl;
      cout << endl;
    }

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
            for(int i = 0; i < this -> lengthOfNames; i++)
              cout << "∿";
            cout << " | ";
          }
          else 
          {
            for(int i = 0; i < this -> lengthOfNames; i++)
              cout << "∿";
            cout << " | ";
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
        string water = " | ";
        for(int w = 0; w < this -> lengthOfNames;w++)
          water += "∿";
        water += " | ";
        this -> symbolsForCharacters(1,whichCharacter,"∿",water,false,"");
      } 
      else 
      {
        string water;
        for(int w = 0; w < this -> lengthOfNames;w++)
          water += "∿";
        water += " | ";
        this -> symbolsForCharacters(1,whichCharacter,"∿"," | ",true,water);
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

int Jugador::whatDoYouWantToMove()
{
  string move;
  cout << "\n¿Que deseas mover " << this -> name << "? "; 
  getline(cin,move);
  move = toupper(move[0]);

  if(move == "B")
  {
    if(interfaceOfPlaces[2] -> haveNeighbor(nullptr))
    {
      interfaceOfPlaces[0] -> setNeighbor(nullptr);
      interfaceOfPlaces[0] -> setNextNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[1] -> setNeighbor(interfaceOfPlaces[2]);
      interfaceOfPlaces[1] -> setNextNeighbor(interfaceOfPlaces[0]);
      interfaceOfPlaces[2] -> setNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[2] -> setNextNeighbor(nullptr);
    }
    else 
    {
      interfaceOfPlaces[0] -> setNeighbor(interfaceOfPlaces[1]);
      interfaceOfPlaces[0] -> setNextNeighbor(nullptr);
      interfaceOfPlaces[1] -> setNeighbor(interfaceOfPlaces[0]);
      interfaceOfPlaces[1] -> setNextNeighbor(interfaceOfPlaces[2]);
      interfaceOfPlaces[2] -> setNeighbor(nullptr);
      interfaceOfPlaces[2] -> setNextNeighbor(interfaceOfPlaces[1]);
    }
  }
  else if(move == "R")
  {

    // Para cuando individuo se encuentra en la orilla izquierda y la barca es vecina
    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr) && interfaceOfPlaces[0] -> getCharacter("R") != nullptr)
    {
      this -> introduceCharacter(interfaceOfPlaces[1], interfaceOfPlaces[0] -> getCharacter("R"));
      this -> takeCharacter(interfaceOfPlaces[0],interfaceOfPlaces[0] -> getCharacter("R"));
      return 0;
    }

    // Para cuando individuo se encuentra en la barca y la vecino de barca es orilla izquierda
    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr) && interfaceOfPlaces[1] -> getCharacter("R") != nullptr)
    {
      this -> introduceCharacter(interfaceOfPlaces[0], interfaceOfPlaces[1] -> getCharacter("R"));
      this -> takeCharacter(interfaceOfPlaces[1],interfaceOfPlaces[1] -> getCharacter("R"));
      return 0;
    }

    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[2]) && interfaceOfPlaces[0] -> haveNeighbor(nullptr) && interfaceOfPlaces[2] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[1] -> getCharacter("R") != nullptr)
    {
      this -> introduceCharacter(interfaceOfPlaces[2], interfaceOfPlaces[1] -> getCharacter("R"));
      this -> takeCharacter(interfaceOfPlaces[1],interfaceOfPlaces[1] -> getCharacter("R"));
      return 0;
    }

    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[2]) && interfaceOfPlaces[0] -> haveNeighbor(nullptr) && interfaceOfPlaces[2] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> getCharacter("R") != nullptr)
    {
      this -> introduceCharacter(interfaceOfPlaces[1], interfaceOfPlaces[2] -> getCharacter("R"));
      this -> takeCharacter(interfaceOfPlaces[2],interfaceOfPlaces[1] -> getCharacter("R"));
      return 0;
    }
    
    // Para cuando individuo barca se encuentra al otro lado y robot en orilla izquierda
    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[2]) && interfaceOfPlaces[0] -> haveNeighbor(nullptr) && interfaceOfPlaces[2] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[0] -> getCharacter("R") != nullptr)
    {
      this -> takeCharacter(interfaceOfPlaces[0],interfaceOfPlaces[0] -> getCharacter("R"));
      system("clear");
      this -> play = false;
      cout << "El ROBOT se ahogo.\n\n";
      this -> createInterface(false,false);
      return 0;
    }
    
    if(interfaceOfPlaces[1] -> haveNeighbor(interfaceOfPlaces[0]) && interfaceOfPlaces[0] -> haveNeighbor(interfaceOfPlaces[1]) && interfaceOfPlaces[2] -> haveNeighbor(nullptr) && interfaceOfPlaces[2] -> getCharacter("R") != nullptr)
    {
      this -> takeCharacter(interfaceOfPlaces[2],interfaceOfPlaces[2] -> getCharacter("R"));
      system("clear");
      this -> play = false;
      cout << "El ROBOT se ahogo.\n\n";
      this -> createInterface(false,false);
      return 0;
    }
  }
  else if(move == "I")
  {
    system("clear");
    this -> showInstructions(false);
    this -> createInterface(true,false);
  }
  else if(move == "Q")
  {
    system("clear");
    cout << "Gracias por jugar :D" << endl;
    this -> play = false;
  }
  return 0;
}

void Jugador::start(bool _state)
{
  this -> play = _state;
  this -> interfaceSize = interfaceOfPlaces.size();
  if(interfaceOfPlaces[0] -> getSizeOfCharacters() > interfaceOfPlaces[2] -> getSizeOfCharacters())
    this -> characterSizeInInterface = interfaceOfPlaces[0] -> getSizeOfCharacters();
  else
    this -> characterSizeInInterface = interfaceOfPlaces[2] -> getSizeOfCharacters();
  this -> setUniqueCommands();
  this -> setNameAndCommand();
  this -> setPredators();
  this -> setName();
  this -> setPrincipalCharacter();
  this -> showInstructions(true);
  this -> showCommands();
  this -> setLengthOfNames();
  this -> createInterface(_state,true);
}
