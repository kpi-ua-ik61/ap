#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"

float precision;

float sinTeylor(float rad){
	float delta = 1;
	float sinus = 1;
	float n = 1;

	do{
		delta *= -1 * rad * rad / ((n + 1) * (n + 2));
		sinus += delta;
		printf("%f\n", delta);
		n+=2;
	}
	while(abs(delta) < precision);
}

float cosTeylor(float rad){
	float delta = 1;
	float cosin = 1;
	float n = 1;

	do{
		delta *= -1 * rad * rad / (2 * n * (2 * n - 1));
		cosin += cosin;
		n+=1;
	}
	while(abs(delta) < precision);
}

int code() {

	printf("Enter range limits, step in degrees and precise:\n");
	float x1 = returnInputFloat("x1: ");
	float x2 = returnInputFloat("x2: ");
	float step = returnInputFloat("step: ");
	int eps = returnEps();
	
	precision = returnPrecision(eps);
	printf("%f\n", precision);
	
	for (float x = x1; x <= x2; x += step){
		printf("%.*f   ", eps, x);

		float rad = x * M_PI / 180;

		printf("%f\n", rad);

		float sinT = sinTeylor(rad);
		float cosT = cosTeylor(rad);
		float sinus = sin(rad);
		float cosin = cos(rad);

		printf("%.*f   ", eps, sinT);
		printf("%.*f   ", eps, cosT);
		printf("%.*f   ", eps, sinus);
		printf("%.*f   ", eps, cosin);
		printf("%.*f \n", eps, sinT - sinus);
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


