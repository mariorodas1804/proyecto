//enemigos y BOSS

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
