#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

typedef struct complex {
	float real;
	float imaginary;
} complex;

complex Z;

int code() {
	printf("Firstly you need to choose a circuit\n");
	printf("Please refer to GuideAP.pdf page 31\n");
	printf("Choose a circuit [1/2/3/4]:\n");
	char cir = getch(); printf("%c\n", (char)cir);

	if ( cir == '1') {
		float R = returnMinInputFloat("Enter R: ", 0.0);
		float L = returnMinInputFloat("Enter L: ", 0.0);
		float C = returnMinInputFloat("Enter C: ", 0.0);

		float Fmin = returnMinInputFloat("Enter min frequency: ", 0.0);
		float Fmax = returnMinInputFloat("Enter max frequency: ", 0.0);
		float df = returnMinInputFloat("Enter df: ", 0.0);

		if(Fmin == Fmax) {
			printf("Error, should be Fmin != Fmax\n");
			return 0;
		}
		else if (Fmin < Fmax && df < 0){
			printf("Error, should be Fmin < Fmax && df > 0\n");
			return 0;
		}
		else if (Fmin > Fmax && df > 0){
			printf("Error, should be Fmin > Fmax && df < 0\n");
			return 0;
		}

		float f = 1 / (2 * M_PI * sqrt(L * C));
		printf("\nf0 = %14e\n\n", f);

		printf("%*s   |   ", 10, "F");
		printf("%*s   \n", 5, "Z");

		if (Fmin < Fmax) {
			do {
				float w = 2 * M_PI * Fmin;

				float a = L / C;
				float b = - R / (w * C);
				float c = R;
				float d = w * L - 1 / (w * C);

				Z.real =    (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin <= Fmax);
		} else {
			do {
				
				float w = 2 * M_PI * Fmin;

				float a = L / C;
				float b = - R / (w * C);
				float c = R;
				float d = w * L - 1 / (w * C);

				Z.real =    (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin >= Fmax);
		}
	}
	else if ( cir == '2') {
		float R = returnMinInputFloat("Enter R: ", 0.0);
		float L = returnMinInputFloat("Enter L: ", 0.0);
		float C = returnMinInputFloat("Enter C: ", 0.0);

		float Fmin = returnMinInputFloat("Enter min frequency: ", 0.0);
		float Fmax = returnMinInputFloat("Enter max frequency: ", 0.0);
		float df = returnMinInputFloat("Enter step: ", 0.0);

		if(Fmin == Fmax) {
			printf("Error, should be Fmin != Fmax\n");
			return 0;
		}
		else if (Fmin < Fmax && df < 0){
			printf("Error, should be Fmin < Fmax && df > 0\n");
			return 0;
		}
		else if (Fmin > Fmax && df > 0){
			printf("Error, should be Fmin > Fmax && df < 0\n");
			return 0;
		}

		float f = 1 / (2 * M_PI * sqrt(L * C));
		printf("\nf0 = %14e\n\n", f);

		printf("%*s   |   ", 10, "F");
		printf("%*s   \n", 5, "Z");

		if (Fmin < Fmax) {
			do {
				float w = 2 * M_PI * Fmin;

				float a = L / C;
				float b = R / (w * C);
				float c = R;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin <= Fmax);
		} else {
			do {
				
				float w = 2 * M_PI * Fmin;

				float a = L / C;
				float b = R / (w * C);
				float c = R;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);
				
				Fmin += df;
			} while(Fmin >= Fmax);
		}
	}
	else if ( cir == '3') {
		float R1 = returnMinInputFloat("Enter R1: ", 0.0);
		float R2 = returnMinInputFloat("Enter R2: ", 0.0);
		float L = returnMinInputFloat("Enter L:  ", 0.0);
		float C = returnMinInputFloat("Enter C:  ", 0.0);

		float Fmin = returnMinInputFloat("Enter min frequency: ", 0.0);
		float Fmax = returnMinInputFloat("Enter max frequency: ", 0.0);
		float df = returnMinInputFloat("Enter step: ", 0.0);
		
		if(Fmin == Fmax) {
			printf("Error, should be Fmin != Fmax\n");
			return 0;
		}
		else if (Fmin < Fmax && df < 0){
			printf("Error, should be Fmin < Fmax && df > 0\n");
			return 0;
		}
		else if (Fmin > Fmax && df > 0){
			printf("Error, should be Fmin > Fmax && df < 0\n");
			return 0;
		}

		float f = 1 / (2 * M_PI * sqrt(L * C));
		printf("\nf0 = %14e\n\n", f);

		printf("%*s   |   ", 10, "F");
		printf("%*s   \n", 5, "Z");

		if (Fmin < Fmax) {
			do {
				float w = 2 * M_PI * Fmin;

				float a = R1 * R2;
				float b = R1 * (w * L - 1 / (w * C));
				float c = R1 + R2;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin <= Fmax + df);
		} else {
			do {
				float w = 2 * M_PI * Fmin;

				float a = R1 * R2;
				float b = R1 * (w * L - 1 / (w * C));
				float c = R1 + R2;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin >= Fmax);
		}
	}
	else if ( cir == '4') {
		float R1 = returnMinInputFloat("Enter R1: ", 0.0);
		float R2 = returnMinInputFloat("Enter R2: ", 0.0);
		float L = returnMinInputFloat("Enter L:  ", 0.0);
		float C = returnMinInputFloat("Enter C:  ", 0.0);

		float Fmin = returnMinInputFloat("Enter min frequency: ", 0.0);
		float Fmax = returnMinInputFloat("Enter max frequency: ", 0.0);
		float df = returnMinInputFloat("Enter step: ", 0.0);
		
		if(Fmin == Fmax) {
			printf("Error, should be Fmin != Fmax\n");
			return 0;
		}
		else if (Fmin < Fmax && df < 0){
			printf("Error, should be Fmin < Fmax && df > 0\n");
			return 0;
		}
		else if (Fmin > Fmax && df > 0){
			printf("Error, should be Fmin > Fmax && df < 0\n");
			return 0;
		}

		float f = 1 / (2 * M_PI * sqrt(L * C));
		printf("\nf0 = %14e\n\n", f);

		printf("%*s   |   ", 10, "F");
		printf("%*s   \n", 5, "Z");

		if (Fmin < Fmax) {
			do {
				float w = 2 * M_PI * Fmin;

				float a = R1 * R2 + L / C;
				float b = w * L * R1 - R2 / (w * C);
				float c = R1 + R2;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);

				Fmin += df;
			} while(Fmin <= Fmax + df);
		} else {
			do {
				float w = 2 * M_PI * Fmin;

				float a = R1 * R2 + L / C;
				float b = w * L * R1 - R2 / (w * C);
				float c = R1 + R2;
				float d = w * L - 1 / (w * C);

				Z.real = (a * c + b * d) / (c * c + d * d);
				Z.imaginary = (b * c - a * d) / (c * c + d * d);

				printf("%*g   |   ", 10, Fmin);
				printf("%14e + i * (%14e)   \n", Z.real, Z.imaginary);
				
				Fmin += df;
			} while(Fmin >= Fmax);
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
