        
/*Mapa generado progresivo con vector (no sabemos si hay usar arboles o no)

lista 9 (niveles)
1 boss (lvl 9)
lvl 3/8(antes del boss) una tienda o camp
lvl 5 mini boss (1 preg lvl 4 o 2 enemigos si o si (dificultad 2))

//utilizar Pila con puntero

*/
#include "jugador.h"
#include "grafico.h"


void mostrarMapa(int);
void campamento();
void tienda(tRegJugador*);


void mostrarMapa(int pNivel){

    graficoMapa(pNivel);
    
}

void campamento(){
    
     printf("Curandote...");
     sleep(3);
     
}

void tienda(tRegJugador *jugador1){
    int opcion;
    
    if(!jugador1->ventajaCambio){
        if(!jugador1->ventajaEscudo){
            do{
               printf("\nNo posee ninguna ventaja,solo puedes adquirir una, cual quieres adquirir? \n(1-Cambio pregunta(2pts), 2-Escudo(3pts), 3-No adquirir ninguna(0pts))");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja cambio\n");
                       actualizarVentaja(jugador1, 1, 1);
                       actualizarPuntaje(jugador1, 2, 2);
                       break;
                   }
                   case 2:{
                       printf("\nAdquirio ventaja escudo");
                       actualizarVentaja(jugador1, 1, 2);
                       actualizarPuntaje(jugador1, 2, 3);
       	               break;
                   }
                   case 3:{
                       printf("\nHasta luego!");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=3);
            
        }else{
            
            do{
               printf("\nYa posees Ventaja cambio, puedes adquirir ventaja escudo, quieres adquirirla? \n(1-Si 3pts, 2-No 0pts)");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja escudo");
                       actualizarVentaja(jugador1, 1, 2);
                       actualizarPuntaje(jugador1, 2, 3);
       	               break;
                   }
                   
                   case 2:{
                       printf("\nHasta luego!");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=3);
        }
        
    }else{
          do{
               printf("\nYa posees Ventaja escudo, puedes adquirir ventaja cambio, quieres adquirirla? \n(1-Si 2pts, 2-No 0pts)");
               scanf("%d", &opcion);   
               switch(opcion){
                   case 1:{
                       printf("\nAdquirio ventaja cambio");
                       actualizarVentaja(jugador1, 1, 1);
                       actualizarPuntaje(jugador1, 2, 2);
       	               break;
                   }
                   
                   case 2:{
                       printf("\nHasta luego!");
                       break;
                   }
                   default:printf("\nError: eligio un numero incorrecto");
               }
            }while(opcion<=0 && opcion>=3);
    }
    
}
