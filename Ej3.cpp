#include <iostream>
#include <memory>
using namespace std;

struct node {
    int valor;
    shared_ptr<node> siguiente;
    node(int val) : valor(val), siguiente(nullptr) {}
};

struct ListaEnlazada {
    shared_ptr<node> cabeza;
    int size;
    ListaEnlazada() : cabeza(nullptr), size(0) {}
};

void push_front(shared_ptr<ListaEnlazada>& lista, int val) {
    shared_ptr<node> nuevo = make_shared<node>(val);
    nuevo->siguiente = move(lista->cabeza);
    lista->cabeza = move(nuevo);
    lista->size++;
}

void push_back(shared_ptr<ListaEnlazada>& lista, int val) {
    shared_ptr<node> nuevo = make_shared<node>(val);
    if (!lista->cabeza) {
        lista->cabeza = move(nuevo);
        lista->size++;
        return;
    }
    shared_ptr<node> temp = lista->cabeza;
    while (temp->siguiente) {
        temp = temp->siguiente;
    }
    temp->siguiente = move(nuevo);
    lista->size++;
}

void insert(shared_ptr<ListaEnlazada>& lista, int posicion, int val) {
    if (posicion <= 0) {
        push_front(lista, val);
        return;
    }
    if (posicion >= lista->size) {
        cout << "Posición fuera de rango" << endl;
        push_back(lista, val);
        return;
    }
    shared_ptr<node> nuevo = make_shared<node>(val);
    shared_ptr<node> actual = lista->cabeza;
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {
        actual = actual->siguiente;
    }
    nuevo->siguiente = move(actual->siguiente);
    actual->siguiente = move(nuevo);
    lista->size++;
}

void erase(shared_ptr<ListaEnlazada>& lista, int posicion) {
    if (!lista->cabeza || posicion < 0) return;
    if (posicion == 0) {
        lista->cabeza = move(lista->cabeza->siguiente);
        lista->size--;
        return;
    }
    shared_ptr<node> actual = lista->cabeza;
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {
        actual = actual->siguiente;
    }
    if (actual->siguiente) {
        actual->siguiente = move(actual->siguiente->siguiente);
        lista->size--;
    }
}

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
