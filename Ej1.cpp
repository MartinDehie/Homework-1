#include <iostream>

using namespace std;

// Función para crear una matriz cuadrada de tamaño n x n.
int** crearMatrizCuadrada(int n) {
    int** matriz = nullptr;
    try{
    // Reserva memoria para las filas de la matriz.
    matriz = new int*[n];
    }catch(bad_alloc){
        throw runtime_error("No memory");// Manejo de error en caso de fallo en la asignación de memoria.
        return NULL;
    }
    // Reserva memoria para las columnas y asigna valores a la matriz.
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++){
            matriz[i][j] = n*i + (j+1);// Inicializa la matriz con valores secuenciales.
        }
    }
    return matriz;
}
// Función para imprimir la matriz en orden inverso.
void imprimirMatriz(int** matriz, int n, int fila = 0,int columna = 0) {
    for (int i = n * n - 1; i >= 0; i--) {
        cout << "[" << i / n << "][" << i % n << "] = " << matriz[i / n][i % n] << endl;
    }
}
// Función para liberar la memoria asignada a la matriz.
void destruir(int ** matriz,int n){

    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    // Creo la matriz cuadrada.
    int **matriz = crearMatrizCuadrada(n);

    // Imprime la matriz generada.
    cout << "Matriz cuadrada de tamaño " << n << " x " << n << ":" << endl;
    imprimirMatriz(matriz,n);

    //Liberación de la memoria utilizada
    destruir(matriz,n);


    return 0;
}