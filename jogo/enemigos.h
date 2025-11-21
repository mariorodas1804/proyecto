//enemigos y BOSS
#include "grafico.h"
#include "mapa.h"
#define TAMANIOVECTORPREGUNTAS 40
#define TAMANIOVECTORRESPUESTAS 20

typedef char tString [200];

typedef struct{
    tString pregunta;
}tRegArchivo;

//global para guardar la opcion correcta y compararla
char correcta;


//Tipos de datos para vectores con preguntas y respuestas
typedef tString tVectorPreguntas[TAMANIOVECTORPREGUNTAS];
typedef char tVectorRespuestas[TAMANIOVECTORRESPUESTAS];

//variables globales de vectores con preguntas y respuestas
tVectorPreguntas vectorPreguntasFaciles, vectorPreguntasNormales, vectorPreguntasDificiles;
tVectorRespuestas vectorRespuestasFaciles, vectorRespuestasNormales, vectorRespuestasDificiles;

//Prototipado
void abrirArchivos();
void nivelDificultad(int, int, int);
void generacionPregunta(int, int, int, int*);
bool respuesta(char);
bool esABCD(char);

//Funcion para que no ingrese una letra equivocada el usuario
bool esABCD(char pLetra){
    if(tolower(pLetra)=='a' || tolower(pLetra)=='b' || tolower(pLetra)=='c' || tolower(pLetra)=='d'){
        return true;
    }
    else{
        return false;
    }
}

//Funcion para comprobar si la respuesta es la correcta
//Por parametro se pasa la eleccion del usuario y la resp correcta
bool respuestaCorrecta(char pEleccion, char pRespuesta){
     switch (pEleccion) {
        case 'a':{
            if(pEleccion!=pRespuesta){
                return false;
            }
            else{
                return true;
            }
            break;
        }
            
        case 'b':{
            if(pEleccion!=pRespuesta){
                return false;
            }
            else{
                return true;
            }
            break;
        }
            
        case 'c':{
            if(pEleccion!=pRespuesta){
                return false;
            }
            else{
                return true;
            }
            break;
        }
        case 'd':{
        	if(pEleccion!=pRespuesta){
                return false;
            }
            else{
                 return true;
            }
        	break;
        }
            
     }
}

//Funcion utilizada en generacionPregunta
void nivelDificultad(int pDificultad, int pVidas, int pPuntaje){
    int numeroAleatorio=(rand()%40)/2; //utilizamos un numero aleatorio entre cero y 39
                                       //y lo dividimos por dos pues solo hay 20 preguntas por dificultad + 20 conjunto de opciones
    printf("\n");
    printf("\n"); //salteado de linea general
    printf("\n");
    switch(pDificultad){ //se ingresa al vector correspindiente de la dificultad
     case 1:{
          printf("%s\n\n", vectorPreguntasFaciles[numeroAleatorio*2]); //Logica de n*2 ya que en los numeros pares estan guardadas las preguntas
          printf("\t\t%s", vectorPreguntasFaciles[(numeroAleatorio*2)+1]); //(n*2)+1 en el siguiente de la pregunta se encuentra las opciones
          correcta=vectorRespuestasFaciles[numeroAleatorio];
     	  break;
     }
     case 2:{
          printf("%s\n\n", vectorPreguntasNormales[numeroAleatorio*2]);
          printf("\t\t%s", vectorPreguntasNormales[(numeroAleatorio*2)+1]);
          correcta=vectorRespuestasNormales[numeroAleatorio];
     	  break;
     }
     case 3:{
          printf("%s\n\n", vectorPreguntasDificiles[numeroAleatorio*2]);
          printf("\t\t%s", vectorPreguntasDificiles[(numeroAleatorio*2)+1]);
          correcta=vectorRespuestasDificiles[numeroAleatorio];
     	  break;
     }
    }  
    printf("\n\n\n\n");
    printf("-------------------------------------------------------------------------------------------------------------");
    printf("\n|Vida: %d                                                                                        Puntaje: %3d|",pVidas,pPuntaje);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n***********************************************************************************************************************");
}

//Funcion en la que se desarrollan las preguntas
void generacionPregunta(int pVida,int pPuntaje,int pNivel, int *pNivelPregunta){
         /*
         Las preguntas se generan dependiendo del parametro nivel del jugador
         La variable nivel pregunta se utiliza para poder actualizar el puntaje segun el nivel de la pregunta
         Puntaje y vida simplemente se pasan para poder graficar
         
         */
    switch (pNivel){
        //Las dificultades estan definidas por nosotros segun la fase o nivel en el que se encuentre el jugador
        //Enemigos normales
        case 1:{
            nivelDificultad(2, pVida, pPuntaje);
            *pNivelPregunta=2;
            break;
        }
        case 2:{
            nivelDificultad(2, pVida, pPuntaje);
            *pNivelPregunta=2;
            break;
        }
        case 4: {
            nivelDificultad(1, pVida, pPuntaje);
        	*pNivelPregunta=1;
            break;
        }
        case 6: {
            nivelDificultad(1, pVida, pPuntaje);
        	*pNivelPregunta=1;
            break;
        }
        case 7:{
            nivelDificultad(2, pVida, pPuntaje);
        	*pNivelPregunta=2;
            break;
        }
        //Enemigos Elite
        case 5: {
            nivelDificultad(2, pVida, pPuntaje);
        	*pNivelPregunta=2;
            break;
        }
        //BOSS
        case 9:{
            nivelDificultad(3, pVida, pPuntaje);
            *pNivelPregunta=3;
            break;
        }
    }
}

//archivos dat externos con preguntas y respuestas

void abrirArchivos(){
    FILE * archivoPreguntas;
    FILE * archivoRespuestas;
    tRegArchivo regPreguntas;
    int i;
    char respuestas;
    archivoPreguntas=fopen("preguntasFaciles.dat", "rb"); // estructuracion de archivo binario
    for (i=0; i<TAMANIOVECTORPREGUNTAS; i++){ 
        fread(&regPreguntas, sizeof(tString), 1, archivoPreguntas);//Solo se puede utilizar con registros, por eso se crea tRegArchivo
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
    
    archivoRespuestas=fopen("respuestasFaciles.txt","r"); // estructuracion de archivo txt
    for (i = 0; i < TAMANIOVECTORRESPUESTAS && !feof(archivoRespuestas); i++) {
        vectorRespuestasFaciles[i] = fgetc(archivoRespuestas);
    }
    archivoRespuestas=fopen("respuestasNormales.txt","r");
    for (i = 0; i < TAMANIOVECTORRESPUESTAS && !feof(archivoRespuestas); i++) {
        vectorRespuestasNormales[i] = fgetc(archivoRespuestas);
    }
    archivoRespuestas=fopen("respuestasDificiles.txt","r");
    for (i = 0; i < TAMANIOVECTORRESPUESTAS && !feof(archivoRespuestas); i++) {
        vectorRespuestasDificiles[i] = fgetc(archivoRespuestas);
    }
    
}
