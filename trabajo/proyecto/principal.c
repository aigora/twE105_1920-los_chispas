#include <stdio.h>

#include "ahorcadolib.h"

void ahorcado_juego();

void main()
{
	ahorcado_juego();
}


void ahorcado_juego()
{
    do
    {
	system ("PAUSE");    	
    system("cls");
	char letra;
	int intentos=0, fallos=0;
	int aleatorio=0;
	char letrausuario[D]=" ";
	 adivinanza peliculas[8]={"MISION IMPOSIBLE", "TOP GUN", "STAR WARS", "INDIANA JONES", "JUMANJI", "LOS VENGADORES", "EL IRLANDES", "HARRY POTTER"};
    adivinanza series[8]={"JUEGO DE TRONOS", "BREAKING BAD", "LA CASA DE PAPEL", "ELITE", "ARROW", "POKEMON", "VIKINGOS", "STRANGER THINGS"};
	adivinanza teams[8]={"REAL MADRID", "ATLETICO DE MADRID", "BARCELONA", "LIVERPOOL", "WATFORD", "GENK", "RIVER", "BBOCA JUNIORS"};
	printf("\tBienvenidos al Ahorcado !!!!!\n");
		system ("PAUSE");
			system("CLS");
	printf("\tEstamos listos??\n");
		system ("PAUSE");
			system("CLS");
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   scanf(" %c", &letra);

	switch (letra)
    {
       		case 'a':
			case 'A':
				system("CLS");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(8)-1;
				juego(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'b':
			case 'B':
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8)-1;
				juego(series[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'c':
			case 'C':
				system("CLS");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8)-1;
				juego(teams[aleatorio].nomb, letrausuario);
	  			break;
	           

			default:
			printf("Error, seleccione opcion valida\n");
			system ("PAUSE");  
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");

		}while(getch()=='1');
}
