
#include "librerias.h"
#include "enemigos.h"
#include "preguntas.h"
#include "mapa.h"
#include "partida.h"

typedef bool tVidas [5];


typedef struct jugador{
        
        Tvector vida;
        float puntaje;
        int nivel;
        bool ventajasCambio;
        bool ventajaEliminar;
    
}tRegJugador;

FILE * archivoJugador;

inicializarStats(){
    
    guardadoJugador== NULL{

                      variables = default;
    
    }
    else{
        
        guardadoJugador != NULL{
        
                        //traer variables de los archivos
        
        }
    }
}

actualizarVida(tRegJugador*, bool(instruccion de perder o ganar)); //Se usa parametrizacion para saber que hacer con la vida y ahorrar una funcion
//sumarVida
//restarVida
actualizarPuntaje(tRegJugador*, bool(instruccion de sumar o restar), int cuanto sumar o restar); //Se usa parametrizacion para saber que hacer con la puntuacion y ahorrar una funcion
//sumarpuntaje()
//restarpuntaje()
sumarVentaja(int);

