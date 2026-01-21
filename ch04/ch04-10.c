/*
 * remove
 *
 * to remove file, remove is provided.
 * if target is file, then it calls unlink, else it calls rmdir.
 * directory is deleted when it's only empty.
 *
 * #include <stdio.h>
 *
 * int remove(const char* pathname);
 *
 * pathname: path of file.
 *
 */

/*
 * fsync
 *
 * it allows datas in memory to be writed on disk 
 * i guess it's flush.
 * it doesn't return, until synchroinse is finished.
 *
 * #include <unistd.h>
 * 
 * int fsync(int fd);
 *
 * fd: file discriptor to write on disk.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	int ret;

	ret = remove("tmp.bbb");

	if(ret == -1){
		perror("remove tmp.bbb");
		exit(1);
	}

	printf("remove tmp.bbb was successful!\n");

	return 0;
}

