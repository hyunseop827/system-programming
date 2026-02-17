/*
 * write code summing 1 - 100000 and print result.
 * also check the running time, user mode, system mode.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>

unsigned long long int print_sum(){
	unsigned long long int sum = 0;
	
	for (int i = 1 ; i < 100000; i++){
		sum+=i;
		printf("%d: %llu\n",i, sum);
	}

	return sum;
}

int main() {
	struct tms bf1, bf2;
	clock_t ct, t1, t2;

	ct = sysconf(_SC_CLK_TCK);

	printf("start...\n");

	if((t1 = times(&bf1)) == -1){
		perror("time 1");
		exit(1);
	}

	unsigned long long int sum = print_sum();

	if((t2 = times(&bf2)) == -1){
		perror("time 2");
		exit(1);
	}

	printf("run time: %.1f\n", (double)(t2-t1)/ct);
	printf("user mode time: %.1f\n", (double)(bf2.tms_utime-bf1.tms_utime) / ct);
	printf("system mode time: %.1f\n", (double)(bf2.tms_stime - bf1.tms_stime) /ct);
	return 0;
}

	
