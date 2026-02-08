# System infomarion search
- informations about OS, host name and hardware in system.  
- a number of maximum processes and size of memory pages can be also searched.  

## Functions
|purpose|function|
|-------|--------|
|OS info search|`int uname(struct utsname *buf);`|
|system resource search|`long sysconf(int name);`|
|file/directory resource reasearch|`long fpathconf(int fd, int name);`|
|file/directory resource reasearch|`long pathconf(const char *path, int name);`|

# Use information
- Linux system has each users informations, groups, and login history.
- related files: password (/etc/passwd), shadow file (/etc/shadow), group file (/etc/group), and login history (/var/log/utmp).

## Functions
|purpose|function|
|-------|--------|
|login name|`char *getlogin(void);`|
|UID|`uid_t getuid(void);`|
|UID|`uid_t getuid(void);`|
|search password file|`struct passwd *getpwuid(uid_t uid)`;|
|search password file|`struct passwd *getpwnam(const char *name);`|
|search password file|`sturct passwd *getpwent(void);`|
|search password file|`void setpwent(void);`|
|search password file|`void endpwent(void);`|
|search password file|`strcut passwd *fgetpwent(FILE *stream);`|
|search shadow file|`struct spwd *getspnam(const char *name);`|
|search shadow file|`struct spwd *getspent(void);`|
|search shadow file|`void setspent(void);`|
|search shadow file|`void endspent(void);`|
|search shadow file|`struct spwd *fgetspent(FILE *stream);`|
|search group file|`gid_t getgid(void);`|
|search group file|`gid_g getegid(void);`|
|search group file|`struct group *getgrnam(const char *name);`|
|search group file|`struct group *getgrgid(gid_t gid);`|
|search group file|`struct group *getgrent(void);`|
|search group file|`void setgrent(void);`|
|search group file|`void endgrent(void);`|
|search group file|`struct group *fgetgrent(FILE *stream);`|
|login history|`strcut utmp *getutent(void);`|
|login history|`void setutent(void);`|
|login history|`void endutent(void);`|
|login history|`int utmpname(const char *file);`|

# Time management functions
- since 1970.01.01 0.0.0 (UTC), print time in second and managed time infos.
|purpose|function|
|read time|`time_t time(time_t *tloc);`|
|read time|`int gettimeofday(struct timeval *tv, struct timezone *tz);`|
|read time|`int settimeofday(const struct timeval *tv, const struct timezone *tz);`|
|set time zone|`void tzset(void);`|
|disassemble time info|`struct tm *gmtime(const time_t *timep);`|
|disassemble time info|`struct tm *localtime(const time_t *timep);`|
|create time in second|`time_t mktime(struct tm *tm);`|
|formatting time|`char *ctime(const time_t *timep);`|
|formatting time|`char *asctime(const struct tm *tm);`|
|formatting time|`size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);`|











