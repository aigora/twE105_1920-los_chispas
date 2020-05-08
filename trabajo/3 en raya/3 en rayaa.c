#include<stdio.h>
#include<time.h>

void fun (char tab[3][3]);
void num (char tab[3][3]);
void dibujo (char tab[3][3]);
void Casillas(char tab[3][3]);
void rival(char tab[3][3]);

int main(){
	
	char tab [3][3];
printf("Bienvenido al 3 en raya\n\n");
fun (tab);



system ("pause");
return 0;
}

void fun (char tab [3][3]) {
		
num (tab);

dibujo (tab);
Casillas (tab);
dibujo (tab);
rival (tab);
dibujo (tab);

}

void num (char tab[3][3]){
	
	int i, j;
	char k;
	
	k = '1';
	for(i = 0; i < 3;i++)	{
		for (j = 0;j < 3; j++){
			
		tab[i][j] = k++;
		}
	}
	
}
void Casillas (char tab[3][3]){
	char aux;
	int i,j,k;
	do {
		
		do{
			
		printf(" Coloca una ficha: ");
		fflush (stdin);
		scanf("%c",&aux);
		
		
		}
		
		while (aux < '1' || aux > '9');
		
		k = 0;
		
		switch (aux){ 
		case '1':
		{
		
		
			i = 0;
			j = 0;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
	
			case '2':
			{
			i = 0;
			j = 1;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '3':
			{
			i = 0;
			j = 2;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '4':
			{
			i = 1;
			j = 0;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '5':{
		
			
			i = 1;
			j = 1;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '6':{
			
			
			
			i = 1;
			j = 2;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '7' :
			{
			i = 2;
			j = 0;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
			case '8':
			{
			i = 2;
			j = 1;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	}
		
			case '9':	{
			i = 2;
			j = 2;
			if (tab[i][j] == 'X' || tab[i][j] == 'O'){
				k = 1;
				printf("No puedes usar esa casilla, esta ocupada, elige otra \n\n");
				break;
		}
	
}


}
}while (k==1);
tab[i][j] = 'X';

}
void rival (char tab[3][3]){

	int i,j,k;
	srand(time(NULL));
	do {
		i = rand() % 3;
        j = rand() % 3;
        k = 0;
        
        
if (tab[i][j] == 'X' || tab[i][j] == 'O'){

k == 1;
	}
	
	
}while(k == 1);
}




void dibujo (char tab [3][3]){
	
		int i,j;
		
		
	printf("\n -------------------\n");
	
	
	
	for(i = 0; i< 3;i++)
	
	{
		for (j = 0;j < 3; j++)
		{
	printf(" | %c | ", tab[i][j]);
	
}

printf("\n -------------------\n");
}


}







