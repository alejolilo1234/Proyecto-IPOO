#include "../HEADERS/Jugador.h"
#include "../HEADERS/Individuo.h"
#include "../HEADERS/EXTENDS FROM LUGAR/Orilla.h"
#include "../HEADERS/EXTENDS FROM LUGAR/Barca.h"

// Constructor y destructor de la clase Jugador.

Jugador::Jugador()
{
  // 
}

Jugador::~Jugador()
{
  for(int wich = 0; wich < this -> places.size(); wich++)
  {
    // Liberar Lugar(s)
    delete this -> places[wich];
    this -> places[wich] = nullptr;
    // Liberar Individuo(s)
    delete this -> charactersRowOne[wich];
    this -> charactersRowOne[wich] = nullptr;
    delete this -> charactersRowTwo[wich];
    this -> charactersRowTwo[wich] = nullptr;
    delete this -> charactersRowThree[wich];
    this -> charactersRowThree[wich] = nullptr;
    delete this -> charactersRowFour[wich];
    this -> charactersRowFour[wich] = nullptr;
  }
}

// Getters de la clase Jugador.
  
// Setters de la clase Jugador.
  
// Métodos de la clase Jugador.

void Jugador::start(bool _state)
{
  this -> play = _state;
  places[0] -> introduceCharacter(charactersRowOne[0]);
  places[0] -> introduceCharacter(charactersRowTwo[0]);
  places[0] -> introduceCharacter(charactersRowThree[0]);
  places[0] -> introduceCharacter(charactersRowFour[0]);
}

void Jugador::playersName()
{
  cout << "Nombre: ";
  getline(cin,this -> name);
  if(this -> name == ""){
    this -> name = "Jugador 1";
  } 
}

void Jugador::showInstructions()
{
  cout << "\n¡Bienvenido " << this -> name <<  "!\n\nEres un Robot y tu misión es llevar todos los individuos a la otra orilla, usando la barca. Pero no puedes dejar solos al zorro con el conejo, ni al conejo con la lechuga, porque el primero se devoraría al segundo. En la barca solo caben dos individuos, y uno de ellos debes ser tú, para pilotarla. Las órdenes que puedes dar son:\n\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte\n\n";
}

void Jugador::printPlaceRow(vector <Lugar *> &_places)
{
  cout << "| ";
  for(int i = 0; i < _places.size(); i++)
  {
    if(_places[i]->getName().length() < 9)
    {
      int espacios = 9 - _places[i]->getName().length(); cout << _places[i] -> getName();
      for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
    } 
    else cout << _places[i] -> getName() << " | ";
  }
  cout << endl;
}

void Jugador::printCharacterRow(vector <Individuo *> &_character)
{
  cout << "| ";
  if(_character[0]->getName().length() < 9)
  {
    int espacios = 9 - _character[0]->getName().length(); cout << _character[0] -> getName();
    for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
  } 
  else cout << _character[0] -> getName() << " | ";
  
  for(int i = 1; i < 3; i++)
  {
    if(_character[i]->getName().length() < 9)
    {
      int espacios = 9 - _character[i]->getName().length(); cout << _character[i] -> getName();
      for(int i = 0;i < espacios; i++) cout << "~"; cout << " | ";
    } 
    else cout << _character[i] -> getName() << " | ";
  }

  if(_character[3]->getName().length() < 9)
  {
    int espacios = 9 - _character[3]->getName().length(); cout << _character[3] -> getName();
    for(int i = 0;i < espacios; i++) cout << "."; cout << " | ";
  } 
  else cout << _character[3] -> getName() << " | ";
  

  // for(int i = 0; i < _character.size(); i++)
  // {
  //   if(_character[i]->getName().length() < 9)
  //   {
  //     int espacios = 9 - _character[i]->getName().length(); cout << _character[i] -> getName();
  //     for(int i = 0;i < espacios; i++) cout << "~"; cout << " | ";
  //   } 
  //   else cout << _character[i] -> getName() << " | ";
  // }
  cout << endl;
}

void Jugador::createInterface()
{
  do{
    for(int i = 0; i < 49; i++) cout << "-"; cout << endl;

    this -> printPlaceRow(places);
    this -> printCharacterRow(charactersRowOne);
    this -> printCharacterRow(charactersRowTwo);
    this -> printCharacterRow(charactersRowThree);
    this -> printCharacterRow(charactersRowFour);

    for(int i = 0; i < 49; i++) cout << "-"; cout << endl;

    this -> whatDoYouWantToMove();
  } while(this -> play == true);
}

