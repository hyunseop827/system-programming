# File info search functions
in Linux, all datas from files come from I-node. 
struct to search file info: `strcut stat` included `<stat.h>`  

|purpose|function|
|------|-------|
|search file info|`int stat(const char *pathname, struct stat *statbuf)`|
|search file info|`int fstat(int fd, strcut stat *statbuf)`|

# File access permission functions
permission is written in `stat.st_mode`.
using, pre-described constants and macro to interprete `st_mode` 

|purpose|fuction|
|-------|-------|
|check file permission|`int access(const char *pathname, int mode)`|
|change file permission|`int chmod(const char *pathname, mode_t mode)`|
|change file permission|`int fchmod(int fd, mode_t mode)`|

# Link functions
- link means another file to access file or directory.
- hard link uses same I-node of original file.
- symbolic link create sperate file. use different I-node, and save path of original file.

|purpose|fuction|
|-------|-------|
|create hard link|`int link(const char *oldpath, const char *newpath)`|
|create symbolic link|`int symlink(const char *target, const char *linkpath)`|
|seach infos of symbolic link|`int lstat(const char *pathname, struct stat *statbuf)`|
|read infos of symbolic link|`ssize_t readlink(const char *pathname, char *buf, size_t bufsize)`|
|search original path of symbolic link|`char *realpath(const char *path, char *resolved_path)`|
|unlink|`int unlink(const char *pathname)`|

