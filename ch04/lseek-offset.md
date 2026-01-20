# offset whence
one file only have one offest. if it's start of file then it's 0.  
`read` and `write` move offset to how many they have been through.  
to check and change offset, `lseek()` is needed.

|value|description|
|-----|-----------|
|`SEEK_SET`|calculate start of file|
|`SEEK_CUR`|calculate currnet postion of file|
|`SEEK_END`|calculate end of file|

# Examples.


```C
// move to 5 byte from the start.
lseek(fd, 5, SEEK_SET);
```

```C
// move to EOF
lseek(fd, 0, SEEK_END);
```

```C
// to check current position
cur_offset = lseek(fd,0,SEEK_CUR);
```

