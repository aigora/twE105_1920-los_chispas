#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "ahorcadolib.h"

void ahorcado_juego();

int main()
{
	
	char letra;
	do
	{
	printf("\tBienvenido a Gameboys\nSelecciona un juego\na)Ahorcado\n");
	scanf("%c", &letra);
	switch(letra)
	{
		case 'a':
		case 'A':
		{
		 ahorcado_juego();
		}break;
		
		default:
		printf("Error, seleccione opcion valida\n");

	   }
    } 
	while(1);

return 0;
}


void ahorcado_juego()
{
	int r=0;
    do
    {
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	char letra;
	int intentos=0, fallos=0;
	int aleatorio=0;
	char letrausuario[D]=" ";
	 adivinanza peliculas[8]={"MISION IMPOSIBLE", "TOP GUN", "STAR WARS", "INDIANA JONES", "JUMANJI", "LOS VENGADORES", "EL IRLANDES", "HARRY POTTER"};
    adivinanza series[8]={"JUEGO DE TRONOS", "BREAKING BAD", "LA CASA DE PAPEL", "ELITE", "ARROW", "POKEMON", "VIKINGOS", "STRANGER THINGS"};
	adivinanza teams[8]={"REAL MADRID", "ATLETICO DE MADRID", "BARCELONA", "LIVERPOOL", "WATFORD", "GENK", "RIVER", "BBOCA JUNIORS"};
	printf("\tBienvenidos al Ahorcado !!!!!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\tEstamos listos??\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   scanf(" %c", &letra);

	switch (letra)
    {
       		case 'a':
			case 'A':
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(8)-1;
				juego(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'b':
			case 'B':
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8)-1;
				juego(series[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'c':
			case 'C':
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8)-1;
				juego(teams[aleatorio].nomb, letrausuario);
	  			break;
	           

			default:
			printf("Error, seleccione opcion valida\n");
  
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");
        scanf(" %i", &r);
		}while(r==1);
}
