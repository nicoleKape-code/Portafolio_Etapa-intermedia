#include "Criaturas.h"

Criaturas::Criaturas(string name, float cr, string type, string size, int ac, int hp, string align){
  this->name=name;
  this->cr=cr;
  this->type=type;
  this->size=size;
  this->ac=ac;
  this->hp=hp;
  this->align=align;
  vivo=true;
}

int Criaturas::getAc(){
  return ac;
}

float Criaturas::getCr(){
  return cr;
}

int Criaturas::getHp(){
  return hp;
}

string Criaturas::getName(){
  return name;
}

string Criaturas::getSize(){
  return size;
}

string Criaturas::getType(){
  return type;
}

bool Criaturas::getVivo(){
  return vivo;
}

string Criaturas::getAlign(){
  return align;
}

void Criaturas::setVivo(bool vivo){
  this->vivo=vivo;
}

void Criaturas::printInfo(){
  cout<<"Nombre: "<<name<<endl;
  cout<<"CR: "<<cr<<endl;
  cout<<"Tipo: "<<type<<endl;
  cout<<"Tamaño: "<<size<<endl;
  cout<<"AC: "<<ac<<endl;
  cout<<"HP: "<<hp<<endl;
  cout<<"Alineación: "<<align<<endl;
}