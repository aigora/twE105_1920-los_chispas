#include <stdio.h>
//Acierto del ataque
int acierto(int prob, int valor_aleatorio, int dano);

//Probabilidad de critico

int main (){
	
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta	
	//Ataque[3] = { Tipo, Daño, Precision}		
	//Estudiante
	char nombre[9];
	int vida_est = 200;
	int latigo_cepa0[3] = {3, 25, 75}, pistola_agua0[3] = {1, 15, 100}, ascuas0[3] = {2, 35, 75}, cura[3] = {0, 40, 70};
	int eleccion = 4;
	
	//Ash, tipo 2 - Fuego
	int ascuas[3] = {2, 35, 75}, lanzallamas[3] = {2, 55, 50}, llamarada[3] = {2, 75, 33}, placaje0[3] = {0, 25, 90};
	
	//Brock, tipo 3 - Planta
	int placaje1[3] = {0, 25, 90}, latigo_cepa[3] = {3, 25, 75}, esporas[3] = {3, 55, 50}, planta_feroz[3] = {3, 75, 33};
	
	//Misty, tipo 1 - Agua
	int placaje2[3] = {0, 25, 90}, pistola_agua[3] = {1, 15, 100}, hidrobomba[3] = {1, 30, 70}, aqua_jet[3] = {1, 60, 45};
	
	//Rival combate
	int vida_rival = 200, tipo;
	
	//Otro
	int turno = 1;
	int probabilidad_acierto, probabilidad_critico;
	srand(time(NULL));
	
	
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
	system("cls");
	//Combate
	while (vida_rival > 0 || vida_est > 0){
		
		//Contador turnos
		printf("-------------------------\nTurno %i\n\n", turno);
		turno++;
		
		//Turno estudiante
		printf("Elige una accion:\n Latigo Cepa<1> , Pistola Agua<2>, Ascuas<3>, Cura<4>\n");
		scanf("%i", &eleccion);
		
		if (eleccion == 1){
			vida_rival -= acierto(latigo_cepa[2], srand()% 101, latigo_cepa[1]);
			
			}
		else if (eleccion == 2){
			vida_rival -= acierto(pistola_agua[2], srand()% 101, pistola_agua[1]); 
			}
		else if (eleccion == 3){
			vida_rival -= acierto(ascuas[2], srand()% 101, ascuas[1]);
		}
		else if (eleccion == 4){
			vida_est += acierto(cura[2], srand()% 101, cura[1]);
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
	
	if(valor_aleatorio < prob)
		return dano;
	else
		return dano - dano;
}
