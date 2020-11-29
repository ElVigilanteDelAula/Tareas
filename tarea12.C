#include <stdio.h>
#include <stdlib.h>
struct lector{
	int matricula_str[255], primer_parcial_str[255], segundo_parcial_str[255], pia_str[255], final_str[255];
};
 
void archivo(struct lector *punters, int i);


int main(){
	struct lector lector_archivo[3];
	for(int i=0; i<3;i++){
		archivo(&lector_archivo[i], i);
   }
}

 void archivo(struct lector *punteros, int i){
	int j=0;
	FILE*fp;
    fp = fopen("evaluaciones.csv", "r+"); 
    	fscanf(fp, "%s %s %s %s %s\n", punteros->matricula_str, punteros->primer_parcial_str, punteros->segundo_parcial_str, punteros->pia_str, punteros->final_str);
	for(j=0;j<=i;j++){
	fscanf(fp, "%s %s %s %s %s\n", punteros->matricula_str, punteros->primer_parcial_str, punteros->segundo_parcial_str, punteros->pia_str, punteros->final_str);
    }
	printf("a ");
	printf("linea %i :%s %s %s %s %s\n",i+1,punteros->matricula_str, punteros->primer_parcial_str, punteros->segundo_parcial_str, punteros->pia_str, punteros->final_str);
   
   fclose(fp);
}

