# Definded Signals in <signal.h>

|signal|number|default processing|occuring condition|
|------|------|------------------|------------------|
|SIGHUP|1|exit|lose connection to terminal by hang up|
|SIGINT|2|exit|interrupt by Ctrl+C from user|
|SIGQUIT|3|core dump|exit signal by Ctrl+\ from user|
|SIGILL|4|core dump|use wrong command|
|SIGTRAP|5|core dump|trap occured at trace or break point|
|SIGABRT|6|core dump|occured by `abort()`|
|SIGIOT|6|core dump|same as `SIGABRT`|
|SIGBUS|7|core dump|occured by bus error|
|SIGFPE|8|core dump|occured by arithmetic operations|
|SIGKILL|9|exit|forced exit|
|SIGUSR1|10|exit|user customised signal 1|
|SIGSEGV|11|core dump|segmentation error|
|SIGUSR2|12|exit|user customised signla 2|
|SIGPIPE|13|exit|occured by wrong pipe processing|
