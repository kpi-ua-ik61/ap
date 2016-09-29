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
		float v = cbrtf(-q / 2 - sqrtf(d));

		float yone = u + v;
		float temp1 = -1 * yone / 2;
		float temp2 = cbrtf(3) * (u - v) / 2;

		printf("y1: %f\n", yone);
		printf("y2: %f + i * %f\n", temp1, temp2);
		printf("y2: %f - i * %f\n", temp1, temp2);
	}
	else if (d == 0){
		float yone = 3 * q / p;
		float ytwo = -1 * 3 * p / 2 / p;
		float ythree = ytwo;

		printf("y1: %f\n", yone);
		printf("y2: %f\n", ytwo);
		printf("y3: %f\n", ythree);

		float check = pow(yone, 3) + a * pow(ytwo, 2) + b * ythree + c;
		printf("\nCheck: %f", check);
		
	}
	else if (d < 0) {
		float r = sqrtf(-1 * pow(p, 3) / 27);
		float fi = acos(-1 * q / 2 * r);

		float yone = 2 * abs(cbrtf(r)) * cos(fi / 3);
		float ytwo = 2 * abs(cbrtf(r)) * cos((fi + 2 * M_PI) / 3);
		float ythree = 2 * abs(cbrtf(r)) * cos((fi + 4 * M_PI) / 3);

		printf("y1: %f\n", yone);
		printf("y2: %f\n", ytwo);
		printf("y3: %f\n", ythree);

		float check = pow(yone, 3) + a * pow(ytwo, 2) + b * ythree + c;
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


