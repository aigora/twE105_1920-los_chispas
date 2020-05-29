#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//definimos las filas y columnas
#define nf 10
#define nc 10

//Funciones
int printmapa1(int map[nf][nc]); //Imprime mapa inicial con casillas
int printmapac(int map[nf][nc]); //Imprime un mapa que pueda contener caracteres
int ponerbarcosAlm(int fililla1, int fililla2, int columnilla1, int columnilla2, int map[nf][nc], int l);
int ponerbarcosCPU(int l, int map[nf][nc], int tipo);
int ataqueCPU(); //Disparos de la CPU
int ataqueAlm(); //Disparos del jugador
int infcasilla(char casilla[2]); //Comprueba si el formato de casilla introducio es válido y asigna unos valores a la coordenada introducida
int letafil(char casi[2]);
int numacol(char casi[2]);
