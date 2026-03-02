/*
 * in sa_flags, if SA_SIGINFO is assigned, then the reason can be shown.
 *
 * void handler(int sig, siginfo_t *info, coid *uncontext) { ~~ }
 * sig: signal to call handler.
 * info: siginfo_t's address.
 * uncontext: uincontext_t struct address. to see process's context.
 */

/*
 * siginfo_t struct
 *
 * typedef struct {
 * 	int	si_signo;
 * 	int	si_errno;
 * 	int	si_code;
 *
 * 	union {
 * 		int	si_trapno;
 * 		pid_t	si_pid;
 * 		uid_t	si_uid;
 * 		int	si_status;
 * 		clock_t	si_utime;
 * 		clock_t	si_stime;
 * 		sigval_t si_value;
 * 		int	si_int;
 * 		void	*si_ptr;
 * 		int	si_overrun;
 * 		int	si_timerid;
 * 		void	*si_addr;
 * 		long	si_band;
 * 		int	si_fd;
 * 		short	si_addr_lsb;
 * 		void	*si_lower;
 * 		void	*si_upper;
 * 		int	si_pkey;
 * 		void	*si_call_addr;
 * 		int	si_syscall;
 * 		unsiged int si_arch;
 * 	}
 * } siginfo_t;
 */

/*
 * psginfo
 *
 * #include <siginfo.h>
 *
 * void psiginfo(const siginfo_t *pinfo, const char *s);
 *
 * pinfo: poiner of struct that has cause of signal.
 * s: string to print out.
 *
 * pinfo has siginfo_t address.
 * s is printed out first then the signal info is next.
 *
 */

#include <ucontext.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo, siginfo_t *sf, ucontext_t *uc) {
	psiginfo(sf, "received signal:");
	printf("si_code: %d\n", sf->si_code);
}

int main() {
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = (void (*)(int, siginfo_t *, void *))sig_handler;

	sigemptyset(&act.sa_mask);

	if (sigaction(SIGUSR1, &act, (struct sigaction *)NULL) < 0) {
			perror("sigaction");
			perror("sigaction");
			exit(1);
	}

	pause();

	return 0;
}
