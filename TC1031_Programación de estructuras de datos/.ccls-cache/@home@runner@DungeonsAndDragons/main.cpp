#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "Dnd.h"
#include "string.h"

// Este método carga la lista de monstruos desde un archivo CSV
// Complejidad de tiempo: O(n), donde n es el número de líneas en el archivo.
void loadMonsters(ListaLigada<Monster*> & monsters){
  string line, token; 
  fstream archivo("monsters_.csv", ios::in);
  if(archivo.is_open()){
    getline(archivo, line);  // Ignora la primera línea (header)
    while(getline(archivo, line)){
      stringstream strdata(line);
      string name; 
      getline(strdata, name, ',');
      string cr; 
      getline(strdata, cr, ',');
      string type;
      getline(strdata, type, ',');
      string size;
      getline(strdata, size, ',');
      string ac;
      getline(strdata, ac, ',');
      string hp;
      getline(strdata, hp, ',');
      string align;
      getline(strdata, align, ',');
      Monster* m= new Monster( name, stod(cr),  type,  size,  stoi(ac),  stoi(hp),  align);
      monsters.addLast(m);
    }
  } else{
    cout << "File not found" << endl;
  }
}

// Este método carga la lista de hechizos y habilidades desde un archivo CSV
// Complejidad de tiempo: O(n), donde n es el número de líneas en el archivo.
void loadHechizosHabilidades(ListaLigada<HechizosHabilidades*> & hechizosHabilidades){
  string line, token;
  fstream archivo("hechizos.csv", ios::in);
  if(archivo.is_open()){
    getline(archivo, line); // Skip header line
    while(getline(archivo, line)){
      stringstream strdata(line);
      string id;
      getline(strdata, id, ',');
      string name;
      getline(strdata, name, ',');
      string tipo;
      getline(strdata, tipo, ',');
      string descripcion; 
      getline(strdata, descripcion, ',');
      HechizosHabilidades* h = new HechizosHabilidades(name, tipo, descripcion,stoi(id));
      hechizosHabilidades.addLast(h);
    }
  } else {
    cout << "File not found" << endl;
  }
}

// Función principal
// Complejidad de tiempo: O(1) + tiempo que tome la ejecución de las funciones loadMonsters y loadHechizosHabilidades
int main() {
  ListaLigada<Monster*> monsters_; 
  ListaLigada<HechizosHabilidades*>hechizos_;
  
  loadMonsters(monsters_);  // Carga los monstruos
  loadHechizosHabilidades(hechizos_);  // Carga los hechizos y habilidades
  
  srand(time(0));  // Inicializa la semilla del generador de números aleatorios
  // Complejidad de tiempo: O(1)
  
  string raza;
  char choice; 
  string nombre; 
  cout<<"Define a tu jugador!"<<endl; 
  cout<<"Escoge la raza: \n a) Elfo \n b) Humano \n c) Enano"<<endl; 
  cin>>choice;
  
  // Bloque de código para determinar la raza del jugador
  // Complejidad de tiempo: O(1)
  if(choice == 'a'){
    raza = "Elfo";
  } else if (choice == 'b'){
    raza = "Humano";
  } else if (choice == 'c'){
    raza = "Enano";
  } else {
    cout<<"Opción no válida, intenta de nuevo"<<endl; 
  }

  while(choice != 'a' && choice != 'b' && choice != 'c'){
    if(choice == 'a'){
      raza = "Elfo";
    } else if (choice == 'b'){
      raza = "Humano";
    } else if (choice == 'c'){
      raza = "Enano";
    } else {
      cout<<"Opción no válida, intenta de nuevo"<<endl;
      cin>>choice; 
    }
  }
  
  cout<<"Escribe el nombre del jugador: "<<endl;
  cin>>nombre;
  
  Dnd DND(monsters_, "raza", "nombre", hechizos_);  // Crea una nueva instancia de Dnd
  // Complejidad de tiempo: O(1)
  
  DND.play();  // Inicia el juego
  // La complejidad de tiempo dependerá de la implementación del método play
  
  hechizos_.get(1)->printAll();  // Imprime la información del primer hechizo/habilidad
  // Complejidad de tiempo: O(1) o O(n) dependiendo de la implementación del método printAll
}
