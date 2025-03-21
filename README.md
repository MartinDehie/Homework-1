# Ejercicio 1 (Ej1.cpp)

Este proyecto permite crear una matriz cuadrada de tamaño n x n donde los elementos de la matriz están numerados de acuerdo con valores crecientes de en 1. El programa permite imprimir la matriz representando el valor acompañado con su indice.
### Funciones:

*crearMatrizCuadrada(n):*
Crea una matriz cuadrada dinámica de tamaño n x n y llena sus elementos con los valores generados por la fórmula n*i + (j+1).

*imprimirMatriz(matriz, n):*
Imprime los elementos de la matriz en formato de coordenadas, comenzando desde el último elemento (en orden descendente).

*destruir(matriz, n):*
Libera la memoria asignada para la matriz cuadrada.

Compilación y ejecución:

g++ -o matriz Ej1.cpp

./matriz

# Ejecicio 2 (Ej2.cpp)

Este proyecto permite registrar mensajes en un archivo de texto (archivo.txt) con diferentes niveles de severidad, información sobre errores, y eventos de seguridad, con la posibilidad de manejar excepciones durante la ejecución del programa.

### Funciones:

*logMessage(string mensaje, int NivelSeveridad)*: Registra un mensaje con un nivel de severidad. Los niveles de severidad incluyen:

1: INFO, 2: DEBUG, 3: WARNING, 4: ERROR, 5: CRITICAL

*logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código)*: Registra un mensaje de error que incluye el nombre del archivo y la línea de código donde ocurrió el error.

*logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario)*: Registra un mensaje de acceso de seguridad, incluyendo el nombre de usuario que realizó la acción.

Función *main()*:

En el cuerpo principal del programa, se simula la ejecución de un sistema, donde se registran varios tipos de mensajes, incluidos los errores. También se lanza una excepción de tipo runtime_error para demostrar cómo manejarla y registrar el error.

### Compilación y ejecución:

g++ -o logmessage Ej2.cpp

./logmessage

# Ejercicio 3 (Ej3.cpp)

Este proyecto implementa una lista enlazada utilizando *smart pointers* de tipo shared_ptr. La lista permite agregar elementos al principio, al final, insertar en una posición específica, eliminar elementos y visualizar la lista y su tamaño.

### Estructura de Datos
*struct node*: Cada nodo de la lista contiene un valor entero y un puntero al siguiente nodo. La clase node tiene un constructor que inicializa su valor y su puntero siguiente.

*struct ListaEnlazada*: Esta estructura contiene un puntero cabeza al primer nodo de la lista y un entero size que mantiene el tamaño actual de la lista.

### Funciones:

*push_front(shared_ptr<ListaEnlazada>& lista, int val)*:
Inserta un nuevo nodo con valor val al principio de la lista.

*push_back(shared_ptr<ListaEnlazada>& lista, int val)*:
Inserta un nuevo nodo con valor val al final de la lista.

*insert(shared_ptr<ListaEnlazada>& lista, int posicion, int val)*:
Inserta un nuevo nodo con valor val en una posición específica de la lista.

*erase(shared_ptr<ListaEnlazada>& lista, int posicion)*:
Elimina el nodo en la posición especificada.

*print_list(const shared_ptr<ListaEnlazada>& lista)*:
Imprime los valores de la lista y su tamaño.

### Compilación y ejecución:

g++ -o lista_enlazada Ej3.cpp

./lista_enlazada

# Ejercicio 4a (Ej4.1.cpp,Ej4.3.cpp)

Este proyecto implementa una función recursiva que compara dos cadenas de caracteres para verificar si son iguales y  se mide el tiempo de ejecución de la función. 

### Funciones:

*sonIguales()*:
La función sonIguales compara dos cadenas de caracteres de forma recursiva. Compara carácter por carácter y devuelve true si ambas cadenas son idénticas, y false si alguna de ellas es diferente o si sus longitudes no coinciden.

*main()*:
En la función main, se crean dos cadenas de caracteres texto1 y texto2, y se mide el tiempo de ejecución de la función sonIguales utilizando la librería chrono.

### Compilación y ejecución:

g++ -o comparar_cadenas Ej4.1.cpp

./comparar_cadenas

# Ejercicio 4c (Ej4.3.cpp)

Este proyecto implementa una función recursiva que compara dos cadenas de caracteres para verificar si son iguales y  se mide el tiempo de ejecución de la función. 

### Funciones:

*sonIguales()*:
La función sonIguales compara dos cadenas de caracteres de forma recursiva y constexpr, lo que significa que puede evaluarse en tiempo de compilación si las cadenas son conocidas en ese momento. La función compara carácter por carácter y devuelve true si ambas cadenas son idénticas, y false si alguna de ellas es diferente o si sus longitudes no coinciden.

*main()*:
En la función main, se crean dos cadenas de caracteres texto1 y texto2, y se mide el tiempo de ejecución de la función sonIguales utilizando la librería chrono.

### Compilación y ejecución:

g++ -o comparar_cadenas_constexpr Ej4.3.cpp

./comparar_cadenas_constexpr
