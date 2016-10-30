#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#include "../lib/inputlib.h"

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

	p = b - powf(a, 2) / 3;
	// printf("p: %f\n", p);

	q = (2 * powf(a, 3) / 27) - (a * b / 3) + c;
	// printf("q: %f\n\n", q);

	d = (powf(p, 3) / 27) + (powf(q, 2) / 4);
	// printf("d: %f\n\n", d);

	if (d > 0){
		float u = cbrtf(-q / 2 + sqrtf(d));
		// printf("u: %f\n", u);

		float v = cbrtf(-q / 2 - sqrtf(d));
		// printf("v: %f\n\n", v);

		float yone = u + v;
		float xone = yone - a / 3;
		float temp1 = -yone / 2 - a/3;
		float temp2 = (sqrtf(3) * (u - v)) / 2;

		printf("x1: %f\n", xone);
		printf("x2: %f + i * %f\n", temp1, temp2);
		printf("x2: %f - i * %f\n", temp1, temp2);
	}
	else if (d == 0){
		float xone = 3 * q / p - a/3;
		float xtwo = -1 * 3 * q / 2 / p - a/3;
		float xthree = xtwo;

		printf("\nx1: %f\n", xone);
		printf("x2: %f\n", xtwo);
		printf("x3: %f\n", xthree);

		// printf("\nCheck: %f", xone*xone*xone + a * xtwo * xtwo + b * xthree + c);
		
	}
	else if (d < 0) {
		float r = sqrtf(-1 * powf(p, 3) / 27);
		float fi = acos(-q / 2 / r);

		float xone = 2 * fabs(cbrtf(r)) * cos(fi / 3) - a/3;
		float xtwo = 2 * fabs(cbrtf(r)) * cos((fi + 2 * M_PI) / 3) - a/3;
		float xthree = 2 * fabs(cbrtf(r)) * cos((fi + 4 * M_PI) / 3) - a/3;

		printf("x1: %g\n", xone);
		printf("x2: %g\n", xtwo);
		printf("x3: %g\n", xthree);

		// printf("\nCheck: %f", xone*xone*xone + a * xtwo * xtwo + b * xthree + c);

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
