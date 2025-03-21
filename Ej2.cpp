#include <iostream>
#include <fstream>
using namespace std;

//A
// Función para registrar mensajes con distintos niveles de severidad en un archivo de log.
void logMessage(string mensaje, int NivelSeveridad){
    ofstream outFile("archivo.txt",ios::app);// Abre el archivo en modo append para no sobrescribir datos previos.
    if (!outFile) {
        throw runtime_error("Error al abrir el archivo");// Lanza una excepción si el archivo no se puede abrir.
    }
    // Dependiendo del nivel de severidad, se agrega una etiqueta al mensaje.
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
        break;
    case 5:
        outFile << "[CRITICAL] " << mensaje << endl;
    default:
        break;
    }
    outFile.close();
    }

//B
// Función para registrar mensajes de error con información del archivo y la línea de código.
void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream outFile("archivo.txt",ios::app);
    if (!outFile) {
        throw runtime_error("Error al abrir el archivo");
        return;
    }
    outFile << "["<< Mensage_de_Error <<"] dentro del archivo" << Archivo << "En la línea: " << Línea_de_Código<< endl;
    outFile.close();
}
// Función para registrar intentos de acceso, indicando el nombre de usuario.
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
    // Registro de distintos eventos en el sistema.
    logMessage("Inicio del programa", 1);
    logMessage("Depuración en curso", 2);    
    logMessage("Posible problema detectado", 3);
    logMessage("Error en módulo X", 4);    
    logMessage("Fallo crítico del sistema", 5);

    // Registro de un error con información de ubicación en el código.
    logMessage("División por cero detectada", __FILE__, __LINE__);

    // Registro de intentos de acceso.
    logMessage("Access Granted", "admin");
    logMessage("Access Denied", "guest");

    try {
        throw runtime_error("Error inesperado");// Simulación de un error inesperado.
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        cerr << "Error crítico, ejecución detenida" << endl;
        return 1;// Finaliza el programa con un código de error.
    }
    return 0;
}