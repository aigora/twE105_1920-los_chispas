#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define E 30
#define D 20
typedef struct{
	char palabra[E];
}pal;
typedef struct{
	char nombre[E];
	int punt;
}usuario;
void principal(char adivinapalabra[E], char cadena[E]);
int numaleatorio(int n);
int ahorcado(char adivinapalabra[E], char cadena[E]);
int imprime_ahorcado(int intentos);
void Puntuaciones(usuario lista_punt[D],FILE *leer);

void main(){
	empezar:
	system("COLOR 2F");
	int aleatorio=0;
	pal peliculas[10]={"AVENGERS ENDGAME" , "TRANSFORMERS" , "HARRY POTTER" , "TITANIC" , "EL SENOR DE LOS ANILLOS" , "STAR WARS" , "GLADIADOR" , "JURASSIC PARK" , "EL CABALLERO OSCURO" , "TOY STORY"};
	pal series[10]={"JUEGO DE TRONOS" , "STRANGER THINGS" , "WESTWORLD" , "FRIENDS" , "COMO CONOCI A VUESTRA MADRE" , "LA QUE SE AVECINA" , "LA CASA DE PAPEL" , "PEAKY BLINDERS" , "EL PRINCIPE DE BEL AIR" , "THE BIG BANG THEORY"};
	pal musica[10]={"BOHEMIAN RHAPSODY" , "THRILLER" , "BOYS DONT CRY" , "WITH OR WITHOUT YOU" , "PURPURINA" , "LET IT BE" , "HEY BROTHER" , "VIVA LA VIDA" , "PAQUITO EL CHOCOLATERO" , "RAP GOD"};
	pal deportes[10]={"MICHAEL JORDAN" , "REAL MADRID" , "PADEL" , "JUANFRAN AL PALO" , "EL BICHO" , "MOHAMED ALI" , "CICLISMO" , "ESCALADA" , "RUGBY" , "PRESS BANCA"};
	char letra;
	char letrausuario[E]=" ";

/*	printf("Bienvenido al Ahorcado\n");
	system ("PAUSE");
	system("CLS");
	printf("En este juego el objetivo es adivinar la frase o palabra con el minimo numero de fallos\n");
	system("PAUSE"); 
	system("CLS");*/
	printf("Selecciona la categoria de la frase:\na.Peliculas\nb.Series\nc.Musica\nd.Deportes\n");
		switch(getch()){
			case 'a':
			case 'A':
				system("CLS");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(10);
				principal(peliculas[aleatorio].palabra, letrausuario);
				break;
				
			case 'b':
			case 'B':
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(10);
				principal(series[aleatorio].palabra, letrausuario);
				break;
				
			case 'c':
			case 'C':
				system("CLS");
				printf("Has elegido la categoria de Musica\n");
				aleatorio = numaleatorio(10);
				principal(musica[aleatorio].palabra, letrausuario);
				break;
				
			case 'd':
			case 'D':
				system("CLS");
				printf("Has elegido la categoria de Deportes\n");
				aleatorio = numaleatorio(10);
				principal(deportes[aleatorio].palabra, letrausuario);
				break;
				
			default:
			printf("Escoge una opcion valida\n");
			system("PAUSE");		
		}
		printf("\n Quieres jugar de nuevo? Pulsa 1:");
		if(getch()=='1') {
			system("cls");
		goto empezar;
	}
}	
	
	


void principal(char adivinapalabra[30], char cadena[30]){
	int intentos=7, fallos=0, i, puntuacion,si_perdido;
	i=0;
	char nombre[20]="";
	usuario lista_puntuaciones[D]={{"iniciar",0}};
	FILE *agregar=fopen("puntuacion_ahorcado.txt","a");
		if(agregar==NULL){
		printf("\n\t Error");
		exit(1);
	}
	float t1=clock(), t2, tiempo_total;
	while(1){
		fallos=ahorcado(adivinapalabra, cadena);
		if(fallos==-1){
			printf("\nHAS GANADO!!\n");
			t2=clock();
			tiempo_total = (t2-t1)/CLOCKS_PER_SEC;
			puntuacion=1000000/(int)tiempo_total*intentos;
			printf("Has tardado %f\nTu puntuacion ha sido de %i\n", tiempo_total, puntuacion);
			printf("Pon Nickname:\n");
			scanf(" %[^\n]", nombre);
			fprintf(agregar, "%s.%i\n", nombre, puntuacion);
			fclose(agregar);
			FILE *leer=fopen("puntuacion_ahorcado.txt","r");
			Puntuaciones(lista_puntuaciones, leer);
			break;
		}
		intentos-=fallos;
		printf("\n\n");
		si_perdido=imprime_ahorcado(intentos);
		if(si_perdido==1) break;
		printf("\nLas letras introducidas que llevas son: %s\n", cadena);
		printf("Introduce una letra:\n");
		cadena[i]=getch();
		system("CLS");				
		i++;					
	}
}

