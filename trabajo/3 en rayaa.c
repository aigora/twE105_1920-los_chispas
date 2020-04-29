#include<stdio.h>

int main(){
	
	char tab [3][3];
printf("Bienvenido al 3 en raya\n\n");
fun (tab);



system ("pause");
return 0;
}

void fun (char tab [3][3]) {
		
num (tab);
Dibujo_tab (tab);

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
void Dibujo_tab (char tab [3][3]){
	
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






