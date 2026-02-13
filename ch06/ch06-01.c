/*
 * sysinfo
 * 
 * returns sysinfo struct
 *
 * #include <sys/sysinfo.h>
 *
 * int sysinfo(struct sysinfo *info);
 *
 * info: address of sysinfo
 *
 */

/*
 * struct sysinfo {
 * 	long uptime; // seconds after boot.
 * 	unsigned long loads[3]; // array for system overload avg.
 * 	unsigned long totalram; // size of ram.
 * 	unsigned long freeram; // size of available ram.
 * 	unsigned long sharedram; // size of shared ram.
 * 	unsigned long bufferram; // size of ram that buffer uses.
 * 	unsigned long totalswap; // size of swap area.
 * 	unsigned long freeswap; // size of available swap area.
 * 	unsigned short procs; // the number of currently running processes.
 * 	unsigned long totalhigh; // size of high memory that assigned to user.
 * 	unsigned long freehigh; // size of available user memory.
 * 	unsigned int mem_unit; // memory in byte.
 * 	char _f[20-2*sizeof(long)-sizeof(int)]; // padding to make it as 64bit
 * }
 */

#include <sys/sysinfo.h>
#include <stdio.h>

int main() {
	struct sysinfo info;

	sysinfo(&info);

	printf("total ram: %ld\n", info.totalram);
	printf("free ram: %ld\n", info.freeram);
	printf("number of proccess: %d\n", info.procs);

	return 0;
}

