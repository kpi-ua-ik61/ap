#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

float function1(float x, float y){
	return (cos(y/x) - 2*sin(1/x) + 1/x);
}

float function2(float x, float y){
	return (sin(log(x)) - cos(log(x)) + y*log(x));
}

float derivative(float x){
	
}

float half(int method, float a, float b, float y, float precision){
	float x;
	do{
		x = (a + b) / 2;
		if(method == 1){
			if(function1(a)*function1(x) > 0)
				a = x;
			else
				b = x;
		}
	}
	while(fabs(b-a) > precision);

	return x;
}

float newton(int method, float b, float y, float precision){
	float x;

	if(method == 1){
		x = function1(b, y);

		do{
			float delta = function1(x, y) / 
		}

	}
}

int code() {

	float a = returnInputFloat("Enter a: ");
	float b = returnInputFloat("Enter b: ");
	float y = returnInputFloat("Enter y: ");
	int eps = returnEps();
	float precision = returnPrecision(eps);



	// choose equation

	// choose method
	
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


