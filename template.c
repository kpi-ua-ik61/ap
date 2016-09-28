#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inputlib.h"

int code() {

	// code

	return 0;
}

int main() {

	char exitchar;

	do {
		code();

		printf("\n");
		printf("Again? [y/n]: ");
		exitchar = getchar();

		printf("\n");
	}
	while( exitchar == 'y' || exitchar == 'Y' );

	return 0;
}


