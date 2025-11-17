//partida va a ser la biblioteca que llama a la mayoria de las otras funciones
#include "librerias.h"

#include "jugador.h"
//#include "enemigos.h"
//#include "preguntas.h"
//#include "mapa.h"
#define TAMANIOVECTORPREGUNTAS 40
#define TAMANIOVECTORRESPUESTAS 20

typedef char tString [60];

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

generacionMapa();  //mapa.h

grafico ubicacion = nivel del jugador;
                ________________________________________________  
               |   
               |           printf(    %s
               |               
               |            pritnf( 
               |__________________________________________________


*/

//Prototipado de funciones en Partida.h
void abrirArchivos();
void inicializadorDelJuego();
void procesoJuego(tRegJugador*);
void generacionPelea(tRegJugador*);
bool preguntarContinuar();

//Tipos de datos para vectores con preguntas y respuestas
typedef tString tVectorPreguntas[TAMANIOVECTORPREGUNTAS];
typedef char tVectorRespuestas[TAMANIOVECTORRESPUESTAS];

//variables globales de vectores con preguntas y respuestas
tVectorPreguntas vectorPreguntasFaciles, vectorPreguntasNormales, vectorPreguntasDificiles;
tVectorRespuestas vectorRespuestasFaciles, vectorRespuestasNormales, vectorRespuestasDificiles;

//archivos dat externos con preguntas y respuestas
FILE * archivoPreguntas;
FILE * archivoRespuestas;

//variables globales generales
tRegJugador jugador;
int nivelPregunta;

void abrirArchivos(){
    tRegArchivo regPreguntas;
    int i;
    char respuestas;
    archivoPreguntas=fopen("preguntasFaciles.dat", "rb");
    for (i=0; i<TAMANIOVECTORPREGUNTAS; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasFaciles[i], regPreguntas.pregunta);
    }
    archivoPreguntas=fopen("preguntasNormales.dat","rb");
    for (i=0; i<TAMANIOVECTORPREGUNTAS; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasNormales[i], regPreguntas.pregunta);
    }
    archivoPreguntas=fopen("preguntasDificiles.dat","rb");
    for (i=0; i<TAMANIOVECTORPREGUNTAS; i++){
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);
        strcpy(vectorPreguntasDificiles[i], regPreguntas.pregunta);
    }
    
    archivoRespuestas=fopen("respuestasFaciles.txt","r");
    for (i=0; i<TAMANIOVECTORRESPUESTAS; i++){
        fscanf(archivoRespuestas, "%c", respuestas);
        vectorRespuestasFaciles[i]=respuestas;
    }
    archivoRespuestas=fopen("respuestasNormales.txt","r");
    for (i=0; i<TAMANIOVECTORRESPUESTAS; i++){
        fscanf(archivoRespuestas, "%c", respuestas);
        vectorRespuestasNormales[i]=respuestas;
    }
    archivoRespuestas=fopen("respuestasDificiles.txt","r");
    for (i=0; i<TAMANIOVECTORRESPUESTAS; i++){
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

void procesoJuego(tRegJugador* jugador1){
    
    int campaOTienda, nivelPregunta;
    
    do{
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
            if(jugador1->nivel==5){
                
                printf("OH NO, DOS ENEMIGOS DE ELITES HAN APARECIDO!!");
                nivelDificultad(5, &nivelPregunta);
                generacionPelea(jugador1);
            
                actualizarPuntaje(jugador1, 2, 2);
            
                nivelDificultad(5, &nivelPregunta);
                generacionPelea(jugador1);
                
                
                actualizarPuntaje(jugador1, 2, 2);
            
            }
			else{
				generacionEnemigo();  //grafico
            
                printf("OH NO UN ENEMIGO SALVAJE HA APARECIDO");
                nivelDificultad(jugador1->nivel, &nivelPregunta);
                generacionPelea(jugador1);
                
                actualizarPuntaje(jugador1, 2, nivelPregunta); //nivelPregunta
            }
        
        }  
        avanzarEnMapa(&jugador1);
        jugador1->nivel++;//nivel se actualiza acá
        
    }while(preguntarContinuar() && jugador1->nivel<9);
    
      if(jugador1->nivel == 9){
            
            printf("EL JEFE ESTA ENOJADO!");
            
            generacionPregunta(9);
            generacionPelea(jugador1);
            generacionPregunta(9);
            generacionPelea(jugador1);
            generacionPregunta(10);
            generacionPelea(jugador1);
      
      }
      else{
          printf("Hasta luego!");
          mostrarStats(*jugador1);
          exit(EXIT_SUCCESS);
      }  
}

//pregunta 1 (39/2)*2             respuesta<MAx && respuesta%2     int ((aleatorio%MAX)/2)*2 &sorteado%2
//a) b) c) d)           

void generacionPelea(tRegJugador* jugador1){
    char respuesta;
    bool respuestaIncorrecta;
	do{
	   	scanf("%c", &respuesta);
		if(respuestaCorrecta(respuesta)){
	   		respuestaIncorrecta=false;
	   	}
		else{
			respuestaIncorrecta=true;
			actualizarVida(jugador1, 2);
		}
	         
	}while(respuestaIncorrecta && jugador1->vida>0);
		        
	if(jugador1->vida==0){
	    printf("acabou caralho");//cambiar
	    mostrarStats(*jugador1);
	    exit(EXIT_SUCCESS);
	
	}
	
	jugador1->enemigosMatados++; //cuenta enemigos matados luego de comprobar que no perdio
}

bool preguntarContinuar(){
    
    char respuesta;
    do{
    	printf("Quieres avanzar al siguiente nivel? (S-Si o N-no)");
	    scanf("%c",&respuesta);
	    if(tolower(respuesta) == 's'){
	        return true;
	    }
    	if(tolower(respuesta) == 'n'){
    		return false;
    	}else{
    		printf("\nError al ingresar letra vuelva a ingresar");
    	}

    }while(tolower(respuesta) != 's' && (tolower(respuesta) != 'n'));
    
    
}
   
   
   
   
   
   
   
   
   
   
        
