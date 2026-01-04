/*
 * practice allocation and re-allocation.
 * then free them.
 */

#include <stdlib.h>
#include <stdio.h>

int main(void){
	
	// malloc
	int *ptr = malloc(sizeof(int) * 100);

	// check
	if (ptr == NULL){
		perror("malloc");
		return 1;
	}
	printf("malloc\n");
	printf("memory = %zu\n",sizeof(int) * 100);

	for(int i = 0 ; i < 100; i++){
		ptr[i] = i;
	}

	// realloc
	int *tmp = realloc(ptr, sizeof(int) * 200);
	
	// check
	if(tmp == NULL){
		perror("realloc");
		return 1;
	}

	ptr = tmp;	
	printf("realloc\n");
	printf("memory = %zu\n",sizeof(int) * 200);

	for(int i = 100; i <200; i ++){
		ptr[i] = i;
	}
	
	// result
	printf("check: ptr[0]=%d ptr[99]=%d ptr[100]=%d ptr[199]=%d\n",
           ptr[0], ptr[99], ptr[100], ptr[199]);

	// free
	free(ptr);

	return 0;
}

