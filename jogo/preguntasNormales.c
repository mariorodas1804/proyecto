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
    archivo_dat = fopen("preguntasNormales.dat", "wb");
    if (archivo_dat == NULL) {
        printf("Error al crear preguntas.dat\n");
        return 1;
    }
    
    // Crear archivo respuestas.txt
    archivo_txt = fopen("respuestasNormales.txt", "w");
    if (archivo_txt == NULL) {
        printf("Error al crear respuestas.txt\n");
        fclose(archivo_dat);
        return 1;
    }
    
    // Pregunta 1
    strcpy(preg.pregunta, "En que caso Quicksort tiene complejidad O(n^2)?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Datos aleatorios b)Pivote siempre peor elemento c)Datos ordenados d)Nunca");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 2
    strcpy(preg.pregunta, "Cual es la diferencia entre una lista simplemente y doblemente enlazada?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Velocidad b)Doble tiene puntero anterior c)Simple es mas rapida d)Tamaño");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 3
    strcpy(preg.pregunta, "Que tecnica usa Mergesort para ordenar?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Fuerza bruta b)Divide y conquista c)Programacion dinamica d)Greedy");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 4
    strcpy(preg.pregunta, "Cual es la altura minima de un arbol binario con 15 nodos?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)3 b)4 c)5 d)15");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 5
    strcpy(preg.pregunta, "Que algoritmo de busqueda usa una tabla hash?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Busqueda secuencial b)Busqueda binaria c)Busqueda por hashing d)DFS");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 6
    strcpy(preg.pregunta, "Que es un arbol AVL?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Arbol binario b)Arbol autobalanceado c)Arbol completo d)Arbol B");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 7
    strcpy(preg.pregunta, "Cual es la complejidad de insertar en un heap?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(1) b)O(log n) c)O(n) d)O(n log n)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 8
    strcpy(preg.pregunta, "Que recorrido de grafo visita primero en profundidad?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)BFS b)DFS c)Dijkstra d)Prim");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 9
    strcpy(preg.pregunta, "Que problema resuelve el algoritmo de Dijkstra?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Ordenamiento b)Camino mas corto c)Arbol minimo d)Flujo maximo");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 10
    strcpy(preg.pregunta, "Cual es la ventaja de una lista enlazada sobre un array?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Acceso mas rapido b)Insercion dinamica eficiente c)Menos memoria d)Mas simple");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 11
    strcpy(preg.pregunta, "Que es la recursion de cola (tail recursion)?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Recursion infinita b)Llamada recursiva es ultima operacion c)Dos llamadas recursivas d)Recursion con arrays");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 12
    strcpy(preg.pregunta, "Cual estructura es mas adecuada para implementar una cola de prioridad?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Array b)Lista enlazada c)Heap d)Pila");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 13
    strcpy(preg.pregunta, "Que tecnica evita calcular subproblemas repetidos?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Divide y conquista b)Backtracking c)Memoizacion d)Greedy");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 14
    strcpy(preg.pregunta, "En un arbol binario de busqueda, donde se encuentra el minimo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Raiz b)Nodo mas a la izquierda c)Nodo mas a la derecha d)Cualquier hoja");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 15
    strcpy(preg.pregunta, "Cual es la complejidad promedio de busqueda en una tabla hash?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(1) b)O(log n) c)O(n) d)O(n^2)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 16
    strcpy(preg.pregunta, "Que es un grafo dirigido?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Con ciclos b)Aristas con direccion c)Sin ciclos d)Conexo");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 17
    strcpy(preg.pregunta, "Cual algoritmo garantiza estabilidad en ordenamiento?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Quicksort b)Heapsort c)Mergesort d)Selection Sort");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 18
    strcpy(preg.pregunta, "Que complejidad tiene eliminar el minimo de un min-heap?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(1) b)O(log n) c)O(n) d)O(n log n)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 19
    strcpy(preg.pregunta, "Que representa un ciclo en un grafo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Camino sin repetir vertices b)Camino que vuelve al inicio c)Arbol d)Grafo conexo");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 20
    strcpy(preg.pregunta, "Cual es la principal desventaja de la recursion?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Dificil de entender b)Consume mucha pila c)Lenta d)No funciona siempre");
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
