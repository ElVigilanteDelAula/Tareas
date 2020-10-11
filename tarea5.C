#include <stdio.h>
#include <stdlib.h>

int main (){
	int matriz1[' '][' '], matriz2[' '][' '], matriz_resultante[' '][' '],i,j,contador=0;
	printf("matriz 1\n");
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			matriz1[i][j]= contador;
			contador++;
			printf("%i ",matriz1[i][j]);
		}
		printf("\n");
	}
	printf("\n\nmatriz 2\n");
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			matriz2[i][j]= contador;
			contador++;
			printf("%i ",matriz2[i][j]);
		}
		printf("\n");
	}
	printf("\n\nmatriz resultante\n");
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			matriz_resultante[i][j]= matriz1[i][j]+matriz2[i][j];
			contador++;
			printf("%i ",matriz_resultante[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
