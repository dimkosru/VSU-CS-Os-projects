#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 10

void *print_message_function(void *ptr);
void *bubbleSort(void *ptr);

int main(void) {
	pthread_t thread1, thread2;
	int a[MAX];
	int b[MAX];
	int *message1 = a;
	int *message2 = b;

	srand(time(NULL ));

    // Заполенение массивов
	int i = 0;
	for (i = 0; i < MAX; i++) {
		a[i] = rand() % MAX;
		b[i] = rand() % MAX;

	}

    // Создание потоков
	pthread_create(&thread1, NULL, bubbleSort, (void*) message1);
	pthread_create(&thread2, NULL, bubbleSort, (void*) message2);

	pthread_join(thread1, NULL );
	pthread_join(thread2, NULL );

    // Вывод результата
	i = 0;
	for (i = 0; i < MAX; i++) {
		printf("%d \n", a[i]);
	}
	return 0;
}

/* Тестовая функция для вывода массива */
void *print_message_function(void *ptr) {
	int *a;
	a = (int *) ptr;

	int i = 0;
	for (i = 0; i < MAX; i++) {
		printf("%d \n", a[i]);
	}
	return 0;
}


/* Пузырьковая сортировка */
void *bubbleSort(void *ptr) {
	int *a;
	a = (int *) ptr;

	int i, j;
	int x;
	for (i = 0; i < MAX; i++) {
		for (j = MAX - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
	return 0;
}
