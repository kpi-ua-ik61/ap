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
	printf("q: %f\n\n", q);

	d = (pow(p, 3) / 27) + (pow(q, 2) / 4);
	printf("d: %f\n\n", d);

	if (d > 0){
		float u = cbrtf(-q / 2 + sqrtf(d));
		printf("u: %f\n", u);

		float v = cbrtf(-q / 2 - sqrtf(d));
		printf("v: %f\n\n", v);

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
		float xtwo = -1 * 3 * p / 2 / p - a/3;
		float xthree = xtwo;

		printf("x1: %f\n", xone);
		printf("x2: %f\n", xtwo);
		printf("x3: %f\n", xthree);

		float check = pow(xone, 3) + a * pow(xtwo, 2) + b * xthree + c;
		printf("\nCheck: %f", check);
		
	}
	else if (d < 0) {
		float r = sqrtf(-1 * pow(p, 3) / 27);
		float fi = acos(-1 * q / 2 * r);

		float xone = 2 * abs(cbrtf(r)) * cos(fi / 3) - a/3;
		float xtwo = 2 * abs(cbrtf(r)) * cos((fi + 2 * M_PI) / 3) - a/3;
		float xthree = 2 * abs(cbrtf(r)) * cos((fi + 4 * M_PI) / 3) - a/3;

		printf("x1: %f\n", xone);
		printf("x2: %f\n", xtwo);
		printf("x3: %f\n", xthree);

		float check = pow(xone, 3) + a * pow(xtwo, 2) + b * xthree + c;
		printf("\nCheck: %f", check);

	}

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


