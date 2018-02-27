#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

int n=99999; // simply placeholder value
typedef enum {thinking, eating, hungry} state;
state State[999999];
pthread_mutex_t available[999999];
pthread_cond_t condition[999999];



void printState(void) {
	printf("Current state:\n");
	printf("0 means thinking, 1 means eating, 2 means hungry\n");
	printf("Philosopher number         State\n");
	for (int i = 0; i < n; i++) {
		printf("%d                 %d\n", i, State[i]);
	}
}

void pickup_forks(int p_n) {
	printState();
	int t = rand() % 180 + 1; // eat for random time upto 3 minutes
	int left = (p_n + 1) % n;
	int right;
	if (p_n == 0) {
		right = n - 1;
	} else {
		right = p_n - 1;
	}
	pthread_mutex_lock(&available[p_n]);
	//while (!available[left] && 
	sleep(t);
	pthread_mutex_unlock(&available[p_n]);
}

void *worker (void * p_n) {
	int * k = (int *) p_n;
	int p = *k;
	printf("here\n");
	while(1) {
		pickup_forks(p);
		//return_forks(p);	
	}
}

int main(int argc, const char * argv[])
{
	printf("*************************************************\n\nNote: I am assuming that the no. of philosophers input to the program does not exceed 999999.\n*************************************************\n");
	scanf("%d", &n);
	srand(time(NULL));
	// start with thinking for all philosophers
	for(int i=0; i<n; i++) {
		State[i] = thinking;
		if( pthread_cond_init(&condition[i], NULL) != 0) {
         		perror("pthread_cond_init");
         		exit(1);
         	}
         	// mutex with cond variable
         	// cond var as a way in C to wait and signal
         	// consistency index between condition & available
         	if (pthread_mutex_init(&available[i], NULL) != 0) {
         		perror("pthread_mutex_init");
         		exit(1);
         	}
     	}
     	pthread_t threads[n];
     	pthread_attr_t attrs[n];
     	for (int i=0; i<n; i++) {
		pthread_attr_init(&attrs[i]);
	}
     	int * pass;
     	int i;
     	for (i=0; i<n; i++) {
     		pass = &i;
     		pthread_create(&threads[i], &attrs[i], worker, (void *) pass); 
     	}
     	return 0;			
}
