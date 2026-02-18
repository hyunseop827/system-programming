/*
 * with CLA and set ENV.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("2 arguments required\n");
		exit(1);
	}

	char *env = argv[1];
	char *value = argv[2];

	char *val = getenv(env);

	if(val == NULL){
		printf("%s is not defined ...\nset ENV\n", env);

		setenv(env,value,0);

		printf("finished...\n");
		char *res = getenv(env);
		printf("%s = %s\n", env, res);
	}
	else{
		printf("%s is always defined as %s\n", env, val);
		printf("want to overwrite? (1:yes, 0: no)\n");
		int choice;
		scanf("%d", &choice);	

		if(choice == 0){
			printf("bye bye\n");
			return 0;
		}
		else if(choice == 1){
			printf("overwriting...\n");
			setenv(env, value, 1);

			char *res = getenv(env);
			printf("%s is now %s\n", env, res);
			return 0;
		}
		else{
			printf("inapproriate option...\n");
			printf("error!!\n");
			exit(1);
		}
	}
}

