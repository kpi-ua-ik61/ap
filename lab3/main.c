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
		printf("%f   >=   ", d);
		printf("%f   ", eps);
		printf("%.*f\n", e, y);
	}
	while(fabs(d) >= eps);
}

int main() {
	do {

		eps = 1;

		d = 1;

		y = 1;

		char term;

		float d = 1;

		printf("Root power k = ");
		scanf("%d%c", &k, &term);
		if ( term != '\n' ) {
			printf("Input error, enter normal value");
			break;
		}

		printf("        of x = ");
		scanf("%f%c", &x, &term);
		if ( term != '\n' ) {
			printf("Input error, enter normal value");
			break;
		}

		printf("   precize e = ");
		scanf("%d%c", &e, &term);
		if ( term != '\n' || e < 0 || e >6 ) {
			printf("Input error, enter normal value");
			break;
		}

		for (int i = 0; i < e; i++)	{
			eps *= 0.1;
			//printf("%g\n", eps);
		}


		if (k == 0) printf("ERRRRROOOOOOOORRRRRRRRRRRR");
		else if (k == -1) {
			if (x != 0) y = 1/x;
			else printf("Error\n");
		}
		else if (k == 1) y = x;
		else if ( k < 0) {
			if (k%2 == 0) {
				if (x > 0) {
					iter();
					y = 1/y;
				}
				else printf("Error\n");
			}
			else{
				if (x != 0){
					iter();
					y = 1/y;
				}
				else printf("Error\n");
			}
		}
		else if ( k > 0) {
			if (x == 0) y = 0;
			if (k%2 == 0) {
				if (x > 0) {
					iter();
				}
				else printf("Error\n");
			}
			else{
				iter();
			}
		}

		printf("%.*f\n", e, y);

		printf("Again? [y/n]: ");
		ex = getchar();

		printf("\n\n");

	}
	while( ex == 'y' || ex == 'Y' );
	

	return 0;
}
