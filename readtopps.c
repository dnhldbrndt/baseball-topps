/* Function that reads the topps files and stores the read number values into an array */
#include<stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXSIZE 1000


int readtopps(char* filename, int* temparray, int* elements){
	FILE *fp;
 
    char line[MAXSIZE];
	char linebreak[20] = "-------------------";
	int i ;

	int count = 0;

	/*open the file*/
	fp = fopen(filename,"r");
	if(fp == NULL){
		printf("\nfile not found read ");
		return -1;
	}
 
    /*continue the loop till the break line is found and then break to begin reading*/
	while(fgets(line, MAXSIZE , fp)!=NULL) {
		line [strlen(line) - 1] = '\0';
		if(strcmp(line, linebreak) == 0){
			 break;
		 }
		 
	}

	/* read from file and store values into array until the end of the file*/ 
	for(i = 0; !feof(fp); i++) {
	fscanf(fp, "%d", &temparray[i]);
	count++;
	}
	*elements = count;
	fclose(fp);
	return (0);
}