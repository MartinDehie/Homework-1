#include <iostream>
#include <chrono>
using namespace std;

bool sonIguales(char *a, char *b) {
    if (*a == '\0' && *b == '\0') 
        return true;
    if (*a != *b) 
        return false;
    return sonIguales(a + 1, b + 1);
}

int main() {
    char *texto1 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";
    char *texto2 = "alksdnlaksdnaksjnasldknaosdbakjsdbalkdnalsdalksdnalkdnalksdnalskd";

    auto startTime = chrono::high_resolution_clock::now();
    sonIguales(texto1,texto2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "A sonIguales le tomó: " << elapsedTime.count() << "nanosegundos" << endl;
    return 0;
}
