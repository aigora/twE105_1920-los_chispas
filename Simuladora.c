#include <stdio.h>


int main (){
	
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta
	
	//Ataque[3] = { Tipo, Daño, Precision}
	
	
	//Estudiante
	char nombre[9];
	int vida_est;
	int latigo_cepa[3] = {3, 25, 75}, pistola_agua[3] = {1, 15, 100}, ascuas[3] = {2, 35, 50}, cura[3] = {0, 0, 70}
	int eleccion;
	
	//Ash
	int 
	
	//Brock
	
	
	//Misty
	
	
	//Rival combate
	int vida_rival = 200;
	
	//Otro
	int turno = 1;
	
	//Introduccion
	printf("Bienvenido al simulador de examenes, por favor, escribe tu nombre: ");
	scanf("%s", &nombre);
	
	printf("A continuacion elige a quien quieres enfrentarte: /n");
	printf("Ash <1> /n Brock <2> /n Misty <3>");
	scanf("%i", &eleccion);
	
	if (eleccion == 1)
		
	//Combate
	while (vida_rival > 0){
		
		//Contador turnos
		printf("Turno %i", turno);
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
		printf("Tienes %i puntos\n\n", nota);
		
		
	}
printf("Felicidades %s has aprobado el examen", nombre);
}
