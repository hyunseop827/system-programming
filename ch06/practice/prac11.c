/*
 * using loop and do file IO with `open()` and `close()` for 100000000 and check the system time and user mode time
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void file_io(mode_t mode) {
	// FILE IO
	for(int i =0 ; i < 100000000;  i++){
		int fd = open("test.txt", O_RDONLY);
		close(fd);
	}
}

int main() {

	struct tms buf1, buf2;
	clock_t ct, t1, t2;

	ct = sysconf(_SC_CLK_TCK);
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd;

	printf("making test.txt file...\n");
	fd = creat("test.txt", mode);
	close(fd);

	printf("start file IO...\n");

	if ((t1 = times(&buf1)) == -1){
		perror("times 1");
		exit(1);
	}

	file_io(mode);

	if ((t2 = times(&buf2)) == -1){
		perror("times 2");
		exit(1);
	}

	printf("file IO is finnished\n");
	unlink("test.txt");

	double user = (double)(buf2.tms_utime - buf1.tms_utime) / ct;
	double system = (double)(buf2.tms_stime - buf1.tms_stime) / ct;

	printf("user time: %.2f\n", user);
	printf("system time: %.2f\n", system);

	return 0;
}

