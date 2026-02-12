/*
 * write mydate
 * options
 *
 * -a: y.m.d.day.h.m.s
 * -y: year
 * -m: month
 * -d: day
 * -w: day
 * -h: h.m.s
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>

void print_option(char n, struct tm *tm) {
	switch(n){
		case 'a':
			printf("%d.%d.%d.%d.%d.%d.%d\n",
       tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_wday,
       tm->tm_hour, tm->tm_min, tm->tm_sec);
			break;

		case 'y':
			printf("%d\n", tm->tm_year + 1900);
			break;
		case 'm':
			printf("%d\n", tm->tm_mon + 1);
			break;
		case 'd':
			printf("%d\n", tm->tm_mday);
			break;
		case 'w':
			printf("%d\n", tm->tm_wday);
			break;
		case 'h':
			printf("%d.%d.%d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
			break;

		default:
			perror("unknown option");
			exit(1);
			break;
	}
}


int main (int argc, char* argv[]){

	extern char *optarg;
	extern int optind;

	struct tm *tm;
	time_t timep;

	time(&timep);
	tm = localtime(&timep);

	char n;
	while((n = getopt(argc, argv, "aymdwh")) != -1){
		print_option(n, tm);
	}

	return 0;
}


