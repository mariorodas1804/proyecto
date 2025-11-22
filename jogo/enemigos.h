//enemigos y BOSS
#include "grafico.h"
#define TAMANIOVECTORPREGUNTAS 40
#define TAMANIOVECTORRESPUESTAS 20

typedef char tString [200];

typedef struct{
    tString pregunta;
}tRegArchivo;

//global para guardar la opcion correcta y compararla
char correcta;
int vidasRestantes, cantidadPuntaje;


//Tipos de datos para vectores con preguntas y respuestas
typedef tString tVectorPreguntas[TAMANIOVECTORPREGUNTAS];
typedef char tVectorRespuestas[TAMANIOVECTORRESPUESTAS];

//variables globales de vectores con preguntas y respuestas
tVectorPreguntas vectorPreguntasFaciles, vectorPreguntasNormales, vectorPreguntasDificiles;
tVectorRespuestas vectorRespuestasFaciles, vectorRespuestasNormales, vectorRespuestasDificiles;

//Prototipado
void traerArchivoTexto(FILE*, tVectorRespuestas, int);
void traerArchivoBinario(FILE*, tVectorPreguntas, int);
void abrirArchivos();
//Preguntas
void nivelDificultad(int, int, int);
void generacionPregunta(int, int, int, int*);
bool respuesta(char);
bool esABCD(char);

//Peleas
void generacionPelea(tRegJugador*);
void peleaElite(tRegJugador*);
void peleaNormal(tRegJugador*);
void peleaBoss(tRegJugador*);


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

    return pEleccion == pRespuesta;
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

void traerArchivoBinario(FILE* archivo, tVectorPreguntas pVector, int pIndice){
    // Caso base el final del vector(por las dudas)
    if (pIndice >= TAMANIOVECTORPREGUNTAS || feof(archivo)) {
        return;
    }
    
    tRegArchivo regPreguntas;
    
    if (fread(&regPreguntas, sizeof(tString), 1, archivo) == 1) {
        strcpy(pVector[pIndice], regPreguntas.pregunta);
        
        //Llamada recursiva
        traerArchivoBinario(archivo, pVector, pIndice + 1);
    }
}

void traerArchivoTexto(FILE* archivo, tVectorRespuestas pVector, int pIndice){
    // Caso base final del vector o del archivo(por las dudas)
    if (pIndice >= TAMANIOVECTORRESPUESTAS || feof(archivo)) {
        return;
    }
    
    char caracter = fgetc(archivo);
    
    // Si no es el fin del archivo guardamos y seguimos
    if (caracter != EOF) {
        pVector[pIndice] = caracter;
        
        traerArchivoTexto(archivo, pVector, pIndice + 1);
    }
}

