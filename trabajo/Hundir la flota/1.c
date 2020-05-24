#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//definimos las filas y columnas
#define nf 10
#define nc 10

//Funciones
int Printmapa1(int mat[nf][nc]); //Imprime mapa inicial con ceros como agua en las casillas
int mapaCPU[nf][nc]; //Mapa del ordenador
int mapaAlmirante[nf][nc]; //Mapa del jugador
int DisparosmapCPU[nf][nc]; //Mapa del rastro de disparos lanzados por la CPU
int DisparosmapAlm[nf][nc]; //Mapa del rastro de disparos lanzados por el jugador
int film, columm;
char casilla[2]; //Casilla del tablero con formato letra + numero (ej: A1)


void main()
{
	int letra, i, j;
	printf("Bienvenido a Hundir la flota\n");
	printf("Para empezar a jugar pulse 1, si desea ver las instrucciones pulse 2\n\n");
	scanf("%i",&letra);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i<nf; i++){
		for (j = 0; j<nc; j++){
				mapaCPU[i][j] = 0; 
				mapaAlmirante[i][j] = 0;
			}	
	}	
	Printmapa1(mapaAlmirante);
	for (i = 0; i<nf; i++){
		for (j = 0; j<nc; j++){
				DisparosmapAlm[i][j] = '*';
				DisparosmapCPU[i][j] = '*';
			}	
	}
}

int Printmapa1(int mat[nf][nc]) //Imprime una matriz como tablero inicial con casillas determinadas por una letra y un numero (ej: A1)
{
    int i;
    
    printf("   |");
    for(i=1; i<=10; i++){
    		printf(" %i |",i);	
		}
		printf("\n---------------------------------------------\n A |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[0][i]);	
		}
		printf("\n---------------------------------------------\n B |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[1][i]);
		} 
	    printf("\n---------------------------------------------\n C |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[2][i]);
		}	   	
		printf("\n---------------------------------------------\n D |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[3][i]);
		}
		printf("\n---------------------------------------------\n E |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[4][i]);
		}
		printf("\n---------------------------------------------\n F |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[5][i]);
		}    
		printf("\n---------------------------------------------\n G |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[6][i]);
		}   	
		printf("\n---------------------------------------------\n H |");
	for(i=0; i<10; i++) {
			printf(" %i |",mat[7][i]);
		}
		printf("\n---------------------------------------------\n I |");
	for(i=0; i<10; i++){
			printf(" %i |",mat[8][i]);
		}
	   	printf("\n---------------------------------------------\n J |");	
	for(i=0; i<10; i++){
			printf(" %i |",mat[9][i]);
		}  
	    printf("\n---------------------------------------------\n");
}
int BarcosAlm(int mapaAlmirante[nf][nc]){
	char casilla1, casilla2;
	printf("Almirante decida el primer punto donde va a colocar su portaviones de 5 casillas");
	scanf("%c", &casilla1);
	printf("Almirante decida el último punto donde va a colocar su portaviones de 5 casillas");
	scanf("%c", &casilla2);
	
		
}
int infcasilla(char casilla[2]) //Comprueba si el formato de casilla introducio es válido
{
	if((casilla[0]>='a' && casilla[0]<='j') || (casilla[0]>='A' && casilla[0]<='J')) //Asigna a la letra de la casilla a una fila
		{
		if(casilla[0]>='a' && casilla[0]<='j')
		{
				film = casilla[0] - 'a';
		}
		else if(casilla[0]>='A' && casilla[0]<='J')
		{
				film = casilla[0] - 'A';
		}
		else
				return 0;
		}
	if (casilla[1] >= 49 && casilla[1] <= 57) //Asigna aL numero de la casilla a una columna
	{
		columm = casilla[1]- '1';
				return 1;
	}
		else
				return 0;
}
int boom( ) //Disparos del jugador
{
	int dispara = 0;
	char casilladp[2];
	
	while(dispara==0)
	{
		printf("Almirante decida la casilla a la que va a disparar: \n");
		scanf(" %c", &casilladp);
		infcasilla( casilladp);
		
		if(infcasilla( casilladp) == 1){
			if (mapaAlmirante[film][columm] != '*'){ //comprueba si anteriormente habia disparado en esa posicion
				printf("\n  Ya has disparado a esa casilla, intenta otra distinta");
			}
			else
			{
				if (DisparosmapCPU[film][columm] == 0) //Cuando tocas agua y fallas se sabra porque la casilla es 0 
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					mapaAlmirante[film][columm] = '~';
					printf("Has fallado, hemos tocado agua");
					return 0;
				}
				if (DisparosmapCPU[film][columm] == 2) //Cuando es 2 ha dado a una slancha de tamaño2
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado una lancha");
					mapaAlmirante[film][columm] = '2';
					return 2;
				}
				if (DisparosmapCPU[film][columm] == 3) //Cuando es 3 ha dado a un submarino de tamaño 3 
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un submarino");
					mapaAlmirante[film][columm] = '3';
					return 3;
				}
				if (DisparosmapCPU[film][columm] == 4) //Cuando es 4 ha dado a un buque de tamaño 4
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un buque");
					mapaAlmirante[film][columm] = '4';
					return 4;
				}
				if (DisparosmapCPU[film][columm] == 5) //Cuando es 5 ha dado a un portaaviones de tamaño5
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un portaaviones");
					mapaAlmirante[film][columm] = '5';
					return 5;
				}
			}
		}
	}
}
int boomenmicara( ) //Disparos de la CPU
{
	int film, columm;
	int dispara = 0;
	while(dispara==0)
	{
		film = rand() % (nf+1); //fila random a la que disparo
		columm = rand() % (nc+1); //columa random a la que dispara
			if (mapaCPU[film][columm] == '*'){ //comprueba si anteriormente habia disparado en esa posicion
				if (DisparosmapAlm[film][columm] == 0) //Cuando toca agua se sabra porque la casilla es 0
				{
					mapaCPU[film][columm] = '~';
					printf("Uff, nos hemos salvado los enemigos han fallado");
					return 0;
				}
				else  
				{
					if (DisparosmapAlm[film][columm] == 2) //Cuando es 2 ha dado a una slancha de tamaño2
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado una de nuestras lancha");
						mapaCPU[film][columm] = '2';
						return 2;
					}
					if (DisparosmapAlm[film][columm] == 3) //Cuando es 3 ha dado a un submarino de tamaño 3 
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado uno de nuestros submarino");
						mapaCPU[film][columm] = '3';
						return 3;
					}
					if (DisparosmapAlm[film][columm] == 4) //Cuando es 4 ha dado a un buque de tamaño 4
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado uno de nuestros buques");
						mapaCPU[film][columm] = '4';
						return 4;
					}
					if (DisparosmapAlm[film][columm] == 5) //Cuando es 5 ha dado a un portaviones de tamaño5
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado nuestro portaaviones");
						mapaCPU[film][columm] = '5';
						return 5;
					}
				}
			}
	}
}

