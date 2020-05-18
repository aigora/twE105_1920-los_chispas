
#include<stdio.h>
#include<time.h>

void fun (char tab[3][3]);
void Prim (char tab[3][3]);
void dib (char tab[3][3]);
void Casillas (char tab[3][3]);
void rival (char tab[3][3]);
int final (char tab[3][3]);

int main(){
	
	printf("            BIENVENIDO AL TRES EN RAYA,PREPARADO?\n\n\n\n");
	
	char tab[3][3];
	
	fun (tab);
	

	return 0;
}

void fun (char tab[3][3]){
int i = 0,j;

Prim (tab);

do{

	dib (tab);
	
	if(i % 2 == 0){
		Casillas (tab);
	}
	
	else {
	rival (tab);
	}
	j = final (tab);
	i++;
	
}


while( i<=8 && j == 2);

	dib (tab);

if(j == 0){
	printf("¡Enhorabuena, has ganado!\n\n");
}
else if(j == 1){
		printf("Lo siento has perdido, pero puedes intentarlo de nuevo ;)\n\n");

}
else {
		printf("Has empatado, ganas de otra?\n\n");

}

}



void Prim (char tab[3][3]){
	int i,j;
	char k;
	
	k = '1';
	
	for( i = 0;i<3;i++){
		for( j=0;j<3;j++){
			tab[i][j] = k++;
		}
	}
}

void Casillas(char tab[3][3]){
	int i,j,k;
	char aux;
	
	do {
	do {
		printf("Coloca una ficha: ");
		fflush(stdin);
		scanf("%c",&aux);
	}	while (aux < '1' || aux> '9');
	
	k = 0;
	
	switch (aux){
		case '1':{
		i = 0;
		j = 0;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 1 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '2':{
		i = 0;
		j = 1;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 2 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '3':{
		i = 0;
		j = 2;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 3 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '4':{
		i = 1;
		j = 0;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 4 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '5':{
		i = 1;
		j = 1;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 5 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '6':{
		i = 1;
		j = 2;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 6 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '7':{
		i = 2;
		j = 0;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 7 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '8':{
		i = 2;
		j = 1;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 8 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
		
		case '9':{
		i = 2;
		j = 2;	
		if(tab[i][j] == 'X' ||tab[i][j] == 'O'){
			k = 1;
			printf("La casilla 9 esta ocupada, elige otra por favor \n\n");
		}
			break;
		}
	}
	}while (k == 1);
	
	tab[i][j] = 'X';
}

void rival (char tab[3][3]){
	int i,j,k;

	srand(time(NULL));
	do {
		i = rand() %3;
     	j = rand()%3;
		k = 0;
		
		 	if(tab[i][j] == 'X' || tab[i][j] == 'O'){
		 		k = 1;
			 }
	}while ( k == 1);		
	
	tab[i][j] = 'O';
}

void dib (char tab[3][3]){
	int i,j;
	
	for(i=0;i<3;i++){
		for(j = 0;j<3;j++){
	    	if (j <2){
				printf(" %c |",tab[i][j]);
	    	}
	    	else{
	    		printf(" %c ",tab[i][j]);
			}
		}
		if(i<2){
					printf("\n-----------\n");
		}
	}
	printf("\n\n");
}

int final (char tab[3][3]){
if(tab[0][0]== 'X'|| tab[0][0] == 'O'){
	if(tab[0][0] == tab[0][1] && tab[0][0]== tab[0][2] ) {
		if (tab[0][0] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	}
	if(tab[0][0]== tab[1][0] && tab[0][0] == tab[2][0]){
		if (tab[0][0] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	}
 }	
 
 if(tab[1][1] == 'X' || tab[1][1] == 'O'){
 	if ( tab[1][1] == tab[0][0] && tab[1][1] == tab[2][2]){
 		if (tab[1][1] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	}
	if ( tab[1][1]== tab[1][0] && tab[1][1] == tab[1][2]){
			if (tab[1][1] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	 }
		if ( tab[1][1]== tab[2][0] && tab[1][1] == tab[0][2]){
			if (tab[1][1] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	 }
	 	if ( tab[1][1]== tab[0][1] && tab[1][1] == tab[2][1]){
			if (tab[1][1] == 'X'){
			return 0;
		}
		else{
			return 1;
		}
	 }
 }
 if (tab[2][2] == 'X' || tab[2][2] =='O'){
 	if(tab[2][2] == tab[2][0] && tab[2][2] == tab[2][1]){
 			if (tab[2][2] == 'X'){
			return 0;
		}
		else{
			return 1;
		}	
	 }
	 if(tab[2][2] == tab[0][2] && tab[2][2] == tab[1][2]){
 			if (tab[2][2] == 'X'){
			return 0;
		}
		else{
			return 1;
		}	
	 }
 }
 return 2;
}
