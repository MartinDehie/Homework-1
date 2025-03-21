#include <iostream>
#include <fstream>
using namespace std;

//A

void logMessage(string mensaje, int NivelSeveridad){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        throw runtime_error("Error al abrir el archivo");
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
        break;
    }
    outFile.close();
    }

//B
void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        throw runtime_error("Error al abrir el archivo");
        return;
    }
    outFile << "["<< Mensage_de_Error <<"] dentro del archivo" << Archivo << "En la línea: " << Línea_de_Código<< endl;
    outFile.close();
}
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        throw runtime_error("Error al abrir el archivo");
        return;
    }
    outFile << "[SECURITY]"<< Mensaje_De_Acceso <<endl;
    outFile.close();
}   
int main(){      
    logMessage("Inicio del programa", 1);
    
    logMessage("Depuración en curso", 2);
    
    logMessage("Posible problema detectado", 3);
    
    logMessage("Error en módulo X", 4);
    
    logMessage("Fallo crítico del sistema", 5);
    
    logMessage("División por cero detectada", __FILE__, __LINE__);

    logMessage("Access Granted", "admin");
    logMessage("Access Denied", "guest");

    try {
        throw runtime_error("Error inesperado");
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        cerr << "Error crítico, ejecución detenida" << endl;
        return 1;
    }
    return 0;
}