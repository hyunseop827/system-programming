/*
 * exit()
 *
 * exit() stop process and return status value to parent.
 * at this moment, it launches all the fucntion where functions which are reserved by `atexit()`
 * if `atexit()` couldn't return, then exit() also doesn't return rest.
 *
 * exit() also close all the streams after makes them flush. and them delete all the files from `tmpfile()`
 * after this, it calls `_exit()` which is system call and returns all the resources which was been using by process.
 *
 * it's because `exit()` is C standard function so it needs to call system call.
 *
 * #include <stdlib.h>
 *
 * void exit(int status);
 *
 * status: exit status value.
 *
 */

/*
 * atexit()
 *
 * `atexit()` and `on_exit()` functions book functions before process exit.
 *
 * #include <stdlib.h>
 *
 * int atexit(void (*function)(void));
 * int on_exit(void (*function)(int, void *), void *arg);
 *
 * function: name of fucntions to call before exit.
 *
 */

/*
 * _exit()
 *
 * usually it doesn't get called by itself, normally called by from `exit()`
 *
 * #include <unistd.h>
 *
 * void _exit(int status);
 *
 * stauts: exit status value.
 *
 */

#include <stdlib.h>
#include <stdio.h>

void cleanup1(){
	printf("clean up 1 is called.\n");
}

void cleanup2(int status, void *arg){
	printf("clean up 2 is called: %ld.\n", (long)arg);
}

int main(){
	atexit(cleanup1);
	on_exit(cleanup2, (void *) 20);

	exit(0);
}

