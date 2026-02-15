/*
 * using `sysinfo()` and print system's memory and swap status.
 *
 */

#include <stdio.h>
#include <sys/sysinfo.h>

int main() {

	struct sysinfo info;

	sysinfo(&info);

	printf("total-memory: %ld\n", info.totalram);
	printf("swap status: %ld / %ld\n", info.totalswap, info.freeswap);

	return 0;
}

