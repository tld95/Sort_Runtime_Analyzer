#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"

int cmpfunc(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

void bubble_sort(int input[], int input_size) {
	for (int i = input_size; i > 0; i--) {
		for (int j = 0; j < i-1; j++) {
			if (input[j] > input[j+1]) {
				int temp = input[j];			
				input[j] = input[j+1];
				input[j+1] = temp;	
			}			
		}
	}	
}

void selection_sort(int input[], int input_size) {
	int max;
	int max_index;

	for (int i = input_size; i > 0; i--) {
	
		max = input[0];	
		max_index = 0;

		for (int j = 0; j < i; j++) {
			if (input[j] > max) {
				max_index = j;
				max = input[j];
			}			
		}
		input[max_index] = input[i-1];
		input[i-1] = max; 	
	}
}

void quick_sort(int input[], int input_size) {
	qsort(input,input_size,sizeof(int),cmpfunc);
}
