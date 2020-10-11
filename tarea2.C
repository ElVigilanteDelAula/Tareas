#include <stdio.h>
#include <stdlib.h>

int main(){

	char caracter = 'e';
	int valor_ascii = (int) caracter;
	if(valor_ascii>=48 && valor_ascii<=57){
		printf("digito\n");
		}
	else{
		if(valor_ascii<=90 && valor_ascii>64){
			printf("mayuscula\n");
			}
		else{
			if(valor_ascii>96 && valor_ascii<123){
				printf("minuscula\n");	
				}
			else{
				printf("caracter especial\n");
				}
			}
		}
	printf("el valor del caracter %c es %i\n\n\n", caracter, valor_ascii);
	system("pause");
	system("cls");
	
	int entero1=10, entero2=3;
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
