#include "pch.h"
#include <stdio.h>
#include <string.h>
void SelectionSortString(char str[][2], int array_size);
int GetIndexOfMin(char str[][2], int starting_index, int final_index);
int main(void) {
	char str[][2] = { "f", "c", "b", "a" };
	int str_len = sizeof(str) / sizeof(char[2]);
	int i;

	printf("Unsorted Array\n");
	for (i = 0; i < str_len; i++) {
		printf("%s ", str[i]);
	}
	SelectionSortString(str, str_len);
	printf("\nSorted Array\n");
	for (i = 0; i < str_len; i++) {
		printf("%s ", str[i]);
	}

	return 0;
}
void SelectionSortString(char str[][2], int array_size) {
	int fill,           //index of first element in unsorted subarray. Will begin at 0
		index_of_min;   //index of smallest string in unsorted subarray
	char temp[20];       //temporary storage of a string
	for (fill = 0; fill < array_size - 1; fill++) {
		//get index of smallest string in unsorted subarray
		index_of_min = GetIndexOfMin(str, fill, array_size - 1);
		//exchange strings at fill and index_of_min
		if (fill != index_of_min) {
			strcpy(temp, str[index_of_min]);
			strcpy(str[index_of_min], str[fill]); /* ***********Debug mode says there's a problem here********/
			strcpy(str[fill], temp);
		}
	}
}
int GetIndexOfMin(char str[][2], int starting_index, int final_index) {
	int i,
		index_of_min = starting_index;       //assume first element of subarray is smallest string
	for (i = starting_index; i <= final_index; i++) {
		if (strcmp(str[i], str[index_of_min]) < 0)
			index_of_min = i;
	}
	return index_of_min;
}