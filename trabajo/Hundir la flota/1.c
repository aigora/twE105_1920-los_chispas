#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define nf 10
#define nc 10

int Printmapa1(int mat[nf][nc]); //Imprime mapa inicial con ceros como agua en las casillas
int mapaCPU[nf][nc]; //Mapa del ordenador
int mapaAlmirante[nf][nc]; //Mapa del jugador
int DisparosmapCPU[nf][nc]; //Mapa del rastro de disparos lanzados por la CPU
int DisparosmapAlm[nf][nc]; //Mapa del rastro de disparos lanzados por el jugador
int filmatriz, columatriz;
char casilla[2]; //Casilla del tablero con formato letra + numero (ej: A1)


void main()
{
	int letra, i, j;
	printf("Bienvenido a Hundir la flota\n");
	printf("Para empezar a jugar pulse 1, si desea ver las instrucciones pulse 2\n\n");
	scanf("%i",&letra);
	system("cls");
	for (i=0; i<nf; i++)
		for (j=0; j<nc; j++)
			{
				mapaCPU[i][j] = 0; 
				mapaAlmirante[i][j] = 0;
			}	
	Printmapa1(mapaAlmirante);
	
	

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
	if((casilla[0]>='a' && casilla[0]<='j') || (casilla[0]>='A' && casilla[0]<='J')){
		if (casilla[0]=='a'||casilla[0]=='A') //asigna la letra introducida por el usuario a un numero (fila)
				filmatriz = 0;
		else if (casilla[0] == 'b' || casilla[0] == 'B')
				filmatriz = 1;
		else if (casilla[0] == 'c' || casilla[0] == 'C')
				filmatriz = 2;
		else if (casilla[0] == 'd' || casilla[0] == 'D')
				filmatriz = 3;
		else if (casilla[0] == 'e' || casilla[0] == 'E')
				filmatriz = 4;
		else if (casilla[0] == 'f' || casilla[0] == 'F')
				filmatriz = 5;
		else if (casilla[0] == 'g' || casilla[0] == 'G')
				filmatriz = 6;
		else if (casilla[0] == 'h' || casilla[0] == 'H')
				filmatriz = 7;
		else if (casilla[0] == 'i' || casilla[0] == 'I')
				filmatriz = 8;
		else if (casilla[0] == 'j' || casilla[0] == 'J')
				filmatriz = 9;
		else
				return 0;
	}
	if ((casilla[1]-1) >= '0' && (casilla[1]-1) <= '9'){
		columatriz = casilla[1]- '1';
				return 1;
	}
		else
				return 0;
}

