#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "ahorcadolib.h"
#include "batallalib.h"

void ahorcado_juego();
void batalla_juego();
int main()
{
	
	char letra;
	do
	{
	printf("\tBienvenido a Gameboys\nSelecciona un juego\na)Ahorcado\nb)Batalla\n");
	scanf("%c", &letra);
	switch(letra)
	{
		case 'a':
		case 'A':
		{
		 ahorcado_juego();
		}break;
		case 'b':
		case 'B':
		{
		 batalla_juego();
		}break;
		
		default:
		printf("Error, seleccione opcion valida\n");

	   }
    } 
	while(1);

return 0;
}
void batalla_juego()
{
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta
		
	//Ataque[3] = { Tipo, Daño, Precision}
			
	//Estudiante
	char nombre[9];
	int vida_est = 200;
	int latigo_cepa[3] = {3, 25, 75}, pistola_agua[3] = {1, 15, 100}, ascuas[3] = {2, 35, 75}, cura[3] = {0, 40, 100};
	int eleccion = 4;
	int dano_recibido;
	
	//Ataques rivales

	int lanzallamas[3] = {2, 55, 50}, llamarada[3] = {2, 75, 33}, placaje[3] = {0, 25, 90};
	int esporas[3] = {3, 55, 50}, planta_feroz[3] = {3, 75, 33};
	int hidrobomba[3] = {1, 30, 70}, aqua_jet[3] = {1, 60, 45};
	
	//Rival combate
	int vida_rival = 200, tipo, ataque;
	
	//Otro
	int turno = 1;
	int dano_hecho;
	int i;
	int acabado = 0;
	

	rival misty;
	
		for(i=0; i<=2; i++){
			
			misty.atq1[i] = hidrobomba[i];
			misty.atq2[i] = aqua_jet[i];
			misty.atq3[i] =  placaje[i];
			misty.atq4[i] = pistola_agua[i];
		}
		
	rival brock;
		
		for(i=0; i<=2; i++){
			
			brock.atq1[i] = esporas[i];
			brock.atq2[i] = planta_feroz[i];
			brock.atq3[i] =  placaje[i];
			brock.atq4[i] = latigo_cepa[i];
		}
	rival ash;
	
		for(i=0; i<=2; i++){
			
			ash.atq1[i] = lanzallamas[i];
			ash.atq2[i] = llamarada[i];
			ash.atq3[i] =  placaje[i];
			ash.atq4[i] = ascuas[i];
		}
	
	//Introduccion
	printf("Bienvenido al simulador de combate, por favor, escribe tu nombre: ");
	scanf("%s", &nombre);
	
	printf("\nA continuacion %s, elige a quien quieres enfrentarte: \n", nombre);
	while(eleccion > 3){
	printf("Misty <1> \nAsh <2> \nBrock <3>\n");
	scanf("%i", &eleccion);
		}
		
		
	if (eleccion == 1){
		tipo = 1;
		strcpy(misty.nombre_rival, "Misty");
		printf("Asi que eliges a %s, buena eleccion", misty.nombre_rival);
	}
	else if (eleccion == 2){
		tipo = 2;
		strcpy(ash.nombre_rival, "Ash");
		printf("Asi que eliges a %s, buena eleccion", ash.nombre_rival);
	}
	else if (eleccion == 3){
		tipo = 3;
		strcpy(brock.nombre_rival, "Brock");
		printf("Asi que eliges a %s, buena eleccion", brock.nombre_rival);
	}
		
//cls aqui y pause
	//Combate
	while (acabado != 1){
		
		//Contador turnos
		printf("\n----------------------------------------\nTurno %i\n\n", turno);
		turno++;
		
	
		//Turno estudiante
		printf("Elige una accion:\n Latigo Cepa<1> , Pistola Agua<2>, Ascuas<3>, Cura<4>\n");
		scanf("%i", &eleccion);
		if (eleccion == 1){
			dano_hecho= multiplicador_tipo(tipo, latigo_cepa[0]) * critico(numaleatorio(100)) * acierto(latigo_cepa[2], numaleatorio(100), latigo_cepa[1]);
			printf("Le has quitado %i puntos de vida\n", dano_hecho);
			}
		else if (eleccion == 2){
			dano_hecho = (multiplicador_tipo(tipo, pistola_agua[0]) * critico(numaleatorio(100)) * acierto(pistola_agua[2], numaleatorio(100), pistola_agua[1])); 
			printf("Le has quitado %i puntos de vida\n", dano_hecho);
			}
		else if (eleccion == 3){
			dano_hecho= multiplicador_tipo(tipo, ascuas[0]) * critico(numaleatorio(100)) * acierto(ascuas[2], numaleatorio(100), ascuas[1]);
			printf("Le has quitado %i puntos de vida\n", dano_hecho);
		}
		else if (eleccion == 4){
			vida_est += 40;
			printf("Te has curado 40 puntos, tu vida pasa a ser %i\n", vida_est);
			dano_hecho = 0;
		}
		vida_rival -= dano_hecho;
		printf("La vida del rival pasa a ser %i", vida_rival);
		//Turno rival
		
		if(tipo == 1)
		dano_hecho = dano_ataque_rival(numaleatorio(3), misty.atq1[2], misty.atq2[2], misty.atq3[2], misty.atq4[2], numaleatorio(100), misty.atq1[1], misty.atq2[1], misty.atq3[1], misty.atq4[1], numaleatorio(100));
		else if(tipo == 2)
		dano_hecho = dano_ataque_rival(numaleatorio(3), ash.atq1[2], ash.atq2[2], ash.atq3[2], ash.atq4[2], numaleatorio(100), ash.atq1[1], ash.atq2[1], ash.atq3[1], ash.atq4[1], numaleatorio(100));
		else if(tipo == 3)
		dano_hecho = dano_ataque_rival(numaleatorio(3), brock.atq1[2], brock.atq2[2], brock.atq3[2], brock.atq4[2], numaleatorio(100), brock.atq1[1], brock.atq2[1], brock.atq3[1], brock.atq4[1], numaleatorio(100));
		
		vida_est -= dano_hecho;
		
		printf("\n\n\nEl rival te ha hecho %i puntos de dano, tu vida pasa a ser %i\n\n\n\n\n\n\n\n\n\n\n", dano_hecho, vida_est);
		//cls aqui
		
		if(vida_est <= 0)
		acabado = 1;
		else if(vida_rival <= 0)
		acabado = 1;
		
		}
	if (vida_rival && vida_est <= 0)
		printf("Doble KO");
	else if(vida_rival <= 0)
		printf("Felicidades has ganado");
	else if (vida_est <= 0)
		printf("Mejor suerte en la proxima");
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