int numaleatorio(int n){
srand(time(NULL));
int i;
	i = rand()%n;
	return i;
}

int ahorcado(char adivinapalabra[30], char letrausuario[30]){
	
	int i, n,Pregunta_fallo, iguales, ganado=1, dif='A'-'a',ultima_letra_usuario=strlen(letrausuario);
	
	for(i=0; adivinapalabra[i]!='\0'; i++){
		
		for(n=0, iguales=0; n<ultima_letra_usuario; n++){
			if(letrausuario[n]==adivinapalabra[i] || letrausuario[n]==adivinapalabra[i]-dif){
				iguales = 1;
			}
		}
		if(iguales==1){
			printf("%c ", adivinapalabra[i]);
		}
		else if(adivinapalabra[i]==' '){
			printf("   "); 
		}
		else{
			ganado=0;
					
			if( adivinapalabra[i]>= 'A' &&  adivinapalabra[i]<= 'Z'){
				printf("_ ");	
			}
		
			if(adivinapalabra[i] >= 'a' && adivinapalabra[i] <= 'z'){
				printf("_ ");
			}
		}
	}
	if(ganado==1){
		//printf("\nHAS GANADO!!");
		return -1;
	}
	if(strlen(adivinapalabra)!=1)//Para que no empiece a comprobar si hay algún fallo antes de que el vector tenga contenido
		for(i=0,Pregunta_fallo=1;adivinapalabra[i]!='\0';i++)
			if(letrausuario[ultima_letra_usuario-1]==adivinapalabra[i] || letrausuario[ultima_letra_usuario-1]==adivinapalabra[i]-dif)
				Pregunta_fallo=0;
		
	return Pregunta_fallo;
}
int imprime_ahorcado(int intentos){
	if(intentos==7){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|\n|\n|\n|\n|\n|__\n");	
	}
	if(intentos==6){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|\n|\n|\n|\n|__\n");	
	}
	if(intentos==5){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|        |\n|\n|\n|\n|__\n");
	}
	if(intentos==4){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _| \n|       \n|\n|\n|__\n");
	}																			
	if(intentos==3){																				 
	printf("Te quedan %d intentos\n\n", intentos);					 
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|       \n|\n|\n|__\n");
			}
				
	if(intentos==2){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        |\n|\n|\n|__\n");
	}
	if(intentos==1){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       |  \n|\n|__\n");
	}
	if(intentos==0){
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       | |\n|\n|__\n");
	printf("HAS PERDIDO :(\n");	
	return 1;
	}
	return 0;
}

void Puntuaciones(usuario lista_punt[D],FILE *leer_archivo){//Ordena el vector de usuarios de mayor (en la posición 0) a menor
	usuario aux;
	int i=0,j;
	while(fscanf(leer_archivo,"%[^.].%i\n",lista_punt[i].nombre,&lista_punt[i].punt)!=EOF)
		i++;
	for(i=0;lista_punt[i].punt!=0;i++)
		for(j=i+1;lista_punt[j].punt!=0;j++)
			if(lista_punt[i].punt<lista_punt[j].punt){
				aux=lista_punt[i];
				lista_punt[i]=lista_punt[j];
				lista_punt[j]=aux;
			}
						system("cls");
		printf("\t   Nombre \t Puntuacion");
		for(i=0;lista_punt[i].punt!=0&&i<10;i++)
			printf("\n\t%i- %s \t %i",i+1,lista_punt[i].nombre,lista_punt[i].punt);
