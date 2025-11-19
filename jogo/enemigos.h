//enemigos y BOSS

#include "mapa.h"
#define TAMANIOVECTORPREGUNTAS 40
#define TAMANIOVECTORRESPUESTAS 20

typedef char tString [60];

typedef struct{
    tString pregunta;
}tRegArchivo;

typedef bool tVector [3];

typedef struct{
    
    int dificultad;
    int pregunta;
    char respuestaCorrecta;
    
    
}tEnemigo;

typedef struct{
    
    int preguntaBoss;
    char respuestaCorrectaBoss;
  //  tVector vida;
    
}tBoss;

typedef struct{
    tString pregunta;
    tString respuestaA;
    tString respuestaB;
    tString respuestaC;
    tString respuestaD;
}tPreguntas;

char correcta;


//Tipos de datos para vectores con preguntas y respuestas
typedef tString tVectorPreguntas[TAMANIOVECTORPREGUNTAS];
typedef char tVectorRespuestas[TAMANIOVECTORRESPUESTAS];

//variables globales de vectores con preguntas y respuestas
tVectorPreguntas vectorPreguntasFaciles, vectorPreguntasNormales, vectorPreguntasDificiles;
tVectorRespuestas vectorRespuestasFaciles, vectorRespuestasNormales, vectorRespuestasDificiles;

//archivos dat externos con preguntas y respuestas
FILE * archivoPreguntas;
FILE * archivoRespuestas;

//a b c d

//se va a guardar un registro de tipo tPreguntas con la linea correspondiente a la pregunta que toco
//tambien se guarda un registro de tipo trespuestas con la respuesta correcta
//fread(&regPregunta);fread(&regRepuesta)

//scanf(char, respuesta);
//tolower(respuesta);

void abrirArchivos();
void nivelDificultad(int, int, int);
void generacionPregunta(int, int, int, int*);
bool respuesta(char);
bool esABCD(char);

bool esABCD(char pLetra){
    if(tolower(pLetra)=='a' || tolower(pLetra)=='b' || tolower(pLetra)=='c' || tolower(pLetra)=='d'){
        return true;
    }
    else{
        return false;
    }
}

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

void nivelDificultad(int pDificultad, int pVidas, int pPuntaje){
    int numeroAleatorio=rand()/2;
    printf("\n");//hud
    printf("\n");
    printf("\n");
    switch(pDificultad){
     case 1:{
          printf("%s\n\n", vectorPreguntasFaciles[numeroAleatorio*2]);
          printf("\t\t\t\t\t%s", vectorPreguntasFaciles[(numeroAleatorio*2)+1]);
          correcta=vectorRespuestasFaciles[numeroAleatorio];
     	  break;
     }
     case 2:{
          printf("%s\n\n", vectorPreguntasNormales[numeroAleatorio*2]);
          printf("\t\t\t\t\t%s", vectorPreguntasNormales[(numeroAleatorio*2)+1]);
          correcta=vectorRespuestasNormales[numeroAleatorio];
     	  break;
     }
     case 3:{
          printf("%s\n\n", vectorPreguntasDificiles[numeroAleatorio*2]);
          printf("\t\t\t\t\t%s", vectorPreguntasDificiles[(numeroAleatorio*2)+1]);
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


void generacionPregunta(int pVida,int pPuntaje,int pNivel, int *pNivelPregunta){
         
    switch (pNivel){
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

void abrirArchivos(){}