void Jugador::whatDoYouWantToMove()
{
  string mover;
  cout << "\n¿Que desea mover? "; getline(cin,mover);
  mover = toupper(mover[0]);

  if(mover[0] == 'B')
  {
    if((charactersRowOne[1]->getId() == 3) || (places[2]->getId() == 2 && charactersRowOne[2]->getId() == 3))
    {
      Lugar *aux = places[1];
      places[1] = places[2];
      places[2] = aux;
      Individuo *aux2 = charactersRowOne[1];
      charactersRowOne[1] = charactersRowOne[2];
      charactersRowOne[2] = aux2;
      Individuo *aux3 = charactersRowTwo[1];
      charactersRowTwo[1] = charactersRowTwo[2];
      charactersRowTwo[2] = aux3;
      Individuo *aux4 = charactersRowThree[1];
      charactersRowThree[1] = charactersRowThree[2];
      charactersRowThree[2] = aux4;
      Individuo *aux5 = charactersRowFour[1];
      charactersRowFour[1] = charactersRowFour[2];
      charactersRowFour[2] = aux5;
    } 
    
    this -> clear();
  }




  else if(mover[0] == 'R')
  {
    if(places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowOne[1]->getId() == 0)
    {
      Individuo *aux = charactersRowOne[0];
      charactersRowOne[0] = charactersRowOne[1];
      charactersRowOne[1] = aux;
      places[1] -> introduceCharacter(charactersRowOne[1]);
    } 
    else if ((places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowOne[0]->getId() == 0 && charactersRowOne[1]->getId() == 3) || (places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowOne[0]->getId() == 0 && places[1]->getId() == 2))
    {
      Individuo *aux = charactersRowOne[1];
        charactersRowOne[1] = charactersRowOne[0];
        charactersRowOne[0] = aux;
        places[1] -> takeOutCharacter();
    }
    else if(places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowOne[0]->getId() == 0 && charactersRowOne[1]->getId() == 0 && charactersRowOne[2]->getId() == 6 && places[2]->getId() == 2)
    {
      // cout << "Hola mundo\n";
    }
    
    this -> clear();
  }







  else if(mover[0] == 'Z')
  {
    if(places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowTwo[1]->getId() == 0)
    {
      Individuo *aux = charactersRowTwo[0];
      charactersRowTwo[0] = charactersRowTwo[1];
      charactersRowTwo[1] = aux;
      places[1] -> introduceCharacter(charactersRowTwo[1]);
    }
    else if ((places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowTwo[0]->getId() == 0 && charactersRowTwo[1]->getId() == 4) || (places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowTwo[0]->getId() == 0 && places[1]->getId() == 2))
    {
      Individuo *aux = charactersRowTwo[1];
        charactersRowTwo[1] = charactersRowTwo[0];
        charactersRowTwo[0] = aux;
        places[1] -> takeOutCharacter();
    }
    else if(places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowTwo[0]->getId() == 0 && charactersRowTwo[1]->getId() == 0 && charactersRowTwo[2]->getId() == 6 && places[2]->getId() == 2)
    {
      // cout << "Hola mundo\n";
    }

    this -> clear();
  }




  
  else if(mover[0] == 'C')
  {
    if(places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowThree[1]->getId() == 0)
    {
      Individuo *aux = charactersRowThree[0];
      charactersRowThree[0] = charactersRowThree[1];
      charactersRowThree[1] = aux;
      places[1] -> introduceCharacter(charactersRowThree[1]);
    } 
    else if ((places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowThree[0]->getId() == 0 && charactersRowThree[1]->getId() == 5) || (places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowThree[0]->getId() == 0  && places[1]->getId() == 2))
    {
      Individuo *aux = charactersRowThree[1];
        charactersRowThree[1] = charactersRowThree[0];
        charactersRowThree[0] = aux;
        places[1] -> takeOutCharacter();
    }
    else if(places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowThree[0]->getId() == 0 && charactersRowThree[1]->getId() == 0 && charactersRowThree[2]->getId() == 6 && places[2]->getId() == 2)
    {
      // cout << "Hola mundo\n";
    }

    this -> clear();
  }
  



  
  else if(mover[0] == 'L')
  {
    if(places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowFour[1]->getId() == 0)
    {
      Individuo *aux = charactersRowFour[0];
      charactersRowFour[0] = charactersRowFour[1];
      charactersRowFour[1] = aux;
      places[1] -> introduceCharacter(charactersRowFour[1]);
    }
    else if ((places[1]->getCharactersSize() < places[1]->getCapacity() && charactersRowFour[0]->getId() == 0 && charactersRowFour[1]->getId() == 6) || (places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowFour[0]->getId() == 0 && places[1]->getId() == 2))
    {
      Individuo *aux = charactersRowFour[1];
        charactersRowFour[1] = charactersRowFour[0];
        charactersRowFour[0] = aux;
        places[1] -> takeOutCharacter();
    }
    else if(places[1]->getCharactersSize() == places[1]->getCapacity() && charactersRowFour[0]->getId() == 0 && charactersRowFour[1]->getId() == 0 && charactersRowFour[2]->getId() == 6 && places[2]->getId() == 2)
    {
      // cout << "Hola mundo\n";
    }
    
    this -> clear();
  }
  



  
  else if(mover[0] == 'Q')
  {
    this -> play = false;
  }





  else 
  {
    this -> clear();
  }
} 


void Jugador::introducePlace(Lugar *_place)
{
  this -> places.push_back(_place);
}

void Jugador::introduceCharacter(int _row,Individuo *_character)
{
  switch(_row){
    case 1:
      this -> charactersRowOne.push_back(_character);
      break;
    case 2:
      this -> charactersRowTwo.push_back(_character);
      break;
    case 3:
      this -> charactersRowThree.push_back(_character);
      break;
    case 4:
      this -> charactersRowFour.push_back(_character);
      break;
  }
}

void Jugador::clear()
{
  system("clear");
  cout << "\n\t- B para mover Barca\n\t- R para mover Robot\n\t- Z para mover Zorro\n\t- C para mover Conejo\n\t- L para mover Lechuga\n\t- Q para rendirte" << endl <<endl;
  createInterface();
}
