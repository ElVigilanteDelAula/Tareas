#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct datos{
	char matricula[' ']; 
	float parcial1, parcial2,parcial3,parcial4, parcial5, parcial6, parcial7;
};

void leer_archivo(struct datos *punteros, FILE*fp);
int promedio_alumno(struct datos *punteros);
int parciales_reprobados_por_alumnos(struct datos *punteros);
void promedio_parcial(struct datos *punteros, int *puntero_parcial);
int promedio_grupo(int calificaciones,int promedios[],int i);
void reprobados_por_parcial(int *puntero_reprobados, struct datos *punteros);
int reprobados(int promedios[],int i);
void impresion(struct datos *punteros, int promedios_alumno[], int parciales_reprobados[], int i,FILE*fp);
void impresion2(int promedios_parciales[], FILE*fp, int parciales_reprobados[],int total_de_no_aprobados,int promedio_por_grupo);


int main(){
FILE*fp;
char archivo[' '],parciales[' '][7];
int tamano=0, promedio_alumno_parcial[' '], parciales_reprobados[' '],
promedio_por_parciales[7]={0}, promedio_por_grupo=0, cantidad_reprobados_parcial[7]={0},total_de_no_aprobados;
fp =fopen("calificaciones_pia_pe.csv","r+");

while((fscanf(fp,"%s\n",archivo))!=EOF){
	tamano++;
}
tamano = tamano-1;
rewind(fp);
struct datos examenes[tamano];
fscanf(fp,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,\n]\n",examenes[0].matricula, parciales[0], parciales[1], parciales[2], parciales[3], parciales[4], parciales[5], parciales[6]);

for(int i=0;i<tamano;i++){
	leer_archivo(&examenes[i], fp);
}

for(int i=0;i<tamano;i++){
	promedio_alumno_parcial[i] = promedio_alumno(&examenes[i]);
	parciales_reprobados[i] = parciales_reprobados_por_alumnos(&examenes[i]);
	promedio_parcial(&examenes[i], promedio_por_parciales);
	reprobados_por_parcial(cantidad_reprobados_parcial,&examenes[i]);
}

for(int i=0;i<=6;i++){
	promedio_por_parciales[i]= ((float)promedio_por_parciales[i]/tamano) + 0.5;
	promedio_por_grupo=promedio_grupo(promedio_por_grupo,promedio_por_parciales, i);
}

promedio_por_grupo = ((float)promedio_por_grupo/7) + 0.5;
total_de_no_aprobados=reprobados(promedio_alumno_parcial,tamano);
fclose(fp);

fp =fopen("Calificaciones_pia(completa).csv","w+");
fprintf(fp,"matricula,parcial1,parcial2,parcial3,parcial4,parcial5,parcial6,parcial7,promedio de calificaciones parciales,no aprobados\n");
for(int i=0;i<tamano;i++){	
	impresion(&examenes[i],promedio_alumno_parcial,parciales_reprobados,i,fp);
}
	impresion2(promedio_por_parciales,fp,cantidad_reprobados_parcial,total_de_no_aprobados,promedio_por_grupo);
	
fclose(fp);
printf("el archivo esta listo");
return 0;
}



void leer_archivo(struct datos *punteros, FILE*fp){
	char matricula_4_digitos[' '];
fscanf(fp,"%[^,], %f, %f, %f, %f, %f, %f, %f ",punteros->matricula,&punteros->parcial1,&punteros->parcial2,&punteros->parcial3,&punteros->parcial4,&punteros->parcial5,&punteros->parcial6,&punteros->parcial7);
 	strrev(punteros->matricula);
 	strncpy(matricula_4_digitos,punteros->matricula,4);
 	strrev(matricula_4_digitos);
 	strcpy(punteros->matricula,matricula_4_digitos);
}

int promedio_alumno(struct datos *punteros){
	int promedio;
	promedio = punteros->parcial1 + punteros->parcial2 + punteros->parcial3 + punteros->parcial4 + punteros->parcial5 + punteros->parcial6 + punteros->parcial7;
	promedio= ((float)promedio/7) + 0.5;
	return promedio;
}

