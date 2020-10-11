#include <stdio.h>
#include <stdlib.h>

int main(){
	int ancho = 30, alto = 20,i,j;
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
