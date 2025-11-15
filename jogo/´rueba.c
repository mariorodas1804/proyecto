#include <stdio.h>
int main(){
    
    void generacionPregunta(int pNivel, int *pNivelPregunta){
        
        switch (pNivel){
            case 1:{
                generacionPregunta(2)
                pNivelPregunta=2;
                break;
            }
            case (2):{
                generacionPregunta(2)
                return 2;
            }
            case 4: {
                generacionPregunta(1)
            	return 1;
            }
            case 5: {
                pregunta nivel (2)
            	return 2;
            }
            case 6: {
                generacionPregunta(1)
            	return 1;
            }
            case 7:{
                generacionPregunta(2)
            	return 2;
            }
            //BOSS
            case 9:{
                generacionPregunta(3)
                return 3;
            }
            case 10:{
                generacionPregunta(4)
                return 4;
            }
        }
    }
}

Abrirarchivos(){
    preguntas=fopen("preguntasFaciles.dat")
    for (i=0;){
        fread()
        vectorPreguntasFaciles[i];
    }
    preguntas=fopen("preguntasNormales.dat")
    for (i=0;){
        fread()
        vectorPreguntasNormales[i];
    }
}
