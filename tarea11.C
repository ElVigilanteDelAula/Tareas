#include <stdio.h>
#include <string.h>

struct Evaluacion{
    char Matricula[15];
    int PrimerParcial;
    int SegundoParcial;
    int PIA;
    float Final;
} Evaluaciones[3];


void ingreso_de_datos();
void impresion_de_datos();


int main(){
   ingreso_de_datos();
   impresion_de_datos();
   return 0;
}

   
void ingreso_de_datos(){
	for(int i=0;i<3;i++){
		Evaluaciones[i].PrimerParcial = 10 - i;
		Evaluaciones[i].SegundoParcial = 10 - i;
		Evaluaciones[i].PIA = 10 - i;
		Evaluaciones[i].Final= 10 - i;
	}
   strcpy(Evaluaciones[0].Matricula, "11");
   strcpy(Evaluaciones[1].Matricula, "12");
   strcpy(Evaluaciones[2].Matricula, "13");
} 


void impresion_de_datos(){
   FILE *fp;
   fp = fopen("evaluaciones.csv", "w+");
   fprintf(fp, "Matricula; PrimerParcial; SegundoParcial; PIA; Final\n");
   for(int i = 0; i < 3; i++){
      fprintf(fp, "%s; %d; %d; %d; %.2f\n", Evaluaciones[i].Matricula, Evaluaciones[i].PrimerParcial, Evaluaciones[i].SegundoParcial, Evaluaciones[i].PIA, Evaluaciones[i].Final);
   }
   fclose(fp);
   printf("Archivo guardado");
}