//archivos dat externos con preguntas y respuestas
void abrirArchivos(){
    
    FILE * archivoPreguntas;
    FILE * archivoRespuestas;
    //Se traen del archivo externos las preguntas de las 3 dificultades
    archivoPreguntas = fopen("preguntasFaciles.dat", "rb");
    if (archivoPreguntas != NULL) {
        traerArchivoBinario(archivoPreguntas, vectorPreguntasFaciles, 0);
        fclose(archivoPreguntas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
    archivoPreguntas = fopen("preguntasNormales.dat", "rb");
    if (archivoPreguntas != NULL) {
        traerArchivoBinario(archivoPreguntas, vectorPreguntasNormales, 0);
        fclose(archivoPreguntas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
    archivoPreguntas = fopen("preguntasDificiles.dat", "rb");
    if (archivoPreguntas != NULL) {
        traerArchivoBinario(archivoPreguntas, vectorPreguntasDificiles, 0);
        fclose(archivoPreguntas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
    
    
    //Se traen del archivo externos las respuestas de las 3 dificultades
    archivoRespuestas = fopen("respuestasFaciles.txt", "r");
    if (archivoRespuestas != NULL) {
        traerArchivoTexto(archivoRespuestas, vectorRespuestasFaciles, 0);
        fclose(archivoRespuestas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
    archivoRespuestas = fopen("respuestasNormales.txt", "r");
    if (archivoRespuestas != NULL) {
        traerArchivoTexto(archivoRespuestas, vectorRespuestasNormales, 0);
        fclose(archivoRespuestas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
    archivoRespuestas = fopen("respuestasDificiles.txt", "r");
    if (archivoRespuestas != NULL) {
        traerArchivoTexto(archivoRespuestas, vectorRespuestasDificiles, 0);
        fclose(archivoRespuestas);
    } else {
        printf("Error: No se pudo abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    
}

//Funcion que sucede una pelea doble
void peleaElite(tRegJugador* jugador1){

    vidasRestantes=acumuladorVidas(*jugador1);
    sleep(3);
    system("cls");
    printf("OH NO, DOS ENEMIGOS DE ELITES HAN APARECIDO!!");
    sleep(2);
    mostrarMapa(55);
    generacionPregunta(vidasRestantes,jugador1->puntaje,5, &cantidadPuntaje); 
    generacionPelea(jugador1); 
    
    actualizarPuntaje(jugador1, 1, 2); //se actualiza segun avance el jugador
    
    generacionPregunta(vidasRestantes,jugador1->puntaje,5, &cantidadPuntaje);  //
    generacionPelea(jugador1);                                                 //
    
    
    actualizarPuntaje(jugador1, 1, 2);                                         // Sucedede 2 veces

}

void peleaNormal(tRegJugador* jugador1){
    
    //Lo mismo que pelea elite solo que una sola pelea
    vidasRestantes=acumuladorVidas(*jugador1);
    printf("\nOH NO UN ENEMIGO SALVAJE HA APARECIDO");
    generacionPregunta(vidasRestantes,jugador1->puntaje,jugador1->nivel, &cantidadPuntaje);
    generacionPelea(jugador1);
    
    actualizarPuntaje(jugador1, 1, cantidadPuntaje);
}

//Funcion de pelea del Boss
void peleaBoss(tRegJugador* jugador1){
    
    printf("EL JEFE ESTA ENOJADO!!");
    sleep(1);
    system("cls");
    printf("\n\n\t\t\tEL JEFE ESTA ENOJADO!!!!");
    sleep(1);
    system("cls");
    printf("\n\tEL JEFE ESTA ENOJADO!!!!");
    sleep(1);
    system("cls");
    printf("\t\t\t\tEL JEFE ESTA ENOJADO!!!!");
    sleep(1);
    vidasRestantes=acumuladorVidas(*jugador1);
    mostrarMapa(9);
    generacionPregunta(vidasRestantes,jugador1->puntaje,9, &cantidadPuntaje);
    generacionPelea(jugador1);
    jugador1->enemigosMatados--;
    actualizarPuntaje(jugador1, 1, cantidadPuntaje);
    mostrarMapa(10);
    generacionPregunta(vidasRestantes,jugador1->puntaje,9, &cantidadPuntaje);
    generacionPelea(jugador1);
    jugador1->enemigosMatados--;
    actualizarPuntaje(jugador1, 1, cantidadPuntaje);
    mostrarMapa(11);
    generacionPregunta(vidasRestantes,jugador1->puntaje,9, &cantidadPuntaje);
    generacionPelea(jugador1);
    actualizarPuntaje(jugador1, 1, cantidadPuntaje);
    mostrarMapa(12);
    printf("Haz vencido al jefe");
    sleep(2);
    system("cls");
    printf("Ganaste!!");
    sleep(1);
    system("cls");
    printf("\n\n\t\t\tGanaste!!!!");
    sleep(1);
    system("cls");
    printf("\n\tGanaste!!!!");
    sleep(1);
    system("cls");
    printf("\t\t\t\tGanaste!!!!");
    sleep(1);
    system("cls");
    printf("\tGanaste!!!!");
    
    //Al igual que las demas peleas se desarrollan 3 preguntas dificiles al jugador
}

//Funcion de la generacion de la pelea
void generacionPelea(tRegJugador* jugador1){
    //generacion de locales para utilizarlas
    char respuesta;
    bool respuestaIncorrecta, escudo=false;
    int opcion,i, cantidadPuntaje;
    
    if(jugador1->ventajaCambio){ //se estructura un sistema de preguntas en la que el jugador tiene la posibilidad de usar una de las dos ventajas
        if(jugador1->ventajaEscudo){
            do{
               printf("\nPosee ambas ventajas\n1-Cambio pregunta\n2-Escudo\n3-No usar\n\n");
               fflush(stdin);
               scanf("\n%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nNueva pregunta:\n");
                       generacionPregunta(vidasRestantes,jugador1->puntaje, jugador1->nivel, &cantidadPuntaje); //pregunta nueva
                       actualizarVentaja(jugador1, 2, 1);
                       break;
                   }
                   case 2:{
                       printf("\nEscudo activado\n");
                       escudo=true; //Activacion del escudo
                       actualizarVentaja(jugador1, 2, 2);
       	               break;
                   }
                   case 3:{
                       printf("\nNo se utilizara nada\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto\n");
               }
            }while(opcion!=1 && opcion!=2 && opcion!=3);
            
        }else{
            
            do{
               printf("\nPosee Ventaja cambio \n1-Usar\n2-No usar\n");
               fflush(stdin);
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nNueva pregunta:\n");
                       generacionPregunta(vidasRestantes,jugador1->puntaje, jugador1->nivel, &cantidadPuntaje);
                       actualizarVentaja(jugador1, 2, 1);
                       break;
                   }
                   case 2:{
                       printf("\nNo se utilizara nada\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto\n");
               }
            }while(opcion!=1 && opcion!=2);
        }
        
    }else{
        if(jugador1->ventajaEscudo){
            do{
               printf("\nPosee Ventaja escudo \n1-Usar\n2-No usar\n");
               fflush(stdin);
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nEscudo activado\n");
                       escudo=true;
                       actualizarVentaja(jugador1, 2, 2);
       	               break;
                   }
                   case 2:{
                       printf("\nNo se utilizara nada\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto\n");
               }
            }while(opcion!=1 && opcion!=2);
        }  
    }
    
	do{
	    vidasRestantes=acumuladorVidas(*jugador1);

        printf("\nIngrese respuesta: \t");
        do{
          fflush(stdin);
          scanf("%c", &respuesta);   //se guarda la opcion elegida
          if(!esABCD(respuesta)){    //se activa la comprobacion
             printf("\nElegista una letra equivocada, ingrese denuevo\n");
          }
        }while(!esABCD(respuesta));
           
    	if(respuestaCorrecta(tolower(respuesta), correcta)){
    	    printf("\nRespuesta correcta! Puede avanzar.\n");
       		respuestaIncorrecta=false;     		
       	}
    	else{
    		respuestaIncorrecta=true;
    		if(escudo){
    		    printf(" \nProtegido por el escudo!"); //en caso de tener la ventaja se activa
    		    printf("\n\n\n\t\tRESPUESTA INCORRECTA, SIGUES TENIENDO: %d VIDAS (responda devuelta)\n",vidasRestantes);
    		}else{
    		    printf("\n\n\n\t\tRESPUESTA INCORRECTA, PERDISTE UNA VIDA TE QUEDAN: %d (responda devuelta)\n",vidasRestantes-1);
    		    actualizarVida(jugador1, 2);
    		}
    	}
        escudo=false;// si se utilizo la ventaja entonces pasa a perderla	         
	}while(respuestaIncorrecta && acumuladorVidas(*jugador1)>0);

    //Comparacion de la vida al llegar a 0 se activa el endgame
	if(acumuladorVidas(*jugador1)==0){
	    sleep(2);
	    system("cls");
	    printf("Perdiste!!");
	    sleep(1);
	    system("cls");
	    printf("\n\n\t\t\tPerdiste!!");
	    sleep(1);
	    system("cls");
	    printf("\n\tPerdiste!!");
	    sleep(1);
	    system("cls");
	    printf("\t\t\t\tPerdiste!!");
	    sleep(1);
	    system("cls");
	    printf("\tPerdiste!!");
	    char nombreJugador[MAX];
        printf("\nIngresa tu nombre para el ranking: ");
        fflush(stdin);
        fgets(nombreJugador, MAX, stdin);
        nombreJugador[strcspn(nombreJugador, "\n")] = 0; // Quitar \n
        
        agregarAlRanking(&ranking, *jugador1, &nombreJugador);
        guardarRankingEnArchivo(ranking, &archivoRanking);
        printf("Jugador '%s' agregado al ranking con %d puntos\n", nombreJugador, jugador1->puntaje);
        
        printf("\nEste es el ranking: ");
        
        graficarTop10(ranking);
        printf("\n");
	    system("pause");
	    mostrarStats(*jugador1);
	    creditos();
	}
	
	jugador1->enemigosMatados++; //cuenta enemigos matados luego de comprobar que no perdio
}
