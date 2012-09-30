#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *print_message_function(void *ptr);

int main(void) {
	pthread_t thread1, thread2;
	int a[200];
	int b[200];
	int *message1 = a;
	int *message2 = b;
	int iret1, iret2;

	srand(time(NULL ));

	int i = 0;
	for (i = 0; i < 200; i++) {
		a[i] = 200 - i;
		b[i] = 200 - i;
		//	b[i]=rand()%100;
	}
	/* Create independent threads each of which will execute function */

	iret1 = pthread_create(&thread1, NULL, print_message_function,
			(void*) message1);
	iret2 = pthread_create(&thread2, NULL, print_message_function,
			(void*) message2);

	/* Wait till threads are complete before main continues. Unless we  */
	/* wait we run the risk of executing an exit which will terminate   */
	/* the process and all threads before the threads have completed.   */

	pthread_join(thread1, NULL );
	pthread_join(thread2, NULL );

	//printf("Thread 1 returns: %d\n", iret1);
	//printf("Thread 2 returns: %d\n", iret2);
	return 0;
}

void *print_message_function(void *ptr) {
	int *message;
	message = (int *) ptr;

	int i = 0;
	for (i = 0; i < 200; i++) {
		printf("%d \n", message[i]);
	}
}
