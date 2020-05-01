#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define D 30

//ESTRUCTURAS
typedef struct{
	char nomb[D];
}adivinanza;

//FUNCIONES 
int numaleatorio(int n);//1
void juego(char adivinapalabra[D], char cadena[D]);//2
int ahorcado(char adivinapalabra[D], char cadena[D]);//3
int imp_ahorcado(int intentos);//4

//CODIGO PRINCIPAL
void main()
{

	char letra;
	int intentos=0, fallos=0;
	int aleatorio=0;
	char letrausuario[D]=" ";
	
	printf("\tBienvenidos al Ahorcado !!!!!\n");
		system ("PAUSE");
			system("CLS");
	printf("\tEstamos listos??\n");
		system ("PAUSE");
			system("CLS");
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   
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
				juego(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           }
       		case 'b':
			case 'B':
	           {
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8);
				juego(series[aleatorio].nomb, letrausuario);
	  			break;
	           }
       		case 'c':
			case 'C':
	           {
				system("CLS");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8);
				juego(teams[aleatorio].nomb, letrausuario);
	  			break;
	           }

			default:
			printf("Error, seleccione opcion valida\n");
			system ("PAUSE");   
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");
		if(getch()=='1') {
			system("cls");
		goto empezar;
    }
}



//FUNCIONES 
//1
int numaleatorio(int n)
{
srand(time(NULL));
int i;
	i = rand()%n;
	return i;	
}
//2

void juego(char adivinapalabra[D], char cadena[D])
{int errores, intentos, puntuacion, perder;
 char nombre_g[D]="";
 float t1 =clock(), t2, tf;
while(1)
{
	fallos=ahorcado(adivinapalabra, cadena);
	if(fallos==-1)
	{
		printf("Enhorabuena, has ganado!!!!!!!");
		t2=clock();
		tf=(t2-t1)/CLOCKS_PER_SEC;
		puntuacion=1000000/tf*intentos;
		printf("Tu puntuacion ha sido de %d y lo has terminado en %f, no esta nada mal...", puntuacion, tf);
		printf("Con que nombre quieres guardar la puntuacion obtenida?\n");
		scanf("%s\n", nombre);
				/*	fprintf(agregar, "%s.%i\n", nombre, puntuacion);
			fclose(agregar);
			FILE *leer=fopen("puntuacion_ahorcado.txt","r");
			Puntuaciones(lista_puntuaciones, leer);
			break;*/
	}
	intentos-=fallos;
	perder=imp_ahorcado(intentos);	
}

}

//3
int ahorcado(char adivinapalabra[D], char letrausuario[D])
{
}


//4
int imp_ahorcado(int intentos)
{
		if(intentos==7){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|\n|\n|\n|\n|\n|__\n");	
	}
	if(intentos==6){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|\n|\n|\n|\n|__\n");	
	}
	if(intentos==5){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|        |\n|\n|\n|\n|__\n");
	}
	if(intentos==4){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _| \n|       \n|\n|\n|__\n");
	}																			
	if(intentos==3){																				 
	printf("\tTe quedan %d intentos\n\n", intentos);					 
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|       \n|\n|\n|__\n");
			}
				
	if(intentos==2){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        |\n|\n|\n|__\n");
	}
	if(intentos==1){
	printf("\tTe quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       |  \n|\n|__\n");
	}
	if(intentos==0){
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       | |\n|\n|__\n");
	printf("\tHAS PERDIDO :(\n");	
	return 1;
	}
	return 0;
}


