#include <stdio.h>
#include <conio.h>
#include <math.h>

char term;

float a;
float b;
float c;

float s;

float p;
float pp;

void perimetr() {
	p = a+b+c;
	pp = p/2;
	printf("Perimetr: %f units\n\n", p);
}

void area() {
	s = sqrt(pp*(pp-a)*(pp-b)*(pp-c));
	printf("Area: %f sq.units\n\n", s);
}

void height() {
	float ha = 2*s/a;
	float hb = 2*s/b;
	float hc = 2*s/c;
	printf("Height to the side\n -a: %f units\n -b: %f units\n -c: %f units\n\n", ha, hb, hc);
}

void median() {
	float ma = 0.5*sqrt(2*b*b+2*c*c-a*a);
	float mb = 0.5*sqrt(2*a*a+2*c*c-b*b);
	float mc = 0.5*sqrt(2*b*b+2*a*a-c*c);
	printf("Median to the side\n -a: %f units\n -b: %f units\n -c: %f units\n\n", ma, mb, mc);
}

void bisector() {
	float bisa = 2 * sqrt(b*c*pp*(pp-a))/(b+c);
	float bisb = 2 * sqrt(a*c*pp*(pp-b))/(a+c);
	float bisc = 2 * sqrt(b*a*pp*(pp-c))/(b+a);
	printf("Bisector to the side\n -a: %f units\n -b: %f units\n -c: %f units\n\n", bisa, bisb, bisc);
}

main() {
	printf("Enter a: ");
	if(scanf("%f%c", &a, &term) != 2 || term != '\n'){         // перевірка введених даних через return scanf
	    printf("Input error!\n");
	    return 0;
	}

	printf("Enter b: ");
	if(scanf("%f%c", &b, &term) != 2 || term != '\n'){
	    printf("Input error!\n");
	    return 0;
	}

	printf("Enter c: ");
	if(scanf("%f%c", &c, &term) != 2 || term != '\n'){
	    printf("Input error!\n");
	    return 0;
	}

	printf("\n");

	if(!(a+b > c && b+c > a && a+c > b)){                                            // перевірка чи існує такий трикутник
		printf("Such triangle does not exist!\n");
		
		return 0;
	}

	perimetr();

	area();

	height();

	median();

	bisector();

	getch();

}