#include <stdlib.h>
#include <stdio.h>

typedef int (*operador)(int[]);

struct estructuras{
	int numeros_entrada[5];
	operador funcion_operador;
};

int suma(int numeros_suma[]);
int menor(int numeros_menor[]);
int mayor(int numeros_mayor[]);
int promedio(int promedio[]);
int ejecutador(struct estructuras *puntero);


int main(){
	struct estructuras estructura[4];
	int i;
	
	for(i=0; i<4; i++){
		for(int j=0; j<5; j++){
			estructura[i].numeros_entrada[j]= j;
		}
	}
	
	estructura[0].funcion_operador = suma;
	estructura[1].funcion_operador = menor;
	estructura[2].funcion_operador = mayor;
	estructura[3].funcion_operador = promedio;
	
	for(i=0;i<4;i++){
		int resultado = ejecutador(&estructura[i]);
		printf("resultado de la funcion %i = %i\n",i+1,resultado);
	}
	return 0;
}


int suma(int numeros_suma[]){
	int valor_total=0;
	for(int i=0;i<5;i++){
		valor_total = valor_total + numeros_suma[i];
	}
	return valor_total;
}


int menor(int numeros_menor[]){
	int valor_menor = numeros_menor[1];
	for(int i=0;i<5;i++){
		valor_menor = (valor_menor<numeros_menor[i]) ?valor_menor : numeros_menor[i];
	}
}


int mayor(int numeros_mayor[]){
	int valor_mayor = numeros_mayor[1];
	for(int i=0;i<5;i++){
		valor_mayor= (valor_mayor>numeros_mayor[i]) ?valor_mayor : numeros_mayor[i];
	}
}


int promedio(int promedio[]){
	int promedio_total=0;
	for(int i=0;i<5;i++){
		promedio_total = promedio_total + promedio[i];
	}
	promedio_total = (float) promedio_total/5;
	return promedio_total;
}


int ejecutador(struct estructuras *puntero){
    return puntero->funcion_operador(puntero->numeros_entrada);
}

