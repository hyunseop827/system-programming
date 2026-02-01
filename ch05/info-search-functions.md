# System information search function
In Linux,fuctions to search basic informations such as hardware, OS, memory page, and maximum length of password.

## graph of system information functions
|purpose|function|
|-------|--------|
|OS info search|`int uname(struct utsname *buf)`|
|System info search|`long sysconf(int name)`|
|file/directory resource search|`long fpathconf(int fd, int name)`|
|file/directory resource search|`long pathconf(const char *path, int name)`|

# User information search function
In case of User, there are user account information, group information, login history.  
User related functions are included with function to read from 'login name', 'UID', 'password file(/etc/passwd)' or 'shadow file(/etc/shadow)'.  
Group search functions also have functions to access to 'GID', 'group file(etc/group)'  
Login history functions read data from '/var/log/utmp'.  

## graph of user information functions
|purpose|function|
|-------|--------|
|login search|`char *getlogin(void)`|
|UID search|`uid_t getuid(void)`|
|UID search|`uid_t geteuid(void)`|
|password file search|`struct passwd *getpwuid(uid_t uid)`|
|password file search|`struct passwd *getpwnam(const char *name)`|
|password file search|`struct passwd *getpwent(void)`|
|password file search|`void setpwent(void)`|
|password file search|`void endpwent(void)`|
|password file search|`struct passwd *fgetpwent(FILE *stream)`|
|shadow file search|`struct spwd *getspnam(const char *name)`|
|shadow file search|`struct spwd *getspent(void)`|
|shadow file search|`void setspent(void)`|
|shadow file search|`void endspent(void)`|
|shadow file search|`struct spwd *fgetspent(FILE *stream)`|
|group information search|`gid_t getgid(void)`|
|group information search|`gid_t getegid(void)`|
|group information search|`struct group *getgrnam(const char *name)`|
|group information search|`struct group *getgrgid(gid_t gid)`|
|group information search|`struct group *getgrent(void)`|
|group information search|`void setgrent(void)`|
|group information search|`void endgrent(void)`|
|group information search|`struct group *fgetgrent(FILE *stream)`|
|login history search|`strcut utmp *getutent(void)`|
|login history search|`void setutent(void)`|
|login history search|`void endutent(void)`|
|login history search|`int utmpname(const char *file)`|

# Time control functions
In use of Linux OS, controling time is often used in many cases such as file or directory creation and change user informations etc.  
In Linux, it gives you functions to search current time, to set time zone, to return time information as struct and to assign format for printing out time.

## graph of time control functions
|purpose|function|
|-------|--------|
|time read|`time_t time(time_t *tloc)`|
|time read|`int gettimeofday(struct timeval *tv, struct timezone *tz)`|
|time read|`int settimeofday(const struct timeval *tv, const struct timezone *tz)`|
|set time zone|`void tzset(void)`|
|disassemble time information|`struct tm *gmtime(const time_t *timep)`|
|disassemble time information|`struct tm *localtime(const time_t *tiemp)`|
|create time in seconds|`time_t mktime(struct tm *tm)`|
|print time in format|`char *ctime(const time_t *timep)`|
|print time in format|`char *asctime(const struct tm *tm)`|
|print time in format|`size_t strftime(char *s, size_t max, const char *format, const struct tm *tm)`|

