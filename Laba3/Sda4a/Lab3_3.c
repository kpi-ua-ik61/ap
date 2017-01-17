#include <curses.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int coefCheck(char* coefNum){
	float result;
	char enter;

	printf("\nEnter your number, that must be a coefficient %s: ", coefNum);
	if (scanf("%f%c", &result, &enter) != 2 || enter != '\n'){
		printf("ERROR \nYou cannot enter symbols, \nand the programm doesnt want to continue work with such uncompetent user\nwhat a shame");
		exit(0);
	}
	else {
		return result;
	}
	
	
}
int code(){
	float x1, x2, x3;
	float coefA = coefCheck("A");
	float coefB = coefCheck("B");
	float coefC = coefCheck("C");
	printf("Your coefs are A:%f  B:%f  C:%f", coefA, coefB, coefC);
	
	if ((coefA == 0) && (coefB == 0) && (coefC == 0))
	{
		x1 = 0;
		x2 = 0;
		x3 = 0;
		printf("\nYour results:\nx1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);
	}
	if ((coefB == ((coefA * coefA) / 3)) && (coefC == ((coefA * coefA * coefA) / 27)))
	{
		x1 = (-coefA / 3);
		x2 = (-coefA / 3);
		x3 = (-coefA / 3);
		printf("\nYour results:\nx1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);
	}
	else
	{
		float p, q, d, z1, z2, z3;
		p = (coefB - ((coefA * coefA) / 3));
		q = ((2 * (coefA * coefA * coefA) / 27) - (((coefA * coefB) / 3) + coefC));
		d = ((( p * p * p) / 27) + ((q * q) / 4));
		if (d > 0){
			float u, v, y2, y3;
			u = cbrtf((-q / 2) + sqrtf(d));
			v = cbrtf((-q / 2) - sqrtf(d));
			z1 = (u + v);
			y2 = ((sqrt(3) * (u - v)) / 2);
			z2 = (-(u + v) / 2);
			y3 = y2;
			z3 = z2;
			x1 = (z1 - (coefA / 3));
			x2 = (z2 - (coefA / 3));
			x3 = (z3 - (coefA / 3));
			printf("\nYour results:\nx1 = %f\nx2 = %f + i * %f\nx3 = %f - i * %f\n", x1, x2, x2, x3, x3);
		}
		if (d == 0){
			z1 = ((3 * q) / p);
			z2 = (-(3 * q) / (2 * p));
			z3 = z2;
			x1 = (z1 - (coefA / 3));
			x2 = (z2 - (coefA / 3));
			x3 = (z3 - (coefA / 3));
			printf("\nYour results:\nx1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);
		}
		if (d < 0){
			float r, f;
			r = sqrtf((-p * p * p) / 27);
			f = acos(-q / (2 * r));
			z1 = ((2 * fabs(cbrtf(r))) * cos(f / 3));
			z1 = ((2 * fabs(cbrtf(r))) * cos((f + 2 * M_PI) / 3));
			z1 = ((2 * fabs(cbrtf(r))) * cos((f + 4 * M_PI) / 3));
			x1 = (z1 - (coefA / 3));
			x2 = (z2 - (coefA / 3));
			x3 = (z3 - (coefA / 3));
			printf("\nYour results:\nx1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);
		}
	}
}
int main(){
	code();
	exit(0);
}