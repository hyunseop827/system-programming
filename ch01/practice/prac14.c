/*
 * write code for CLA program, and sum numbers givin as arguments.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int sum = 0;

	// cast to string
	int a = atoi (argv[1]);
	int b = atoi (argv[2]);

	// case 1 - numbers are equal.
	if(a == b){
		printf("sum = %d",a);
		return 0;
	}

	// case 2 - numbers are not eqaul.
	int max = a > b ? a : b;
	int min = a < b ? a : b; 

	for(int i = min ; i <= max ; i++){
		sum += i;
	}

	printf("sum = %d", sum);
	return 0;
}
