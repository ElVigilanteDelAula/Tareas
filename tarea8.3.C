#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("numero de argumentos invalidos");
		exit(-1);
	}
	int elementos_maximos = atoi(argv[1]);

     int serie[elementos_maximos];

     int indice;

     for(indice = 0; indice < elementos_maximos; indice++){

         serie[indice] = (indice+1)*(indice+1);

     }

     int sumatoria = 0;

     for(indice = 0; indice < elementos_maximos; indice++){

         sumatoria = (sumatoria + serie[indice]);

     }

     printf("Valores sumados: ");

     for(indice = 0; indice < elementos_maximos; indice++){

         printf("%i, ", serie[indice]);

     }

     printf("\nSumatoria %d", sumatoria);

     int total_calculado = (elementos_maximos*(elementos_maximos+1)*(2*elementos_maximos+1))/6;

     printf("\nTotal calculado %d", total_calculado);
	
	
	
	return 0;
}
