/*
 * get user name and print user's group
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>
#include <string.h>

int main() {

	char user_name[256];

	printf("user name? :");
	scanf("%s", user_name);

	struct group *grp;

	int n,m;

	while((grp = getgrent()) != NULL) {
		m = 0;
		while(grp->gr_mem[m] != NULL){
			char* target = grp->gr_mem[m++];
			if(strcmp(user_name, target) == 0){
				printf("%s is in group: %s\n", user_name, grp->gr_name);
				}
		}
	}

	return 0;
}

