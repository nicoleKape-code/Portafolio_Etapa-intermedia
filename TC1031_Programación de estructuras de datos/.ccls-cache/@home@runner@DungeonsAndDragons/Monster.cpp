#include "Monster.h"

// Constructor: inicializa un nuevo monstruo con los atributos proporcionados
// Complejidad de tiempo: O(1)
Monster::Monster(string name, float cr, string type, string size, int ac, int hp, string align){
    this->name=name;
    this->cr=cr;
    this->type=type;
    this->size=size;
    this->ac=ac;
    this->hp=hp;
    this->align=align;
    vivo=true;  // Este método inicializa un nuevo monstruo con los atributos proporcionados.
}

// Método getAc: retorna el valor de Armor Class (AC) del monstruo
// Complejidad de tiempo: O(1)
int Monster::getAc(){
    return ac;
}

// Método getCr: retorna el valor de Challenge Rating (CR) del monstruo
// Complejidad de tiempo: O(1)
float Monster::getCr(){
    return cr;
}

// Método getHp: retorna los puntos de vida (HP) del monstruo
// Complejidad de tiempo: O(1)
int Monster::getHp(){
    return hp;
}

// Método getName: retorna el nombre del monstruo
// Complejidad de tiempo: O(1)
string Monster::getName(){
    return name;
}

// Método getSize: retorna el tamaño del monstruo
// Complejidad de tiempo: O(1)
string Monster::getSize(){
    return size;
}

// Método getType: retorna el tipo del monstruo
// Complejidad de tiempo: O(1)
string Monster::getType(){
    return type;
}

// Método getVivo: verifica si el monstruo está vivo
// Complejidad de tiempo: O(1)
bool Monster::getVivo(){
    return vivo;
}

// Método getAlign: retorna la alineación del monstruo
// Complejidad de tiempo: O(1)
string Monster::getAlign(){
    return align;
}

// Método setVivo: establece el estado de vida del monstruo
// Complejidad de tiempo: O(1)
void Monster::setVivo(bool vivo){
    this->vivo=vivo;
}

// Método printInfo: imprime la información del monstruo
// Complejidad de tiempo: O(1)
void Monster::printInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Cr: "<<cr<<endl;
    cout<<"Type: "<<type<<endl;
    cout<<"Size: "<<size<<endl;
    cout<<"Ac: "<<ac<<endl;
    cout<<"Hp: "<<hp<<endl;
    cout<<"Alignment: "<<align<<endl;
}

// Método gotKilled: imprime un mensaje cuando el monstruo es asesinado
// Complejidad de tiempo: O(1)
void Monster::gotKilled(){
    cout<<"*** FELICIDADES ***";
    cout<<"Haz matado a "<<name<<endl;
}

// Método setHp: establece los puntos de vida (HP) del monstruo y verifica si ha sido asesinado
// Complejidad de tiempo: O(1)
void Monster::setHp(int hp){
    this->hp=hp;
    if(this->hp<0){
        setHp(0);
        setVivo(false);
        gotKilled();
    }
}

// Método sobrecargado del operador <<: imprime la información del monstruo
// Complejidad de tiempo: O(1)
ostream & operator<<(ostream & salida, Monster &m){
    salida << m.name <<" : "<<m.hp<<endl;
    return salida; 
}
