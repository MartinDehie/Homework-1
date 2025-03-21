#include <iostream>

using namespace std;

int** crearMatrizCuadrada(int n) {
    int** matriz = nullptr;
    try{
    matriz = new int*[n];
    }catch(bad_alloc){
        throw runtime_error("No memory");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++){
            matriz[i][j] = n*i + (j+1);
        }
    }
    return matriz;
}

void imprimirMatriz(int** matriz, int n, int fila = 0,int columna = 0) {
    for (int i = n * n - 1; i >= 0; i--) {
        cout << "[" << i / n << "][" << i % n << "] = " << matriz[i / n][i % n] << endl;
    }
}
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

    int **matriz = crearMatrizCuadrada(n);

    cout << "Matriz cuadrada de tamaño " << n << " x " << n << ":" << endl;
    imprimirMatriz(matriz,n);

    destruir(matriz,n);


    return 0;
}