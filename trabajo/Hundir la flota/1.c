#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define nf 10
#define nc 10

int Printmapa1(int mat[nf][nc]); //Imprime mapa inicial con 0 en cada casilla
int mapaIA[nf][nc];//matriz que representa los barcos del cpu
int mapaAlmirante[nf][nc];//matriz que representa los barcos del jugador


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
				mapaIA[i][j] = 0; 
				mapaAlmirante[i][j] = 0;
			}	
	Printmapa1(mapaAlmirante);
	

}

int Printmapa1(int mat[nf][nc]) //Imprime una matriz de tal forma que es legible al usuario y se muestra como un tablero
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
