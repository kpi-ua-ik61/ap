#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"

float precision;
int eps;

float sinTeylor(float rad){
	float delta = rad;
	float sinus = rad;
	float n = 1;

	do{
		delta *= -1 * rad * rad / ((n + 1) * (n + 2));
		sinus += delta;
		//printf("%f\n", sinus);
		n+=2;
	}
	while(fabs(delta) >= precision);

	sinus *= pow(10, 6-eps);
	sinus /= pow(10, 6-eps);
	//printf("%f\n", sinus);

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
	
	float step = returnInputFloat("step: ");
	if(step == 0){ printf("Step can't be 0!");}

	if(x1 < x2 && step < 0){
		printf("If x1 < x2 step should be step > 0\n");
		return 0;
	}

	if(x1 > x2 && step > 0){
		printf("If x1 > x2 step should be step < 0\n");
		return 0;
	}
	eps = returnEps();
	
	precision = returnPrecision(eps);
	printf("precision: %f\n\n", precision);

	printf("%*s   |   ", 10, "x");
	printf("%*s   |   ", 8, "rad");
	printf("%*s   ", 8, "sinT");
	printf("%*s   ", 8, "sin");
	printf("%*s   |   ", 9, "diff");
	printf("%*s   ", 8, "cosT");
	printf("%*s   ", 8, "cos");
	printf("%*s\n", 9, "diff");

	// printf(" x         rad          sinT         sin         sinT-sin         cosT         cos         cosT-cos\n");
	int rowCounter = 0;
	int pageCounter = 0;
	int rowNumber = 0;
	int pageNumber = 0;
	if(step > 0) {
		for (float x = x1; x <= x2; x += step){
			rowNumber++;
		}

		if(rowNumber%15 == 0) pageNumber = rowNumber/15;
		else if (rowNumber%15 > 0) pageNumber = rowNumber/15+1;

		for (float x = x1; x <= x2; x += step){
			printf("%*.*f   |   ", 10, 6, x);

			float rad = x * M_PI / 180;
			printf("%*.*f   |   ", 8, 6, rad);

			// printf("  %f\n", x);

			float sinT = sinTeylor(rad);
			float cosT = cosTeylor(rad);
			float sinus = sin(rad);
			float cosin = cos(rad);

			printf("%*.*f   ", 6, 6, sinT);
			printf("%*.*f   ", 6, 6, sinus);
			printf("%*.*f   |   ", 9, 6, sinus-sinT);
			printf("%*.*f   ", 6, 6, cosT);
			printf("%*.*f   ", 6, 6, cosin);
			printf("%*.*f\n", 9, 6, cosin-cosT);

			rowCounter++;

			if(rowCounter % 15 == 0){
				pageCounter++;
				printf("Page %d/%d, press any key to continue...", pageCounter, pageNumber);
				getch();
				printf("\n");
				if(rowCounter != rowNumber){
					printf("%*s   |   ", 10, "x");
					printf("%*s   |   ", 8, "rad");
					printf("%*s   ", 8, "sinT");
					printf("%*s   ", 8, "sin");
					printf("%*s   |   ", 9, "diff");
					printf("%*s   ", 8, "cosT");
					printf("%*s   ", 8, "cos");
					printf("%*s\n", 9, "diff");
				}

			}
		}
	}
	else {
		for (float x = x1; x >= x2; x += step){
			printf("%*.*f   |   ", 10, 6, x);

			float rad = x * M_PI / 180;
			printf("%*.*f   |   ", 8, 6, rad);

			float sinT = sinTeylor(rad);
			float cosT = cosTeylor(rad);
			float sinus = sin(rad);
			float cosin = cos(rad);

			printf("%*.*f   ", 6, 6, sinT);
			printf("%*.*f   ", 6, 6, sinus);
			printf("%*.*f   |   ", 9, 6, sinT - sinus);
			printf("%*.*f   ", 6, 6, cosT);
			printf("%*.*f   ", 6, 6, cosin);
			printf("%*.*f\n", 9, 6, cosin - cosT);
		}
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