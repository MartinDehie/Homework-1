#include <iostream>
#include <memory>
using namespace std;

struct node {
    int valor;
    unique_ptr<node> siguiente;
    node(int val) : valor(val), siguiente(nullptr) {}
};

struct ListaEnlazada {
    unique_ptr<node> cabeza;
    int size;
    ListaEnlazada() : cabeza(nullptr), size(0) {}
};

void push_front(unique_ptr<ListaEnlazada>& lista, int val) {
    unique_ptr<node> nuevo = make_unique<node>(val);
    nuevo->siguiente = move(lista->cabeza);
    lista->cabeza = move(nuevo);
    lista->size++;
}

void push_back(unique_ptr<ListaEnlazada>& lista, int val) {
    unique_ptr<node> nuevo = make_unique<node>(val);
    if (!lista->cabeza) {
        lista->cabeza = move(nuevo);
        lista->size++;
        return;
    }
    node* temp = lista->cabeza.get();
    while (temp->siguiente) {
        temp = temp->siguiente.get();
    }
    temp->siguiente = move(nuevo);
    lista->size++;
}

void insert(unique_ptr<ListaEnlazada>& lista, int posicion, int val) {
    if (posicion <= 0) {
        push_front(lista, val);
        return;
    }
    if (posicion >= lista->size) {
        cout << "Posición fuera de rango" << endl;
        push_back(lista, val);
        return;
    }
    unique_ptr<node> nuevo = make_unique<node>(val);
    node* actual = lista->cabeza.get();
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {
        actual = actual->siguiente.get();
    }
    nuevo->siguiente = move(actual->siguiente);
    actual->siguiente = move(nuevo);
    lista->size++;
}

void erase(unique_ptr<ListaEnlazada>& lista, int posicion) {
    if (!lista->cabeza || posicion < 0) return;
    if (posicion == 0) {
        lista->cabeza = move(lista->cabeza->siguiente);
        lista->size--;
        return;
    }
    node* actual = lista->cabeza.get();
    for (int i = 0; i < posicion - 1 && actual->siguiente; i++) {
        actual = actual->siguiente.get();
    }
    if (actual->siguiente) {
        actual->siguiente = move(actual->siguiente->siguiente);
        lista->size--;
    }
}

void print_list(const unique_ptr<ListaEnlazada>& lista) {
    const node* temp = lista->cabeza.get();
    while (temp) {
        cout << temp->valor << " -> ";
        temp = temp->siguiente.get();
    }
    cout << "NULL" << endl;
    cout << "Tamaño: " << lista->size << endl;
}


int main() {
    auto lista = make_unique<ListaEnlazada>();
    
    push_front(lista, 10);
    push_front(lista, 20);
    push_back(lista, 30);
    insert(lista, 1, 15);
    print_list(lista);
    
    erase(lista, 2);
    print_list(lista);
    
    return 0;
}
