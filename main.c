#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int n;

void pickup_forks(int p) 
{
	// lock mutex
	pthread_mutex_lock(&available);
	state[p] = eating;
	// random (60 - 180 secs)
	// unlock mutex
}

int check_others(int p)
{
	// if sideways in hungry state -> convert to eating
	if (state[i] == 
}

void return_forks(int p)
{
	// unlock mutex
	pthread_mutex_unlock(&available);
	state[p] = thinking;
	check_others(p);
}

int main(int argc, char * argv[])
{
	n = (int) argv[1];
	printf("No. of philosophers in the program is %d", n);
	typedef enum {thinking, hungry, eating} state[n];
	pthread_cond_t condition[n];
	// start with thinking for all philosophers
	for(int i=0; i<n; i++) {
		state[i] = thinking;
		if(pthread_cond_init(condition[i], pthread_condattr_default) != 0) {
         		perror("pthread_cond_init");
         		exit(1);
         	}
     	}
     	
     	//for (i=0; it)[i]),pthread_attr_default,
	//   	       philosopher, &((tab->self)[i]))!= 0) {
         //perror("pthread_create");
         //exit(1);}
	//}
	//pthread_create();
	return 0;			
}
