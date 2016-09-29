#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"

float a;
float b;
float c;

int code() {

	float p;
	float q;

	float d;

	printf("Solving cubing equation x^3 + ax^2 + bx + c = 0\n");
	a = returnInputFloat("Enter a: ");
	b = returnInputFloat("Enter b: ");
	c = returnInputFloat("Enter c: ");

	p = b - pow(a, 2) / 3;
	printf("p: %f\n", p);

	q = (2 * pow(a, 3) / 27) - (a * b / 3) + c;
	printf("q: %f\n", q);

	d = (pow(p, 3) / 27) + (pow(q, 2) / 4);
	printf("d: %f\n", d);

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


