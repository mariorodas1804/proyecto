//Ranking.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mapa.h"

#define MAX 50
//definicion de estructuras
typedef char tStringRanking[MAX];

typedef struct nodoRanking{
    tStringRanking nombre;
    int puntaje;
    int nivel;
    int enemigosMatados;
    struct nodoRanking* izq;
    struct nodoRanking* der;
}tNodoRanking;

typedef tNodoRanking* tArbolRanking;

typedef struct{
    tStringRanking nombre;
    int puntaje;
    int nivel;
    int enemigosMatados;
}tRegistroRanking;

//prototipado
void inicializarArbol(tArbolRanking*);
void insertarNodo(tArbolRanking*, tStringRanking*, int, int, int);
void agregarAlRanking(tArbolRanking*, tRegJugador, tStringRanking*);

void limpiarRanking(tArbolRanking*);

void graficarTop10(tArbolRanking);
void mostrarInorden(tArbolRanking);
void mostrarStatsTop10(tArbolRanking, int*);

//busqueda
tNodoRanking* buscarPorNombre(tArbolRanking , tStringRanking*);
void buscarYMostrarJugador(tArbolRanking, tStringRanking*);
int contarJugadores(tArbolRanking);

//Persistencia de archivos
void guardarRanking(tArbolRanking, FILE*);
void cargarRanking(tArbolRanking*, tStringRanking*);
void guardarRankingEnArchivo(tArbolRanking, tStringRanking*);

//
void inicializarArbol(tArbolRanking* pArbol){
    *pArbol = NULL;
}

void insertarNodo(tArbolRanking* pRaiz, tStringRanking* pNombre, int pPuntaje, int pNivel, int pEnemigosMatados){
    //Caso base arbol vacio
    //Solo una vez se ingresa los datos
    if(*pRaiz == NULL){
        *pRaiz = (tNodoRanking*)malloc(sizeof(tNodoRanking));
        if (*pRaiz == NULL) {
            printf("Error: No se pudo asignar memoria\n");
            return;
        }
        
        strcpy((*pRaiz)->nombre, *pNombre);
        (*pRaiz)->puntaje = pPuntaje;
        (*pRaiz)->nivel = pNivel;
        (*pRaiz)->enemigosMatados = pEnemigosMatados;
        (*pRaiz)->izq = NULL;
        (*pRaiz)->der = NULL;
        
        return;
    }
    
    //Caso recursivo ir a izquierda o derecha
    if (pPuntaje <= (*pRaiz)->puntaje) {
        //Menor o igual puntaje, izquierda
        insertarNodo(&((*pRaiz)->izq), pNombre, pPuntaje, pNivel, pEnemigosMatados);
    } else {
        //Mayor puntaje, derecha
        insertarNodo(&((*pRaiz)->der), pNombre, pPuntaje, pNivel, pEnemigosMatados);
    }
}

void agregarAlRanking(tArbolRanking* pRaiz, tRegJugador jugador1, tStringRanking* pNombre) {
    insertarNodo(pRaiz, pNombre, jugador1.puntaje, jugador1.nivel, jugador1.enemigosMatados);
}

void limpiarRanking(tArbolRanking* pRaiz) {
    if (*pRaiz != NULL) {
        limpiarRanking(&((*pRaiz)->izq));
        limpiarRanking(&((*pRaiz)->der));
        free(*pRaiz);
        *pRaiz = NULL;
    }
}

//Mostrar de Menor a Mayor
void mostrarInorden(tArbolRanking pRaiz) {
    if (pRaiz != NULL) {
        mostrarInorden(pRaiz->izq);
        printf("%-20s | %5d pts | Nivel: %2d | Enemigos: %2d\n", 
               pRaiz->nombre, pRaiz->puntaje, pRaiz->nivel, pRaiz->enemigosMatados);
        mostrarInorden(pRaiz->der);
    }
}

//Mostramos las estadisticas luego de la llamada graficarTop10()
void mostrarStatsTop10(tArbolRanking pRaiz, int* pContador) {
    if (pRaiz == NULL || *pContador >= 10) {
        return;
    }
    
    // Primero mostramos los mayores puntajes
    mostrarStatsTop10(pRaiz->der, pContador);
    
    //Procesar nodo actual hasta 10
    if (*pContador < 10) {
        (*pContador)++;
        printf("%2d. %-20s | %5d pts | Nivel: %2d | Enemigos: %2d\n", 
               *pContador, pRaiz->nombre, pRaiz->puntaje, pRaiz->nivel, pRaiz->enemigosMatados);
    }
    
    // Luego los menores puntajes
    mostrarStatsTop10(pRaiz->izq, pContador);
}