int parciales_reprobados_por_alumnos(struct datos *punteros){
	int cantidad=0;
	
	if(punteros->parcial1<7){
		cantidad++;
	}
	if(punteros->parcial2<7){
		cantidad++;
	}
	if(punteros->parcial3<7){
		cantidad++;
	}
	if(punteros->parcial4<7){
		cantidad++;
	}
	if(punteros->parcial5<7){
		cantidad++;
	}
	if(punteros->parcial6<7){
		cantidad++;
	}
	if(punteros->parcial7<7){
		cantidad++;
	}
	return cantidad;
}

void promedio_parcial(struct datos *punteros, int *puntero_parcial){
	puntero_parcial[0]= puntero_parcial[0] + punteros->parcial1;
	puntero_parcial[1]= puntero_parcial[1] + punteros->parcial2;
	puntero_parcial[2]= puntero_parcial[2] + punteros->parcial3;
	puntero_parcial[3]= puntero_parcial[3] + punteros->parcial4;
	puntero_parcial[4]= puntero_parcial[4] + punteros->parcial5;
	puntero_parcial[5]= puntero_parcial[5] + punteros->parcial6;
	puntero_parcial[6]= puntero_parcial[6] + punteros->parcial7;
}
int promedio_grupo(int calificaciones,int promedios[],int i){
	calificaciones = calificaciones + promedios[i];
	return calificaciones;
}
void reprobados_por_parcial(int *puntero_reprobados, struct datos *punteros){
	if(punteros->parcial1<7){
		puntero_reprobados[0]= puntero_reprobados[0] + 1;
	}
	if(punteros->parcial2<7){
		puntero_reprobados[1]= puntero_reprobados[1] + 1;
	}
	if(punteros->parcial3<7){
		puntero_reprobados[2]= puntero_reprobados[2] + 1;
	}
	if(punteros->parcial4<7){
		puntero_reprobados[3]= puntero_reprobados[3] + 1;
	}
	if(punteros->parcial5<7){
		puntero_reprobados[4]= puntero_reprobados[4] + 1;
	}
	if(punteros->parcial6<7){
		puntero_reprobados[5]= puntero_reprobados[5] + 1;
	}
	if(punteros->parcial7<7){
		puntero_reprobados[6]= puntero_reprobados[6] + 1;
	}
}

int reprobados(int promedios[],int i){
	int cantidad=0;
	for(int j=0; j<i;j++){
	if(promedios[j]<7){
		cantidad++;
	}
}
	return cantidad;
}
void impresion(struct datos *punteros, int promedios_alumno[], int parciales_reprobados[], int i, FILE*fp){
	fprintf(fp,"%c%s,%2.f,%2.f,%2.f,%2.f,%2.f,%2.f,%2.f,",02,punteros->matricula,punteros->parcial1,punteros->parcial2,punteros->parcial3,punteros->parcial4,punteros->parcial5,punteros->parcial6,punteros->parcial7);
	fprintf(fp,"%i,%i\n",promedios_alumno[i],parciales_reprobados[i]);
}

void impresion2(int promedios_parciales[], FILE*fp, int parciales_reprobados[],int total_de_no_aprobados,int promedio_por_grupo){
	int i;
	fprintf(fp,"promedios\n ,");
	for(i=0;i<=6;i++){	
		if(i==6){
			fprintf(fp,"%i, ,%i\n",promedios_parciales[i],promedio_por_grupo);
		}
		else{	
			fprintf(fp,"%i,",promedios_parciales[i]);
		}
	}
	fprintf(fp,"No aprobados\n ,"); 
	for(i=0;i<=6;i++){	
		if(i==6){
			fprintf(fp,"%i, ,%i\n",parciales_reprobados[i],total_de_no_aprobados);
		}
		else{	
			fprintf(fp,"%i,",parciales_reprobados[i]);
		}
	}
}

