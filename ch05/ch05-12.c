/*
 * getgrent, setgrent, endgrent, fgetgrent
 *
 * >> getgrent reads `/etc/group` from the beginning. returns NULL when it's EOF
 * >> setgrent move offset of `/etc/group` to the start point.
 * >> endgrent close `/etc/group`
 * >> fgetgrent read where file pointer points.
 *
 * #include <sys/types.h>
 * #include <grp.h>
 *
 * struct group *getgrent(void);
 * void setgrent(void);
 * void endgretn(void);
 * struct group *fgetgrent(FILE *stream);
 *
 * stream: file pointer
 *
 */

#include <grp.h>
#include <stdio.h>

int main() {
	struct group *grp;
	int n, m;

	for(n = 0; n<3;n++){
		grp = getgrent();
		printf("groupname: %s, GID: %d ",grp->gr_name, (int)grp->gr_gid);

		m=0;

		printf("members: ");
		while(grp->gr_mem[m] != NULL){
			printf("%s ",grp->gr_mem[m++]);
		}
		printf("\n");

	}
	return 0;
}

