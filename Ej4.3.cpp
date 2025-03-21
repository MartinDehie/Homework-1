#include <iostream>
#include <chrono>

using namespace std;

constexpr bool sonIguales(const char* a, const char* b) {
    return (*a == '\0' && *b == '\0') ? true :
           (*a != *b) ? false :
           sonIguales(a + 1, b + 1);
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
