//Lab3,1_v2.c Updated logic
#include <curses.h> // the curse of Linuxoid
#include <stdio.h> // standart lib
#include <math.h> //  "I've got the POWaaar!!" 
#include <stdlib.h> // still exit
#include <string.h>

void error(char* errorMsg) // Error printer at the end of the proga 
{
	printf("\nERROR\n %s \nClosing program\n ", errorMsg);
	exit(0);
}

void calculations(){
	int i, g, err, a, b, c;
	double x, y, k, T, yi, E;

	printf("Enter your number X that you wish to check: "); //Собственно процесс проверки
	a = scanf("%lf", &x);
	if (x == 0){
		error("Your number X cannot be 0");
	}
	printf("Enter your power of roots K: ");
	b = scanf("%lf", &k);
	if (k == 0){
		error("Your root K, cannot be 0");
	}
	printf("Enter how many numbers after koma, that you wish to see \nThis program can support accuracy of calculations from 1 to 15 numbers after coma \nThat means that you must choose wisely\n\nYou can enter something like this:\n1e-5 which means 5 nums after koma\n0.00001 alternative to 1e-5\n");
	c = scanf("%lf", &E);
	if((1 > c) && (c > 15)){
		error("Double only have 15 nums after koma, so enter integers from 1 to 15");
	}
	if ((a != 1) && (b != 1) && (c != 1)){
		error("Something went wrong, looks like symbols in input buffer");
	}
	g = k;
	if (((g < 0) && (g%2 == 0) && (x < 0)) || ((g > 0) && (g%2 == 0) && (x < 0))){
		error("When your root is an even number\n your number X cannot be lesser than 0");
	}

	int N = 0;
	double M = E;
	while (M < 1){
		M = M*10;
		N++;
	}
	y = 1;
	T = 1;
		if ((k == 1) || (x == 0)){
			y = x;
			printf("\n Answer => %.*lf\n", N, y);
		}
	if (k < 0){
		k = -k;
		x = 1/x;
	}
	while (T > E){
		yi = y;
		for (i = 0; i < (k - 2); i++){
			yi = y * yi;
		}
		T = (1 / k) * ((x / yi) -y);
		y = y + T;
		if (T < 0){
			T = -T;
		}
	}
	printf("\nAnswer is: %.*lf\n", N, y);
	exit (0);

}
int main()
{
	calculations();
}	