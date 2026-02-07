/*
 * strftime
 *
 * strftime let user print time in certain format
 * check strftime-format.md
 *
 * #include <time.h>
 *
 * size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
 *
 * s: address of array to store time.
 * max: size of s.
 * foramt: formats.
 * tm: address of struct with time info.
 *
 */

#include <time.h>
#include <stdio.h>

char *output[] = {"%x %X", "%G %m %d %U %H:%M", "%r"};

int main() {
	struct tm *tm;
	int n;
	time_t timep;
	char buf[257];

	time(&timep);
	tm = localtime(&timep);

	for (n = 0; n < 3; n++){
		strftime(buf, sizeof(buf), output[n], tm);
		printf("%s = %s\n", output[n], buf);
	}

	return 0;
}


