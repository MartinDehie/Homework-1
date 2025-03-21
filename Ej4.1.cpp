#include <iostream>
#include <chrono>
using namespace std;

// Función recursiva para comparar dos cadenas de caracteres.
bool sonIguales(char *a, char *b) {
    if (*a == '\0' && *b == '\0')  // Si ambos punteros llegan al final de la cadena, son iguales.
        return true;
    if (*a != *b)// Si los caracteres en la misma posición son distintos, las cadenas no son iguales. 
        return false;
    return sonIguales(a + 1, b + 1);// Llamada recursiva para comparar el siguiente carácter.
}
/*Se usa char* en lugar de string por eficiencia, ya que permite recorrer la cadena sin generar copias innecesarias. 
Además, char* accede directamente a la memoria, optimizando la comparación carácter por carácter.*/

int main() {
    char *texto1 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";
    char *texto2 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";

    auto startTime = chrono::high_resolution_clock::now();
    sonIguales(texto1,texto2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "sonIguales() demoró : " << elapsedTime.count() << "nanosegundos en ejecutar" << endl;
    return 0;
}
