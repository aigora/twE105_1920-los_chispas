#include <stdio.h>
#include <time.h>
#define N 10
#define D 30

typedef struct{
	char nomb[D];
}adivinanza;

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
	printf("Selecciona categoria:\na)Peliculas\nb)Series\nc)Equipos Futbol\n");
   
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
				principal(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           }
       		case 'b':
			case 'B':
	           {
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8);
				principal(series[aleatorio].nomb, letrausuario);
	  			break;
	           }
       		case 'c':
			case 'C':
	           {
				system("CLS");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8);
				principal(teams[aleatorio].nomb, letrausuario);
	  			break;
	           }
			   			   			
	}

	system ("PAUSE");
	system("CLS");
}
