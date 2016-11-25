#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

int code() {
	int n, a, b, eo;
	//char symbol;
	float **slar, *bsl, *x, *xp, *delta, *sum, eps, *tsum, tdel, prop;

	printf("\nEnter number of unknown x, accuracy and all coefficients and constants\n");

	n = returnInputInt("Enter number of unknown x: ");
	eo = returnEps();
	eps = returnPrecision(eo);

	slar = (float**)calloc(n, sizeof(float*));

	for (a = 0; a < n; a++) {
		slar[a] = (float*)calloc(n, sizeof(float*));
	}

	bsl = (float*)calloc(n, sizeof(float));
	x = (float*)calloc(n, sizeof(float));
	xp = (float*)calloc(n, sizeof(float));
	delta = (float*)calloc(n, sizeof(float));
	sum = (float*)calloc(n, sizeof(float));
	tsum = (float*)calloc(n, sizeof(float));

	printf("\n");

	for (a = 0; a < n; a++) {
		for (b = 0; b < n; b++) {
			char buf[100];
			sprintf(buf, "Enter coefficient #%d.%d: ", a + 1, b + 1);

			slar[a][b] = returnInputFloat(buf);
		}

		char buf[100];
		sprintf(buf, "Enter constant #%d: ", a + 1);

		bsl[a] = returnInputFloat(buf);
	}

	printf("\nYour system:\n");
	for (a = 0; a < n; a++) {
		for (b = 0; b < n; b++) {
			if ((b != 0) && (slar[a][b] >= 0 )) {
				printf("+");
			}
			printf("%g*x%d", slar[a][b], b + 1);
			if (b == (n - 1)) {
				printf("=%g\n", bsl[a]);
			}
		}
	}

	for (a = 0; a < n; a++) {
		tsum[a] = 0;
		for (b = 0; b < n; b++) {
			if (a != b) {
				tsum[a] += slar[a][b];
			}
		}
		if (fabs(slar[a][a]) <= fabs(tsum[a])) {
			printf("Sorry, programm can\'t solve this system:\n");
			printf("absolute value of diagonal elements may be bigger than\n");
			printf("absolute value of sum of other elemens in the string.\n");
			return 0;
		}
	}

	for (a = 0; a < n; a++) {
	  xp[a] = bsl[a] / slar[a][a];
	}
	do {
		prop = 0;
		for (a = 0; a < n; a++) {
			sum[a] = 0;
			for (b = 0; b < n; b++) {
				if (a != b) {
					sum[a] += slar[a][b] * xp[b];
				}
			}
			x[a] = (bsl[a] - sum[a]) / slar[a][a];
			delta[a] = fabs(x[a] - xp[a]);
			if (delta[a] > prop) {
				prop = delta[a];
			}
			xp[a] = x[a];
		}
	} while(prop >= eps);

	printf("Your results:\n");
	for (a = 0; a < n; a++) {
		printf("x%d = %g\n", a + 1, xp[a]);
	}

	for (a = 0; a < n; a++) {
		free(slar[a]);
	}
	free(slar);
	free(bsl);
	free(x);
	free(xp);
	free(delta);
	free(sum);
	free(tsum);

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
