//partida va a ser la biblioteca que llama a la mayoria de las otras funciones
#include "librerias.h"
#include "jugador.h"
#include "enemigos.h"
#include "preguntas.h"
#include "mapa.h"


abrirArchivos(){
    preguntasFaciles=fopen("preguntasFaciles.dat")
    preguntasNormales=fopen("preguntasNormales.dat")
    preguntasDificiles=fopen("preguntasDificiles.dat")
    respuestas=fopen("respuestas.dat")
    
}

FILE * registroPartida;

typedef bool tVector [5];


inicializadorDelJuego(){
    
    abrirArchivos();
    intro();
    generacionMapa();
    menu();
    
};

//nivel se actualiza acá
procesoJuego(){
    
    do {
        graficar mapa con niveles restantes(nivel)
        if(nivel=3 o nivel=8){
            switch
            1.campamento();
            2.tienda();
            avanzar en el mapa;
            igualar nivel;
            continue;
        }
        generacionEnemigo();
        generacionPregunta();
        do{
    
             printf(pregunta);
             printf(respuestas);
             scanf(respuesta);

             repuestaIncorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
             
        }while(respuestaIncorrecta);
        
        sumar puntuacion dependiendo de nivel;
        avanzar en el mapa;
        igualar nivel;
        
        
    } while(preguntar continuar)
    
        preguntaBoss(2)
        preguntaBoss(3)
        preguntaBoss(4)
