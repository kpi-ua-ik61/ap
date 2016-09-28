#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int k;
float x;
int e;

float eps = 1;

float d = 1;

float y = 1;

char ex = 'y';

/*float power(float num, int power){
	float delta = 1;
	for(int i; i < power; i++){
		delta = delta * num;
		//printf("%f\n", delta);
	}
	return delta;
}*/

void iter(){
	do{
		d = (1.0/abs(k)) * ((x/pow(y, abs(k)-1)) - y);
		y += d;
		//printf("%f   >=   ", d);
		//printf("%f   ", eps);
		//printf("%.*f\n", e, y);
	}
	while(fabs(d) >= eps);
}


int calc() {
	eps = 1;

	d = 1;

	y = 1;

	char term;

	float d = 1;

	int icheck = 0;

	do{
		printf("Root power k = ");
		scanf("%d%c", &k, &term);
		if ( term != '\n' || k == 0) {
			printf("Input error, k must be an integer number, k != 0\n");
			printf("Try again or press Ctrl+C to exit\n");
			icheck = 0;
			fflush(stdin);
		}
		else icheck = 1;
	}
	while (!icheck);

	
	do{
		printf("        of x = ");
		if (scanf("%f%c", &x, &term) != 2 || term != '\n' ) {
			printf("Input error, x must be a number\n");
			printf("Try again or press Ctrl+C to exit\n");
			icheck = 0;
			fflush(stdin);
		}
		else icheck = 1;
	}
	while (!icheck);

	icheck = 0;
	do{
		printf("   precize e = ");
		scanf("%d%c", &e, &term);
		if ( term != '\n' || e < 0 || e >6 ) {
			printf("Input error, e must be an integer number, 0 < e <= 6\n");
			printf("Try again or press Ctrl+C to exit\n");
			icheck = 0;
			fflush(stdin);
		}
		else icheck = 1;
	}
	while (!icheck);

	for (int i = 0; i < e; i++)	{
		eps *= 0.1;
		//printf("%g\n", eps);
	}

	if (k == -1) {
		if (x != 0) y = 1/x;
		else {
				printf("Error k=-1 x=0\n");
				return 0;
			}
	}
	else if (k == 1) y = x;
	else if ( k < 0) {
		if (k%2 == 0) {
			if (x > 0) {
				iter();
				y = 1/y;
			}
			else {
				printf("Error k<0 & !k/2\n");
				return 0;
			}
		}
		else{
			if (x != 0){
				iter();
				y = 1/y;
			}
			else {
				printf("Error k<0 x=0\n");
				return 0;
			}
		}
	}
	else if ( k > 0) {
		if (k%2 == 0) {
			if (x > 0) {
				iter();
			}
			else if (x == 0) {
				y = 0;
			}
			else {
				printf("Error k>0 x<=0\n");
				return 0;
			}
		}
		else{
			if (x == 0) {
				y = 0;
			}
			else iter();
		}
	}

	printf("\nAnswer: y = %.*f\n", e, y);
}

int main() {
	do {

		calc();

		printf("\n");

		printf("Again? [y/n]: ");
		ex = getchar();

		printf("\n");


		fflush(stdin);

	}
	while( ex == 'y' || ex == 'Y' );

	return 0;
}
