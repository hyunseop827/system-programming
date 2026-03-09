# Concept of signal.
signal is software interrupt, it sends message to process in asynchronous.

# Processing method of signal.
- terminates a process based on the signal it receives.
- ignore a process that signal receives.
- assign a function to process the signal before it receives signal.
- block a signal while process is running.

# Signal handler.
If the task remains before a process ends or certain signals try not to termintaes a process, a function could be assigned. This function is called "signal handler"

# Signal set.
signal set is from POSIX to handler multiple signals, it can assign signals to process.

# Alarm signal.
Alarm signal occurs signal after certain time passes.

# Signal set.
signal set is from POSIX to handler multiple signals, it can assign signals to process.

# Alarm signal.
Alarm signal occurs signal after certain time passes. Either it can occur just once after time passess or it can occur signals periodically.

# Signal functions.

|purpose|function|
|-------|--------|
|sending signal|`int kill(pid_t pid, int sig);`|
|sending signal|`int raise(int sig);`|
|sending signal|`void abort(void);`|
|sending signal|`int sigsend(idtype_t idtype, id_t id, int sig);`|
|assigning signaler handler|`sighandler_t signal(int signum, sighandler_t handler);`|
|assigning signal handler|`sighandler_t sigset(int sig, sighandler_t disp);`|
|assigning signal handler|`int sigignore(int sig);`|
|signal set|`int sigemptyset(sigset_t *set);`|
|signal set|`int sigfillset(sigset_t *set);`|
|signal set|`int sigaddset(sigset_t *set, int signum);`|
|signal set|`int sigdelset(sigset_t *set, int signum);`|
|signal set|`int sigismember(const sigset_t *set, int signum);`|
|control signal|`int sigaction(int signum, const struct sigaction *act, struct sigaction *oldset);`|
|alarm signal|`unsigned int alarm(unsigned int seconds);`|
|interval timer|`int getitimer(int which, struct itimerval *curr_value);`|
|interval timer|`int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue);`|
|printing signal info|`void psiginfo(const siginfo_t *pinfo, const char *s);`|
|printing signal info|`void psignal(int sig, const char *s);`|
|printing signal info|`char *strsignal(int sig);`|
|signal block and release|`int sighold(int sig);`|
|signal block and release|`int sigrelse(int sig);`|
|signal block and release|`int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);`|
|waiting signal|`int pasue(void);`|
|waiting signal|`int sigpause(int sig);`|
|waiting signal|`int sigsuspend(const sigset_t *mask);`|

