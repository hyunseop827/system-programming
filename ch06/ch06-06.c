/*
 * environ
 *
 * environ is pointer for all environments.
 *
 * #include <unistd.h>
 *
 * extern char * *environ;
 *
 */

#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main() {
	char **env;

	env = environ;

	// so in C, usually in next to while 0/NULL means false, and else are true.
	// **env ends with NULL at the end.
	// *env[n] = NULL
	// so while(*env) is okay with this time.
	
	while (*env){
		printf("%s\n", *env);
		env++;
	}
}

