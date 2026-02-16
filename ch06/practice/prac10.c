/*
 * #include <stdio.h>
 *
 * int main() {
 * 	sleep(5);
 * }
 *
 * check the running time.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int test_main(void){
	sleep(5);
}

int main() {

	time_t t;
	struct tms buf;

	clock_t t1, t2, ct;

	if ((t1 = times(&buf)) == -1){
		perror("time 1");
		exit(1);
	}

	test_main();

	if((t2 = times(&buf)) == -1){
		perror("time 1");
		exit(1);
	}

	ct = sysconf(_SC_CLK_TCK);

	printf("run-time for code: %.2f sec\n", (double)(t2-t1)/ct);

	return 0;
}


	

