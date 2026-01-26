# Low-level file IO
low-level file IO use system call from kernel to make IO work. not only normal file can be targeted also speical files too.

## Low-Level file IO function
|purpose|fuction|
|-------|-------|
|file open/create|`int open(const char *pathname, int flags)`|
|file open/create|`int open(const char *pathname, int flags, mode_t mode)`|
|file create|`int creat(const char *pathname, mode_t mode)`|
|file close|`int close(int fd)`|
|read date|`ssize_t read(int fd, void *buf, size_t count)`|
|write date|`ssize_t write(int fd, const void *buf, size_t count)`|
|change offset|`off_t lseek(int fd, off_t offset, int whence)`|
|copy file descriptor|`int dup(int oldfd)`|
|copy file descriptor|`int dup2(int oldfd, int newfd)`|
|delete file|`int remove(const char *pathname)`|
|control file descriptor|`int fcntl(int fd, int cmd, ... /* args */)`|
|disk synchronise|`int fsync(int fd)`|

#
