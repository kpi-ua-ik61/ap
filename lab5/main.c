#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"


int code() {
	int arrLength = 0;
	int strLength = 0;

	printf("Use random generator [Y/N]: ");
	char r = getch();
	printf("\n\n");
	
	if(r == 'y'){
		arrLength = randInt(2, 5);
		strLength = randInt(3, 5);
	}
	else {
		arrLength = returnMinInputInt("Enter array length: ", 2);
		strLength = returnMinInputInt("Enter string length: ", 2) + 2;
	}

	char array[arrLength][strLength];
	char *arrAddr[arrLength];
	
	if(r == 'y'){
		for(int i = 0; i < arrLength; i++){
			for(int k = 0; k < strLength-1; k++){
				array[i][k] = (char) randInt(97, 122);
			}
			array[i][strLength] = '\0';
		}
	}
	else {
		for(int i = 0; i < arrLength; i++){
			char outbuf[100];
			sprintf(outbuf, "Enter array value #%d: ", i+1);
			printf("%s", outbuf);

			fgets(array[i], strLength, stdin);

			if ((strlen(array[i])>0) && (array[i][strlen (array[i]) - 1] == '\n'))
				array[i][strlen (array[i]) - 1] = '\0';

			fflush(stdin);
		}
	}

	for (int i=0; i < arrLength; i++) {
		arrAddr[i]=array[i];
	}

	printf("\n");
	for(int i = 0; i < arrLength; i++){
		printf("%s\n", array[i]);
	}

	printf("\nAscending:\n");

	//  ***  ascending sort ***
	char t[strLength];
	for(int a = 0; a < arrLength; a++){
		for(int b = a+1; b < arrLength; b++){
			if(strcmp(arrAddr[a], arrAddr[b]) > 0){ 
				*t = *arrAddr[a];
				*arrAddr[a] = *arrAddr[b];
				*arrAddr[b] = *t;
			}
		}
	}
	

	for(int i = 0; i < arrLength; i++){
		printf("%s\n", array[i]);
	}

	printf("\n\nDescending:\n");

	//  ***  descending sort ***
	for(int a = 0; a < arrLength; a++){
		for(int b = a+1; b < arrLength; b++){
			if(strcmp(arrAddr[a], arrAddr[b]) < 0){ 
				*t = *arrAddr[a];
				*arrAddr[a] = *arrAddr[b];
				*arrAddr[b] = *t;
			}
		}
	}
	

	for(int i = 0; i < arrLength; i++){
		printf("%s\n", array[i]);
	}
	
	return 0;
}


int main() {

	char exitchar;

	randInit();

	do {
		code();

		printf("\n");
		printf("Again? [y/n]: ");
		exitchar = getch();

		printf("\n");
	}
	while( exitchar == 'y' || exitchar == 'Y' );

	return 0;
}


