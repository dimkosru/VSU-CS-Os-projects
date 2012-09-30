/*
 * main.c
 *
 *  Created on: 30.09.2012
 *      Author: dimko
 */

#include <stdio.h>
#define MAX 10

int main(void) {
	int array[MAX] = { 5, 34, -1, 64, -2, 62, -7, 2, 73, 10 };
	//int a = 0;
	//int i = 0;

	/*
	 while (scan("%d", &a)) {
	 array[i] = a;
	 }*/
	int i=0;
	for (i = 0; i < MAX; i++) {
		printf("%d ", array[i]);
	}

	for (i = 1; i < MAX; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}

	printf("\n");
	for (i = 0; i < MAX; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
