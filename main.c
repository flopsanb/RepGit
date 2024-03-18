#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //Necesario para srand
#include <unistd.h> //Necesario para sleep()
#include "bingo.h"

#define TRUE 1
#define FALSE 0

int main()
{
    int enJuego = TRUE;
    int numeroJugada = 1;
    int bola;
    char enter;
    int verLineaJugador1 = TRUE;
    int verLineaJugador2 = TRUE;


    /* Inicializa el generador de numeros */
    srand((unsigned int)time(NULL));

    /* Define las estructuras de datos */
    int carton1[FILAS_CARTON][COLUM_CARTON] = {{15,48,75,89,4},{12,46,32,56,7},{19,69,51,11,1}};
    int carton2[FILAS_CARTON][COLUM_CARTON];

    /* Inicializa el cartón del jugador 2 */
    inicializarCarton(carton2);

    printf("Cartones de los jugadores:");
    printf("\n--------------------------\n\n");

    /* Muestra los cartones */
    printf("Carton del jugador 1\n");
    mostrarCarton(carton1);

    printf("Carton del jugador 2\n");
    mostrarCarton(carton2);

    printf("\n--------------------------\n");
    /* Ciclo de la partida */
    while(enJuego)
    {
        /* Extrae una nueva bola */
        bola = generaAleatorio(1, 90);

        /* Informa de numero jugada y resultado */
        printf("Jugada %d\n", numeroJugada++);
        printf("Ha salido el : %d\n", bola);

        /* Comprueba el cartón del jugador 1 */
        comprobarNumero(carton1, bola);

        /* Muestra los cartones */
        printf("Carton del jugador 1\n");
        mostrarCarton(carton1);

        /* Comprueba el cartón del jugador 2 */
        comprobarNumero(carton2, bola);

        /* Muestra los cartones */
        printf("Carton del jugador 2\n");
        mostrarCarton(carton2);

        /* Comprueba línea del jugador 1 o del 2 */
        if((comprobarLinea(carton1) || comprobarLinea(carton2)) && verLineaJugador1 && verLineaJugador2)
        {
            
            /* Comprueba línea del jugador 1 y 2 */
            if(comprobarLinea(carton1) && comprobarLinea(carton2)){

                printf("Woooooo.... EMPATE en Lineas !!!!!\n");

                verLineaJugador1 = FALSE;
                verLineaJugador2 = FALSE;

                /* Comprueba línea del jugador 1 */
            }else if(comprobarLinea(carton1)){

                printf("Linea del jugador 1\n");
                scanf("%c", &enter);
                verLineaJugador1 = FALSE;
            

                /* Comprueba línea del jugador 2 */
            }else{

                printf("Linea del jugador 2\n");
                scanf("%c", &enter);
                verLineaJugador2 = FALSE;

            }

        }

        /* Comprueba si hay bingo en jugador 1 */
        if(comprobarBingo(carton1))
        {
            printf("BINGOOOO ... del jugador 1\n");
            enJuego = FALSE;
        }

        /* Comprueba si hay bingo en jugador 2 */
        if(comprobarBingo(carton2))
        {
            printf("BINGOOOO ... del jugador 2\n");
            enJuego = FALSE;
        }

        sleep(1);
    }


    return 0;
}
