/*
 * If system call was successed it returns 0, else -1.
 * errno store error code.
 * man page describes each error codes.
 *
 * errno is external variable where error codes will be written
 * after system call or library function, all result code will be in errno.
 *
 * errno is not return from function or system call.
 * errno is error code when system call and function returns -1 or NULL.
 * errno is for checking error code to know why it would happen
 */

#include <stdio.h>
#include <unistd.h>
#include <error.h>

extern int errno;

int main() {
	if (access ("test.txt", F_OK) == -1 ){
		printf("errno=%d\n",errno);
	}
}
