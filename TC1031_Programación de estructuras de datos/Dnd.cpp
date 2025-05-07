#include "Dnd.h"

Dnd::Dnd(ListaLigada<Monster*> criaturas, string r, string n, ListaLigada<HechizosHabilidades*> hh){
  this->criaturas=criaturas;
  for(int i=0;i<20;i++){
    int place=rand()%20;
    calabozos.addLast(criaturas.get(place));
  }
  player=Jugador(r,n,hh);
}

int Dnd::rollUbicacion(){ //O(1)
  posicion= rand()%21;
  return posicion;
}

int Dnd::rollDañoM(){ //O(1)
  return rand()%11;
}

int Dnd::rollDañoP(){ //O(1)
  return rand()%16;
}

void Dnd::ataqueMonstruo(){ //O(n)
  int ataque=rollDañoM();
  player.setLp(player.getLp()-ataque);
  cout<<"El "<<calabozos.get(posicion-1)->getName()<<" te ha atacado"<<endl;
  cout<<"-"<<ataque<<" LP"<<endl;
  cout<<"LP actual: "<<player.getLp()<<endl;
}

void Dnd::ataquePlayer(){  //O(n)
  int ataque=rollDañoP();
  cout<<"Haz atacado al "<<calabozos.get(posicion-1)->getName()<<endl;
  cout<<-ataque<<endl;
calabozos.get(posicion-1)->setHp(calabozos.get(posicion-1)->getHp()-ataque);
  cout<<calabozos.get(posicion-1)->getName()<<" HP: "<<calabozos.get(posicion-1)->getHp();
}

void Dnd::play(){ //O(n^2)
  
  while(player.getVivo()==true&&player.getGana()==false){
    posicion=rollUbicacion();
    cout<<"Haz entrado al calabozo "<<posicion<<endl;
    
    if(calabozos.get(posicion-1)->getVivo()==true){
      cout<<"Frente a ti se encuentra el siguiente monstruo:"<<endl;
      calabozos.get(posicion-1)->printInfo(); //O(n)
      cout<<"*** COMBATE ***"<<endl;
      
      while(player.getVivo()==true&&calabozos.get(posicion-1)->getVivo()==true){
        cout<<endl;
        ataqueMonstruo();
        int choice;
        cout<<"Elige tu siguiente acción:"<<endl;
        cout<<"1) Atacar al "<<calabozos.get(posicion-1)->getName()<<endl;
        cout<<"2) Usar un hechizo"<<endl;
        cout<<"3) Usar una habilidad o posión"<<endl;
        cin>>choice;
        
        if(choice==1){
          ataquePlayer();
        }
          
        else if(choice==2){
          
          for(int i=0;i<player.getHechizosHabilidades().size();i++){
            if(player.getHechizosHabilidades().get(i)->getTipo()=="hechizo"){ //O(n^2)
              player.getHechizosHabilidades().get(i)->printAll();
            }
          }
          cout<<"¿Qué hechizo deseas usar?"<<endl;
          int hechizo;
          cin>>hechizo;
          int daño=rollDañoP();
          int index=0;
          bool found=false;
          while(found==false){
            if(player.getHechizosHabilidades().get(index)->getID()==hechizo){
              found=true;
            }
            index++;
          }
          player.usarHechizo(index, daño, calabozos.get(posicion-1));
          //player.getHechizosHabilidades().remove(index);
        }
          
        else if(choice==3){
          cout<<player.getHechizosHabilidades().size()<<endl;
          for(int i=0;i<player.getHechizosHabilidades().size();i++){
            
            if(player.getHechizosHabilidades().get(i)->getTipo()=="habilidad"||player.getHechizosHabilidades().get(i)->getTipo()=="poción"){
              player.getHechizosHabilidades().get(i)->printAll();
            }
          }
          cout<<"¿Qué habilidad o poción deseas usar?"<<endl;
          int habilidadPocion;
          cin>>habilidadPocion;
          int daño=rollDañoP();
          int index=0;
          bool found=false;
          while(found==false){
            if(player.getHechizosHabilidades().get(index)->getID()==habilidadPocion){
              found=true;
            }
            index++;
          }
          player.usarHechizo(index, daño, calabozos.get(posicion-1));
          //player.getHechizosHabilidades().remove(index-1);
        }
          
        else{
          throw -1;
        }
      }
      
      if(calabozos.get(posicion-1)->getVivo()==false){
        player.addMDerrotados(calabozos.get(posicion-1));
        cout<<"+"<<calabozos.get(posicion-1)->getCr()*player.getLp()<<" LP"<<endl;
        player.setLp(player.getLp()+calabozos.get(posicion-1)->getCr()*player.getHp());
        cout<<"LP actual: "<<player.getLp()<<endl<<endl;
        cout<<"Avanzas al siguiente calabozo"<<endl;
      }
        
      else{
        cout<<endl<<"Haz muerto"<<endl;
      }
    }
      
    else{
      cout<<"Ya haz matado a este monstruo"<<endl;
    }
  }
  if(player.getGana()==true){
    cout<<"*** HAZ GANADO ***"<<endl;
  }
  cout<<"*** MONSTRUOS VENCIDOS ***"<<endl;
  for(int i=0; i<player.getMDerrotados().size();i++){ //O(n^2)
    cout<<"enter"<<endl;
    player.getMDerrotados().get(i)->printInfo();
  }
  cout<<"Total derrotados: "<<player.getMDerrotados().size()<<endl;
  cout<<endl;
  cout<<"*** ESTADO DEL CALABOZO ***"<<endl;
  for(int i=0; i<calabozos.size(); i++){
    cout<<"Calabozo "<<i+1<<":"<<endl;
    calabozos.get(i)->printInfo();
  }
}