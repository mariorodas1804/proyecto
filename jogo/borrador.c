/*  *Borrador*

    a modo slay the spire juego progresivo y roguelite
    
     Secciones claves
                * Jugador (menu o interfaz para navegacion)
                * Partida( una seed de generacion aleatoria)
                * Niveles (arboles binarios) y progreso (estructuras condicionales)
                * Boss (algoritmos con diferentes preguntas y tipos )
                * guardado de partidas ( archivos binarios junto con punteros )
                
                (podrian hacerse en .h para hacerlo mas sencillo de config)
                
- 1 solo jugador o partida que se vaya guardando
- X niveles con distintos tipos de preguntas
- Dificultad de las preguntas que sea aleatoria (1 a 3 de dificultad y 4 exclusivamente para el Boss)
- Combate de multiple choice
- En una pelea podrian haber maximo 2 enemigos (max 2 de dificultad si son dos enemigos)
- OPCIONAL: diferentes ventajas como:
                                     * cambiar pregunta
                                     * eliminar 2 opciones
                                     * 
                                     
El mapa o progreso constituido por un arbol generado aleatoriamente
en el que el camino se base en desiciones de donde quiere dirigirse el jugador

*/

// SEPARACION DE DE SECCIONES EN BIBLIOTECAS

#include "jugador.h"
#include "enemigos.h"
#include "preguntas.h"
#include "mapa.h"
#include "partida.h"

// EN ESTA PESTANIA SERA EL MAIN DEL PROGRAMA

FILE * archivoPartida; //busqueda de partida guardada o generacion de partida nueva *partida.h*

int main(){
    
    menu();

}

menu(){
  //  inicializadorDelJuego(){
    
    switch(opcion){
    
    case 1 = partidaNueva{
        
        variable nivel=0;
        generacionDelMapa();
        
        break;
    }
    case 2 = cargarPartida{
        
        pullBranch()//rescatar puntuacion,nivel,mapa y vida(variable jugador entera);
        
    	break;
    }
    case 0 = salir();{
        
        printf("Bye");
        return;
    	break;
    }

continuar(){
    
    
    1.cuantas piedras tiro pedrito a)5 b)2 c)8 d)1//1.-40.(faciles) del 41.-80.(normales) del 81.-120.(dificiles)
        
    1.a
    2.c
}

recorrido(){
    calavera--calavera--tienda--
    
    do {
        graficar mapa con niveles restantes(nivel)
        if(nivel=3 o nivel=8){
            switch
            1.campamento();
            2.tienda();
            avanzar en el mapa;
            igualar nivel;
            continue;
        }
        generacionEnemigo();
        do{
            generacionPregunta(){
                                 printf(pregunta);
                                 printf(respuestas);
                                 scanf(respuesta);
            
                                 repuestaCorrecta?(respuesta)(si si avanza; si no pierde vida y entra en bucle);
            }
        }while(respuestaIncorrecta);
        
        sumar puntuacion dependiendo de nivel;
        avanzar en el mapa;
        igualar nivel;
        
        
    } while(preguntar continuar)
    
        preguntaBoss(2)
        preguntaBoss(3)
        preguntaBoss(4)
        
        
        
inicializadorDelJuego(){
    
    //graficos
    
}


