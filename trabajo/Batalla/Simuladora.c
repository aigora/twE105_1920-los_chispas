#include <stdio.h>
#include <string.h>

//Estructuras
typedef struct {
char nombre_rival[5];
int atq1[3];
int atq2[3];
int atq3[3];
int atq4[3];

} rival;

//Funciones
int multiplicador_tipo(int tipo_atq, int tipo_rival);
int acierto(int prob, int valor_aleatorio, int dano);
int critico(int valor_critico);

	
int main (){
	
	
	// 0 - Sin tipo, 1 - Agua, 2 - Fuego, 3 - Planta
		
	//Ataque[3] = { Tipo, Daño, Precision}
			
	//Estudiante
	char nombre[9];
	int vida_est = 200;
	int latigo_cepa[3] = {3, 25, 75}, pistola_agua[3] = {1, 15, 100}, ascuas[3] = {2, 35, 75}, cura[3] = {0, 40, 100};
	int eleccion = 4;
	
	//Ataques rivales

	int lanzallamas[3] = {2, 55, 50}, llamarada[3] = {2, 75, 33}, placaje[3] = {0, 25, 90};
	int esporas[3] = {3, 55, 50}, planta_feroz[3] = {3, 75, 33};
	int hidrobomba[3] = {1, 30, 70}, aqua_jet[3] = {1, 60, 45};
	
	//Rival combate
	int vida_rival = 200, tipo, ataque;
	
	//Otro
	int turno = 1;
	srand(time(NULL));
	int dano_hecho;
	int i;
	

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
		
	system ("PAUSE");
	system("cls");
	//Combate
	while (vida_rival > 0 || vida_est > 0){
		
		//Contador turnos
		printf("\n----------------------------------------\nTurno %i\n\n", turno);
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
		
		printf("La vida del rival pasa a ser %i", vida_rival);
		//Turno rival
		
		
		if(tipo == 1){
			
			ataque = srand()% 4 ;
			
			if(ataque == 0){
				
				
			}
			
			if(ataque == 1){
			}
			
			if(ataque == 2){
			}
			
			if(ataque == 3){
			}
		}
		
		system("cls");
		
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
