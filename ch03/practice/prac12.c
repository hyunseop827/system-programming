/*
 * write code, with CLA.
 * print original permission and change permission
 *
 * ex)
 * mychomod g+w a.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){

	int count = argc;

	if(count != 3){
		printf("2 arugments required\n");
		exit(1);
	}

	//declare stuff...
	char* target = argv[2];
	char* permission = argv[1];

	// debug 
	printf("%s -- %s \n",target,permission);
	struct stat statbuf;
	int result;

	// stat to print original permission
	result = stat(target, &statbuf);

	if(result == -1){
		perror("stat");
		exit(1);
	}

	// printf original permission
	unsigned int k = (unsigned int)statbuf.st_mode;

	// cases...
	// rwx rwx rwx \0
	char og_p[10] = "---------"; 
	if ( (k & S_IRUSR) != 0 ) og_p[0] = 'r';
	if ( (k & S_IWUSR) != 0 ) og_p[1] = 'w';
	if ( (k & S_IXUSR) != 0 ) og_p[2] = 'x';

	if ( (k & S_IRGRP) != 0 ) og_p[3] = 'r';
	if ( (k & S_IWGRP) != 0 ) og_p[4] = 'w';
	if ( (k & S_IXGRP) != 0 ) og_p[5] = 'x';

	if ( (k & S_IROTH) != 0 ) og_p[6] = 'r';
	if ( (k & S_IWOTH) != 0 ) og_p[7] = 'w';
	if ( (k & S_IXOTH) != 0 ) og_p[8] = 'x';

	printf("original permission: %s\n", og_p);

	printf("----- changing permission... ------ \n");

	//change permission.


	// break down arguemtns.
	int length = strlen(permission);

	int i = 0;
	unsigned int who_mask;
	unsigned int perm_mask;
	char op;


	while (permission[i] != '\0'){

		who_mask = 0;
		perm_mask = 0;
		op = '\0';

		while((permission[i] == 'u') || (permission[i] =='a') || (permission[i] == 'o') || (permission[i] == 'g')){

			if(permission[i] == 'u') who_mask|=S_IRWXU;
			if(permission[i] == 'g') who_mask|=S_IRWXG;
			if(permission[i] == 'o') who_mask|=S_IRWXO;
			if(permission[i] == 'a') who_mask|=(S_IRWXU|S_IRWXG|S_IRWXO);
			i++;
		}

		if (who_mask == 0){
			who_mask = (S_IRWXU|S_IRWXG|S_IRWXO);
		}

		if ((permission[i] == '-') || (permission[i]=='+') || permission[i]=='='){
			op = permission[i];
			i++;
		}
		else{
			printf("operator isn't right\n");
			exit(1);
		}

		while (permission[i] != '\0' && permission[i] != ',') {
			char c = permission[i];
			if (c == 'r') {
				if (who_mask & S_IRWXU) perm_mask |= S_IRUSR;
				if (who_mask & S_IRWXG) perm_mask |= S_IRGRP;
				if (who_mask & S_IRWXO) perm_mask |= S_IROTH;
			}
			else if (c == 'w') {
				if (who_mask & S_IRWXU) perm_mask |= S_IWUSR;
				if (who_mask & S_IRWXG) perm_mask |= S_IWGRP;
				if (who_mask & S_IRWXO) perm_mask |= S_IWOTH;
			}
			else if (c == 'x') {
				if (who_mask & S_IRWXU) perm_mask |= S_IXUSR;
				if (who_mask & S_IRWXG) perm_mask |= S_IXGRP;
				if (who_mask & S_IRWXO) perm_mask |= S_IXOTH;
			}
			else {
				printf("unexpected token\n");
				exit(1);
			}

			i++;
		}


		if (op == '+'){
			k = k| perm_mask;
		}
		else if (op=='-'){
			k = k & (~perm_mask);
		}
		else if (op=='='){
			k = (k&(~who_mask)) | perm_mask;
		}

		if (permission[i] == ','){
			i++;
			continue;
		}
		else break;
	}


	//chmod;

	chmod(target,k);

}

