/*
 * get user ID and print password aging(min, max, warn, inactive)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main() {
	struct spwd *spw;

	char user_id[256];

	printf("user id? :");
	scanf("%s", user_id);

	// sudo needed
	spw = getspnam(user_id);

	if(spw == NULL) {
		printf("error, %s doesn't exsit\n", user_id);
		exit(1);
	}

	printf("login name: %s\n",spw->sp_namp);
	printf("sp_min: %ld\n", spw->sp_min);
	printf("sp_max: %ld\n", spw->sp_max);
	printf("sp_warn: %ld\n", spw->sp_warn);
	printf("sp_inact: %ld\n", spw->sp_inact);

	return 0;
}


