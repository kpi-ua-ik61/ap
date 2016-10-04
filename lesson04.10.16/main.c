#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
// #include <math.h>

// #include "../lib/inputlib/inputlib.c"

int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};

int main() {

	for(int i = 0; i < sizeof(array)/sizeof(int); i += 5){
		for(int j = 0; j < 5; j++){
			printf("%d  ", array[i+j] );
		}
		printf("\n");
	}

	return 0;
}


