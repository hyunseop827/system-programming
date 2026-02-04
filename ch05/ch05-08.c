/*
 * spwd struct
 *
 * struct for shadow file. `/etc/shadow`
 * it's written in `shadow.h`
 *
 * sturct spwd{
 * 	char *sp_nampp; // login name
 * 	char *sp_pwdp; // encrypted password
 * 	int sp_lstachg; // lastest day from changing passwd since 01/01/1970
 * 	int sp_min; // minimum days to use changed password
 * 	int sp_max; // maximum days to use current password 
 * 	int sp_warn; // starting warns untill day to change password
 * 	int sp_inact; // days after password is expired.
 * 	int sp_expire; // the day that password will be expired since 01/01/1970
 * 	unsigned int sp_flag; // reserved for later, currently not used.
 * }
 */

/*
 * getspname
 *
 * it reads name's password infos.
 *
 * #include <shadow.h>
 *
 * struct spwd *getspnam(const char *name);
 *
 * name: name to search infos.
 */

#include <shadow.h>
#include <stdio.h>

int main() {
	struct spwd *spw;

	spw = getspnam("hyunseop");

	printf("login name: %s\n", spw->sp_namp);
	printf("passwd: %s\n",spw->sp_pwdp);
	printf("last change: %ld\n", spw->sp_lstchg);

	return 0;
}

