#include <stdio.h>
#include <stdlib.h>
#include "IO.h"

#define MAX_LENGTH 100

int read_data(int** data, int* count, char* file_name) {
	FILE *input_data; 
	char line[MAX_LENGTH];
	*data = (int *)malloc(sizeof(int));

	input_data = fopen(file_name,"r");
	
	if (input_data == NULL) {
		perror("Could not open data.txt.");
		return -1;	
	}

	while(fgets(line, MAX_LENGTH, input_data) != NULL) {
		if (count > 0) {
			*data = (int *)realloc(*data, sizeof(int)*((*count)+1));
		}

		if (data != NULL) {	
			int index = (*count);
			sscanf(line,"%d", (*data)+index);
			(*count)++;	
		} else {
			free(data);
			perror("Error reallocating memory to data array.");
			return -1;		
		}
	}

	fclose(input_data);
	return 0;
}



int write_data(int** data, int count, char* file_name) {
	int index = 0;
	FILE *output_data = NULL;
	
	output_data = fopen(file_name,"w");


	if (output_data == NULL) {
		perror("Could not open sorted.txt");
		return -1;	
	}

	for (index = 0; index < count; index++) {
		fprintf(output_data,"%d\n", (*data)[index]);
	}

	fclose(output_data);
	return 0;
}
