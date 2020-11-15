#include <stdlib.h>
#include <stdio.h>

 struct cuadrilatero{
     int base;
     float altura;
   }; 
  
int main(int argc, char *argv[]){
	if(argc != 3){
		printf("numero de argumentos invalidos");
		exit(-1);
	}
	int i,j;
   struct cuadrilatero cuadrilatero1;
   cuadrilatero1.base= atoi(argv[1]);
   cuadrilatero1.altura= atoi(argv[2]);
   printf("Base del cuadrilatero1: %d \n", cuadrilatero1.base);
   printf("Altura del cuadrilatero1: %.4f \n", cuadrilatero1.altura);
 
 for(i=1;i<=cuadrilatero1.altura;i++){
		if(i==1 || i==cuadrilatero1.altura){
		  printf("+");	
		}
		else{
			printf("|");
		}
		for(j=1;j<cuadrilatero1.base-1;j++){
			if(i==1 || i==cuadrilatero1.altura){
				printf("__");
			}
			else{
				printf("  ");
			}
		}
		if(i==1 || i==cuadrilatero1.altura){
		  printf("+");	
		}
		else{
			printf("|");
		}
		printf("\n");
	}
 
  return 0;

 }

