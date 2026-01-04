/*
 * use get opt, write code to perform requirments below.
 *
 * 1) name of program should be: ex1_15.out 
 * - could be done with gcc -o.
 *
 * 2) -pnh options, when it's not givin. print avaiable options.
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int n;
	if(argc  == 1){
		printf("options\n");
		printf("-p : print greeting message\n");
		printf("-n <arguments> : greeting <arguments>\n");
		printf("-h : print options\n");
		return 0;
	}

	while ((n = getopt(argc,argv, "pn:h")) != -1){
		switch(n){
			case 'p':
				printf("Welcome Linux System Programming\n");
				break;
			case 'n':
				printf("Nice to meet you %s\n",optarg);
				break;
			case 'h':
				printf("options\n");
				printf("-p : print greeting message\n");
				printf("-n <arguments> : greeting <arguments>\n");
				printf("-h : print options\n");
				break;
		}
	}
	
	return 0;
}

