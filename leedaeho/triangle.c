#include <stdio.h>

int main(int argc, char* argv[]){
	int i = 0, j = 0;
	int inputParam =*(argv[1]) - '0';
		
	for(i=0 ; i<inputParam ; i++){
		for(j=0 ; j<i+1 ; j++){
			printf("*");
		} 
		printf("\n");
	}
	return 0;
}
