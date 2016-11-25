#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "lib/inputlib.h"
#include "lib/rand.h"

int code() {

	for (int i = 0; i < 100; i++){
		char c = (char) randInt(97, 122);
		putchar(c);
	}
	return 0;
}

int main() {

	randInit();

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