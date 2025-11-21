#include "jugador.h"


//Apartado en el que se tratan lo que serian los eventos especiales del juego
void campamento(tRegJugador*);
void tienda(tRegJugador*);

//Funcion que cumple el evento especial de campamento
void campamento(tRegJugador *jugador1){
    
     printf("Curandote...");
     sleep(3);
     actualizarVida(jugador1,1); //mismo caso que la actualizarVentaja 1 para sumar
}

//Funcion que cumple el evento especial de tienda
void tienda(tRegJugador *jugador1){
    int opcion;
    if(!jugador1->ventajaCambio){ //Preguntas acerca de si posee alguna de las ventajas
        if(!jugador1->ventajaEscudo){
            do{
               printf("\nNo posee ninguna ventaja,solo puedes adquirir una, cual quieres adquirir? \n(1-Cambio pregunta(2pts), 2-Escudo(3pts), 3-No adquirir ninguna(0pts))\n");
               fflush(stdin);
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja cambio\n");
                       actualizarVentaja(jugador1, 1, 1); //Como estaba puesto en jugador.h, se llama a la funcion y se utilizan los paramentros para sumar o restas
                       actualizarPuntaje(jugador1, 2, 2); // 1 es para sumar y 2 es para restar y el tercer parametro representa a la cantidad
                       break;
                   }
                   case 2:{
                       printf("\nAdquirio ventaja escudo\n");
                       actualizarVentaja(jugador1, 1, 2);
                       actualizarPuntaje(jugador1, 2, 3);
       	               break;
                   }
                   case 3:{
                       printf("\nHasta luego!\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion!=1 && opcion!=2);
            //dependiendo el caso ingresa a uno o al otro
        }else{
            do{
               printf("\nYa posees Ventaja escudo, puedes adquirir ventaja cambio, quieres adquirirla? \n(1-Si 2pts, 2-No 0pts)\n");
               fflush(stdin);
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja cambio\n");
                       actualizarVentaja(jugador1, 1, 1);
                       actualizarPuntaje(jugador1, 2, 2);
       	               break;
                   }
                   
                   case 2:{
                       printf("\nHasta luego!\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto\n");
               }
            }while(opcion!=1 && opcion!=2);
        }
        
    }else{
        if(!jugador1->ventajaEscudo){
            do{
                printf("\nYa posees Ventaja cambio, puedes adquirir ventaja escudo, quieres adquirirla? \n(1-Si 3pts, 2-No 0pts)\n");
                fflush(stdin);
                scanf("%d", &opcion);   
                switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja escudo\n");
                       actualizarVentaja(jugador1, 1, 2);
                       actualizarPuntaje(jugador1, 2, 3);
                       break;
                   }
                   
                   case 2:{
                       printf("\nHasta luego!\n");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto\n");
                }
            }while(opcion!=1 && opcion!=2);
        }
    }
    
}
