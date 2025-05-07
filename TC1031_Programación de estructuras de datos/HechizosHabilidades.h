#include "Dice.h"


class HechizosHabilidades{
  private:
    string name, tipo, descripcion;
    int id;
  public:
    HechizosHabilidades(string, string, string, int);
    string getName();
    string getTipo();
    string getDescripcion();
    void printAll();
    int getID();
};