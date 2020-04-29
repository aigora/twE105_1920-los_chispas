#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define D 30

//ESTRUCTURAS
typedef struct{
	char nomb[D];
}adivinanza;

//FUNCIONES 
int numaleatorio(int n);//1
void juego(char adivinapalabra[D]);//2
int ahorcado(char adivinapalabra[E], char cadena[E]);//3
int imprime_ahorcado(int intentos);//4

//CODIGO PRINCIPAL
void main()
{

	char letra;
	int intentos=0, fallos=0;
	int aleatorio=0;
	
	printf("\tBienvenidos al Ahorcado !!!!!\n");
		system ("PAUSE");
			system("CLS");
	printf("\tEstamos listos??\n");
		system ("PAUSE");
			system("CLS");
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   
    adivinanza peliculas[8]={"MISION IMPOSIBLE", "TOP GUN", "STAR WARS", "INDIANA JONES", "JUMANJI", "LOS VENGADORES", "EL IRLANDES","HARRY POTTER"};
    adivinanza series[8]={"JUEGO DE TRONOS", "BREAKING BAD", "LA CASA DE PAPEL", "ELITE", "ARROW", "POKEMON", "VIKINGOS", "STRANGER THINGS"};
	adivinanza teams[8]={"REAL MADRID", "ATLETICO DE MADRID", "BARCELONA", "LIVERPOOL", "WATFORD", "GENK", "RIVER", "BBOCA JUNIORS"};
	switch (letra)
    {
       		case 'a':
			case 'A':
	           {
				system("CLS");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(8);
				juego(peliculas[aleatorio].nomb);
	  			break;
	           }
       		case 'b':
			case 'B':
	           {
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8);
				juego(series[aleatorio].nomb);
	  			break;
	           }
       		case 'c':
			case 'C':
	           {
				system("CLS");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8);
				juego(teams[aleatorio].nomb);
	  			break;
	           }

			default:
			printf("Error, seleccione opcion valida\n");
			system ("PAUSE");   
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");
		if(getch()=='1') {
			system("cls");
		goto empezar;
    }
}



//FUNCIONES 
//1
int numaleatorio(int n)
{
srand(time(NULL));
int i;
	i = rand()%n;
	return i;	
}
//2

void juego(char adivinapalabra[D])
{int errores, intentos;
while(1)
{
	
}


}

//3
int ahorcado(char adivinapalabra[E], char cadena[E])
{
}


//4
int imprime_ahorcado(int intentos)
{
}


