/*
 * stat 
 *
 * stat function returns i-node's infos of file. 
 * it doesn't need to have authority when you use this fuction.
 * yet, still need read authorioty to reach directory.
 * returns 0, when it's successed, else return -1.
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * #include <unistd.h>
 *
 * int stat(const char *pathname, struct stat *statbuf);
 * 
 * pathname: file
 * statbuf: address of struct to store infos.
 *
 * stat struct is for storing inode's infos.
 * it denpends on which distro, yet usually you can check with
 * `man -s 2 stat`
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	stat("linux.txt", &statbuf);

	printf("I-node= %d\n",(int)statbuf .st_ino);
	printf("Mode= %o\n", (unsigned int)statbuf .st_mode);
	printf("Nlink= %o\n", (unsigned int)statbuf .st_nlink);
	printf("UID= %d\n", (int)statbuf .st_uid);
	printf("GID= %d\n", (int)statbuf .st_gid);
	printf("SIZE= %d\n", (int)statbuf .st_size);
	printf("Blksize= %d\n",(int)statbuf .st_blksize);
	printf("Blocks= %d\n", (int)statbuf .st_blocks);

	printf("** timespec style\n");
	printf("Atime= %d\n", (int)statbuf .st_atim.tv_sec);
	printf("Mtime= %d\n", (int)statbuf .st_mtim.tv_sec);
	printf("Ctime= %d\n", (int)statbuf .st_ctim.tv_sec);
	printf("** old style\n");
	printf("Atime= %d\n", (int)statbuf .st_atime);
	printf("Mtime= %d\n", (int)statbuf .st_mtime);
	printf("Ctime= %d\n", (int)statbuf .st_ctime);
}

