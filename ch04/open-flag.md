# flags often used in `open`
flags can be used with `|`.


|flags|function|
|-----|--------|
|`O_RDONLY`|open file as read-only|
|`O_WRONLY`|open file as write-only|
|`O_RDWR`|open file as read-write|
|`O_CREAT`|create file if it doesn't exist, permission is required. if file is already existing, then it's not working.|
|`O_EXCL`|like `O_CREAT`, create file if it doesn't exist, if it does, print error message and do not create one|
|`O_APPEND`|add content in the end of file|
|`O_TRUNC`|when you create file, if the file is existing and being opened as `READ`. This option deletes all of content and make file length as 0|
|`O_SYNC`/`O_DSYNC`|when writing, usually contents writed on buffers, then flushed later. If this option is on, it writes on directly and flush. `O_SYNC` is waiting till file's modification time is also modified. this option may your computer run slow, yet it garauntees you that file will be saved in your disk|

