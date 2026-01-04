/*
 * use case of ch01-03 code and make it different.
 */
#include <stdio.h>

extern int subnum(int a, int b);

int main() {
	int sum;

	sum = subnum(1,5);
	printf("1 - 5  = %d\n",sum);
}

