#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("numero de argumentos invalidos");
		exit(-1);
	}
	int entero1=atoi(argv[1]), entero2=atoi(argv[2]);
	int suma= entero1 + entero2, resta = entero1-entero2, multiplicacion = entero1*entero2;
	int division_entera = entero1/entero2;
	float division_flotante= (float) entero1/entero2;
	printf("la suma de %i y %i es = %i\n",entero1, entero2, suma); 
	printf("la resta de %i y %i es = %i\n",entero1, entero2, resta);
	printf("la multiplicacion de %i y %i es = %i\n",entero1, entero2, multiplicacion);
	printf("la division entera de %i y %i es = %i\n",entero1, entero2, division_entera);
	printf("la division flotante de %i y %i es = %f\n\n\n",entero1, entero2, division_flotante);
	system("pause");
	system("cls");   
	return 0;
}
