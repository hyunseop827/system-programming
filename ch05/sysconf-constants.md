# Important constants for `sysconf()`
constants are written in `sys/unistd.h`. to check other constants, `man sysconf`.  

|constant|purpose|
|--------|-------|
|`_SC_ARG_MAX`|max size of arguments used in `exec()`|
|`_SC_CHILD_MAX`|allowed a number of proccesses which used in UID|
|`_SC_HOST_NAME_MAX`|max length of host name|
|`_SC_LOGIN_NAME_MAX`|max length of login name|
|`_SC_CLK_TCK`|click tock per second|
|`_SC_OPEN_MAX`|max files that one  process can open|
|`_SC_PAGESIZE`|page size of system memory|
|`_SC_VERSION`|POSIX.1 version that system supports|

