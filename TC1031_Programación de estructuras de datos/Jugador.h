#include "HechizosHabilidades.h"
#include "Monster.h"
#include "ListaLigada.h"

class Jugador{
  private:
    int hp, lp;
    string raza, nombre;
    ListaLigada<Monster*> mDerrotados;
    ListaLigada<HechizosHabilidades*> hechizosHabilidades; //¿no es extra? 
    bool vivo; //¿no es extra? 
    bool gana=false;
  public:
    Jugador(){};
    Jugador(string, string, ListaLigada<HechizosHabilidades*>);
    int getHp();
    void getInfo();
    int getLp();
    ListaLigada<Monster*> getMDerrotados();
    ListaLigada<HechizosHabilidades*> getHechizosHabilidades();
   // bool getVivo();
    void setHp(int);
    void setLp(int);
    void addMDerrotados(Monster*);
    void setVivo(bool);
    bool getVivo();
    bool getGana();
    void usarHechizo(int,int,Monster*);
};