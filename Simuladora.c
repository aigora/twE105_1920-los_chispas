#include <stdio.h>


int main (){
	
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta
	
	//Ataque[3] = { Tipo, Daño, Precision}
	
	
	//Estudiante
	char nombre[9];
	int vida_est;
	int latigo_cepa[3] = {3, 25, 75}, pistola_agua[3] = {1, 15, 100}, ascuas[3] = {2, 35, 50}, cura[3] = {0, 0, 70};
	int eleccion = 4;
	
	//Ash, tipo 2 - Fuego
	
	
	//Brock, tipo 3 - Planta
	
	
	//Misty, tipo 1 - Agua
	
	
	//Rival combate
	int vida_rival = 200, tipo;
	
	//Otro
	int turno = 1;
	int probabilidades;
	
	//Introduccion
	printf("Bienvenido al simulador de combate, por favor, escribe tu nombre: ");
	scanf("%s", &nombre);
	
	printf("A continuacion, %s elige a quien quieres enfrentarte: \n", nombre);
	while(eleccion > 3){
	printf("Ash <1> \nBrock <2> \nMisty <3>\n");
	scanf("%i", &eleccion);
		}
		
		
	if (eleccion == 1)
		tipo = 2;
	else if (eleccion == 2)
		tipo = 3;
	else if (eleccion == 3)
		tipo = 1;
		
	//Combate
	while (vida_rival > 0){
		
		//Contador turnos
		printf("\n\n\n-------------------------\nTurno %i\n\n", turno);
		turno++;
		
		//Turno estudiante
		printf("Elige una accion:\n Latigo Cepa<1> , Pistola Agua<2>, Ascuas<3>, Cura<4>\n");
		scanf("%i", &eleccion);
		
		if (eleccion == 1){
				vida_rival -= latigo_cepa[1];
			}
		else if (eleccion == 2){
				vida_rival -= pistola_agua[1]; 
			}
		else if (eleccion == 3){
				vida_rival -= ascuas[1];
		}
		else if (eleccion == 4){
				vida_est += 25;
		}
		
		
	}
printf("Felicidades %s has aprobado el examen", nombre);
}
