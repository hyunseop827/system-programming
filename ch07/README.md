# Creation of Process
- in a program, by calling function, it can creat a process.
- `system()` function needs argument to creat new order.
- `fork()` is common way to make process, it copies parent process and makes child process.

|purpose|function|
|-------|--------|
|start program|`int system(const char *command);`|
|create process|`pid_t fork(void);`|
|create process|`pid_t vfork(void);`|

# Exit Process
- In Linux, when process eixts, it saves `exit status`.
- child process returns exit status to parent process.
- normally if it's 0, it means it was successful, if it's not 0, it was not successful.

|purpose|function|
|-------|--------|
|exit process|`void exit(int status);`|
|exit process|`void _exit(int status);`|
|assign task at exit|`int atexit(void (*function)(void));`|
|assign task at exit|`int on_exit(void (*function)(int, void *), void *args);`|

# `exec` functions
- `exec` functions can overwrite the program with arguments.
- `exec` functions can also utilise with `fork()` and make new child process with differen task.

|purpose|function|
|-------|--------|
process execution|`int execl(const char *pathname, const char *arg, ..., (char *)NULL);`|
|process execution|`int execlp(const char *file, const char *argc, ...., (char *)NULL);`|
|process execution|`int execle(const char *pathname, const char *arg, ... ,(char *)NULL, char *const envp[]);`|
|process execution|`int execv(const char *pathname, char *const argv[]);`|
|process execution|`int execvp(const char *file, char *const argv[]);`|
|process execution|`int execvpe(const char *file, char *const argv[], char *const envp[]);`|

# Synchronization Processes
if the exits wasn't in order between child and parent processes, then it could cause the creation of "zombie process". In order to prevent this situation, synchronisation between parent process and child process is required.

|purpose|function|
|-------|--------|
|synchronise|`pid_t wait(int *wstatus);`|
|synchronise with certain process|`pid_t waitpid(pid_t pid, int *wstatus, int options);`|
|synchronise with certain process|`int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);`|


