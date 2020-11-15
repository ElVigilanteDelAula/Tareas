#include <stdlib.h>
#include <stdio.h>

int factorial(int valor);

int main(int argc, char *argv[]){
	int valor_total,valor;
	
	if(argc != 2){
		printf("numero de argumentos invalidos\n");
		exit(-1);
	}
	
	valor = atoi(argv[1]);
	valor_total = factorial(valor);
	printf("el valor de %i factorial es : %i",valor,valor_total);
}

int factorial(int valor){
	if(valor <= 1){
		return 1;
	}
	else{
		return valor = valor*factorial(valor-1);
	}
}
