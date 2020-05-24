#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define D 30
#define F 20
//ESTRUCTURAS
typedef struct{
	char nomb[D];
}adivinanza;

typedef struct{
	char nombre[D];
	int punt;
}usuario;

//FUNCIONES 
int numaleatorio(int n);//1
void juego(char adivinapalabra[D], char cadena[D]);//2
int ahorcado(char adivinapalabra[D], char cadena[D]);//3
int imp_ahorcado(int intentos);//4
void Puntuaciones(usuario lista_punt[F],FILE *leer);//5

//CODIGO PRINCIPAL
void main()
{
    do
    {
	system ("PAUSE");    	
    system("cls");
	char letra;
	int intentos=0, fallos=0;
	int aleatorio=0;
	char letrausuario[D]=" ";
	 adivinanza peliculas[8]={"MISION IMPOSIBLE", "TOP GUN", "STAR WARS", "INDIANA JONES", "JUMANJI", "LOS VENGADORES", "EL IRLANDES", "HARRY POTTER"};
    adivinanza series[8]={"JUEGO DE TRONOS", "BREAKING BAD", "LA CASA DE PAPEL", "ELITE", "ARROW", "POKEMON", "VIKINGOS", "STRANGER THINGS"};
	adivinanza teams[8]={"REAL MADRID", "ATLETICO DE MADRID", "BARCELONA", "LIVERPOOL", "WATFORD", "GENK", "RIVER", "BBOCA JUNIORS"};
	printf("\tBienvenidos al Ahorcado !!!!!\n");
		system ("PAUSE");
			system("CLS");
	printf("\tEstamos listos??\n");
		system ("PAUSE");
			system("CLS");
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   scanf(" %c", &letra);

	switch (letra)
    {
       		case 'a':
			case 'A':
				system("CLS");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(8)-1;
				juego(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'b':
			case 'B':
				system("CLS");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8)-1;
				juego(series[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'c':
			case 'C':
				system("CLS");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8)-1;
				juego(teams[aleatorio].nomb, letrausuario);
	  			break;
	           

			default:
			printf("Error, seleccione opcion valida\n");
			system ("PAUSE");  
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");
		//if(getch()=='1') {
		//	system("cls");
		}while(getch()=='1');
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

void juego(char adivinapalabra[D], char usadas[D])
{int errores=0, intentos=7, puntuacion, perder, i=0;
 char nombre_g[D]="";
 float t1 =clock(), t2, tf;
 usuario lista_puntuaciones[F]={{"iniciar",0}};
 FILE *agregar=fopen("puntuacion_ahorcado.txt","a");
	if(agregar==NULL){
		printf("\n\t Error");
		exit(1);
	}
while(1)
{
	errores=ahorcado(adivinapalabra, usadas);
	if(errores==-1)
	{
		printf("Enhorabuena, has ganado!!!!!!!");
		t2=clock();
		tf=(t2-t1)/CLOCKS_PER_SEC;
		puntuacion=1000000/tf*intentos;
		printf("Tu puntuacion ha sido de %d y lo has terminado en %f, no esta nada mal...", puntuacion, tf);
		printf("Con que nombre quieres guardar la puntuacion obtenida?\n");
		scanf(" %s\n", nombre_g);
			fprintf(agregar, "%s.%i\n", nombre_g, puntuacion);
			fclose(agregar);
			FILE *leer=fopen("puntuacion_ahorcado.txt","r");
			Puntuaciones(lista_puntuaciones, leer);
			break;
	}
	intentos-=errores;
	perder=imp_ahorcado(intentos);	
	if(perder==1)
	break;
	printf("\n\tLlevas seleccionadas las siguientes letras: %s\n", usadas);
	printf("\n\tIntroduce nueva letra\n");
	usadas[i]=getch();
	system("cls");
	i++;	
}

}

//3
int ahorcado(char adivinapalabra[D], char letrausuario[D])
{
	int i=0, a, same, ultima_letra_usuario=strlen(letrausuario), dif='A'-'a', Pregunta_fallo, ganado=1;
	while(adivinapalabra[i]!='\0')
	{
	  for(a=0, same=0; a<ultima_letra_usuario; a++)
	  {
	  	if(letrausuario[a]==adivinapalabra[i] || letrausuario[a]==adivinapalabra[i]-dif)
	  	{same=1;
		  }
		  }
	  if(same==1){
	    printf(" %c", adivinapalabra[i]);}
    	else if(adivinapalabra[i]==' '){
			printf("   "); }
	  else{
	  	ganado=0;
	  	if(adivinapalabra[i]>= 'A' && adivinapalabra[i]<='Z'){
	  		printf("_ ");
		  }
		  	  	if(adivinapalabra[i]>= 'a' && adivinapalabra[i]<='z'){
	  		printf("_ ");
		  }
	  }	
	  i++;	  	
	}
	if(ganado==1){
		//printf("\nHAS GANADO!!");
		return -1;
	}
	if(strlen(adivinapalabra)!=1)
		for(i=0,Pregunta_fallo=1;adivinapalabra[i]!='\0';i++)
			if(letrausuario[ultima_letra_usuario-1]==adivinapalabra[i] || letrausuario[ultima_letra_usuario-1]==adivinapalabra[i]-dif)
				Pregunta_fallo=0;
		
	return Pregunta_fallo;	
}


//4
int imp_ahorcado(int intentos)
{
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
	printf("\tHAS PERDIDO :(\n");	
	return 1;
	}
	return 0;
}



//5
void Puntuaciones(usuario lista_punt[F],FILE *leer_archivo)
{
	usuario aux;
	int i, a;
	i=0;
		while(fscanf(leer_archivo,"%[^.].%i\n",lista_punt[i].nombre,&lista_punt[i].punt)!=EOF){
		i++;}
			for(i=0;lista_punt[i].punt!=0;i++)
		      for(a=i+1;lista_punt[a].punt!=0;a++)
		    	if(lista_punt[i].punt<lista_punt[a].punt){
				aux=lista_punt[i];
				lista_punt[i]=lista_punt[a];
				lista_punt[a]=aux;
			}
    system("cls");
    printf("\t   Nombre \t Puntuacion");
		for(i=0;lista_punt[i].punt!=0&&i<10;i++)
			printf("\n\t%i- %s \t %i",i+1,lista_punt[i].nombre,lista_punt[i].punt);    
}





