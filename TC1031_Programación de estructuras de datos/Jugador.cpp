#include "Jugador.h"
#include<cstring>
#include "string.h"
//O(1)
Jugador::Jugador(string raza, string nombre, ListaLigada<HechizosHabilidades*> hechizosHabilidades){
  this -> raza = raza;
  this -> nombre = nombre; 
  hp = 50; 
  lp = 100; 
  vivo=true;
  this->hechizosHabilidades=hechizosHabilidades;
}
//O(1)
int Jugador::getHp(){
  return hp;
}
//O(1)
int Jugador::getLp(){
  return lp;
}
//O(1)
void Jugador::getInfo(){
  
}
//O(1)
ListaLigada<Monster*> Jugador::getMDerrotados(){
  return mDerrotados;
}
//O(1)
ListaLigada<HechizosHabilidades*> Jugador::getHechizosHabilidades(){
  return hechizosHabilidades;
}
//O(1)
void Jugador::setVivo(bool vivo){
  this->vivo=vivo;
}
//O(1)
void Jugador::setHp(int hp){
  this->hp=hp;
  if(this->hp<=0){
    setHp(0);
    setVivo(false);
  }
}
//O(1)
void Jugador::setLp(int lp){
  this->lp=lp;
  if(this->lp<0){
    setLp(0);
    setVivo(false);
  }
}
// Time Complexity: O(n) in the worst case, where n is the number of defeated monsters.
void Jugador::addMDerrotados(Monster *m){ //checar 
  //modificar para que quede alfabético
  if(mDerrotados.isempty()){
    mDerrotados.addLast(m);
  } else {
    
      Monster* aux = mDerrotados.getFirst();
      int i = 1;
      while (i < mDerrotados.size() && strcmp(aux->getName().c_str(), m->getName().c_str())!= 0) {
        aux = mDerrotados.get(i); //O(n)
        i++;
      }
      mDerrotados.insert(m, i); //O(n)
    }

  if(mDerrotados.size() >= 20){
    gana = true; 
  }
}
//O(1)
bool Jugador::getVivo(){
  return vivo;
}
//O(1)
bool Jugador::getGana(){
  return gana;
}
//O(1)
void Jugador::usarHechizo(int index, int faceDice, Monster* m){
  int hlpActual;
  int LpAdicionalJugador;
  int ataque;
  HechizosHabilidades* actual=hechizosHabilidades.get(index-1);
  if(actual->getName()=="Desintegrar"){
    cout<<"Haz atacado al "<<m->getName()<<endl;
    ataque=5*faceDice + 20;
    cout<<-ataque<<endl;
    hlpActual =  m->getHp() - (5*faceDice + 20);
    m->setHp(hlpActual); 
    cout<<m->getName()<<" HP: "<<m->getHp();
  }
  else if(actual->getName()=="Detectar magia"){
    cout<<"El jugador ahora puede detectar magia.";
  }
  else if(actual->getName()=="Rociada venenosa"){
    hlpActual =  m->getHp() - (1*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Descarga sobrenatural"){
    hlpActual =  m->getHp() - (1*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Toque vampírico"){
    hlpActual =  m->getHp() - (3*faceDice);
    m->setHp(hlpActual);

    LpAdicionalJugador = getLp() + (3*faceDice)/2;
    setLp(LpAdicionalJugador);
    
  }
  else if(actual->getName()=="Infligir heridas"){
    hlpActual =  m->getHp() - (3*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Barrera de cuchillas"){
    hlpActual =  m->getHp() - (6*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Circulo de muerte"){
    hlpActual =  m->getHp() - (8*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Maestro duelista"){
    hlpActual =  m->getHp() - (3*faceDice);
    m->setHp(hlpActual);
  }
  else if(actual->getName()=="Curar Heridas"){
    LpAdicionalJugador = getLp() + (1*faceDice);
    setLp(LpAdicionalJugador);
  }
  else if(actual->getName()=="Bendicion"){
      LpAdicionalJugador = getLp() + (2 * faceDice);
      setLp(LpAdicionalJugador);
  }
  else if(actual->getName()=="Detectar el bien y el mal"){
    cout<<"El jugador ahora puede detectar el bien y el mal.";
  }
  else if(actual->getName()=="Entender idiomas"){
    cout << "El jugador ahora puede entender partes del idioma.";
  }
  else if(actual->getName()=="Hablar con los animales"){
    cout << "El jugador ahora puede hablar con animales.";
  }
  else if(actual->getName()=="Dormir"){
    hlpActual = getHp() - (5*faceDice);
    m->setHp(hlpActual);
  }
}
