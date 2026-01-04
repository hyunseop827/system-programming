/*
 * argc, argv seem okay, yet sperating each options and processing are difficult.
 * 
 * getopt (Linux)
 *
 * #include <unistd.h>
 *
 * int getopt(int argc, char * const argv[], const char *optstring);
 * extern char *optarg;
 * extern int optind, opterr, optopt;
 *
 * argc: declared in main.
 * argv: declared in main.
 * optstring: string for options to be used in this program.
 *
 * example.
 * abc: means, -abc <argument>
 * `:` means exactly one argument is required.
 * 
 * `optarg` is when charater that needs `:`, which means requiring arguments.
 * `optind` is next address of argv, initialised as 1.
 *
 * getopt returns same option character, when it's on `optstring`.
 * getopt returns `?` and error message when there is error.
 *
 * charater that occured error will be written in optopt.
 * when opterr = 0, it won't show up error message.
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int n;
	extern char *optarg;
	extern int optind;

	printf("Current Optind : %d\n", optind);
	while ((n = getopt(argc,argv, "abc:")) != -1){
		switch (n){
			case 'a':
				printf("Option: a\n");
				break;
			case 'b':
				printf("Option: b\n");
				break;
			case 'c':
				printf("Option: c, Arguments=%s\n", optarg);
				break;
		}
		printf("Next Optind : %d\n", optind);
	}
}
