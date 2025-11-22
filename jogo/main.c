////////    MAIN    ////////
#include "partida.h"

void intro();

int main(){
    
    intro();
    srand(time(NULL));
    inicializadorDelJuego();
    
}

void intro(){
    
    printf("Hola! bienvenido al juego slay the algorithm!");
    

    printf("\n\n\n\t Disfrutalo!");
    sleep(3);
    system("cls");
}
