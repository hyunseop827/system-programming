# Differences Between `exec` Functions

All `exec` functions replace the current process image with a new program. On success they do **not** return; on failure they return `-1` and set `errno`.

## Four Key Differences

1. **How arguments are passed**
   - `l` (list): variadic argument list
   - `v` (vector): `char *argv[]` array

2. **Environment handling**
   - default: inherit current environment
   - `e`: pass an explicit `char *envp[]`

3. **PATH search**
   - `p`: search for the executable in `PATH`
   - no `p`: requires an explicit path

4. **Base system call**
   - `execve` is the underlying system call–style primitive

## Function Summary

- `execl(path, arg0, arg1, ..., NULL)`
  - explicit path, argument list, inherit environment

- `execv(path, argv)`
  - explicit path, argument vector, inherit environment

- `execle(path, arg0, ..., NULL, envp)`
  - explicit path, argument list, explicit environment

- `execve(path, argv, envp)`
  - explicit path, argument vector, explicit environment
  - lowest-level primitive

- `execlp(file, arg0, ..., NULL)`
  - search `PATH`, argument list, inherit environment

- `execvp(file, argv)`
  - search `PATH`, argument vector, inherit environment

- `execvpe(file, argv, envp)`
  - search `PATH`, argument vector, explicit environment

## C Examples (Hello World)

Each example prints `Hello, world` by executing `/bin/echo` with different `exec` variants. On success, the `exec` call does not return.

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    execl("/bin/echo", "echo", "Hello, world", (char *)NULL);
    perror("execl");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *argv[] = {"echo", "Hello, world", NULL};
    execv("/bin/echo", argv);
    perror("execv");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *envp[] = {"LANG=C", NULL};
    execle("/bin/echo", "echo", "Hello, world", (char *)NULL, envp);
    perror("execle");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *argv[] = {"echo", "Hello, world", NULL};
    char *envp[] = {"LANG=C", NULL};
    execve("/bin/echo", argv, envp);
    perror("execve");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    execlp("echo", "echo", "Hello, world", (char *)NULL);
    perror("execlp");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *argv[] = {"echo", "Hello, world", NULL};
    execvp("echo", argv);
    perror("execvp");
    return 1;
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *argv[] = {"echo", "Hello, world", NULL};
    char *envp[] = {"LANG=C", NULL};
    execvpe("echo", argv, envp);
    perror("execvpe");
    return 1;
}
```
