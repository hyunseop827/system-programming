/*
 * get user ID and print home directory and login shell
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	char user_id[256];

	printf("user id? :");
	scanf("%s", user_id);

	struct passwd *pw;

	pw = getpwnam(user_id);

	if(pw == NULL){
		printf("user not found\n");
		exit(1);
	}

	printf("Home Directory: %s\n", pw->pw_dir);
	printf("Login ID: %s\n",pw->pw_name);

	return 0;
}

