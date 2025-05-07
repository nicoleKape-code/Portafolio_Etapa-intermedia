#include <iostream>
using namespace std;

template <typename T> class Node {
private:
  T data;  // Datos almacenados en el nodo
  Node<T> *next;  // Puntero al siguiente nodo en la lista
  Node<T> *previous;  // Puntero al nodo anterior en la lista
  template <typename U> friend class ListaLigada;  // Permite que la clase ListaLigada acceda a los miembros privados de la clase Node

public:
  // Este método construye un nodo con los datos y punteros proporcionados.
  // Complejidad de tiempo: O(1)
  Node(T data, Node<T> *next, Node<T> *previous)
      : data(data), next(next), previous(previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
  }
};

template <typename T> class ListaLigada {
private:
  Node<T> *head;  // Puntero al primer nodo en la lista
  Node<T> *last;  // Puntero al último nodo en la lista
  int contador;  // Contador de elementos en la lista

public:
  // Este método inicializa una nueva lista ligada vacía.
  // Complejidad de tiempo: O(1)
  ListaLigada() {
    head = last = nullptr;
    contador = 0;
  }

  // Este método retorna el tamaño de la lista.
  // Complejidad de tiempo: O(1)
  int size() {
    return contador;
  }

  // Este método imprime todos los elementos de la lista.
  // Complejidad de tiempo: O(n), donde n es el número de elementos en la lista
  void print() {
    Node<T> *aux = head;
    while (aux != nullptr) {
      cout << aux->data << " ";
      aux = aux->next;
    }
    cout << endl;
  }

  // Este método verifica si la lista está vacía.
  // Complejidad de tiempo: O(1)
  bool isempty() {
    if (contador > 0) {
      return false;
    } else {
      return true;
    }
  }

  // Este método añade un elemento al inicio de la lista.
  // Complejidad de tiempo: O(1)
  void addFirst(T dato) {
    Node<T> *newNode = new Node<T>(dato, nullptr, nullptr);
    if (isempty() == true) {
      head = last = newNode;
    } else {
      newNode->next = head;
      head->previous = newNode;
      head = newNode;
    }
    contador++;
  }

  // Este método añade un elemento al final de la lista.
  // Complejidad de tiempo: O(1), ya que tenemos un puntero al último nodo
  void addLast(T dato) {
    if (isempty()) {
      addFirst(dato);
    } else {
      Node<T> *newNode = new Node<T>(dato, nullptr, last);
      last->next = newNode;
      last = newNode;
      contador++;
    }
  }

  // Este método obtiene el elemento en la posición especificada.
  // Complejidad de tiempo: O(n), en el peor de los casos, donde n es el número de elementos en la lista
  T get(int index) {
    if (index < 0 || index > contador || isempty()) {
      throw -1;
    } else {
      Node<T> *temp = head;
      for (int i = 0; i < index; i++) {
        temp = temp->next;
      }
      return temp->data;
    }
  }

  // Este método elimina y retorna el primer elemento de la lista.
  // Complejidad de tiempo: O(1)
  T remove_front() {
    if (isempty()) {
      throw -1;
    } else if (head == last) {
      T dato = head->data;
      delete head;
      head = last = nullptr;
      contador -= 1;
      return dato;
    } else {
      T num = head->data;
      head = head->next;
      delete head->previous;
      head->previous = nullptr;
      contador -= 1;
      return num;
    }
  }

  // Este método elimina y retorna el último elemento de la lista.
  // Complejidad de tiempo: O(1)
  T remove_last() {
    if (isempty()) {
      throw -1;
    } else if (head == last) {
      T dato = head->data;
      delete head;
      head = last = nullptr;
      contador -= 1;
      return dato;
    } else {
      T num = last->data;
      last = last->previous;
      delete last->next;
      last->next = nullptr;
      contador -= 1;
      return num;
    }
  }

  // Este método obtiene y retorna el primer elemento de la lista.
  // Complejidad de tiempo: O(1)
  T getFirst() { //O(1)
    if (isempty()) {
      throw -1;
    } else {
      return head->data;
    }
  }

  // Este método obtiene y retorna el último elemento de la lista.
  // Complejidad de tiempo: O(1)
  T getLast() { //O(1)
    if (isempty()) {
      throw -1;
    }
    return last->data;
  }

  // Este método inserta un elemento en la posición especificada.
  // Complejidad de tiempo: O(n), en el peor de los casos, donde n es el número de elementos en la lista
  void insert(T dato, int index) {
    if (isempty()) {
      throw -1;
    } else if (index < 0 && index > contador) {
      throw -1;
    } else {
      Node<T> *aux = head;
      for (int i = 0; i < index; i++)
        aux = aux->next;
      Node<T> *n = new Node<T>(dato, NULL, NULL);
      n->next = aux;
      n->previous = aux->previous;
      aux->previous = n;
      n->previous->next = n;
      contador++;
    }
  }

  // Este método elimina y retorna el elemento en la posición especificada.
  // Complejidad de tiempo: O(n), en el peor de los casos, donde n es el número de elementos en la lista
  T remove(int index) {
    if (isempty()) {
      throw -1;
    } else if (index == 0) {
      return remove_front();
    } else if (index == contador - 1) {
      return remove_last();
    } else {
      Node<T> *aux = head;
      for (int i = 0; i < index; i++) {
        aux = aux->next;
      }
      T dato = aux->data;
      aux->previous->next = aux->next;
      aux->next->previous = aux->previous;
      aux->next = nullptr;
      aux->previous = nullptr;
      delete aux;
      contador -= 1;
      return dato;
    }
  }
};
