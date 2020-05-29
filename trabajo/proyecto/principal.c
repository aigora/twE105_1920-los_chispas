#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "ahorcadolib.h"
#include "batallalib.h"
#include "rayalib.h"
#include "hundirlaflotalib.h"


void ahorcado_juego();

void batalla_juego();

void tresenraya_juego();

void hundirlaflota_juego();

int main()
{
	
	char letra;
	do
	{

	printf("\tBienvenido a Gameboys\nSelecciona un juego\na)Ahorcado\nb)Batalla\nc)3 en raya\n");
	scanf(" %c", &letra);
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
		
		
		case 'c':
		case 'C':
		{
		 tresenraya_juego();
		}break;
		
		case 'd':
		case 'D':
		{
		 hundirlaflota_juego();
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
	
	//Ataques enemigoes

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
		char chaz;
	int intentos=0, fallos=0;
	int aleatorio=0;
    do
    {
printf("\n\n\n\n\n\n");
//	char letra;
//	int intentos=0, fallos=0;
//	int aleatorio=0;
	char letrausuario[D]=" ";
	 adivinanza peliculas[8]={"MISION IMPOSIBLE", "TOP GUN", "STAR WARS", "INDIANA JONES", "JUMANJI", "LOS VENGADORES", "EL IRLANDES", "HARRY POTTER"};
    adivinanza series[8]={"JUEGO DE TRONOS", "BREAKING BAD", "LA CASA DE PAPEL", "ELITE", "ARROW", "POKEMON", "VIKINGOS", "STRANGER THINGS"};
	adivinanza teams[8]={"REAL MADRID", "ATLETICO DE MADRID", "BARCELONA", "LIVERPOOL", "WATFORD", "GENK", "RIVER", "BOCA JUNIORS"};
	printf("\tBienvenidos al Ahorcado !!!!!\n");
    printf("\n");
	printf("\tEstamos listos??\n");
    printf("\n"); 
	printf("Bien, comencemos!!!!\n");
	printf("Selecciona categoria:\n\ta)Peliculas\n\tb)Series\n\tc)Equipos Futbol\n");
   scanf(" %c", &chaz);

	switch (chaz)
    {
       		case 'a':
			case 'A':
                printf("\n\n\n");
				printf("Has elegido la categoria de Peliculas\n");
				aleatorio = numaleatorio(8)-1;
				juego(peliculas[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'b':
			case 'B':
                printf("\n\n\n");
				printf("Has elegido la categoria de Series\n");
				aleatorio = numaleatorio(8)-1;
				juego(series[aleatorio].nomb, letrausuario);
	  			break;
	           
       		case 'c':
			case 'C':
                printf("\n\n\n");
				printf("Has elegido la categoria de Equipos de Futbol\n");
				aleatorio = numaleatorio(8)-1;
				juego(teams[aleatorio].nomb, letrausuario);
	  			break;
	           

			default:
			printf("Error, seleccione opcion valida\n");
  
			   			   			
	}
    	printf("\n Quieres jugar de nuevo? Pulsa 1:");
        scanf("%i", &r);
        printf("%i", r);
		}while(r==1);
}

void tresenraya_juego(){



	
	printf("            BIENVENIDO AL TRES EN RAYA,PREPARADO?\n\n\n\n");
	
	char tab[3][3];
	
	fun (tab);
	


}
void hundirlaflota_juego(){
	//VARIABLES
		int mapaCPU[nf][nc]; //Mapa del ordenador
		int mapaAlmirante[nf][nc]; //Mapa del jugador
		int DisparosmapCPU[nf][nc]; //Mapa del rastro de disparos lanzados por la CPU
		int DisparosmapAlm[nf][nc]; //Mapa del rastro de disparos lanzados por el jugador
		int Almhundido, CPUhundido; //Variable que detecta si el barco esta hundido
		char casilla[2]; //Casilla del tablero con formato letra + numero (ej: A1)
		char coordbarco1[2], coordbarco2[2];
		int film, columm;
		int fililla1, columnilla1, fililla2, columnilla2;
		int lanchaCPU=2, submarinoCPU=3, buqueCPU=4, portaavionesCPU=5; //Tipos de barcos de la CPU y su longitud
		int lanchaAlm=2, submarinoAlm=3, buqueAlm=4, portaavionesAlm=5; //Tipos de barcos del jugador y su longitud
		int barcosCPU=4, barcosAlm=4; //Numero de barcos de cada flota
		int letra, i, j, a, b, c, d;
		int barcoacolocar=1; 
	  	int comprobacioncasilla1=1, comprobacioncasilla2=1;
	  	int numbarcos;
		int finalizado=0; //Si es uno el juego finaliza
		int numdisp=0; //numero de disparos realizados por el jugador
		
	int comienzo;
	printf("--------------------------------------------------\n-----------BIENVENIDO A HUNDIR LA FLOTA-----------\n--------------------------------------------------\n");
	printf("Para empezar a jugar pulse 1, si desea ver las instrucciones pulse 2:\n\n");
	scanf(" %i",&comienzo);
	do{
		if(comienzo==1)
			break;
		if(comienzo==2){
			printf("Es un juego en el que diriges una flota y tendras que derrotar a la flota de la CPU\n");
			printf("Hay un tablero en el que tendrás que colocar tus barcos\n");
			printf("Deberas ir introduciendo las coordenadas de la primera y la ultima casilla de cada barco siguiendo el formato ej: E5\n");
			printf("Cuando hayas terminado, deberas comenzar tu ataque, escogiendo casillas a las que atacar\n");
			printf("Para hundir un barco enemigo deberás golpear todas sus casillas\n");
			printf("Ganas si hundes todos los barcos enemigos y pierdes si el enemigo te destruye todos tus barcos antes\n");
			printf("!!Adelante, Almirante!!\n\n\n");
			break;
		}
	}while(comienzo==1 || comienzo==2);
	srand (time(NULL));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i<nf; i++){
		for (j = 0; j<nc; j++){
				mapaCPU[i][j] = 0; 
				mapaAlmirante[i][j] = 0;
			}	
	}	
	
	for (i = 0; i<nf; i++){
		for (j = 0; j<nc; j++){
				DisparosmapAlm[i][j] = '*';
				DisparosmapCPU[i][j] = '*';
			}	
	}
	
	ponerbarcosCPU(5,mapaCPU,5);	//Coloca un portaaviones 
	ponerbarcosCPU(4,mapaCPU,4);	//Coloca los buque s
	ponerbarcosCPU(3,mapaCPU,3);	//Coloca los submarinos
  	ponerbarcosCPU(2,mapaCPU,2);	//Coloca las lancha 
  	
  	do{
  		if(barcoacolocar==1) //Pide las casillas del barco y lo crea en el mapa
  		{
  			  	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				if(comprobacioncasilla1==0 || comprobacioncasilla2==0)
					printf("Coordenadas introducidas no válidas, vuelva a introducir la casilla con el formato adecuado ej: E3\n\n");
				printmapa1(mapaAlmirante);
				printf("Introduzca la primera casilla del portaaviones, ocupa 5 casillas\n");
				scanf(" %s", &coordbarco1);
				comprobacioncasilla1 = infcasilla(coordbarco1);
				a=letafil(coordbarco1);
				b=numacol(coordbarco1);
				fililla1=a;
				columnilla1=b;
			
				if(comprobacioncasilla1==1){
					printf("\nIntroduzca la segunda casilla del portaaviones\n");
					scanf(" %s", &coordbarco2);
					comprobacioncasilla2 = infcasilla(coordbarco2);
					c=letafil(coordbarco2);
					d=numacol(coordbarco2);
					fililla2=c;
					columnilla2=d;
	
					if (comprobacioncasilla2== 1)			
						if (ponerbarcosAlm(fililla1, fililla2, columnilla1, columnilla2, DisparosmapAlm, 5)==1)
							barcoacolocar++;			
				}
		}
		if(barcoacolocar==2) //Pide las casillas del barco y lo crea en el mapa
  		{
  			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			if(comprobacioncasilla1==0 || comprobacioncasilla2==0)
				printf("Coordenadas introducidas no válidas, vuelva a introducir la casilla con el formato adecuado ej: E3\n");
				printmapa1(mapaAlmirante);
				printf("Introduzca la primera casilla del buque, ocupa 4 casillas\n");
				scanf(" %s", &coordbarco1);
				comprobacioncasilla1 = infcasilla(coordbarco1);
				a=letafil(coordbarco1);
				b=numacol(coordbarco1);
				fililla1=a;
				columnilla1=b;
				
					if(comprobacioncasilla1==1){
						printf("\nIntroduzca la segunda casilla del buque\n");
						scanf(" %s", &coordbarco2);
						comprobacioncasilla2 = infcasilla(coordbarco2);
						c=letafil(coordbarco2);
						d=numacol(coordbarco2);
						fililla2=c;
						columnilla2=d;
						if (comprobacioncasilla2== 1)			
							if (ponerbarcosAlm(fililla1, fililla2, columnilla1, columnilla2, DisparosmapAlm, 4)==1)
								barcoacolocar++;			
				}	
		}
		if(barcoacolocar==3) //Pide las casillas del barco y lo crea en el mapa
  		{
  			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			if(comprobacioncasilla1==0 || comprobacioncasilla2==0)
				printf("Coordenadas introducidas no válidas, vuelva a introducir la casilla con el formato adecuado ej: E3\n");
				printmapa1(mapaAlmirante);
				printf("Introduzca la primera casilla del submarino, ocupa 3 casillas\n");
				scanf(" %s", &coordbarco1);
				comprobacioncasilla1 = infcasilla(coordbarco1);
				a=letafil(coordbarco1);
				b=numacol(coordbarco1);
				fililla1=a;
				columnilla1=b;
				
					if(comprobacioncasilla1==1){
						printf("\nIntroduzca la segunda casilla del submarino\n");
						scanf(" %s", &coordbarco2);
						comprobacioncasilla2 = infcasilla(coordbarco2);
						c=letafil(coordbarco2);
						d=numacol(coordbarco2);
						fililla2=c;
						columnilla2=d;
						if (comprobacioncasilla2== 1)			
							if (ponerbarcosAlm(fililla1, fililla2, columnilla1, columnilla2, DisparosmapAlm, 3)==1)
								barcoacolocar++;			
					}
		}
		if(barcoacolocar==4) //Pide las casillas del barco y lo crea en el mapa
  		{
  			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			if(comprobacioncasilla1==0 || comprobacioncasilla2==0)
				printf("Coordenadas introducidas no válidas, vuelva a introducir la casilla con el formato adecuado ej: E3\n");
				printmapa1(mapaAlmirante);
				printf("Introduzca la primera casilla de la lancha, ocupa 2 casillas\n");
				scanf(" %s", &coordbarco1);
				comprobacioncasilla1 = infcasilla(coordbarco1);
				a=letafil(coordbarco1);
				b=numacol(coordbarco1);
				fililla1=a;
				columnilla1=b;
				
					if(comprobacioncasilla1==1){
						printf("\nIntroduzca la segunda casilla de la lancha\n");
						scanf(" %s", &coordbarco2);
						comprobacioncasilla2 = infcasilla(coordbarco2);
						c=letafil(coordbarco2);
						d=numacol(coordbarco2);
						fililla2=c;
						columnilla2=d;
						if (comprobacioncasilla2== 1)			
							if (ponerbarcosAlm(fililla1, fililla2, columnilla1, columnilla2, DisparosmapAlm, 2)==1)
								barcoacolocar++;			
					}
		}
		if (barcoacolocar==5) //se termina la colocacion de barcos por parte del jugador
		{
			numbarcos++;
			break;
		}
	}while(numbarcos==0);
	  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	  printf("Se aproxima al enemigo, vamos a derrotarlos Almirante\nComo se dice quien golpea primero, golpea 2 veces\nVamos a sorprender al enemigo!\n\n");

	  while(finalizado==0)
	  {
	  	printmapa1(DisparosmapAlm);
	  	Almhundido=ataqueAlm();
	  	numdisp++;
	  	
	  	if(Almhundido==2) //Signfica que ha tocado un barco con numero de casillas igual al numero que aparece, en este caso una lancha
		{
		  	lanchaCPU--;
		  	if(lanchaCPU==0) //Si este numero es 0 significa que has tocado todas sus casillas y lo hundes
				{
				printf("Comandante hemos conseguido hundir una lancha enemiga!\n");
				barcosCPU--;
			}
		}
	  	if(Almhundido==3) 
		{
		  	submarinoCPU--;
		  	if(submarinoCPU==0)
			{
				printf("Comandante hemos conseguido hundir un submarino enemiga!\n");
				barcosCPU--;
			}
		}
	  	if(Almhundido==4) 
		{
		  	buqueCPU--;
		  	if(buqueCPU==0)
			{
				printf("Comandante hemos conseguido hundir un buque enemigo!\n");
				barcosCPU--;
			}
		}
	  	if(Almhundido==5) 
		{
			portaavionesCPU--;
		  	if(portaavionesCPU==0)
			{
				printf("Comandante hemos conseguido hundir el portaaviones enemigo!\n");
				barcosCPU--;
			}
		}
	  
		if(barcosCPU==0)//Cuando hundes todos los barcos
		{
		FILE *puntos;
			char usuario;
			int puntuacion;
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Lo hemos conseguido Almirante hemos derrotado a la flota enemiga!\n");
			printf("Almirante que nombre deseas ponerle a esta batalla?\n");
			scanf(" %c", &usuario);	
			printf("Este ha sido tu numero de disparos utilizados: %i\n",numdisp);
			if(numdisp<=20){
				printf("Ha sido una batalla relámpago, hemos tenido mucha suerte Almirante\n");
				puntuacion=100;	
			}
			else if(numdisp>20 && numdisp<=40){
				printf("No ha sido una batalla corta pero tampoco larga, hemos tenido suerte Almirante\n");
				puntuacion=80;	

			}
			else if(numdisp>40 && numdisp<=60){
				printf("Ha sido una batalla dura pero pordría haber sido peor, ha ido bien Almirante\n");
				puntuacion=60;	
			}	
			else if(numdisp>60 && numdisp<=80){
				printf("Ha sido una batalla larga, debemos volver a base Almirante hemos sufrido daños\n");	
				puntuacion=40;	
			}
			else if(numdisp>80 && numdisp<=100){
				printf("Ha sido una batalla horrible, no veía algo así desde Pearl Harbor, debemos volver a base Almirante hemos sufrido enormes bajas\n");
				puntuacion=20;	
			}
			fprintf(puntos, "Batalla:%s, Numerodisparos:%i, Puntuacion:%i", usuario, numdisp, puntuacion);
			fclose(puntos);
			finalizado++;
			break;
		}
	
	  	printf("Nos estan atacando ahora\n\n");
	  	CPUhundido=ataqueCPU();
		if(CPUhundido==2) //Signfica que ha tocado un barco con numero de casillas igual al numero que aparece, en este caso una lancha
		{
		  	lanchaAlm--;
		  	if(lanchaAlm==0) //Si este numero es 0 significa que has tocado todas sus casillas y lo hundes
				{
				printf("Comandante hemos conseguido hundir una lancha enemiga!\n");
				barcosAlm--;
			}
		}
	  	if(CPUhundido==3) 
		{
		  	submarinoAlm--;
		  	if(submarinoAlm==0)
			{
				printf("Comandante hemos conseguido hundir un submarino enemiga!\n");
				barcosAlm--;
			}
		}
	  	if(CPUhundido==4) 
		{
		  	buqueAlm--;
		  	if(buqueAlm==0)
			{
				printf("Comandante hemos conseguido hundir un buque enemigo!\n");
				barcosAlm--;
			}
		}
	  	if(CPUhundido==5) 
		{
			portaavionesAlm--;
		  	if(portaavionesAlm==0)
			{
				printf("Comandante hemos conseguido hundir el portaaviones enemigo!\n");
				barcosAlm--;
			}
		}
		if(barcosAlm==0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Almirante ha sido masacre, pero no moriremos en vano, nuestros aliados habrán ganado el tiempo suficiente para destruir el resto de su ejercito\n");
			finalizado++;
			break;
		}
	}	  
}
