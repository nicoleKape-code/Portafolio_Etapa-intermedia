#include "HechizosHabilidades.h"


HechizosHabilidades::HechizosHabilidades(string name, string tipo, string descripcion, int id){
  this->name=name;
  this->tipo=tipo;
  this->descripcion=descripcion;
  this->id=id;
}

string HechizosHabilidades::getName(){ //O(1)
  return name;
}

string HechizosHabilidades::getTipo(){ //O(1)
  return tipo;
}

void HechizosHabilidades::printAll(){ //O(1)
  cout<<id<<": "<<name<<endl<<descripcion<<endl;
}

int HechizosHabilidades::getID(){ //O(1)
  return id;
}