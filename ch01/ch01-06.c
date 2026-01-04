/*
 * CLA (Command Line Arguments) is argument when user use command line.
 *
 * example.
 * ls -l : `-l` is consider as arugments and option.
 *
 * CLA is automatically brought to main.
 * usually main is defined like this.
 * int main() { ~ } / int main(void) { ~ }
 *
 * if main wants CLA, should be declared like this.
 * int main(int argc, char *argv[]) { ~ }
 *
 * argc: number of arguments, size of argv.
 * argv: array of each argument.
 *
 * argv[0] is name of program.
 */

#include <stdio.h>

int main(int argc, char *argv[]){
	int n;

	printf("argc = %d\n", argc);
	for(n = 0; n <argc; n++){
		printf("argv[%d] = %s\n", n, argv[n]);
	}
}

