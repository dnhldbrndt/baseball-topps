/* This functions reads the pairs of names and numbers  from the want.names file and stores the values into two seperate arrays*/

#include <string.h>
#include <stdio.h>
#include "baseball.h"

#define MAXSIZE 1000

int readnames(char* filename, Baseball* baseball, int year){
	FILE *fp;
	char yearheader[20];
	char line[MAXSIZE];
	int x = 0;

	sprintf(yearheader, "%d Topps baseball", year);

	/*open the file*/
	fp = fopen(filename,"r");
	if(fp == NULL){
		printf("\nfile not found");
		return -1;
	}
 
	/* goes through the file until the specified year header is reached */
	while(fgets(line, MAXSIZE, fp)!=NULL) {
		line [strlen(line) - 1] = '\0';
		if(strcmp(line, yearheader) == 0){
			 break;
		 }

	}

	/* loops through the values until the list for the year ends */
	while( strcmp(line,  "") != 0) {
		fgets(line, MAXSIZE, fp);
		line [strlen(line) - 1] = '\0';

		if(strcmp(line, "") == 0) break;
		else
		sscanf(line, "%d %s", &baseball->toppsarray[x], &baseball->toppsnames[x]);
		x++;
 
	}

	baseball->count =  x;
	fclose(fp);
	return (0);
}