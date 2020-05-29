#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//definimos las filas y columnas
#define nf 10
#define nc 10

//Funciones
int printmapa1(int map[nf][nc]); //Imprime mapa inicial con casillas
int printmapac(int map[nf][nc]); //Imprime un mapa que pueda contener caracteres
int ponerbarcosAlm(int fililla1, int fililla2, int columnilla1, int columnilla2, int map[nf][nc], int l);
int ponerbarcosCPU(int l, int map[nf][nc], int tipo);
int ataqueCPU(); //Disparos de la CPU
int ataqueAlm(); //Disparos del jugador
int infcasilla(char casilla[2]); //Comprueba si el formato de casilla introducio es válido y asigna unos valores a la coordenada introducida
int letafil(char casi[2]);
int numacol(char casi[2]);

int printmapac(int map[nf][nc]) //Imprime una matriz como tablero inicial con casillas determinadas por una letra y un numero (ej: A1)
{
    int i;
    
    printf("   |");
    for(i=1; i<=10; i++){
    		printf(" %i |",i);	
		}
		printf("\n---------------------------------------------\n A |");
	for(i=0; i<10; i++){
			printf(" %c |",map[0][i]);	
		}
		printf("\n---------------------------------------------\n B |");
	for(i=0; i<10; i++){
			printf(" %c |",map[1][i]);
		} 
	    printf("\n---------------------------------------------\n C |");
	for(i=0; i<10; i++){
			printf(" %c |",map[2][i]);
		}	   	
		printf("\n---------------------------------------------\n D |");
	for(i=0; i<10; i++){
			printf(" %c |",map[3][i]);
		}
		printf("\n---------------------------------------------\n E |");
	for(i=0; i<10; i++){
			printf(" %c |",map[4][i]);
		}
		printf("\n---------------------------------------------\n F |");
	for(i=0; i<10; i++){
			printf(" %c |",map[5][i]);
		}    
		printf("\n---------------------------------------------\n G |");
	for(i=0; i<10; i++){
			printf(" %c |",map[6][i]);
		}   	
		printf("\n---------------------------------------------\n H |");
	for(i=0; i<10; i++) {
			printf(" %c |",map[7][i]);
		}
		printf("\n---------------------------------------------\n I |");
	for(i=0; i<10; i++){
			printf(" %c |",map[8][i]);
		}
	   	printf("\n---------------------------------------------\n J |");	
	for(i=0; i<10; i++){
			printf(" %c |",map[9][i]);
		}  
	    printf("\n---------------------------------------------\n");
}
int printmapa1(int map[nf][nc]) //Imprime una matriz como tablero inicial con casillas determinadas por una letra y un numero (ej: A1)
{
    int i;
    
    printf("   |");
    for(i=1; i<=10; i++){
    		printf(" %i |",i);	
		}
		printf("\n---------------------------------------------\n A |");
	for(i=0; i<10; i++){
			printf(" %i |",map[0][i]);	
		}
		printf("\n---------------------------------------------\n B |");
	for(i=0; i<10; i++){
			printf(" %i |",map[1][i]);
		} 
	    printf("\n---------------------------------------------\n C |");
	for(i=0; i<10; i++){
			printf(" %i |",map[2][i]);
		}	   	
		printf("\n---------------------------------------------\n D |");
	for(i=0; i<10; i++){
			printf(" %i |",map[3][i]);
		}
		printf("\n---------------------------------------------\n E |");
	for(i=0; i<10; i++){
			printf(" %i |",map[4][i]);
		}
		printf("\n---------------------------------------------\n F |");
	for(i=0; i<10; i++){
			printf(" %i |",map[5][i]);
		}    
		printf("\n---------------------------------------------\n G |");
	for(i=0; i<10; i++){
			printf(" %i |",map[6][i]);
		}   	
		printf("\n---------------------------------------------\n H |");
	for(i=0; i<10; i++) {
			printf(" %i |",map[7][i]);
		}
		printf("\n---------------------------------------------\n I |");
	for(i=0; i<10; i++){
			printf(" %i |",map[8][i]);
		}
	   	printf("\n---------------------------------------------\n J |");	
	for(i=0; i<10; i++){
			printf(" %i |",map[9][i]);
		}  
	    printf("\n---------------------------------------------\n");
}
int infcasilla(char casi[2]) //Comprueba si el formato de casilla introducio es válido y asigna unos valores a la coordenada introducida
{
	int film, columm;
	if((casi[0]>='a' && casi[0]<='j') || (casi[0]>='A' && casi[0]<='J')) //Asigna a la letra de la casilla a una fila
		{
		if(casi[0]>='a' && casi[0]<='j')
		{
				film = casi[0] - 'a';
		}
		else if(casi[0]>='A' && casi[0]<='J')
		{
				film = casi[0] - 'A';
		}
		else
				return 0;
		}
	if (casi[1] >= 49 && casi[1] <= 57) //Asigna aL numero de la casilla a una columna
	{
		columm = casi[1]- '1';
				return 1;
	}
		else
				return 0;
}
int letafil(char casi[2]) //Pasa la letra de la coordenada introducida a la fila equivalente
{
	int film, columm;
	if(casi[0]>='a' && casi[0]<='j')
		{
				film = casi[0] - 'a';
		}
		else if(casi[0]>='A' && casi[0]<='J')
		{
				film = casi[0] - 'A';
		}
		return (film);
}
int numacol(char casi[2]) //Pasa el numero de la coordenada introducida a la columna equivalente
{
	int film, columm;
	if (casi[1] >= 49 && casi[1] <= 57) //Asigna aL numero de la casilla a una columna
		columm = casi[1]- '1';
	return (columm);
}
int ataqueAlm() //Disparos del jugador
{
	int a, b;
	int dispara = 0;
	char casilladp[2];
	int film, columm;
	int mapaAlmirante[nf][nc];
	int DisparosmapCPU[nf][nc];
	while(dispara==0)
	{	
		printf("Almirante decida la casilla a la que va a disparar: \n");
		scanf(" %s", &casilladp);
		infcasilla( casilladp);
		a=letafil(casilladp);
		b=numacol(casilladp);
		film=a;
		columm=b;
		if(infcasilla( casilladp) == 1){
			if (mapaAlmirante[film][columm] != '*'){ //comprueba si anteriormente habia disparado en esa posicion
				printf("\n  Ya has disparado a esa casilla, intenta otra distinta");
			}
			else
			{
				if (DisparosmapCPU[film][columm] == 0) //Cuando tocas agua y fallas se sabra porque la casilla es 0 
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					mapaAlmirante[film][columm] = '~';
					printf("Has fallado, hemos tocado agua");
					return 0;
				}
				if (DisparosmapCPU[film][columm] == 2) //Cuando es 2 ha dado a una slancha de tamaño2
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado una lancha");
					mapaAlmirante[film][columm] = '2';
					return 2;
				}
				if (DisparosmapCPU[film][columm] == 3) //Cuando es 3 ha dado a un submarino de tamaño 3 
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un submarino");
					mapaAlmirante[film][columm] = '3';
					return 3;
				}
				if (DisparosmapCPU[film][columm] == 4) //Cuando es 4 ha dado a un buque de tamaño 4
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un buque");
					mapaAlmirante[film][columm] = '4';
					return 4;
				}
				if (DisparosmapCPU[film][columm] == 5) //Cuando es 5 ha dado a un portaaviones de tamaño5
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("Hemos tocado un portaaviones");
					mapaAlmirante[film][columm] = '5';
					return 5;
				}
			}
		}
	}
}
int ataqueCPU() //Disparos de la CPU
{
	
	int film, columm;
	int dispara = 0;
	int mapaCPU[nf][nc], DisparosmapAlm[nf][nc];
	while(dispara==0)
	{
		film = rand() % (nf); //fila random a la que disparo
		columm = rand() % (nc); //columa random a la que dispara
			if (mapaCPU[film][columm] == '*'){ //comprueba si anteriormente habia disparado en esa posicion
				if (DisparosmapAlm[film][columm] == 0) //Cuando toca agua se sabra porque la casilla es 0
				{
					mapaCPU[film][columm] = '~';
					printf("Uff, nos hemos salvado los enemigos han fallado");
					return 0;
				}
				else  
				{
					if (DisparosmapAlm[film][columm] == 2) //Cuando es 2 ha dado a una slancha de tamaño2
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado una de nuestras lancha");
						mapaCPU[film][columm] = '2';
						return 2;
					}
					if (DisparosmapAlm[film][columm] == 3) //Cuando es 3 ha dado a un submarino de tamaño 3 
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado uno de nuestros submarino");
						mapaCPU[film][columm] = '3';
						return 3;
					}
					if (DisparosmapAlm[film][columm] == 4) //Cuando es 4 ha dado a un buque de tamaño 4
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado uno de nuestros buques");
						mapaCPU[film][columm] = '4';
						return 4;
					}
					if (DisparosmapAlm[film][columm] == 5) //Cuando es 5 ha dado a un portaviones de tamaño5
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("El enemigo ha tocado nuestro portaaviones");
						mapaCPU[film][columm] = '5';
						return 5;
					}
				}
			}
	}	
}
//coloca los barcos según la primera fila y columna introducidas y su última fila y colummna, la clase viene definida por un numero que señala que barco es
int ponerbarcosAlm(int fililla1, int fililla2, int columnilla1, int columnilla2, int mapaAlmirante[nf][nc], int l)
{
	int repetido=0;
	int i;
	int clase = 0;
	if(fililla1==fililla2){
		if((columnilla1 < columnilla2) && (columnilla2-columnilla1+1)==l)
			if(columnilla1+l <= nf){
				for(i=columnilla1;i<=columnilla2;i++){
				if(mapaAlmirante[fililla1][i]!=0)
					repetido++;
				}
				if(repetido==0){
					for(i=columnilla1;i<=columnilla2;i++)  
		    				mapaAlmirante[fililla1][i]= l;
		      			clase++;
		      			return clase;
				}
			}
		if((columnilla1 > columnilla2) && (columnilla1-columnilla2+1)==l)
			if(columnilla1+1 >= l){
				for(i=columnilla1;i>=columnilla2;i--){
					if(mapaAlmirante[fililla1][i]!=0)
						repetido++;
				}
				if(repetido==0){
					for(i=columnilla1;i>=columnilla2;i--)
		    				mapaAlmirante[fililla1][i]= l;
	      				clase++;
	      				return clase;
				}			
			}
	}
	if(columnilla1 == columnilla2){
		if((fililla1 < fililla2) && (fililla2-fililla1+1)==l)
			if(fililla1+ l <= nf){
				for(i=fililla1;i<=fililla2;i++){
				if(	mapaAlmirante[i][columnilla1]!=0)
					repetido++;
				}
				if(repetido==0){
					for(i=fililla1;i<=fililla2;i++)  
	    					mapaAlmirante[i][columnilla1]= l;
	      				clase++;
	      				return clase;
				}
			}
			
		
		if((fililla1 > fililla2) && (fililla1-fililla2+1)== l)
			if(fililla1>= (l-1)){
				for(i=fililla1;i>=fililla2;i--){
					if(	mapaAlmirante[i][columnilla1]!=0)
						repetido++;
				}
				if(repetido==0){
					for(i=fililla1;i>=fililla2;i--)  
		    				mapaAlmirante[i][columnilla1]= l;
		      			clase++;
		      			return clase;
				}
			}
	}
}
int ponerbarcosCPU(int l, int mapa[nf][nc], int tipo)
{
	
	int filX, columnX, repetido, vacio=0;
	int i, dir; //l es la longitud de los barcos y dir la direccción que utilizaremos ahora
	do
	{
		filX = rand() % (nf); 
		columnX = rand() % (nc);
		dir = rand() % (4) +1;
		repetido=0;
		
		if(dir==1)							
	  		if(filX+1 >= l)				//Comprueba que cabe un barco arriba de la casilla generada
	  		{ 
				for(i=filX;i>=(filX-l+1);i--)  	      	
		      		if(mapa[i][columnX]!=0)	    		
		    			repetido++;					      	
		    	if(repetido==0)
		   		{
	  	  			for(i=filX;i>=(filX-l+1);i--)  
		      			mapa[i][columnX]=tipo;
		      		vacio++;
		   		}
			}
			
		if(dir==2)							
		if(columnX+l <= nf)					//Comprueba que cabe un barco a la derecha de la casilla generada
  		{ 
	 		for(i=columnX;i<=(columnX+l-1);i++)  	      	
	      		if(mapa[filX][i]!=0)	    	
	    			repetido++;					      	
	   		if(repetido == 0)
	   		{
  	  			for(i=columnX;i<=(columnX+l-1);i++)  	      		
	    			mapa[filX][i]=tipo;	      		
	   			vacio++;
	    	}
		}
		
		if(dir==3)							
	  		if(filX+l <= nf)				//Comprueba que cabe un barco abajo de la casilla generada
	  		{ 
				for(i=filX;i<=(filX+l-1);i--)  	      	
		      		if(mapa[i][columnX]!=0)	    		
		    			repetido++;					      	
		    	if(repetido==0)
		   		{
	  	  			for(i=filX;i<=(filX+l-1);i--)
		      			mapa[i][columnX]=tipo;
		      		vacio++;
		   		}
			}
		
		if(dir==4)							
		if(columnX+1 >= l)					//Comprueba que cabe un barco a la izquierda de la casilla generada
  		{ 
	 		for(i=columnX;i>=(columnX-l+1);i++)  	      	
	      		if(mapa[filX][i]!=0)	    	
	    			repetido++;					      	
	   		if(repetido == 0)
	   		{
  	  			for(i=columnX;i>=(columnX-l+1);i++)      		
	    			mapa[filX][i]=tipo;	      		
	   			vacio++;
	    	}
		}	
	}while(vacio==0);
}


void main()
{
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



