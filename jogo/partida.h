#include "enemigos.h"


//Prototipado de funciones
void inicializadorDelJuego();
void procesoJuego(tRegJugador*);
bool preguntarContinuar();
void menu();

//variables globales generales
tRegJugador jugador;

//Funcion principal que estructura el juego
void inicializadorDelJuego(){
    
    abrirArchivos();
    inicializarArbol(&ranking);
    strcpy(archivoRanking, "archivoRanking.dat");
    cargarRankingDesdeArchivo(&ranking, &archivoRanking);
    menu();
    
};

//Funcion que desarrolla el juego
void procesoJuego(tRegJugador* jugador1){
    
    int campaOTienda, cantidadPuntaje;
    inicializarStats(jugador1);
    do{
        mostrarMapa(jugador1->nivel); //Pasamos el parametro del nivel en el que se encuentra el jugador para que el mapa grafique segun lo pasado
        
        if(jugador1->nivel==3 || jugador1->nivel==8){ //Eventos especiales en nivel 3 y 8
            vidasRestantes=acumuladorVidas(*jugador1);
            graficoHud(vidasRestantes, jugador1->puntaje);
            do{
                printf("\nDesea ingresar al campamento para restaurar vida o a la tienda?(comodines)(1 o 2):\t");
                fflush(stdin);
                scanf("%d", &campaOTienda);
                switch(campaOTienda){
                    case 1:{
                        campamento(jugador1);
                        
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
            if(jugador1->nivel==5){ //Evento en el que se desarrolla doble pregunta
                peleaElite(jugador1);
            }
			else{
                peleaNormal(jugador1);
            }
        
        }  
        jugador1->nivel++;//nivel se actualiza acá
        
    }while(preguntarContinuar() && jugador1->nivel<9);
    
      if(jugador1->nivel == 9){
            
            peleaBoss(jugador1);
    	    mostrarStats(*jugador1);
    	    char nombreJugador[MAX];
            printf("\n¡Felicidades! Ingresa tu nombre para el ranking: ");
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
    	    creditos();
      }
      else{
          printf("Hasta luego!");
          mostrarStats(*jugador1);
          system("cls");
          char nombreJugador[MAX];
        printf("\nIngresa tu nombre para el ranking: ");
        fflush(stdin);
        fgets(nombreJugador, MAX, stdin);
        nombreJugador[strcspn(nombreJugador, "\n")] = 0; // Quitar \n
        
        agregarAlRanking(&ranking, *jugador1, &nombreJugador);
        guardarRankingEnArchivo(ranking, &archivoRanking);
        printf("Jugador '%s' agregado al ranking con %d puntos\n", nombreJugador, jugador1->puntaje);
        
        printf("\n");
	    system("pause");
          creditos();
          exit(EXIT_SUCCESS);
      }  
}

//Funcion para finalizar o continuar con el juego
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

//Funcion para comenzar el juego
void menu(){
    int seleccion;
    tRegJugador jugador;
    do{
       printf("\n\n\t1-Empezar\n\t2-Instrucciones\n\t3-ranking\n\t4-salir\n\n");
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
               printf("Este juego basico es basado un juego estilo roguelite, en el que principalmente se trata de generaciones aleatorias de \npreguntas con un sistema de vidas y ventajas en el que errar cada pregunta te resta 1 de vida, y responder \ncorrectamente te suma puntaje en el que se acumula hasta el final de la partida.\nTales ventajas pueden ser: Escudo(te libra de 1 de danio al errar una pregunta), Cambio(cambia la pregunta una vez \nseleccionada).Siempre que inicies una partida comenzaras con una sola ventaja.\nLos niveles de enemigos(preguntas), varian de nivel de dificultad y posiblemente te encuentres con un enemigo o varios \ny al final de la run te encontraras contra un jefe, en el que cuidado! puede o no ser dificil.\nA lo largo del camino te encontraras con campamentos en el que restauraran 1 vida o tiendas en el que podras canjear \npuntos por alguna ventaja(no se pueden tener la misma mas de una vez).\nPor favor disfruta y recuerda que solo es un juego, no te frustres que todo se aprende disfrutando un poco mas.:)");
           	break;
           	}
           case 3:{
               system("cls");
               graficarTop10(ranking);
               system("pause");
           	break;
           }
           case 4:{
               creditos();
           	break;
           }default:printf("Eleccion incorrecta");
       }   
    }while(seleccion!=4);
    
}
       
