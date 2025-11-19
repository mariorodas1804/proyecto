#include "librerias.h"
#define VIDAS 7

//definicion de vector para guardar vidas
typedef bool tVidas [VIDAS];

//definicion de datos para jugador
typedef struct{
        
        tVidas vida;
        int puntaje;
        int nivel;
        bool ventajaCambio;
        bool ventajaEscudo;
        int enemigosMatados;
    
}tRegJugador;

//prototipo de funciones
void inicializarStats(tRegJugador*);
void actualizarVida(tRegJugador*, int);
void actualizarPuntaje(tRegJugador*, int, int);
void actualizarVentaja(tRegJugador*, int, int);
void mostrarStats(tRegJugador);
int acumuladorVidas();

/*
FILE * archivoJugador;
*/
void inicializarStats(tRegJugador* jugador1){
    int i;
    for(i=0; i<VIDAS-2; i++){
    	jugador1->vida[i]=true;
    }
    jugador1->puntaje=0;
    jugador1->nivel=1;
    jugador1->ventajaCambio=true;
    jugador1->ventajaEscudo=false;
    jugador1->enemigosMatados=0;
}

//Se usa parametrizacion para saber que hacer con la vida y ahorrar una funcion

void actualizarVida(tRegJugador* jugador1, int pActualizacion){
	int i;
	if(pActualizacion==2){
		for(i=0; i<VIDAS; i++){
			if(jugador1->vida[i]){
				jugador1->vida[i]=false;
				return;
			}
		}
	}
	else{
		for(i=0; i<VIDAS; i++){
			if(!jugador1->vida[i]){
				jugador1->vida[i]=true;
				return;
			}
		}
	}
}

//Se usa parametrizacion para saber que hacer con la puntuacion y ahorrar una funcion

void actualizarPuntaje(tRegJugador* jugador1, int pActualizacion, int pCantSuma_Resta){
	if(pActualizacion==1){
		jugador1->puntaje+=pCantSuma_Resta;
	}
	else{
		jugador1->puntaje-=pCantSuma_Resta;
	}
}
 
 //Se usa parametrizacion para saber que ventaja y que hacer con esa ventaja
 
void actualizarVentaja(tRegJugador* jugador1, int pActualizacion ,int pOpcion){//falta crear comprobacion para ver si tienen antes de eliminar o sumar
	if(pActualizacion==1){
		if(pOpcion==1){
			jugador1->ventajaCambio=true;	
		}
		else{
			jugador1->ventajaEscudo=true;
		}
	}
	else{
		if(pOpcion==1){
			jugador1->ventajaCambio=false;
		}
		else{
			jugador1->ventajaEscudo=false;
		}
	}
}

void mostrarStats(tRegJugador jugador1){
	int vidasRestantes=0, i;
	printf("\nPuntaje final: %d", jugador1.puntaje);
	printf("------------------------------");
	for(i=0; i<VIDAS; i++){
		if(jugador1.vida[i]){
			vidasRestantes++;
		}
	}
	printf("\nVidas restantes: %d", vidasRestantes);
	printf("------------------------------");
	printf("\nNivel alcanzado: %d", jugador1.nivel);
	printf("------------------------------");
	printf("\nEnemigos abatidos: %d", jugador1.enemigosMatados);
	printf("------------------------------");
	printf("\n");
	system("pause");
	printf("\n");
}

int acumuladorVidas(tRegJugador jugador1){
    int aux=0, i;
    for(i=0; i<VIDAS; i++){
        if(jugador1.vida[i]){
           aux++;
        }
    }
    return aux;
}
