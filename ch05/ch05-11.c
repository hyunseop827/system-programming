/*
 * group struct
 *
 * it's written in `grp.h`
 *
 * struct group{
 * 	char *gr_name; // group name
 *	char *gr_passwd; // group passwd. usually blank, yet if user sets group passwd, it saves encrypted passwd.
 *	gid_t gr_gid; // group ID number
 *	char **gr_mem; // group members' login names.
 * }
 */

/*
 * getgrname, getgrgid
 *
 * >> getgrname read group name
 * >> getgrgid read group ID
 *
 * #include <sys/types.h>
 * #include <grp.h>
 *
 * struct group *getgrnam(const char *name);
 * struct group *getgrgid(gid_t gid);
 *
 * name: group name to be searched.
 * gid: group ID to be searched.
 *
 */

#include <grp.h>
#include <stdio.h>

int main() {
	struct group *grp;
	int n;

	grp = getgrnam("adm");
	printf("group name: %s\n", grp->gr_name);
	printf("GID: %d\n", (int)grp->gr_gid);

	n = 0;
	printf("members: ");

	while(grp->gr_mem[n] != NULL){
		printf("%s ", grp->gr_mem[n++]);
		printf("\n");
	}
	
	return 0;
}

