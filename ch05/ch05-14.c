/*
 * time
 *
 * it gives time since 1970/01/01/0/0/0 (UTC) in second.
 * it returns address in `tloc`, returns -1 when it's failed.
 *
 * #include <time.h>
 *
 * time_t time(time_t *tloc);
 *
 * tloc: address to save time.
 *
 */

#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main() {
	time_t tloc;

	time(&tloc);

	printf("time(sec): %d\n", (int)tloc);

	return 0;
}

