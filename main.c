/* Program that updates the player name list of topps baseball cards. It reads a list of 2-digit years from the 
command line which represent the files that need to be opened and processed. The program then stores the found values into 
an array,  compares them with those found in the name list, and prints the matches into a new file. */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "baseball.h"

#define WANTNAMES "want.names"

int main( int argc, char *argv[])
{
	int readtopps(char*, int*, int*);
	int readnames(char*,Baseball*, int);
	int comparetopps(char*, int*,  int, Baseball*, int);

	char filename[20];
	char newfile[20];
	int year;
	int temparray[200];
	int count;
	int x = 0;
	Baseball baseballcard;
	
	strcpy(newfile, "new.names");

	/* loop as long as there are files left to process*/
	while (argc-1 != 0){
		year = 1900 + atoi(argv[1+x]);
		sprintf(filename, "topps.%d", atoi(argv[1+x]));
		
		readtopps(filename, temparray, &count);
		readnames(WANTNAMES, &baseballcard, year);
		comparetopps(newfile, temparray, count, &baseballcard, year);
		
		x++;
		argc--;
	}

    return (0);
}



