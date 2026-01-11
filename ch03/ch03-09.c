/*
 * symlink
 *
 * to generate symbolic link.
 * 
 * returns 0 if it successed, else -1.
 *
 * #include <unistd.h>
 *
 * int symlink(const char *target, const char *linkpath);
 *
 * target: path to original file
 * linkpath: new path for symbolic link.
 *
 */

#include <unistd.h>

int main() {
	symlink("linux.txt", "linux.sym");
}

