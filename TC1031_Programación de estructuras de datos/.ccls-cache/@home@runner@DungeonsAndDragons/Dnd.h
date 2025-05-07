#include "Jugador.h"
class Dnd{
  private:
    ListaLigada<Monster*> calabozos;
    ListaLigada<Monster*> criaturas;
    Jugador player;
    int posicion;
  public:
    Dnd(ListaLigada<Monster*>, string, string, ListaLigada<HechizosHabilidades*>);
    int rollUbicacion();
    int rollDañoM();
    int rollDañoP();
    void ataquePlayer();
    void ataqueMonstruo();
    void usarHechizo();
    void usarPocion();
    void vence();
    void play();
};