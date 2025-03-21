#include <iostream>
#include <chrono>

using namespace std;

// Función recursiva para comparar dos cadenas de caracteres

constexpr bool sonIguales(const char* a, const char* b) {
    if (*a == '\0' && *b == '\0')  // Si ambos punteros llegan al final de la cadena, son iguales.
        return true;
    if (*a != *b)// Si los caracteres en la misma posición son distintos, las cadenas no son iguales. 
        return false;
    return sonIguales(a + 1, b + 1);// Llamada recursiva para comparar el siguiente carácter.
}

int main() {
    const char *texto1 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";
    const char *texto2 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";

    auto startTime = chrono::high_resolution_clock::now();
    sonIguales(texto1,texto2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "sonIguales() demoró: " << elapsedTime.count() << "nanosegundos en ejecutar" << endl;
    return 0;
}
/* La versión constexpr es más rápida a la versión normal porque permite que la funcion se ejecute en tiempo de compilación y
la medición ocurre en el tiempo de ejecución. Es decir, que la función con constexpr permite una ejecución más eficiente */
