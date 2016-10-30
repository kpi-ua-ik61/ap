#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "../lib/rand.h"
#include "../lib/inputlib.h"

void sortup(float *ar, int num){ 
	float t;
	for(int a = 0; a < num-1; a++){
		for(int b = a+1; b < num; b++){
			if(ar[a] > ar[b]){ 
				t = ar[a];
				ar[a] = ar[b];
				ar[b] = t;
			}
		}
	}
}

void sortdown(float *ar, int num){ 
	float t;
	for(int a = 0; a < num-1; a++){
		for(int b = a+1; b < num; b++){
			if(ar[a] < ar[b]){ 
				t = ar[a];
				ar[a] = ar[b];
				ar[b] = t;
			}
		}
	}
}

int code() {
	printf("Use random generator [Y/N]: ");
	char t = getch();
	printf("\n\n");
	
	if(t == 'y'){
		int n = randInt(2,10);
		n+=2;
		float array[n];

		for(int i = 0; i < n; i++){
			array[i] = randFloat();
			printf("%f\n", array[i]);
		}

		printf("\n\nAscending:\n");
		sortup(array, n);

		for (int i = 0; i < sizeof(array)/sizeof(float); i++){
			printf("%g\n", array[i]);
		}

		printf("\n\nDescending:\n");
		sortdown(array, n);

		for (int i = 0; i < sizeof(array)/sizeof(float); i++){
			printf("%g\n", array[i]);
		}

		return 0;
	}
	else{
		long int n = returnInputInt("Enter quantity of numbers: ");
		if(n < 2){
			printf("Error, n must be more than 1\n");
			return 0;
		}

		float array[n];

		for(int i = 0; i < n; i++){
			char buf[100];
			sprintf(buf, "Enter array value #%d: ", i+1);
			//printf("Enter array value #%d: ", i);
			array[i] = returnInputFloat(buf);
		}

		printf("\nAscending:\n");
		sortup(array, n);

		for (int i = 0; i < sizeof(array)/sizeof(float); i++){
			printf("%g\n", array[i]);
		}

		printf("\n\nDescending:\n");
		sortdown(array, n);

		for (int i = 0; i < sizeof(array)/sizeof(float); i++){
			printf("%g\n", array[i]);
		}

		return 0;

	}

	// for (int i = 0; i < sizeof(array)/sizeof(int); i++){
	// 	printf("%f ", array[i]);
	// }
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
