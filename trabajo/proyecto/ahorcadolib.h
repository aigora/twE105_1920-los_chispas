#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
 

#define N 10
#define D 30
#define F 20
typedef struct{
	char nomb[D];
}adivinanza;

typedef struct{
	char nombre[D];
	int punt;
}usuario;

int numaleatorio(int n);//1
void juego(char adivinapalabra[D], char cadena[D]);//2
int ahorcado(char adivinapalabra[D], char cadena[D]);//3
int imp_ahorcado(int intentos);//4
void Puntuaciones(usuario lista_punt[F],FILE *leer);//5
