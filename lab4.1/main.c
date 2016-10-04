#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"

float precision;

float sinTeylor(float rad){
	float delta = rad;
	float sinus = rad;
	float n = 1;

	do{
		delta *= -1 * rad * rad / ((n + 1) * (n + 2));
		sinus += delta;
		//printf("%f\n", delta);
		n+=2;
	}
	while(fabs(delta) >= precision);

	return sinus;
}

float cosTeylor(float rad){
	float delta = 1;
	float cosin = 1;
	float n = 1;

	do{
		delta *= -1 * rad * rad / (2 * n * (2 * n - 1));
		cosin += delta;
		n+=1;
	}
	while(fabs(delta) >= precision);

	return cosin;
}

int code() {

	printf("Enter range limits, step in degrees and precise:\n");
	float x1 = returnInputFloat("x1: ");
	float x2 = returnInputFloat("x2: ");
	// if(x1 > x2){
	// 	printf("x1 > x2\n");
	// 	return 0;
	// }
	float step = returnInputFloat("step: ");
	int eps = returnEps();
	
	precision = returnPrecision(eps);
	printf("precision: %f\n\n", precision);

	printf("%*s   ", eps+5, "x");
	printf("%*s   |   ", eps+4, "rad");
	printf("%*s   ", eps+3, "sinT");
	printf("%*s   ", eps+3, "sin");
	printf("%*s   |   ", eps+3, "diff");
	printf("%*s   ", eps+3, "cosT");
	printf("%*s   ", eps+3, "cos");
	printf("%*s\n", eps+3, "diff");

	// printf(" x         rad          sinT         sin         sinT-sin         cosT         cos         cosT-cos\n");
	
	for (float x = x1; x <= x2; x += step){
		printf("%*.*f   ", eps+5, eps, x);

		float rad = x * M_PI / 180;
		printf("%*.*f   |   ", eps+4, eps, rad);

		float sinT = sinTeylor(rad);
		float cosT = cosTeylor(rad);
		float sinus = sin(rad);
		float cosin = cos(rad);

		printf("%*.*f   ", eps+3, eps, sinT);
		printf("%*.*f   ", eps+3, eps, sinus);
		printf("%*.*f   |   ", eps+3, eps, sinT - sinus);
		printf("%*.*f   ", eps+3, eps, cosT);
		printf("%*.*f   ", eps+3, eps, cosin);
		printf("%*.*f\n", eps+3, eps, cosT - cosin);
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
