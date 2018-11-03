#include <iostream>
//#include "venue.h"
//#include "patron.h"
//#include "line.h"

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *printMessage(void *);

int main(int argc, char** argv) {
	pthread_t thread1, thread2;

	int iret1 = pthread_create( &thread1, NULL, printMessage, (void *) "Hello!"); 
	int iret2 = pthread_create( &thread2, NULL, printMessage, (void *) "What's up?");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Yay! We did it! Returned: %d\n", iret1);
	printf("Yay! We did it! Returned: %d\n", iret2);

	return 0;
}


void *printMessage(void *ptr) {
	for (int i = 0; i < 10; i++) {
		pthread_mutex_lock(&m);
		printf("%s\n", (char *) ptr);
		pthread_mutex_unlock(&m);
	}
}
