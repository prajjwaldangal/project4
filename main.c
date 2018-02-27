#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

int n;
typedef enum {thinking, eating, hungry} state;
state State[9999999];
pthread_mutex_t available;
pthread_cond_t condition[9999999];

int main(int argc, char * argv[])
{
	printf("Note: no. of philosophers input to the program must be less than 9999999\n");
	n = (int) argv[1];
	printf("No. of philosophers in the program is %d", n);
	
	// start with thinking for all philosophers
	for(int i=0; i<n; i++) {
		State[i] = thinking;
		if( pthread_cond_init(&condition[i], NULL) != 0) {
         		perror("pthread_cond_init");
         		exit(1);
         	}
     	}
     	while(1) {
     		
     	}
     	
	return 0;			
}
