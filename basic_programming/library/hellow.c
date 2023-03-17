#include "hellow.h"

int hellows(int i) {
	int f;
	for(f= 0 ; f <= i ; f++ ) {
		printf("hellow %d .\r",f);
		fflush( stdout );
		sleep(1);	
	}

	printf("\nbye!!\n");
}