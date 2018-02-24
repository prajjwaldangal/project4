#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


/*
Requirements:
1. Need two chopsticks at the same time to eat
2. each chopstick can be used by only one phlsr at a time
3. fork can only be taken from table and not from other phlsr
4. if phlsr grabs one chop, and the other not available, will 
    keep holding that chop
*/

int n; // number of philosophers
void * picup_forks(int phil); //invoked when phil wants to eat
void * return_forks(int phil); // invoked when phil finish eat
// state
struct state {

};
typedef struct state state;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

int main(int argc, char * argv[]) {
	n = (int) argv[1];
	srand(time(0));
	for (int i=0; i < 5; i++) {
		printf("%d, ", rand()):
	}
	return 0;
}


//
