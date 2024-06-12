/* This function compares two arrays and prints the pairs of names and numbers to the file */

#include <stdio.h>
#include "baseball.h"

int comparetopps (char* filename, int* toppsarray, int elements, Baseball* baseball, int year){
	int i, j;
	FILE *fp;

	/* make new file */
	fp = fopen(filename,"a");
	if(fp == NULL){
		printf("\nfile not found compare");
		return -1;
	}

	fprintf(fp, "%d Topps baseball\n", year);

	/* loop through both arrays printing the matched name/number pairs to the file */
	for(i = 0; i < baseball->count; i++) {
		for(j = 0; j < elements; j++) {
			if (baseball->toppsarray[i] == toppsarray[j]) {
				printf( "%d %s\n", baseball->toppsarray[i], baseball->toppsnames[i]);
				fprintf(fp, "%d %s\n", baseball->toppsarray[i], baseball->toppsnames[i]);
			}

		}

	}
	fprintf(fp, "\n");
	fclose(fp);
	return (0);
}