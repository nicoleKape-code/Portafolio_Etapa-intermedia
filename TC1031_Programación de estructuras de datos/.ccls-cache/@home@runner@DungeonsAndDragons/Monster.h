#include "iostream"
using namespace std;

class Monster{
  private:
    string name, type, size, align;
    double cr;
    int ac, hp;
    bool vivo;
  public:
    Monster(string, float, string, string, int, int, string);
    string getName();
    string getType();
    string getSize();
    string getAlign();
    float getCr();
    int getAc();
    int getHp();
    bool getVivo();
    void setVivo(bool);
    void printInfo();
    void setHp(int);
    void gotKilled();

friend ostream & operator<<(ostream & salida, Monster &m);
};