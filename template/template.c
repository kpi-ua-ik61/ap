#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"

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
		exitchar = getch();

		printf("\n");
	}
	while( exitchar == 'y' || exitchar == 'Y' );

	return 0;
}


