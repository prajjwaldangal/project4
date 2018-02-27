#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

int n=99999; // simply placeholder value
typedef enum {thinking, eating, hungry} state;
state State[9999999];
pthread_mutex_t available;
pthread_cond_t condition[9999999];

void printState(void) {
	printf("Current state:\n");
	printf("0 means thinking, 1 means eating, 2 means hungry\n");
	printf("Philosopher number         State\n");
	for (int i = 0; i < n; i++) {
		printf("%d                 %d\n", i, State[i]);
	}
}

void pickup_forks(int p_n) {
	int t = rand() % 180 + 1; // eat for random time upto 3 minutes
	pthread_mutex_lock(&available);
	
}

void *worker (void * p_n) {
	int * k = (int *) p_n;
	int p = *k;
	while(1) {
		pickup_forks(p);
		//return_forks(p);	
	}
}

int main(int argc, const char * argv[])
{
	printf("*************************************************\n\nNote: I am assuming that the no. of philosophers input to the program does not exceed 9999999.\n*************************************************\n");
	srand(time(NULL));
	printf("Enter number of philosophers for the program\n");
	scanf("%d", &n);
	// start with thinking for all philosophers
	for(int i=0; i<n; i++) {
		State[i] = thinking;
		if( pthread_cond_init(&condition[i], NULL) != 0) {
         		perror("pthread_cond_init");
         		exit(1);
         	}
     	}
     	pthread_t threads[n];
     	pthread_attr_t attrs[n];
     	for (int i=0; i<n; i++) {
		pthread_attr_init(&attrs[i]);
	}
     	int * pass;
     	for (int i=0; i<n; i++) {
     		pass = &i;
     		pthread_create(&threads[i], &attrs[i], worker, (void *) pass); 
     	}
     	printState();
	return 0;			
}