void graficarTop10(tArbolRanking pRaiz) {
    int contador = 0;
    
    printf("\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("¦                         ** TOP 10 JUGADORES **                        ¦\n");
    printf("¦------------------------------------------------------------------------¦\n");
    
    if (pRaiz == NULL) {
        printf("¦  No hay jugadores en el ranking aun.                                 ¦\n");
    } else {
        mostrarStatsTop10(pRaiz, &contador);
        if (contador == 0) {
            printf("¦  No hay jugadores en el ranking.                                     ¦\n");
        }
    }
    
    printf("+------------------------------------------------------------------------+\n");
    printf("\n");
}

tNodoRanking* buscarPorNombre(tArbolRanking pRaiz, tStringRanking* pNombre){
    if (pRaiz == NULL) {
        return NULL;
    }
    
    // Si encontramos el nombre
    if (strcmp(pRaiz->nombre, *pNombre) == 0){
        return pRaiz;
    }
    
    // Buscar en subárbol izquierdo
    tNodoRanking* resultado = buscarPorNombre(pRaiz->izq, pNombre);
    if (resultado != NULL) {
        return resultado;
    }
    
    // Buscar en subárbol derecho
    return buscarPorNombre(pRaiz->der, pNombre);
}

void buscarYMostrarJugador(tArbolRanking pRaiz, tStringRanking* pNombre) {
    tNodoRanking* nodo = buscarPorNombre(pRaiz, pNombre);
    
    if (nodo != NULL) {
        printf("\n Jugador encontrado:\n");
        printf("\tNombre: %s\n", nodo->nombre);
        printf("\tPuntaje: %d\n", nodo->puntaje);
        printf("\tNivel alcanzado: %d\n", nodo->nivel);
        printf("\tEnemigos abatidos: %d\n", nodo->enemigosMatados);
    } else {
        printf("\n Jugador '%s' no encontrado en el ranking.\n", pNombre);
    }
}

int contarJugadores(tArbolRanking pRaiz){
    if (pRaiz == NULL) {
        return 0;
    }
    return 1 + contarJugadores(pRaiz->izq) + contarJugadores(pRaiz->der);
}

void guardarRanking(tArbolRanking pRaiz, FILE* archivo) {
    if (pRaiz == NULL) {
        return;
    }
    
    // Guardar nodo actual
    tRegistroRanking regAux;
    strcpy(regAux.nombre, pRaiz->nombre);
    regAux.puntaje = pRaiz->puntaje;
    regAux.nivel = pRaiz->nivel;
    regAux.enemigosMatados = pRaiz->enemigosMatados;
    
    fwrite(&regAux, sizeof(tRegistroRanking), 1, archivo);
    
    // Guardar subárboles
    guardarRanking(pRaiz->izq, archivo);
    guardarRanking(pRaiz->der, archivo);
}

void guardarRankingEnArchivo(tArbolRanking pRaiz, tStringRanking* pArchivoRanking) {
    FILE* archivo = fopen(*pArchivoRanking, "wb");
    if(archivo == NULL){
        printf("Error no se pudo abrir el archivo %s para escritura\n", *pArchivoRanking);
        return;
    }
    
    guardarRanking(pRaiz, archivo);
    fclose(archivo);
    
    int totalJugadores = contarJugadores(pRaiz);
    printf("Ranking guardado: %d jugadores en '%s'\n", totalJugadores, pArchivoRanking);
}

void cargarRankingDesdeArchivo(tArbolRanking* pRaiz, tStringRanking* pArchivoRanking){
    FILE* archivo = fopen(*pArchivoRanking, "rb");
    if (archivo == NULL) {
        printf("Nota: No se encontró archivo de ranking previo. Se creará uno nuevo.\n");
        return;
    }
    
    tRegistroRanking regAux;
    int contador = 0;
    
    while (fread(&regAux, sizeof(tRegistroRanking), 1, archivo) == 1) {
        insertarNodo(pRaiz, &regAux.nombre, regAux.puntaje, regAux.nivel, regAux.enemigosMatados);
        contador++;
    }
    
    fclose(archivo);
    printf("Ranking cargado: %d jugadores desde '%s'\n", contador, pArchivoRanking);
}
