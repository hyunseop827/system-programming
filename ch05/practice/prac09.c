/*
 * using `sysconf()` and check login ID's length is longer than MAX login name length.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

	int max_login;
	int login;

	max_login = (int)sysconf(_SC_LOGIN_NAME_MAX);
	login = strlen(getlogin());

	printf("max_login_length: %d\n", max_login);
	printf("login_id_length: %d\n", login);

	return 0; 
}

