#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

float y = 0.0;
int fun = 0;
int meth = 0;

float function1(float x){
	return (cos(y/x) - 2*sin(1/x) + 1/x);
}

float function2(float x){
	return (sin(log(x)) - cos(log(x)) + y*log(x));
}

float derivative1(float x){
	float e = 0.0001;

	return ((function1(x+e)-function1(x))/e);
}

float derivative2(float x){
	float e = 0.0001;

	return ((function2(x+e)-function2(x))/e);
}

float half(float a, float b, float precision){
	float x;
	do{
		x = (a + b) / 2;
		if(fun == 1){
			if(function1(a)*function1(x) > 0)
				a = x;
			else
				b = x;
		}
		else{
			if(function2(a)*function2(x) > 0)
				a = x;
			else
				b = x;
		}
	}
	while(fabs(b-a) > precision);

	return x;
}

float newton(float b, float precision){
	float x;
	float delta = 0.0;

	if(fun == 1){
		x = function1(b);

		do{
			delta = function1(x) / derivative1(x);
			x -= delta;
		}
		while(fabs(delta) > precision);

	}
	else{
		x = function2(b);

		do{
			delta = function2(x) / derivative2(x);
			x -= delta;
		}
		while(fabs(delta) > precision);

	}

	return x;
}

int code() {

	float a = returnInputFloat("Enter a: ");
	float b = returnInputFloat("Enter b: ");
	y = returnInputFloat("Enter y: ");
	int eps = returnEps();
	float precision = returnPrecision(eps);

	// choose equation
	printf("\n");

	printf("        y       1   1             \n");
	printf("[1]  cos- - 2sin- - - = 0, x [a,b]\n");
	printf("        x       x                 \n\n");\

	printf("[2]  sin(ln x) - cos(ln x) + yln x = 0, x [a,b]\n\n");

	printf("Choose an equation [1/2] or press any other key to exit: ");
	fun = getch();  printf("%c\n\n\n", (char)fun);
	if(fun == 49) fun = 1;
	else if (fun == 50) fun = 2;
	else return 0;


	char again;
	// choose method

	printf("[1] Method of half division\n");
	printf("[2] Newton's method\n");
	printf("Choose a method [1/2] or press any other key to exit: ");
	meth = getch();  printf("%c\n\n", (char)meth);

	if(meth == 49) meth = 1;
	else if (meth == 50) meth = 2;
	else return 0;

	if(meth == 1) {
		printf("Answer: %f\n", half(a, b, precision));
	}
	else if(meth == 2){
		printf("Answer: %f\n", newton(b, precision));
	}

	printf("\n");
	printf("Calculate with other method? [y/n]: ");
	again = getch();  printf("%c\n\n", (char)again);
	if( again == 'y' || again == 'Y' ){
		if(meth == 1) {
			meth = 2;
			printf("Answer: %f\n", newton(b, precision));
		}
		else{
			meth = 1;
			printf("Answer: %f\n", half(a, b, precision));
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


