#include<stdio.h>
#include"batallalib.h"
int acierto(int prob, int valor_aleatorio, int dano){
	
	int fallo = 0;
	
	if(valor_aleatorio < prob)
		return dano;
	else
		return fallo;
}

int critico(int valor_critico){
	
	int multiplicador_crit;
	if(valor_critico < 15)
		multiplicador_crit = 2;
	
	else
		multiplicador_crit = 1;
	
	return multiplicador_crit;
}

int multiplicador_tipo(int tipo_rival, int tipo_atq){
	
	int multiplicador;
	
	if(tipo_rival == 1){
		
		if(tipo_atq == 1){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}
		
		else if(tipo_atq == 2){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
		
		else if(tipo_atq == 3){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
	}
	else if(tipo_rival == 2){
		
		if(tipo_atq == 1){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
		
		else if(tipo_atq == 2){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}
		
		else if(tipo_atq == 3){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
	}
	else if(tipo_rival == 3){
		
		if(tipo_atq == 1){
			
			printf("No es eficaz\n");
			multiplicador = 0;
		}
		
		else if(tipo_atq == 2){
			
			printf("Es muy eficaz\n");
			multiplicador = 2;
		}
		
		else if(tipo_atq == 3){
			
			printf("Es eficaz\n");
			multiplicador = 1;
		}	
		
	}
	return multiplicador;

}

int dano_ataque_rival(int ataque_aleatorio, int prob1, int prob2, int prob3, int prob4, int valor_aleatorio, int ataque1, int ataque2, int ataque3, int ataque4, int valor_critico){
	
	int dano_hecho_rival;
	
	if(ataque_aleatorio == 0)
	dano_hecho_rival = acierto(prob1, valor_aleatorio, ataque1) * critico(valor_critico);
	
	else if(ataque_aleatorio == 1)
	dano_hecho_rival = acierto(prob2, valor_aleatorio, ataque2) * critico(valor_critico);
	
	else if(ataque_aleatorio == 2)
	dano_hecho_rival = acierto(prob3, valor_aleatorio, ataque3) * critico(valor_critico);
	
	else if(ataque_aleatorio == 3)
	dano_hecho_rival = acierto(prob4, valor_aleatorio, ataque4) * critico(valor_critico);
	
	return dano_hecho_rival;
}
