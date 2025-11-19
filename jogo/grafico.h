#include <stdio.h>
void graficoMapa(int);
void graficoHUD(int);

void graficoHUD(int pNviel){


    printf("\n\n\n\n");
    printf("-------------------------------------------------------------------------------------------------------------");
    printf("\n|Vida: %d                                                                                        puntaje: %3d|",3,3);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n***********************************************************************************************************************");
    
    printf("-------------------------------------------------------------------------------------------------------------");
    printf("\n|Vida: %d                                                                                        puntaje: %3d|",2,3);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n***********************************************************************************************************************");
        
    
}

void graficoMapa(int pNivel){
    switch(pNivel){
        case 1:{printf("\n");//mapa inicial
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|    :)    |          |          |          |          |          |          |          |                 |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|          |          |    <3    |          |     ?    |          |          |    <3    |      ~~~~~~     |");
                printf("\n|    >:(   |    >:(   |==========|    >:(   |     ?    |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|          |          |     $    |          |     ?    |          |          |     +    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
                
        	break;
        }
        case 2:{printf("\n");//lvl 1 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |    :)    |          |          |          |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|          |    <3    |          |     ?    |          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|    >:(   |==========|    >:(   |     ?    |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|          |     $    |          |     ?    |          |          |     +    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 3:{printf("\n");//lvl 2 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |    :)    |          |          |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|    <3    |          |     ?    |          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|==========|    >:(   |     ?    |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|     $    |          |     ?    |          |          |     +    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 4:{printf("\n");//lvl 3 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |    :)    |          |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |     ?    |          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    >:(   |     ?    |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |     ?    |          |          |     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 5:{printf("\n");//lvl 4 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |    :)    |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|     ?    |          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|     ?    |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|     ?    |          |          |     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 55:{printf("\n");//lvl 5 actualizado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |    :)    |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    >:(   |          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    >:(   |          |          |     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 6:{printf("\n");//lvl 5 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |    :)    |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    >:(   |    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |          |     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 7:{printf("\n");//lvl 6 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |    :)    |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    >:(   |==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|          |     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 8:{printf("\n");//lvl 7 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |          |    :)    |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|    <3    |      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|==========|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|     $    |      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 9:{printf("\n");//lvl 8 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |          |          |       :)        |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      |>={ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
       	        break;
        }
        case 10:{printf("\n");//lvl 8.1 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |          |          |       :)        |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      |>x{ |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 11:{printf("\n");//lvl 8.2 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |          |          |       :)        |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      | x( |     |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      ~~~~~~     |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
        case 12:{printf("\n");//lvl 9 superado
                printf("\n");
                printf("\n");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|\n");
                printf("|          |          |          |          |          |          |          |          |                 |\n");
                printf("|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      *|___|*    |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|     *   |   *   |");
                printf("\n|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|xxxxxxxxxx|      * --- *    |");
                printf("\n|----------|----------|----------|----------|----------|----------|----------|----------|-----------------|");
                sleep(1);
        	break;
        }
    }
}


