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
void intro();
void menu();
void creditos();

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
    
    intro():
    abrirArchivos();
    generacionMapa();
    menu();
    
};

void procesoJuego(tRegJugador* jugador1){
    
    int campaOTienda, cantidadPuntaje;
    
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
                generacionPregunta(5, &cantidadPuntaje);
                generacionPelea(jugador1);
            
                actualizarPuntaje(jugador1, 2, 2);
            
                generacionPregunta(5, &cantidadPuntaje);
                generacionPelea(jugador1);
                
                
                actualizarPuntaje(jugador1, 2, 2);
            
            }
			else{
				generacionEnemigo();  //grafico
            
                printf("OH NO UN ENEMIGO SALVAJE HA APARECIDO");
                generacionPregunta(jugador1->nivel, &cantidadPuntaje);
                generacionPelea(jugador1);
                
                actualizarPuntaje(jugador1, 2, cantidadPuntaje); //nivelPregunta
            }
        
        }  
        avanzarEnMapa(&jugador1);
        jugador1->nivel++;//nivel se actualiza acá
        
    }while(preguntarContinuar() && jugador1->nivel<9);
    
      if(jugador1->nivel == 9){
            
            printf("EL JEFE ESTA ENOJADO!");
            
            generacionPregunta(9, &cantidadPuntaje);
            generacionPelea(jugador1);
            generacionPregunta(9, &cantidadPuntaje);
            generacionPelea(jugador1);
            generacionPregunta(10, &cantidadPuntaje);
            generacionPelea(jugador1);
            
            printf("Haz vencido al jefe");
            creditos();
      }
      else{
          printf("Hasta luego!");
          mostrarStats(*jugador1);
          system("cls");
          creditos();
          exit(EXIT_SUCCESS);
      }  
}

//pregunta 1 (39/2)*2             respuesta<MAx && respuesta%2     int ((aleatorio%MAX)/2)*2 &sorteado%2
//a) b) c) d)           

void generacionPelea(tRegJugador* jugador1){
    char respuesta;
    bool respuestaIncorrecta, escudo=false;
    int opcion;
    
    if(jugador1->ventajaCambio){
        if(jugador1->ventajaEscudo){
            do{
               printf("Posee ambas ventajas\n1-Cambio pregunta\n2-Escudo\n3-No usar\n");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nNueva pregunta:\n");
                       generacionPregunta(jugador1->nivel);
                       actualizarVentaja(jugador1, 2, 1);
                       break;
                   }
                   case 2:{
                       printf("\nEscudo activado");
                       escudo=true;
                       actualizarVentaja(jugador1, 2, 2);
       	               break;
                   }
                   case 3:{
                       printf("\nNo se utilizara nada");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=4);
            
        }else{
            
            do{
               printf("Posee Ventaja cambio \n1-Usar\n2-No usar");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nNueva pregunta:\n");
                       generacionPregunta(jugador1->nivel);
                       actualizarVentaja(jugador1, 2, 1);
                       break;
                   }
                   case 2:{
                       printf("\nNo se utilizara nada");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=3);
        }
        
    }else{
        if(jugador1->ventajaEscudo){
            do{
               printf("Posee Ventaja escudo \n1-Usar\n2-No usar");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nEscudo activado");
                       escudo=true;
                       actualizarVentaja(jugador1, 2, 2);
       	               break;
                   }
                   case 2:{
                       printf("\nNo se utilizara nada");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=3);
            
        }  
    }
    
	do{
       	scanf("%c", &respuesta);
    	if(respuestaCorrecta(respuesta)){
    	    printf("\nRespuesta correcta! Puede avanzar.");
       		respuestaIncorrecta=false;     		
       	}
    	else{
    	    printf("\nRespuesta incorrecta!");
    		respuestaIncorrecta=true;
    		if(escudo){
    		    printf(" \nProtegido por el escudo!");
    		}else{
    		    actualizarVida(jugador1, 2);
    		}
    	}
        escudo=false;	         
	}while(respuestaIncorrecta && jugador1->vida>0);


	if(jugador1->vida==0){
	    printf("acabou caralho");//cambiar
	    mostrarStats(*jugador1);
	    creditos();
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


void intro(){
    
    printf("Hola! bienvenido al juego slay the algorithm!");
    

    printf("\n\n\n\t Disfrutalo!");
    sleep(3);
    system("cls");
}
void creditos(){
    
    printf("Este juego fue desarrollado y tiene los derechos reservados a Fabricio Gonzalez Oviedo y Mario Daniel Rodas.");
    printf("\n\tPara la materia AED II de la carrera LSI de la UNNE. (24/11/2025)");
    sleep(3);
    system("pause");
    exit(EXIT_SUCCESS);
}
void menu(){
    int seleccion;
    tRegJugador jugador;
    do{
       printf("\n\t1-Empezar\nt2-Instrucciones\n\t3-Salir");
       scanf("%d",&seleccion);
       switch(seleccion){
           case 1:{
               printf("Cargando...");
               sleep(1);
               ystem("cls");
               printf("Cargando..");
               sleep(1);
               ystem("cls");
               printf("Cargando.");
               sleep(2);
               printf("Que empiece el juego >:D");
               sleep(1);
               system("cls");
               procesoJuego(&jugador);
           	break;
           }
           case 2:{
               printf("Este juego basico es basado un juego estilo roguelite, en el que principalmente se trata de generaciones aleatorias de preguntas con un sistema de vidas y ventajas en el que errar cada pregunta te resta 1 de vida, y responder correctamente te suma puntaje en el que se acumula hasta el final de la partida.\nTales ventajas pueden ser: Escudo(te libra de 1 de danio al errar una pregunta), Cambio(cambia la pregunta una vez seleccionada).\nLos niveles de enemigos(preguntas), varian de nivel de dificultad y posiblemente te encuentres con un enemigo o varios y al final de la run te encontraras contra un jefe, en el que cuidado! puede o no ser dificil.\nA lo largo del camino te encontraras con campamentos en el que restauraran 1 vida o tiendas en el que podras canjear puntos por alguna ventaja(no se pueden tener la misma mas de una vez).\nPor favor disfruta y recuerda que solo es un juego, no te frustres que todo se aprende disfrutando un poco mas.:)");
           	break;
           }
           case 3:{
               creditos();
           	break;
           }default:printf("Eleccion incorrecta");
       }   
    }while(seleccion!=3);
    
}
   
   
   
   
   
   
   
   
   
   
        
