#include<stdio.h>

typedef struct {
char nombre_rival[5];
int atq1[3];
int atq2[3];
int atq3[3];
int atq4[3];

} rival;

//Funciones
int multiplicador_tipo(int tipo_rival, int tipo_atq);
int acierto(int prob, int valor_aleatorio, int dano);
int critico(int valor_critico);
int dano_ataque_rival(int ataque_aleatorio, int prob1, int prob2, int prob3, int prob4, int valor_aleatorio, int ataque1, int ataque2, int ataque3, int ataque4, int valor_critico);
