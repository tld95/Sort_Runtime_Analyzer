#ifndef SORTS_H
#define SORTS_H

void bubble_sort(int input[], int input_size, int (*cmp)(const void *, const void *));
void selection_sort(int input[], int input_size, int (*cmp)(const void *, const void *));
void insertion_sort(int input[], int input_size, int (*cmp)(const void *, const void *));

#endif
