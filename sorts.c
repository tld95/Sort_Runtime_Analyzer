#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"


void bubble_sort(int* input, int input_size, int (*cmp)(const void *, const void *)) {
	for (int i = input_size; i > 0; i--) {
		for (int j = 0; j < i-1; j++) {
			if (cmp((void *)(input+j),(void *)(input+(j+1))) > 0) {
				int temp = *(input+j);			
				*(input+j) = *(input+(j+1));
				*(input+(j+1)) = temp;	
			}			
		}
	}	
}

void selection_sort(int* input, int input_size, int (*cmp)(const void *, const void *)) {
	int* max;
	int max_index;

	for (int i = input_size; i > 0; i--) {
		max = input;	
		max_index = 0;

		for (int j = 0; j < i; j++) {
			if (cmp((void *)(input+j),(void *)(max)) > 0) {
				max_index = j;
				max = (input+j);
			}			
		}

		int temp = (*max);
		*(input+max_index) = *(input+(i-1));
		*(input+(i-1)) = temp; 
	}
}

