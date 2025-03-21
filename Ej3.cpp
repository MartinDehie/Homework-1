#include <iostream>
#include <memory>
using namespace std;

// Definición de un nodo de la lista enlazada.
struct node {
    int valor;
    shared_ptr<node> siguiente;// Puntero al nodo siguiente.
    node(int val) : valor(val), siguiente(nullptr) {}// Constructor del nodo.
};

// Definición de la estructura de la lista enlazada.
struct ListaEnlazada {
    shared_ptr<node> cabeza;//Puntero a la cabeza de lista.
    int size;//Tamaño de la lista.
    ListaEnlazada() : cabeza(nullptr), size(0) {}//Constructor de la lista vacia.
};

void push_front(shared_ptr<ListaEnlazada>& lista, int val) {
    shared_ptr<node> nuevo = make_shared<node>(val);// Crea un nuevo nodo.
    nuevo->siguiente = move(lista->cabeza);// Conecta el nuevo nodo con la cabeza de la lista.
    lista->cabeza = move(nuevo);//Actualiza la cabeza de la lista.
    lista->size++;//Incrementa el tamaño de la lista.
}
// Inserta un nodo al final de la lista.
void push_back(shared_ptr<ListaEnlazada>& lista, int val) {
    shared_ptr<node> nuevo = make_shared<node>(val);
    if (!lista->cabeza) {// Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
        lista->cabeza = move(nuevo);
        lista->size++;
        return;
    }
    shared_ptr<node> temp = lista->cabeza;
    while (temp->siguiente) {// Recorre hasta el último nodo.
        temp = temp->siguiente;
    }
    temp->siguiente = move(nuevo);// Inserta el nuevo nodo al final.
    lista->size++;
}
// Inserta un nodo en una posición específica de la lista.
void insert(shared_ptr<ListaEnlazada>& lista, int posicion, int val) {
    if (posicion <= 0) {// Si la posición es menor o igual a 0, insertar al frente.
        push_front(lista, val);
        return;
    }
    if (posicion >= lista->size) {// Si la posición es mayor o igual al tamaño, insertar al final.
        cout << "Posición fuera de rango" << endl;
        push_back(lista, val);
        return;
    }
    shared_ptr<node> nuevo = make_shared<node>(val);
    shared_ptr<node> actual = lista->cabeza;
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {// Busca la posición deseada.
        actual = actual->siguiente;
    }
    nuevo->siguiente = move(actual->siguiente);
    actual->siguiente = move(nuevo);
    lista->size++;
}
// Elimina un nodo en una posición específica de la lista.
void erase(shared_ptr<ListaEnlazada>& lista, int posicion) {
    if (!lista->cabeza || posicion < 0) return;// Si la lista está vacía o la posición es inválida, no hace nada.
    if (posicion == 0) {// Si se quiere eliminar el primer nodo.
        lista->cabeza = move(lista->cabeza->siguiente);
        lista->size--;
        return;
    }
    shared_ptr<node> actual = lista->cabeza;
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {// Busca el nodo anterior al que se quiere eliminar.
        actual = actual->siguiente;
    }
    if (actual->siguiente) {
        actual->siguiente = move(actual->siguiente->siguiente);
        lista->size--;
    }
}
// Imprime la lista.
void print_list(const shared_ptr<ListaEnlazada>& lista) {
    shared_ptr<node> temp = lista->cabeza;
    while (temp) {
        cout << temp->valor << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL" << endl;
    cout << "Tamaño: " << lista->size << endl;
}


int main() {
    shared_ptr lista = make_shared<ListaEnlazada>();
    
    push_front(lista, 10);
    push_front(lista, 20);
    push_back(lista, 30);
    insert(lista, 1, 15);
    print_list(lista);
    
    erase(lista, 2);
    print_list(lista);
    
    return 0;
}
