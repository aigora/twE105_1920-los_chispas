#include <stdio.h>

//Comprobar el tipo del ataque y decidir si es efectivo
int multiplicador_tipo(int tipo_atq, int tipo_rival);

//Acierto del ataque
int acierto(int prob, int valor_aleatorio, int dano);

//Probabilidad de critico
int critico(int valor_critico);

int main (){
	
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta	
	//Ataque[3] = { Tipo, Daño, Precision}		
	//Estudiante
	char nombre[9];
	int vida_est = 200;
	int latigo_cepa[3] = {3, 25, 75}, pistola_agua[3] = {1, 15, 100}, ascuas[3] = {2, 35, 75}, cura[3] = {0, 40, 100};
	int eleccion = 4;
	//Ash, tipo 2 - Fuego
	int lanzallamas[3] = {2, 55, 50}, llamarada[3] = {2, 75, 33}; //ascuas[3] = {2, 35, 75}, placaje[3] = {0, 25, 90}
	
	//Brock, tipo 3 - Planta
	int esporas[3] = {3, 55, 50}, planta_feroz[3] = {3, 75, 33}; //latigo_cepa[3] = {3, 25, 75},  placaje[3] = {0, 25, 90}
	
	//Misty, tipo 1 - Agua
	int hidrobomba[3] = {1, 30, 70}, aqua_jet[3] = {1, 60, 45}; // placaje[3] = {0, 25, 90}, pistola_agua[3] = {1, 15, 100}
	
	//Rival combate
	int vida_rival = 200, tipo;
	
	//Otro
	int turno = 1;
	srand(time(NULL));
	int dano_hecho;
	
	
	//Introduccion
	printf("Bienvenido al simulador de combate, por favor, escribe tu nombre: ");
	scanf("%s", &nombre);
	
	printf("A continuacion %s, elige a quien quieres enfrentarte: \n", nombre);
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
	system("cls");
	//Combate
	while (vida_rival > 0 || vida_est > 0){
		
		//Contador turnos
		printf("\n-------------------------\nTurno %i\n\n", turno);
		turno++;
		
		//Turno estudiante
		printf("Elige una accion:\n Latigo Cepa<1> , Pistola Agua<2>, Ascuas<3>, Cura<4>\n");
		scanf("%i", &eleccion);
		
		if (eleccion == 1){
			dano_hecho= multiplicador_tipo(tipo, latigo_cepa[0]) * critico(srand()% 101) * acierto(latigo_cepa[2], srand()% 101, latigo_cepa[1]);
			printf("Le has quitado %i puntos de vida", dano_hecho);
			}
		else if (eleccion == 2){
			dano_hecho = (multiplicador_tipo(tipo, pistola_agua[0]) * critico(srand()% 101) * acierto(pistola_agua[2], srand()% 101, pistola_agua[1])); 
			printf("Le has quitado %i puntos de vida", dano_hecho);
			}
		else if (eleccion == 3){
			dano_hecho= multiplicador_tipo(tipo, ascuas[0]) * critico(srand()% 101) * acierto(ascuas[2], srand()% 101, ascuas[1]);
			printf("Le has quitado %i puntos de vida", dano_hecho);
		}
		else if (eleccion == 4){
			vida_est += 40;
			printf("Te has curado 40 puntos, tu vida pasa a ser %i\n", vida_est);
		}
		
		//Turno rival
		
		
		
		
	}
	if(vida_rival == 0)
		printf("Felicidades has ganado");
	else
		printf("Mejor suerte en la proxima");
}




//Funciones

int acierto(int prob, int valor_aleatorio, int dano){
	
	int fallo = 0;
	
	if(valor_aleatorio < prob)
		return dano;
	else
		return fallo;
}

int critico(int valor_critico){
	
	int multiplicador_crit;
	if(valor_critico < 15)
		multiplicador_crit = 2;
	
	else
		multiplicador_crit = 1;
	
	return multiplicador_crit;
}

int multiplicador_tipo(int tipo_atq, int tipo_rival){
	
	int multiplicador;
	
	if(tipo_rival == 1){
		
		if(tipo_atq == 1){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}
		
		else if(tipo_atq == 2){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
		
		else if(tipo_atq == 3){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
	}
	else if(tipo_rival == 2){
		
		if(tipo_atq == 1){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
		
		else if(tipo_atq == 2){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}
		
		else if(tipo_atq == 3){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
	}
	else if(tipo_rival == 3){
		
		if(tipo_atq == 1){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
		
		else if(tipo_atq == 2){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
		
		else if(tipo_atq == 3){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}
	}
	
	return multiplicador;
}
