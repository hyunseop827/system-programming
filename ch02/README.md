# Features of Files in Linux
- in Linux, file, directory, device could be approached as normal file.
- type of files: normal file, speical file, directory.
- component of file: file name, inode, data block.  

# Fuctions to make and delete directory
- used when programmer makes directory or delete it.
- fuctions have same name with command, `man -s 2` is for function.  

|purpose|fuction|
|-------|-------|
|make directory| `int mkdir(const char *pathname, mode_t mode);` |
|delete direcotry| `int rmdir(const char *pathname);`|

# Functions to control directory
- to control directory, functions provide to search location, to move directory and to rename directory etc.  

|purpose|function|
|-------|--------|
|get location path| `char *getcwd(char *buf, size_t size);`|
|get location path| `char *get_current_dir_name(void);`|
|rename directory| `int rename(const char *oldpath, const char *newpath);`|
|move directory| `int chdir(const char *path);`|
|more directory| `int fchdir(int fd);`|

# Functions to read 
- to read directory, open and close functions are required.
- read fucntion, offset adjustment function are provided.  

|purpose|function|
|-------|--------|
|open directory| `DIR *opendir(const char *name);`|
|close directory| `int closedir(DIR *dirp);`|
|read directory| `struct dirent *readdir(DIR *dirp);`|
|offset| `long telldir(DIR *dirp);`|
|offset| `void seekdir(DIR *dirp, long loc);`|
|offset| `void rewinddir(DIR *dirp);`| 
