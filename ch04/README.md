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

# File permission fuction
high-level file IO is also described as "standard file input/output library" and provided as standard function in C  
it accesses data by using buffer, not in byte unit.

## High-Level file IO fucntion
|purpose|fuction|
|-------|-------|
|file open/create|`FILE *fopen(const char *pathname, const char *mode)`|
|file close|`int fclose(FILE *stream)`|
|read character|`int fgetc(FILE *steram)`|
|read character|`int getc(FILE *stream)`|
|read character|`int getchar(void)`|
|read character|`int getw(FILE *stream)`|
|write character|`int fputc(int c, FILE *stream)`|
|write character|`int putc(int c, FILE *stream)`|
|write character|`int putchar(int c)`|
|write character|`int putw(int w, FILE *stream)`|
|read string|`char *gets(const char *s)`|
|read string|`char *fgets(char *s, int szie, FILE *stream)`|
|write string|`int puts(const char *s)`|
|write string|`int fputs(const char *s, FILE *stream)`|
|read buffer|`size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`|
|write buffer|`size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)`|
|read format|`int scanf(const char *format, ... )`|
|read format|`int fscanf(FILE *stream, const char *format, ...)`|
|write format|`int printf(const char *format, ...)`|
|write format|`int fprintf(FILE *stream, const char *format, ...)`|
|file offset|`int fseek(FILE *Stream, long offset, int whence)`|
|file offset|`long ftell(FILE *Stream)`|
|file offset|`void rewind(FILE *stream)`|
|disk synchronise|`int fflush(FILE *stream)`|

# Comparison between `low-level file IO` and `high-level file IO`
|-|low-level file IO|high-level file IO|
|-|-----------------|------------------|
|file idicator|`int fd`(file descriptor)|`FILE *fp`(file pointer)|
|features|fast|easy to use|
|features|IO in byte unit|IO with buffer|
|features|able to approach to special file|easy to data IO sychronise|
|features|-|support many formats|

# Converting file descriptor into file pointer
low-level file IO can be converted to high-level file IO. viceversa can also coverted.
|purpose|function|
|-------|--------|
|file descriptor -> file pointer| `FILE *fdopen(int fd, const char *mode)`|
|file pointer -> file descriptor| `int fileno(FILE *stream)`|

# Create temp file
in order to save temporary file while program is running, temporary files should have different name
|purpose|fuction|
|------|-------|
|create temp file|`char *tmpnam(Char *s)`|
|create temp file|`char *mkitemp(char *template)`|
|create temp file pointer|`FILE *tmpfile()`|
|create temp file descriptor|`int *mkstemp(char *template)`|

