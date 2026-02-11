/*
 * get user name and print user's recently password changed day
 *
 * YYYY/MM/DD format
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>
#include <time.h>

int main() {
	char user_name[256];

	printf("user name? : ");
	scanf("%s", user_name);

	struct spwd *spw;

	spw = getspnam(user_name);

	if(spw == NULL){
		printf("user isn't on the list\n");
		exit(1);
	}

	//day since 1970.01.01	
	int time = spw->sp_lstchg;


	printf("%d days since 1970.01.01\n", time);

	time_t t = (time_t)time * 24 * 60 * 60;

	struct tm *lt = localtime(&t);

	printf("%d/%d/%d\n",(lt->tm_year) + 1900, lt->tm_mon, lt->tm_mday);

	return 0;
}

