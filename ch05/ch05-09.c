/*
 * getspent, setspent, endspent, fgetspent
 *
 * >> getspent read `/etc/shadow` from the beginning. returns NULL at the end.
 * >> setspent move offset of `/etc/shadow` to beginning.
 * >> endspent close `/etc/shadow`
 * >> fgetspent read password from other file pointer.
 *
 * #include <shadow.h>
 *
 * struct spwd *getspent(void);
 * void setspent(void);
 * void endspent(void);
 * struct spwd *getspent(FILE *stream);
 *
 * stream: file pointer
 */

#include <shadow.h>
#include <stdio.h>

int main() {
	struct spwd *spw;
	int n;

	for (n = 0; n < 3; n++){
		spw = getspent();
		printf("login name: %s, passwd: %s\n",spw->sp_namp, spw->sp_pwdp);
	}
	
	return 0;
}

