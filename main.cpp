#include <iostream>
#include <unistd.h>
#include "venue.h"
#include "restaurant.h"
//#include "patron.h"


int main(int argc, char** argv) {
	Restaurant(10, 5);

	return 0;
}

/*
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

void *printMessage(void *);

int main(int argc, char** argv) {
	pthread_t thread1, thread2;

	int iret1 = pthread_create( &thread1, NULL, printMessage, (void *) "Hello!"); 
	int iret2 = pthread_create( &thread2, NULL, printMessage, (void *) "What's up?");

	sleep(1);
	pthread_cond_signal( &condition );

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Yay! We did it! Returned: %d\n", iret1);
	printf("Yay! We did it! Returned: %d\n", iret2);

	return 0;
}


void *printMessage(void *ptr) {
	for (int i = 0; i < 10; i++) {
		pthread_mutex_lock( &mutex );
		pthread_cond_signal( &condition );
		printf("%s\n", (char *) ptr);
		pthread_cond_wait( &condition, &mutex );
		pthread_mutex_unlock( &mutex );


	}
		pthread_mutex_lock( &mutex );
		pthread_cond_signal( &condition );
		printf("%s\n", (char *) ptr);
		pthread_mutex_unlock( &mutex );
}
*/
