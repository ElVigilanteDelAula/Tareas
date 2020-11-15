#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("numero de argumentos invalido\n");
		exit(-1);
	}
	
	int ancho = atoi(argv[1]), alto = atoi(argv[2]),i,j;
	for(i=1;i<=alto;i++){
		if(i==1 || i==alto){
		  printf("+");	
		}
		else{
			printf("|");
		}
		for(j=1;j<ancho-1;j++){
			if(i==1 || i==alto){
				printf("-");
			}
			else{
				printf(" ");
			}
		}
		if(i==1 || i==alto){
		  printf("+");	
		}
		else{
			printf("|");
		}
		printf("\n");
	}
	
	return 0;
}
