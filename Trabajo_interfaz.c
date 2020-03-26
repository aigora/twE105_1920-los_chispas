#include<stdio.h>

int main()
{
	char nombre[11];
	int opt;

	printf("Bienvenido, por favor, escribe tu nombre: ");
	scanf("%s", nombre);
	
	printf("Hola %s, comienza tu nueva aventura\n", nombre);

	printf("Ecoge una de estas opciones para comenzar:\n1)Simulador Batallas\n");
	printf("2)3 en raya\n3)Quien quiere ser Gamemillonario\n4)Ahorcado\n5)Hundir la flota\n6)Your Decision\n");
	
	do
	{
		scanf("%i", &opt);
	}
	while(opt<1 || opt>6);
		switch(opt)
		{
		    case 1:
		    printf("\n");
		      printf("1)Simulador Batallas\n");
		      break;

		    case 2:
		      printf("\n");
		      printf("2)3 en raya\n");
		      break;

		    case 3:
		      printf("\n");
		      printf("3)Quien Quiere ser Gamemillonario\n");
		      break;

		    case 4:
		      printf("\n");
		      printf("4)Ahorcado\n");
		      break;

		    case 5:
		      printf("\n");
		      printf("5)Hundir la flota\n");
		      break;

		    case 6:
		      printf("\n");
		      printf("6)Your Decision\n");
		      break;
    		}
}
