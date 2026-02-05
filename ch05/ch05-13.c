/*
 * utmp struct
 *
 * utmp file and wtmp file share literally same format.
 * utmp struct is needed to read from files. 
 * it's written in `utmp.h`
 *
 * struct utmp {
 * 	short ut_type; // represents data type. *1
 * 	pid_t ut_pid; // login process PID.
 * 	char ut_line[YT_LINESIZE]; // device that user login into.
 * 	char ut_id[4]; // terminal name or ID from `/etc/inittab`.
 * 	char ut_user[UT_NAMESIZE]; // user name
 * 	char ut_host[UT_HOSTSIZE]; 
 * 	struct exit_status ut_exit; // session number *2
 * 	long ut_session; // seesion number 
 * 	struct timeval ut_tv; // lastest update time
 * 	int32_t ut_addr_v6[4]; // in case of ssh, it's host's address.
 * 	char __unused[20];
 * };
 * 
 * *1  check ut_type-constant.md to check about constants.
 *
 * *2  `man -s 5 utmp`.
 * 	struct exit_status {
 * 		short e_termination;
 * 		short e_exit;
 * 	};
 */

/*
 * getutent, setutent, endutent, utmpname
 *
 * >> getutent read `/var/run/utmp` sequentially. returns NULL when it's EOF.
 * >> setutent move offset of `/var/run/utmp` to the beginning.
 * >> endutent closes `/var/run/utmp`
 * >> utmpname saves login info file to other file that given in arguments.
 *
 * #include <utmp.h>
 *
 * struct utmp *getutent(void);
 * void setutent(void);
 * void endutent(void);
 * int utmpname(const char *file);
 *
 * file: file name to assgin.
 *
 */

#include <sys/types.h>
#include <utmp.h>
#include <stdio.h>

int main() {
	struct utmp *ut;
	
	printf("login name line\n");

	printf("----------------\n");

	while((ut = getutent()) != NULL){
		if(ut->ut_type != USER_PROCESS)
			continue;
		printf("%s		%s\n",ut->ut_user, ut->ut_line);
	}

	return 0;
}

