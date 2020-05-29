#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//definimos las filas y columnas
#define nf 10
#define nc 10

#include "hundirlaflotalib.h"

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


