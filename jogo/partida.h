//partida va a ser la biblioteca que llama a la mayoria de las otras funciones

#include "enemigos.h"


//Prototipado de funciones en Partida.h
void inicializadorDelJuego();
void procesoJuego(tRegJugador*);
void generacionPelea(tRegJugador*);
bool preguntarContinuar();
void intro();
void menu();
void creditos();



//variables globales generales
tRegJugador jugador;
int nivelPregunta, vidasRestantes;


void inicializadorDelJuego(){
    
    intro();
    abrirArchivos();
    menu();
    
};

void procesoJuego(tRegJugador* jugador1){
    
    int campaOTienda, cantidadPuntaje;
    inicializarStats(jugador1);
    jugador1->nivel=8;
    do{
        mostrarMapa(jugador1->nivel);
        
        if(jugador1->nivel==3 || jugador1->nivel==8){
            vidasRestantes=acumuladorVidas(*jugador1);
            graficoHud(vidasRestantes, jugador1->puntaje);
            do{
                printf("\nDesea ingresar al campamento para restaurar vida o a la tienda?(comodines)(1 o 2):\t");
                fflush(stdin);
                scanf("%d", &campaOTienda);
                switch(campaOTienda){
                    case 1:{
                        campamento();
                        actualizarVida(jugador1,1);
                    	break;
                    }
                    case 2:{
                        tienda(jugador1); 
                    	break;
                    }
                    default:printf("\nError opcion incorrecta, vuelva a ingresar\n");
                }   
            }while(campaOTienda!=1 && campaOTienda!=2);
            
            
        }
        else{
            if(jugador1->nivel==5){
                vidasRestantes=acumuladorVidas(*jugador1);
                sleep(3);
                system("cls");
                printf("OH NO, DOS ENEMIGOS DE ELITES HAN APARECIDO!!");
                sleep(2);
                mostrarMapa(55);
                generacionPregunta(vidasRestantes,jugador1->puntaje,5, &cantidadPuntaje);
                generacionPelea(jugador1);
            
                actualizarPuntaje(jugador1, 1, 2);
            
                generacionPregunta(vidasRestantes,jugador1->puntaje,5, &cantidadPuntaje);
                generacionPelea(jugador1);
                
                
                actualizarPuntaje(jugador1, 1, 2);
            
            }
			else{
                vidasRestantes=acumuladorVidas(*jugador1);
                printf("\nOH NO UN ENEMIGO SALVAJE HA APARECIDO");
                generacionPregunta(vidasRestantes,jugador1->puntaje,jugador1->nivel, &cantidadPuntaje);
                generacionPelea(jugador1);
                
                actualizarPuntaje(jugador1, 1, cantidadPuntaje); //nivelPregunta
            }
        
        }  
        jugador1->nivel++;//nivel se actualiza acá
        
    }while(preguntarContinuar() && jugador1->nivel<9);
    
      if(jugador1->nivel == 9){
            
            printf("EL JEFE ESTA ENOJADO!!");//cambiar
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
    	    printf("Ganaste!!");//cambiar
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
    	    mostrarStats(*jugador1);
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
       
void generacionPelea(tRegJugador* jugador1){
    char respuesta;
    bool respuestaIncorrecta, escudo=false;
    int opcion,i, cantidadPuntaje;
    
    if(jugador1->ventajaCambio){
        if(jugador1->ventajaEscudo){
            do{
               printf("\nPosee ambas ventajas\n1-Cambio pregunta\n2-Escudo\n3-No usar\n\n");
               fflush(stdin);
               scanf("\n%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nNueva pregunta:\n");
                       generacionPregunta(vidasRestantes,jugador1->puntaje, jugador1->nivel, &cantidadPuntaje);
                       actualizarVentaja(jugador1, 2, 1);
                       break;
                   }
                   case 2:{
                       printf("\nEscudo activado\n");
                       escudo=true;
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
    //    graficoPregunta(vidasRestantes, jugador1->puntaje);
        printf("\nIngrese respuesta: \t");
        do{
          fflush(stdin);
          scanf("%c", &respuesta);
          if(!esABCD(respuesta)){
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
    		    printf(" \nProtegido por el escudo!");
    		    printf("\n\n\n\t\tRESPUESTA INCORRECTA, SIGUES TENIENDO: %d VIDAS (responda devuelta)\n",vidasRestantes);
    		}else{
    		    printf("\n\n\n\t\tRESPUESTA INCORRECTA, PERDISTE UNA VIDA TE QUEDAN: %d (responda devuelta)\n",vidasRestantes-1);
    		    actualizarVida(jugador1, 2);
    		}
    	}
        escudo=false;	         
	}while(respuestaIncorrecta && acumuladorVidas(*jugador1)>0);


	if(acumuladorVidas(*jugador1)==0){
	    sleep(2);
	    system("cls");
	    printf("Perdiste!!");//cambiar
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
	    mostrarStats(*jugador1);
	    creditos();
	}
	
	jugador1->enemigosMatados++; //cuenta enemigos matados luego de comprobar que no perdio
}

bool preguntarContinuar(){
    
    char respuesta;
    do{
    	printf("\nQuieres avanzar al siguiente nivel? (S-Si o N-no)\t");
    	fflush(stdin);
	    scanf("%c",&respuesta);
	    if(tolower(respuesta) == 's'){
	        return true;
	    }
    	if(tolower(respuesta) == 'n'){
    		return false;
    	}else{
    		printf("\nError al ingresar letra vuelva a ingresar\n");
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
    
    printf("\n\nEste juego fue desarrollado y tiene los derechos reservados a Fabricio Gonzalez Oviedo y Mario Daniel Rodas.");
    printf("\n\tPara la materia AED II de la carrera LSI de la UNNE. (24/11/2025)\n\n");
    sleep(3);
    system("pause");
    exit(EXIT_SUCCESS);
}

void menu(){
    int seleccion;
    tRegJugador jugador;
    do{
       printf("\n\n\t1-Empezar\n\t2-Instrucciones\n\t3-Salir\n\n");
       fflush(stdin);
       scanf("%d",&seleccion);
       switch(seleccion){
           case 1:{
               system("cls");
               printf("Cargando.");
               sleep(1);
               system("cls");
               printf("Cargando..");
               sleep(1);
               system("cls");
               printf("Cargando...");
               sleep(2);
               system("cls");
               printf("Que empiece el juego >:D");
               sleep(1);
               system("cls");
               procesoJuego(&jugador);
           	break;
           }
           case 2:{
               printf("Este juego basico es basado un juego estilo roguelite, en el que principalmente se trata de generaciones aleatorias de \npreguntas con un sistema de vidas y ventajas en el que errar cada pregunta te resta 1 de vida, y responder \ncorrectamente te suma puntaje en el que se acumula hasta el final de la partida.\nTales ventajas pueden ser: Escudo(te libra de 1 de danio al errar una pregunta), Cambio(cambia la pregunta una vez \nseleccionada).\nLos niveles de enemigos(preguntas), varian de nivel de dificultad y posiblemente te encuentres con un enemigo o varios \ny al final de la run te encontraras contra un jefe, en el que cuidado! puede o no ser dificil.\nA lo largo del camino te encontraras con campamentos en el que restauraran 1 vida o tiendas en el que podras canjear \npuntos por alguna ventaja(no se pueden tener la misma mas de una vez).\nPor favor disfruta y recuerda que solo es un juego, no te frustres que todo se aprende disfrutando un poco mas.:)");
           	break;
           }
           case 3:{
               creditos();
           	break;
           }default:printf("Eleccion incorrecta");
       }   
    }while(seleccion!=3);
    
}
       
