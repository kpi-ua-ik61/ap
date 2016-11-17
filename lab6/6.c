#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int j;

int function(void) {
	int n, a, b, eo;
	char symbol;
	float **slar, *bsl, *x, *xp, *delta, *sum, eps, *tsum, tdel, prop;

	printf("\nEnter number of unknown x, accuracy and all coefficients and constants\n");

	do {
		printf("\nEnter number of unknown x: ");
		if ((scanf("%d%c", &n, &symbol) != 2) || (symbol != '\n') || (n <= 0) || (n > 32767)) {
			printf("Enter only natural numbers from 1 to 32767.\n");
			fflush(stdin);
			j = 0;
		} else {
			j = 1;
		}
	} while(j != 1);

	do {
		printf("\nEnter accuracy from 0 to 6: ");
		if ((scanf("%d%c", &eo, &symbol) != 2) || (symbol != '\n') || ((eo != 0) && (eo != 1) && (eo != 2) && (eo != 3) && (eo != 4) && (eo != 5) && (eo != 6))) {
			printf("Enter only numbers from 0 to 6.\n");
			fflush(stdin);
			j = 0;
		} else {
			j = 1;
		}
	} while(j != 1);
	switch (eo) {
		case 0: eps = 1; break;
		case 1: eps = 0.1; break;
		case 2: eps = 0.01; break;
		case 3: eps = 0.001; break;
		case 4: eps = 0.0001; break;
		case 5: eps = 0.00001; break;
		case 6: eps = 0.000001; break;
	}

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
			do {
				printf("Enter coefficient #%d.%d: ", a + 1, b + 1);
				if ((scanf("%f%c", &slar[a][b], &symbol) != 2) || (symbol != '\n') || (slar[a][b] > 3.4e38) || (slar[a][b] < (-3.4e38)) || ((slar[a][b] == 0) && (a == b))) {
					printf("Enter only numbers from -3.4e38 to 3.4e38, diagonal elements may not be 0.\n");
					fflush(stdin);
					j = 0;
				} else {
					j = 1;
				}
			} while(j != 1);
		}
		do {
			printf("Enter constant #%d: ", a + 1);
			if ((scanf("%f%c", &bsl[a], &symbol) != 2) || (symbol != '\n') || (bsl[a] > 3.4e38) || (bsl[a] < (-3.4e38))) {
				printf("Enter only numbers from -3.4e38 to 3.4e38.\n");
				fflush(stdin);
				j = 0;
			} else {
				j = 1;
			}
		} while(j != 1);
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
}

int main(void) {
	char temp;
	int t, i;
	do {
		function();
		do {
			i = 0;
			printf("\nDo you want to try again? [Y/N]\n");
			temp = getch();
			t = temp;
			if ((t == 121) || (t == 89)) {
				i = 1;
			}
			if ((t == 110) || (t == 78)) {
				i = (-1);
			}
			if ((i != (-1)) && (i != 1)) {
				printf("Enter Y (Yes) or N (No).\n");
				fflush(stdin);
				j = 0;
			} else {
				j = 1;
			}
		} while (j != 1);
	} while (i != (-1));

	return 0;
}
