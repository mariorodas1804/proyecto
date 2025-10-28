//enemigos y BOSS
#include "librerias.h"
#include "jugador.h"
#include "preguntas.h"
#include "mapa.h"
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

a b c d

//se va a guardar un registro de tipo tPreguntas con la linea correspondiente a la pregunta que toco
//tambien se guarda un registro de tipo trespuestas con la respuesta correcta
//fread(&regPregunta);fread(&regRepuesta)

scanf(char, respuesta);
tolower(respuesta);

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





void preguntaBoss(int pnivel){
     do{
            generacionPregunta(pnivel){
                                 printf(pregunta);
                                 printf(respuestas);
                                 scanf(respuesta);
            
                                 repuestaCorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
            }
        }
        while(respuestaIncorrecta);
        
        puntuacion+pnivel;
/*    //preguntaBoss2()    
         do{
            generacionPregunta(dificultad3){
                                 printf(pregunta);
                                 printf(respuestas);
                                 scanf(respuesta);
            
                                 repuestaCorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
            }
        }while(respuestaIncorrecta);
        
        puntuacion+3;
    //preguntaBoss3()    
         do{
            generacionPregunta(dificultad4){
                                 printf(pregunta);
                                 printf(respuestas);
                                 scanf(respuesta);
            
                                 repuestaCorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
            }
        }while(respuestaIncorrecta);
        
        puntuacion+4;
        */
}
