#ifndef BINGO_H
#define BINGO_H

// Definiciones de constantes
#define FILAS_CARTON 3
#define COLUM_CARTON 5
#define MARCADO -1
#define TRUE 1
#define FALSE 0
#define MIN 1
#define MAX 90

// Declaraciones de funciones
void inicializarCarton(int carton[][COLUM_CARTON]);
int generaAleatorio(int min, int max);
int encuentraValor(int carton[][COLUM_CARTON], int valor);
void mostrarCarton(int carton[][COLUM_CARTON]);
void comprobarNumero(int carton[][COLUM_CARTON], int valor);
int comprobarLinea(int carton[][COLUM_CARTON]);
int comprobarBingo(int carton[][COLUM_CARTON]);

#endif
