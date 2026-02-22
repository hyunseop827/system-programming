/*
 * wrtie code with `system()` print currently directory's absolute path and file list
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	system("pwd");
	system("ls -l");

	return 0;
}

