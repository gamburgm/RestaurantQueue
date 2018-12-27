#include <iostream>
#include <unistd.h>
#include "venue.h"
#include "restaurant.h"
#include "patron.h"
#include "controller.h"


int main(int argc, char** argv) {
	Restaurant v(10, 5);
	cout << "Venue remaining capacity should be 10: " << v.remainingCapacity() << endl;
	cout << "Venue time should be 0: " << v.getTime() << endl;
	cout << "Venue profit should be 0: " << v.getProfit() << endl;
	cout << endl;

	Patron p("yo", 5, 30);
	cout << "patron should have name yo: " << p.getName() << endl;
	cout << "patron should have size 5: " << p.getSize() << endl;
	cout << "patron should have time spent 30: " << p.getTimeSpent() << endl;

	v.addPatron(p.getName(), p.getSize(), p.getTimeSpent(), false);
	cout << "Expecting 10 0 0: " << v.remainingCapacity() << " " << v.getTime() << " " << v.getProfit() << endl;
	for (int i = 0; i < 30; i++) {
		v.tick();
	}

	cout << "Checking current time, which should be 30: " << v.getTime() << endl;
	cout << "Checking current availability, which should be 9: " << v.remainingCapacity() << endl;

	for (int i = 0; i < 30; i++) {
		v.tick();
	}

	cout << "Checking current time, should be 60: " << v.getTime() << endl;
	cout << "Checking current availability, which should be 10: " << v.remainingCapacity() << endl;
	cout << "Checking that we've made money: " << v.getProfit() << endl;

	Controller c(&cin, &cout, &v);

	c.play();

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
