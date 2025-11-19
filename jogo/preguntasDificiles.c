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
    archivo_dat = fopen("preguntasDificiles.dat", "wb");
    if (archivo_dat == NULL) {
        printf("Error al crear preguntas.dat\n");
        return 1;
    }
    
    // Crear archivo respuestas.txt
    archivo_txt = fopen("respuestasDificiles.txt", "w");
    if (archivo_txt == NULL) {
        printf("Error al crear respuestas.txt\n");
        fclose(archivo_dat);
        return 1;
    }
    
    // Pregunta 1
    strcpy(preg.pregunta, "En quicksort con pivote aleatorio, cual es la probabilidad de peor caso en cada particion?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)1/n b)1/n^2 c)1/2 d)Depende de la implementacion");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 2
    strcpy(preg.pregunta, "Cual es la cota inferior teorica para ordenamiento por comparaciones?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(n) b)O(n log n) c)Omega(n log n) d)Theta(n^2)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 3
    strcpy(preg.pregunta, "En un arbol AVL, cual es el factor de balance maximo permitido?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)0 b)1 c)2 d)log n");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 4
    strcpy(preg.pregunta, "Cuantas comparaciones hace en promedio Quicksort para ordenar n elementos?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)n log n b)1.39 n log n c)2 n log n d)n^2");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 5
    strcpy(preg.pregunta, "Que tecnica usa programacion dinamica para evitar recalculos?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Divide y conquista b)Memorizacion o tabulacion c)Backtracking d)Greedy");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 6
    strcpy(preg.pregunta, "En el problema de la mochila 0/1, por que no funciona un enfoque greedy?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Es muy lento b)No tiene subestructura optima c)No cumple eleccion greedy d)Necesita backtracking");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 7
    strcpy(preg.pregunta, "Cual es la complejidad espacial de Mergesort recursivo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(1) b)O(log n) c)O(n) d)O(n log n)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 8
    strcpy(preg.pregunta, "Que condicion debe cumplir un problema para usar programacion dinamica?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Solo subestructura optima b)Subproblemas superpuestos y subestructura optima c)Ser NP-completo d)Tener solucion greedy");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 9
    strcpy(preg.pregunta, "En un arbol B de orden m, cuantas claves tiene un nodo interno como minimo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)m/2 b)ceil(m/2)-1 c)m-1 d)1");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 10
    strcpy(preg.pregunta, "Cual es la complejidad del algoritmo de Floyd-Warshall?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(V^2) b)O(V^2 log V) c)O(V^3) d)O(E log V)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 11
    strcpy(preg.pregunta, "Que algoritmo usa la tecnica greedy para hallar arbol de expansion minima?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Dijkstra b)Floyd-Warshall c)Kruskal o Prim d)Bellman-Ford");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "c");
    
    // Pregunta 12
    strcpy(preg.pregunta, "En analisis amortizado, que tecnica asigna creditos a operaciones?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Metodo agregado b)Metodo contable c)Metodo potencial d)Todas");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 13
    strcpy(preg.pregunta, "Cual es la complejidad de buscar en un arbol B de altura h?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(h) b)O(h log m) c)O(mh) d)O(log n)");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 14
    strcpy(preg.pregunta, "Que propiedad NO garantiza un algoritmo greedy?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Solucion optima siempre b)Rapidez c)Simplicidad d)Eleccion local");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 15
    strcpy(preg.pregunta, "En hashing con encadenamiento, cual es el factor de carga critico?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)0.5 b)0.75 c)1.0 d)Depende de la aplicacion");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "d");
    
    // Pregunta 16
    strcpy(preg.pregunta, "Cual es la diferencia clave entre Dijkstra y Bellman-Ford?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Complejidad b)Bellman-Ford acepta pesos negativos c)Dijkstra es greedy d)Todas correctas");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "d");
    
    // Pregunta 17
    strcpy(preg.pregunta, "En un heap binario completo con n elementos, cuantas hojas tiene aproximadamente?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)n/4 b)n/2 c)n/3 d)log n");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 18
    strcpy(preg.pregunta, "Que estructura de datos usa Union-Find para optimizar operaciones?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)Arbol con compresion de camino b)Lista enlazada c)Grafo d)Tabla hash");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "a");
    
    // Pregunta 19
    strcpy(preg.pregunta, "Cual es el peor caso de Heapsort?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)O(n) b)O(n log n) c)O(n^2) d)No tiene peor caso");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Pregunta 20
    strcpy(preg.pregunta, "En un grafo no dirigido, cuantas aristas tiene como maximo?");
    fwrite(&preg, sizeof(Pregunta), 1, archivo_dat);
    strcpy(opc.opciones, "a)n(n-1) b)n(n-1)/2 c)n^2 d)2^n");
    fwrite(&opc, sizeof(Opciones), 1, archivo_dat);
    fprintf(archivo_txt, "b");
    
    // Cerrar archivos
    fclose(archivo_dat);
    fclose(archivo_txt);
    
    
    return 0;
}
