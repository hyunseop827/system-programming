/*
 * system
 *
 * system is most easiest way to launch new program.
 * yet, to run this command, it also run SHELL so it's not efficient.
 *
 * #include <stdlib.h>
 *
 * int system (const char *command);
 *
 * commnad: command or file name.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	int ret;
	ret = system("ps -ef | grep sshd > sshd.txt");
	printf("Return Value: %d\n", ret);

	return 0;
}

