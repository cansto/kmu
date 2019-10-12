#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int *value = (int*)malloc(sizeof(int));
	*value = 100;

	value = NULL;
	printf("%d\n", *value);

	return 0;
}
