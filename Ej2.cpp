#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

//A)

void logMessageA(string mensaje, int NivelSeveridad){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        cerr << "Error abriendo el archivo!\n";
        return;
    }
    switch (NivelSeveridad){
    case 1:
        outFile << "[INFO] " << mensaje << endl;
        break;
    case 2:
        outFile << "[DEBUG] " << mensaje << endl;
        break;
    case 3:
        outFile << "[WARNING] " << mensaje << endl;
        break;
    case 4:
        outFile << "[ERROR] " << mensaje << endl;
    case 5:
        outFile << "[CRITICAL] " << mensaje << endl;
    default:
        outFile << "[UNKNOWN] " << mensaje << endl;
        break;
    }
    outFile.close();
    }

//B)
void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        cerr << "Error abriendo el archivo!\n";
        return;
    }
    outFile << "["<< Mensage_de_Error <<"] dentro del archivo" << Archivo << "En la línea: " << Línea_de_Código<< endl;
    outFile.close();
}
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        cerr << "Error abriendo el archivo!\n";
        return;
    }
    outFile << "[SECURITY]"<< Mensaje_De_Acceso <<endl;
    outFile.close();
}   
int main(){
    return 0;
}