#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para la pregunta
typedef struct {
    char pregunta[200];
} Pregunta;

// Estructura para las opciones
typedef struct {
    char opciones[200];
} Opciones;

int main() {
    FILE *archivo_dat, *archivo_txt;
    Pregunta preg;
    Opciones opc;
    
    // Crear archivo binario preguntas.dat
    archivo_dat = fopen("preguntasFaciles.dat", "wb");
    if (archivo_dat == NULL) {
        printf("Error al crear preguntas.dat\n");
        return 1;
    }
    
    // Crear archivo respuestas.txt
    archivo_txt = fopen("respuestasFaciles.txt", "w");
    if (archivo_txt == NULL) {
        printf("Error al crear respuestas.txt\n");
        fclose(archivo_dat);
        return 1;
    }
    
    // Pregunta 1
    strcpy(preg.pregunta, "Que es un algoritmo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Un lenguaje de programacion b)Una secuencia finita de pasos c)Un tipo de dato d)Un compilador");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 2
    strcpy(preg.pregunta, "Cual de estas es una estructura de control iterativa?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)If b)Switch c)While d)Break");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 3
    strcpy(preg.pregunta, "Que representa la notacion O grande (Big O)?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Complejidad espacial b)Complejidad temporal c)Ambas a y b d)Optimizacion");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 4
    strcpy(preg.pregunta, "Cual es la estructura de datos tipo LIFO?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Cola b)Pila c)Arbol d)Grafo");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 5
    strcpy(preg.pregunta, "Que tipo de busqueda requiere que los datos esten ordenados?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Busqueda lineal b)Busqueda binaria c)Busqueda secuencial d)Ninguna");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 6
    strcpy(preg.pregunta, "Cual es la complejidad del algoritmo de ordenamiento Quicksort en promedio?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(n) b)O(n log n) c)O(n^2) d)O(log n)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 7
    strcpy(preg.pregunta, "Que es la recursividad?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Un ciclo infinito b)Funcion que se llama a si misma c)Estructura de datos d)Tipo de variable");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 8
    strcpy(preg.pregunta, "En un arbol binario, cuantos hijos puede tener cada nodo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)0, 1 o 2 b)Solo 2 c)Ilimitados d)Solo 1");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 9
    strcpy(preg.pregunta, "Cual de estos NO es un paradigma de programacion?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Procedural b)Funcional c)Orientado a Objetos d)Secuencial");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "d");
    
    // Pregunta 10
    strcpy(preg.pregunta, "Que estructura de datos usa el principio FIFO?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Pila b)Cola c)Lista d)Arbol");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 11
    strcpy(preg.pregunta, "Cual es el peor caso de complejidad del algoritmo Bubble Sort?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(n) b)O(n log n) c)O(n^2) d)O(1)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 12
    strcpy(preg.pregunta, "Que es un puntero en programacion?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Variable que almacena direccion de memoria b)Tipo de dato c)Operador d)Estructura");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 13
    strcpy(preg.pregunta, "Cual es la diferencia entre parametros por valor y por referencia?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)No hay diferencia b)Valor copia, referencia direccion c)Referencia es mas lenta d)Valor usa punteros");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 14
    strcpy(preg.pregunta, "Que recorrido de arbol visita raiz-izquierda-derecha?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Postorden b)Inorden c)Preorden d)Nivel");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 15
    strcpy(preg.pregunta, "Cual es la complejidad de acceso a un elemento en un array?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(n) b)O(log n) c)O(1) d)O(n^2)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 16
    strcpy(preg.pregunta, "Que es una lista enlazada?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Array dinamico b)Secuencia de nodos con punteros c)Estructura ordenada d)Tipo de arbol");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 17
    strcpy(preg.pregunta, "Cual algoritmo de ordenamiento es mas eficiente para datos casi ordenados?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Quicksort b)Mergesort c)Insertion Sort d)Heapsort");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 18
    strcpy(preg.pregunta, "Que es un grafo en estructuras de datos?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Tipo de arbol b)Conjunto de vertices y aristas c)Lista ordenada d)Matriz");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 19
    strcpy(preg.pregunta, "Cual es la ventaja principal de la programacion modular?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Mayor velocidad b)Reutilizacion y mantenibilidad c)Menos memoria d)Mas seguridad");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 20
    strcpy(preg.pregunta, "Que es la complejidad espacial de un algoritmo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Tiempo de ejecucion b)Memoria utilizada c)Numero de operaciones d)Tamaño del codigo");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Cerrar archivos
    fclose(archivo_dat);
    fclose(archivo_txt);
    
    printf("Archivos generados exitosamente!\n");
    printf("- preguntas.dat (binario)\n");
    printf("- respuestas.txt\n");
    
    return 0;
}
