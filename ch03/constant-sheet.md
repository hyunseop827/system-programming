# File permission sheet

## file type search constant sheet 
described in `sys/stat.h`  

|name|digits|funciton|
|----|-----|-----|
|`S_IFMT`|0170000|bit mask for file type's bit|
|`S_IFSOCK`|0140000|socket file|
|`S_IFLNK`|0120000|symbolic link|
|`S_IFREG`|0100000|regular file|
|`S_IFBLK`|0060000|block device special file|
|`S_IFDIR`|0040000|directory|
|`S_IFCHR`|0020000|character special file|
|`S_IFIFO`|0010000|FIFO file|

## file type search macro sheet
described in `sys/stat.h` these are standard POSIX.

|name|definition|fuction|
|---|-----|-----|
| `S_ISREG(m)` | `(((m) & S_IFMT) == S_IFREG)` | true if **regular file** |
| `S_ISDIR(m)` | `(((m) & S_IFMT) == S_IFDIR)` | true if **directory** |
| `S_ISLNK(m)` | `(((m) & S_IFMT) == S_IFLNK)` | true if **symbolic link** |
| `S_ISCHR(m)` | `(((m) & S_IFMT) == S_IFCHR)` | true if **character device** |
| `S_ISBLK(m)` | `(((m) & S_IFMT) == S_IFBLK)` | true if **block device** |
| `S_ISFIFO(m)` | `(((m) & S_IFMT) == S_IFIFO)` | true if **FIFO / pipe** |
| `S_ISSOCK(m)` | `(((m) & S_IFMT) == S_IFSOCK)` | true if **socket** |

## file access permission search constant sheet
described in `sys/stat.h`.

|name|value|fuction|
|---|---|---|
|`S_ISUID`|0x800|AND with `st_mode` to check **setuid**|
|`S_ISGID`|0x400|AND with `st_mode` to check **setgid**|
|`S_ISVTC`|0x200|AND with `st_mode` to check **stick bits**|
|`S_IREAD`|00400|AND with `st_mode` to check **owner's read permission**|
|`S_IWRITE`|00200|AND with `st_mode` to check **owner's write permission**|
|`S_IEXEC`|00100|AND with `st_mode` to check **ownder's execute permission**|

just to move 3bits of `st_mode`, you can check other users' (except owner) permissions. 
`st_mode & (S_IREAD) >> 3)`

## file access permission search constant sheet (POSIX)
instead of SHIFT, in POSIX, people definded other constants just need to AND.
| Constant | Value (octal) | Description |
|---|---:|---|
| `S_IRWXU` | `00700` | Owner has read/write/execute permission |
| `S_IRUSR` | `00400` | Owner has read permission |
| `S_IWUSR` | `00200` | Owner has write permission |
| `S_IXUSR` | `00100` | Owner has execute permission |
| `S_IRWXG` | `00070` | Group has read/write/execute permission |
| `S_IRGRP` | `00040` | Group has read permission |
| `S_IWGRP` | `00020` | Group has write permission |
| `S_IXGRP` | `00010` | Group has execute permission |
| `S_IRWXO` | `00007` | Others have read/write/execute permission |
| `S_IROTH` | `00004` | Others have read permission |
| `S_IWOTH` | `00002` | Others have write permission |
| `S_IXOTH` | `00001` | Others have execute permission |
 
