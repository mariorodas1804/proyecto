//partida va a ser la biblioteca que llama a la mayoria de las otras funciones
#include "librerias.h"
#include "jugador.h"
#include "enemigos.h"
#include "preguntas.h"
#include "mapa.h"


/*                    por hacer
intro();
switch 1inicializador
       2exit

menu();  //main.h

generacionMapa();
                 Campamento();     //mapa.h
                 tienda();         //mapa.h

generacionEnemigo();
generacionPregunta(): //deberia estar dentro de generacionEnemigo
preguntaBoss();
abrirArchivos();

generacionMapa();  //mapa.h

*/

tVidas vidas;
FILE * registroPartida;
tRegJugador jugador;
int nivelPregunta;

abrirArchivos(){
    preguntasFaciles=fopen("preguntasFaciles.dat")
    preguntasNormales=fopen("preguntasNormales.dat")
    preguntasDificiles=fopen("preguntasDificiles.dat")
    respuestasFaciles=fopen("respuestasFaciles.dat")
    respuestasNormales=fopen("respuestasNormales.dat")
    respuestasDificiles=fopen("respuestasDificiles.dat")
    
}


inicializadorDelJuego(){
    intro();
    abrirArchivos();
    generacionMapa();
    menu();
    
};

//nivel se actualiza acá
procesoJuego(tRegJugador* jugador1){

    do {
        graficar mapa con niveles restantes(nivel)
        if(nivel=3 o nivel=8){
            do{
                printf("\nDesea ingresar al campamento(vida) o a la tienda?(comodines)(1 o 2)");
                scanf("%d", &campaOTienda);
                switch(campaOTienda){
                    case 1:{
                        campamento();
                    	break;
                    }
                    case 2:{
                        tienda();
                    	break;
                    }
                    default:printf("\nError opcion incorrecta");
                }   
            }while(campaOTienda!=1 && campaOTienda!=2);
            
            
        }
        else{
            if(jugador1.nivel==5){
                nivelDificultad(5);
                generacionPelea();
            
                actualizarPuntuacion(&jugador1, 2, 2);
            
                nivelDificultad(5);
                generacionPelea();
                
                
                actualizarPuntuacion(&jugador1, 2, 2);
            
            }else{generacionEnemigo();  //grafico
                nivelDificultad(jugador1.nivel);
                generacionPelea();
                
            actualizarPuntuacion(&jugador1, 2, nivelPregunta);
                }
        
            }
        }
        avanzarEnMapa(&jugador1);
        jugador1.nivel++;
        
        
    } while(preguntar continuar)
    
      if(jugador1.nivel == 9){
            preguntaBoss(9)
            generacionPelea()
            preguntaBoss(10)
            generacionPelea()
            preguntaBoss(11)
            generacionPelea()
      
      }  
}

//pregunta 1 (39/2)*2             respuesta<MAx && respuesta%2     int ((aleatorio%MAX)/2)*2 &sorteado%2
//a) b) c) d)

//      
        
preguntaBoss(int){
    generacionPelea()
}
generacionPelea(){
   do{
                 scanf(respuesta);
                 if(respuestaCorrecta(respuesta)){
                     repuestaIncorrecta=false;
                 }
                 else{
                     repuestaIncorrecta=true
                     actualizarVida(&jugador1, 1);
                 }
                 
            }while(respuestaIncorrecta);

}
        
        
