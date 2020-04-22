#include <stdio.h>

int main (){
	//Estudiante
	char nombre[9];
	int vida_est;
	int copiar[2] ={25, 33}, repasar[2] ={10, 100};
	int eleccion;
	
	//Examen
	int nota;
	
	//Otros
	int turno = 1;
	int tiempo;
	
	//Introduccion
	printf("Bienvenido al simulador de examenes, por favor, escribe tu nombre: ");
	scanf("%s", &nombre);
	
	//Combate
	while (nota < 100){
		
		//Contador
		tiempo = 120 - turno * 20;
		printf("\n\nQuedan %i minutos\n", tiempo);
		turno++;
		
		//Turno estudiante
		printf("Elige una accion:\n Copiar<1> , Repasar<2>\n");
		scanf("%i", &eleccion);
		
		if (eleccion == 1){
				nota += copiar[0];
			}
		else if (eleccion == 2){
				nota += repasar[0]; 
			}
		printf("Tienes %i puntos\n\n", nota);
		
		
	}
printf("Felicidades %s has aprobado el examen", nombre);
}
