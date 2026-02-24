# Definded Signals in <signal.h>

|signal|number|default processing|occuring condition|
|------|------|------------------|------------------|
|SIGHUP|1|exit|lose connection to terminal by hang up|
|SIGINT|2|exit|interrupt by Ctrl+C from user|
|SIGQUIT|3|core dump|exit signal by Ctrl+\ from user|
|SIGILL|4|core dump|use wrong command|
|SIGTRAP|5|core dump|trap occured at trace or break point|
|SIGABRT|6|core dump|occurred by `abort()`|
|SIGIOT|6|core dump|same as `SIGABRT`|
|SIGBUS|7|core dump|occurred by bus error|
|SIGFPE|8|core dump|occurred by arithmetic operations|
|SIGKILL|9|exit|forced exit|
|SIGUSR1|10|exit|user customised signal 1|
|SIGSEGV|11|core dump|segmentation error|
|SIGUSR2|12|exit|user customised signla 2|
|SIGPIPE|13|exit|occurred by wrong pipe processing|
|SIGALRM|14|exit|occurred by `alarm()`|
|SIGTERM|15|exit|exit of software|
|SIGSTKFLT|16|exit|stack error from assistance process (not supported in Linux)|
|SIGCHLD|17|ignore|occurred when child process changed|
|SIGCONT|18|ignore|occurred when re-start stopped process|
|SIGSTOP|19|stop|stop signal, stops process till `SIGCONT` signal|
|SIGTSTP|20|stop|occurred when user enter Ctrl+Z|
|SIGTTIN|21|stop|occurred when stops for terminal input|
|SIGTTOU|22|stop|occurred when stops for terminal output|
|SIGURG|23|ignore|occurred urgent situation happens in socket|
|SIGXCPU|24|core dump|occurred when CPU time's over|
|SIGXFSZ|25|core dump|occurred when system file limit is over|
|SIGVTALRM|26|exit|occurred when virtual timer ends|
|SIGPROF|27|exit|occurred when profile timer ends|
|SIGWINCH|28|ignore|happens when window size changes|
|SIGIO|29|exit|happens when asynchronous IO event occur|
|SIGPOLL|SIGIO|exit|same as SIGIO|
|SIGPWR|30|ignore|occurs when power is turned off or restarted|
|SIGSYS|31|core dump|occurs when wrong system call happens|
|SIGUNUSED|31|ignore|reserved number for later use|

