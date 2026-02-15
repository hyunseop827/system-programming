# Concept of process.
- Process means currently running program.
- Process has text area, data area, heap area, stack area and empty area.
- To see a list of processes, use `ps`.  to see process and memory info, use `top`
- memory and swap info: `sysinfo`(2)

# Process identify function
|purpose|function|
|-------|--------|
|memory and swap status search|`int sysinfo(struct sysinfo *info)`|
|search PID|`pid_t getpid(void)`|
|search PPID|`pid_t getppid(void)`|
|search process group|`pid_t getpgrp(void)`|
|search process group|`pid_t getpgid(pid_t pid)`|
|change process group ID|`int setpgid(pid_t pid, pid_t pgid)`|
|search session leader ID|`pid_t getsid(pid_t pid)`|
|create session|`pid_t setsid(void)`|

# Process running time
- process running time = system running time + user running time.
- process running time measurment function: `clock_t times(struct tms *buf)`

# Ways to utilise ENVs
- While the process is running in base environment, which includes login name, login shell, path and etc. These are idenified as ENV. 
- ENV is `environment name=value` form, usually name is uppercase. ENV could be defined in SHELL, also by using function, it could be read or changed.
- external variable use: `extern char **environ;`
- in case of `main`: `int main(int argc, char **argv, char **envp);`
- function use
|purpose|function|
|-------|--------|
|search ENVs|`char *getenv(const char *name);`|
|setting and deleting ENVs|`int putenv(char *string);`|
|setting and deleting ENVs|`int setenv(const char *name, const char *value, int overwrite);`|
|setting and deleting ENVs|`int unsetenv(const char *name);`|


