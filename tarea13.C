#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct datos{
	char matricula[' '];
	float parcial1,parcial2,pia;
};
void imprimir(struct datos *puntero, FILE *fp, int promedio);
int main(int argc, char *argv[]){
	int promedio;
	FILE*fp;
	struct datos examen;
	if(argc != 5){
		printf("numero de argumentos invalidos");
		exit(-1);
	}
	strcpy(examen.matricula,argv[1]);
	examen.parcial1= atoi(argv[2]);
	examen.parcial2= atoi(argv[3]);
	examen.pia= atoi(argv[4]);
	promedio= (examen.parcial1 + examen.parcial2 + examen.pia)/3;
	imprimir(&examen,fp,promedio);
}

void imprimir(struct datos *puntero, FILE *fp,int promedio){
	fp=fopen("tarea13.csv","w+");
	fprintf(fp,"matricula,parcial1,parcial2,pia,promedio\n");
	fprintf(fp,"%s,%2.f,%2.f,%2.f,%i\n",puntero->matricula,puntero->parcial1,puntero->parcial2,puntero->pia,promedio);
	
}
