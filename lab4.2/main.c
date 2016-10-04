#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"

int code() {

	int n = returnInputInt("Enter quantity of numbers: ");

	float array[n];

	for(int i = 0; i < n; i++){
		array[i] = returnInputFloat("Enter array" );
	}

	// for (int i = 0; i < sizeof(array)/sizeof(int); i++)
	// {
	// 	printf("%f ", array[i]);
	// }

	for (int i = 1; i <= n-1; i++){
		for (int j = 1; i <= n-i; j++){
			if (array[j-1] > array[j]){
				
			}
		}
	}

	return 0;
}

int main() {

	char exitchar;

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


