/*
 * write code, with CLA.
 * print original permission and change permission
 *
 * ex)
 * mychomod 777 a.c
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
	//break down numbers.
	if (length != 3) {
		printf("permission should be 3 digits\n");
		exit(1);
	}

	unsigned int new_p = 0;

	int u = permission[0]-'0';
	int g = permission[1]-'0';
	int o = permission[2]-'0';

	// in case of user
	if(u == 1) new_p |= S_IXUSR;
	else if(u == 2) new_p |= S_IWUSR;
	else if(u == 4) new_p |= S_IRUSR;
	else if(u == 3) new_p |= (S_IWUSR | S_IXUSR);
	else if(u == 5) new_p |= (S_IXUSR | S_IRUSR);
	else if(u == 6) new_p |= (S_IWUSR | S_IRUSR);
	else if(u == 7) new_p |= (S_IRUSR | S_IWUSR | S_IXUSR);


	if(g == 1) new_p |= S_IXGRP;
	else if(g == 2) new_p |= S_IWGRP;
	else if(g == 4) new_p |= S_IRGRP;
	else if(g == 3) new_p |= (S_IWGRP | S_IXGRP);
	else if(g == 5) new_p |= (S_IXGRP | S_IRGRP);
	else if(g == 6) new_p |= (S_IWGRP | S_IRGRP);
	else if(g == 7) new_p |= (S_IRGRP | S_IWGRP | S_IXGRP);


	if(o == 1) new_p |= S_IXOTH;
	else if(o == 2) new_p |= S_IWOTH;
	else if(o == 4) new_p |= S_IROTH;
	else if(o == 3) new_p |= (S_IWOTH | S_IXOTH);
	else if(o == 5) new_p |= (S_IXOTH | S_IROTH);
	else if(o == 6) new_p |= (S_IWOTH | S_IROTH);
	else if(o == 7) new_p |= (S_IROTH | S_IWOTH | S_IXOTH);
	
	
	//chmod;
	chmod(target,new_p);

}

