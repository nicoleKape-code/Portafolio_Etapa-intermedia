#include "HechizosHabilidades.h"


HechizosHabilidades::HechizosHabilidades(string name, string tipo, string descripcion, int id){
  this->name=name;
  this->tipo=tipo;
  this->descripcion=descripcion;
  this->id=id;
}

string HechizosHabilidades::getName(){
  return name;
}

string HechizosHabilidades::getTipo(){
  return tipo;
}

void HechizosHabilidades::printAll(){
  cout<<id<<": "<<name<<endl<<descripcion<<endl;
}

int HechizosHabilidades::getID(){
  return id;
}