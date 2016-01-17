#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "IO.h"

int main() {
	int count = 0;	
	int *data;
	clock_t begin,end;
	double time_spent;

	// Get unsorted data from text file
	read_data(&data, &count);

	// Time Sort
	begin = clock();	
    	quick_sort(data, count);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Sort Time for %d elements is %f seconds\n",count, time_spent);

	// Write sorted data to text file
	write_data(&data, count);

	free(data);
	data = NULL;
	return 0;
}

