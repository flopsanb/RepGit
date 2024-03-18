#include "bingo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inicializa el cartón del jugador con números aleatorios y sin duplicados.
void inicializarCarton(int carton[][COLUM_CARTON])
{
    int i, j;
    int numero;

    for(i = 0; i < FILAS_CARTON; i++)
        for(j = 0; j < COLUM_CARTON; j++)
        {
            numero = generaAleatorio(MIN, MAX);
            while(encuentraValor(carton, numero))
                numero = generaAleatorio(MIN, MAX);

            /* Asigna numero a cartón */
            carton[i][j] = numero;
        }
}

// Genera un número aleatorio dentro del rango especificado.
int generaAleatorio(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Busca un valor específico en el cartón del jugador y devuelve TRUE si lo encuentra, FALSE en caso contrario.
int encuentraValor(int carton[][COLUM_CARTON], int valor)
{
    int i, j;

    // Buscar el valor en el cartón
    for(i = 0; i < FILAS_CARTON; i++)
    {
        for(j = 0; j < COLUM_CARTON; j++)
        {
            // Si se encuentra el valor, devolver TRUE
            if(carton[i][j] == valor)
            {
                return TRUE;
            }
        }
    }

    // Si no se encuentra el valor en todo el cartón, devolver FALSE
    return FALSE;
}


// Muestra el cartón del jugador en la consola.
void mostrarCarton(int carton[][COLUM_CARTON])
{
    int i, j;

    for(i = 0; i < FILAS_CARTON; i++)
    {
        for(j = 0; j < COLUM_CARTON; j++)
        {
            printf("%2d ", carton[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

// Busca un número específico en el cartón del jugador y lo marca si lo encuentra, cambiándolo por el valor definido como MARCADO.
void comprobarNumero(int carton[][COLUM_CARTON], int valor)
{
    int i, j;
    int encontrado = FALSE; // Bandera para indicar si se encontró el valor

    // Buscar el valor en el cartón
    for(i = 0; i < FILAS_CARTON && !encontrado; i++)
    {
        for(j = 0; j < COLUM_CARTON && !encontrado; j++)
        {
            // Si se encuentra el valor, marcarlo y establecer la bandera a TRUE
            if(carton[i][j] == valor)
            {
                carton[i][j] = MARCADO;
                encontrado = TRUE;
            }
        }
    }
}


// Verifica si hay al menos una línea en el cartón del jugador, ya sea horizontal o verticalmente.
int comprobarLinea(int carton[][COLUM_CARTON])
{
    int i;

    // Comprobar filas
    for(i = 0; i < FILAS_CARTON; i++)
    {
        // Si encuentra una fila con todas las casillas marcadas, hay línea
        if(carton[i][0] == MARCADO &&
           carton[i][1] == MARCADO &&
           carton[i][2] == MARCADO &&
           carton[i][3] == MARCADO &&
           carton[i][4] == MARCADO)
        {
            return TRUE;
        }
    }

    // Si se recorren todas las filas sin encontrar ninguna con todas las casillas marcadas, no hay línea
    return FALSE;
}


// Verifica si todas las casillas del cartón del jugador están marcadas, lo que indica que hay bingo.
int comprobarBingo(int carton[][COLUM_CARTON])
{

    // Comprobar todas las casillas del cartón
    for(int i = 0; i < FILAS_CARTON; i++)
    {
        for(int j = 0; j < COLUM_CARTON; j++)
        {
            // Si encuentra una casilla no marcada, no hay bingo
            if(carton[i][j] != MARCADO)
            {
                return FALSE;
            }
        }
    }

    // Si se recorren todas las casillas sin encontrar ninguna no marcada, hay bingo
    return TRUE;
}

