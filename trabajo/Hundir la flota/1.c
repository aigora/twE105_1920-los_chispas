#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define nf 10
#define nc 10

void mapainicial(char map1 [nfil][ncol]); //Imprime mapa inicial con 0 en cada casilla



int main()
{
	int letra;
	printf("Bienvenido a Hundir la flota\n");
	printf("Para empezar a jugar pulse 1, si desea ver las instrucciones pulse 2");
	scanf("%i",&letra);
	switch (letra)
	{
		case 1:
		printf("loco\n");	
		break;
		case 2:
		printf("locA\n");
		break;
	}
	char mapa [10] [10];
	
	return 0;
}

void mapainicial(char map1 [nfil][ncol]);
