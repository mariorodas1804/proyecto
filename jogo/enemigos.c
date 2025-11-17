//enemigos y BOSS

#include "partida.h"

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
    int codPreg;
    tString pregunta;
    tString respuestaA;
    tString respuestaB;
    tString respuestaC;
    tString respuestaD;
}tPreguntas;

typedef struct{
    int codPreg;
    tString respuesta;
}tRespuestas;

//a b c d

//se va a guardar un registro de tipo tPreguntas con la linea correspondiente a la pregunta que toco
//tambien se guarda un registro de tipo trespuestas con la respuesta correcta
//fread(&regPregunta);fread(&regRepuesta)

//scanf(char, respuesta);
//tolower(respuesta);

switch (grado) {
        case 'a':
            if(regPregunta.respuestaA==regRespuesta.respuesta){
                return false;
            }
            else{
                perdervida();
                return true;
            }
            break;
        case 'b':
            if(regPregunta.respuestaB==regRespuesta.respuesta){
                return false;
            }
            else{
                perdervida();
                return true;
            }
            break;
        case 'c':
        	break;
            if(regPregunta.respuestaC==regRespuesta.respuesta){
                return false;
            }
            else{
                perdervida()
                return true;
            }
            break;
        case 'd':
            if(regPregunta.respuestaD==regRespuesta.respuesta){
                return false;
            }
            else{
                perdervida()
                 return true;
            }
        	break;
        
        default:
            printf("PUSISTE MAL LA LETRA\n");
            }



void preguntaAleatoria();
void preguntaBoss();


void preguntaAleatoria(){
     do{
            generacionPregunta(nivelEnemigo){
                                 printf(pregunta);
                                 printf(respuestas);
                                 scanf(respuesta);
            
                                 repuestaCorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
            }
        }while(respuestaIncorrecta);
}


generacionPregunta(jugador1.nivel pNivel){
    void generacionPregunta(int pNivel, int *pNivelPregunta){
        
        switch (pNivel){
            //Enemigos normales
            case 1:{
                generacionPregunta(2)
                pNivelPregunta=2;
                break;
            }
            case 2:{
                generacionPregunta(2)
                pNivelPregunta=2;
                break;
            }
            case 4: {
                generacionPregunta(1)
            	pNivelPregunta=1;
                break;
            }
            case 6: {
                generacionPregunta(1)
            	pNivelPregunta=1;
                break;
            }
            case 7:{
                generacionPregunta(2)
            	pNivelPregunta=2;
                break;
            }
            //Enemigos Elite
            case 5: {
                pregunta nivel (2)
            	pNivelPregunta=2;
                break;
            }
            //BOSS
            case 9:{
                generacionPregunta(3)
                pNivelPregunta=3;
                break;
            }
            case 10:{
                generacionPregunta(4)
                pNivelPregunta=4;
                break;
            }
        }
    }
}
