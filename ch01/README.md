# System Programming Standard
ANSI C, IEEE POSIX, X/Open XPG3, XPG4, SVID, SUS

# Understading of System programming
System call is interface for programmers to use file system, user information, system information, system time information, networking.
System programming is to use these system's features.

# System call and library functions.
System call is provided in C language. System call calls kernel's exact module and returns result.  
Library usually doesn't exact call kernel.
System call's located in `man` section 2. Library function's located in `man` section 3.  
```shell
man -s 2 [name]
```
If error has occured, system call returns -1, library functions returns NULL.

