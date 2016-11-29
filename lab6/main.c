#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

int code() {
	int a, b;
	float tdel;
	float prop;

	printf("\nSolving the system of linear equations\n");


	printf("| a(1,1)*x1 + a(1,2)*x2 + ... + a(1,n)*xn = b1\n");
	printf("| a(2,1)*x1 + a(2,2)*x2 + ... + a(2,n)*xn = b2\n");
	printf("| ............................................\n");
	printf("| a(n,1)*x1 + a(n,2)*x2 + ... + a(n,n)*xn = bn\n\n");

	printf("Use random generator [Y/N]: ");
	char t = getch();
	printf("\n\n");

	int n;
	if(t == 'y' || t == 'Y')
		n = randInt(2, 6);
	else 
		n = returnMinInputInt("Enter n: ", 2);

	int eps;
	if (t == 'y' || t == 'Y') 
		n = randInt(2, 6);
	else 
		eps = returnEps();

	float precision = returnPrecision(eps);

	float **syst = calloc(n, sizeof(float*));
	for (a = 0; a < n; a++) {
		syst[a] = (float*)calloc(n, sizeof(float*));
	}

	float *constants = calloc(n, sizeof(float));
	float *x = calloc(n, sizeof(float));
	float *xp = calloc(n, sizeof(float));
	float *delta = calloc(n, sizeof(float));
	float *sum = calloc(n, sizeof(float));
	float *tsum = calloc(n, sizeof(float));

	printf("\n");

	// entering the system
	for (a = 0; a < n; a++) {
		for (b = 0; b < n; b++) {
			if (t == 'y' || t == 'Y')
				syst[a][b] = randFloat();
			else {
				char buf[100];
				sprintf(buf, "Enter a (%d,%d): ", a + 1, b + 1);

				syst[a][b] = returnInputFloat(buf);
			}
		}

		if (t == 'y' || t == 'Y')
			constants[a] = randFloat();
		else {
			char buf[100];
			sprintf(buf, "Enter b%d: ", a + 1);

			constants[a] = returnInputFloat(buf);
		}

	}


	printf("\n");

	// display a sysem
	for (a = 0; a < n; a++) {
		printf("| ");
		for (b = 0; b < n; b++) {
			if ((b != 0) && (syst[a][b] >= 0 )) {
				printf(" +");
			}
			else printf(" ");
			printf("%g*x%d", syst[a][b], b + 1);
			if (b == (n - 1)) {
				printf(" = %g\n", constants[a]);
			}
		}
	}

	printf("\n");


	for (a = 0; a < n; a++) {
		tsum[a] = 0;
		for (b = 0; b < n; b++) {
			if (a != b) {
				tsum[a] += syst[a][b];
			}
		}
		if (fabs(syst[a][a]) < fabs(tsum[a])) {
			printf("Error: diagonal elements may not be bigger than sum of other elemens in a row.\n");
			return 0;
		}
	}

	for (a = 0; a < n; a++) {
	  xp[a] = constants[a] / syst[a][a];
	}

	do {
		prop = 0;
		for (a = 0; a < n; a++) {
			sum[a] = 0;
			for (b = 0; b < n; b++) {
				if (a != b) {
					sum[a] += syst[a][b] * xp[b];
				}
			}
			x[a] = (constants[a] - sum[a]) / syst[a][a];
			delta[a] = fabs(x[a] - xp[a]);
			if (delta[a] > prop) {
				prop = delta[a];
			}
			xp[a] = x[a];
		}
	} while(prop >= precision);

	printf("Answer:\n");
	for (a = 0; a < n; a++) {
		printf("x%d = %g\n", a + 1, xp[a]);
	}

	// releasing the memory

	for (a = 0; a < n; a++) {
		free(syst[a]);
	}
	free(syst);
	free(constants);
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
