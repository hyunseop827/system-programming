/*
 * write a code CLA and print whether it's one of ENVs.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	
	char *target = argv[1];
	char *val;

	val = getenv(target);

	if (val == NULL)
		printf("%s is not ENV\n",target);
	else
		printf("%s is ENV: %s\n",target,val);

	return 0;
}

