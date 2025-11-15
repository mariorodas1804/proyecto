//partida va a ser la biblioteca que llama a la mayoria de las otras funciones
#include "librerias.h"
#include "jugador.h"
#include "enemigos.h"
#include "preguntas.h"
#include "mapa.h"

typedef struct{
    tString pregunta;
}tRegArchivo;


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


grafico ubicacion = nivel del jugador;
                ________________________________________________  
               |   
               |           printf(    %s
               |               
               |            pritnf( 
               |__________________________________________________

b

*/

typedef char tString [60];
typedef tString tVectorPreguntas;
typedef char tVectorRespuestas;

tVectorPreguntas vectorPreguntasFaciles, vectorPreguntasNormales, vectorPreguntasDificiles;
tVectorRespuestas vectorRespuestasFaciles, vectorRespuestasNormales, vectorRespuestasDificiles;

FILE * archivoPreguntas;
FILE * archivoRespuestas;
char respuestas;
tRegJugador jugador;
int nivelPregunta;

abrirArchivos(){
    tRegArchivo regPreguntas;
    archivoPreguntas=fopen("preguntasFaciles.dat", "rb");
    for (i=0; i<40; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasFaciles[i], regPreguntas.pregunta);
    }
    archivoPreguntas=fopen("preguntasNormales.dat","rb");
    for (i=0; i<40; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasNormales[i], regPreguntas.pregunta);
    }
    archivoPreguntas=fopen("preguntasDificiles.dat","rb");
    for (i=0; i<40; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasDificiles[i], regPreguntas.pregunta);
    }
    
    archivoRespuestas=fopen("respuestasFaciles.txt","r");
    for (i=0; i<20; i++){
        fscanf(archivoRespuestas, "%c", respuestas);
        vectorRespuestasFaciles[i]=respuestas;
    }
    archivoRespuestas=fopen("respuestasNormales.txt","r");
    for (i=0; i<20; i++){
        fscanf(archivoRespuestas, "%c", respuestas);
        vectorRespuestasNormales[i]=respuestas;
    }
    archivoRespuestas=fopen("respuestasDificiles.txt","r");
    for (i=0; i<20; i++){
        fscanf(archivoRespuestas, "%c", respuestas);
        vectorRespuestasDificiles[i]=respuestas;
    }
    
}


void inicializadorDelJuego(){
    intro();
    abrirArchivos();
    generacionMapa();
    menu();
    
};

//nivel se actualiza acá
void procesoJuego(tRegJugador* jugador1){
    
    int campaOTienda, nivelPregunta;
    
    do {
        mostrarMapa(jugador1->nivel);
        
        if(jugador1->nivel==3 || jugador1->nivel==8){
            do{
                printf("\nDesea ingresar al campamento para restaurar vida o a la tienda?(comodines)(1 o 2)");
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
                
                printf("OH NO, DOS ENEMIGOS DE ELITES HAN APARECIDO!!");
                nivelDificultad(5, &nivelPregunta);
                generacionPelea();
            
                actualizarPuntuacion(&jugador1, 2, 2);
            
                nivelDificultad(5, &nivelPregunta);
                generacionPelea();
                
                
                actualizarPuntuacion(&jugador1, 2, 2);
            
            }else{generacionEnemigo();  //grafico
            
                printf("OH NO UN ENEMIGO SALVAJE HA APARECIDO");
                nivelDificultad(jugador1.nivel, &nivelPregunta);
                generacionPelea();
                
                actualizarPuntuacion(&jugador1, 2, nivelPregunta); //nivelPregunta
                }
        
            }
        }
        
        avanzarEnMapa(&jugador1);
        jugador1.nivel++;
        
        
    }while(preguntarContinuar() && jugador1->nivel<9);
    
      if(jugador1.nivel == 9){
            
            printf("EL JEFE ESTA ENOJADO!");
            
            generacionPregunta(9)
            generacionPelea()
            generacionPregunta(9)
            generacionPelea()
            generacionPregunta(10)
            generacionPelea()
      
      }
      else{
          printf("Hasta luego!");
          mostrarStats();
          exit(EXIT_SUCCESS);
      }  
}

//pregunta 1 (39/2)*2             respuesta<MAx && respuesta%2     int ((aleatorio%MAX)/2)*2 &sorteado%2
//a) b) c) d)           

void generacionPelea(){
    
    do{
       scanf(respuesta);
       if(respuestaCorrecta(respuesta)){
         repuestaIncorrecta=false;
         }
         
     else{
         repuestaIncorrecta=true
         actualizarVida(&jugador1, 1);
     }
             
    }while(respuestaIncorrecta && jugador1->vida>0);
            
    if(jugador1.vida==0){
        printf("acabou caralho");//cambiar
        mostrarStats();
        exit(EXIT_SUCCESS);
    
    }

}

bool preguntarContinuar(){
    
    char respuesta;
    
    printf("Quieres avanzar al siguiente nivel? (S-Si o N-no)");
    scanf("%c",&respuesta);
    if(tolower(respuesta) == 's'){
        return true;
    }
    else{
        return false;
    }
    
}
   
   
   
   
   
   
   
   
   
   
        
