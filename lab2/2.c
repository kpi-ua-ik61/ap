#include <stdio.h>
#include <conio.h>
#include <math.h>

float a, b, c, pp, s;

void pperimeter(void)
{
	pp=((a+b+c)/2);
}
void area(void)
{
	s=sqrt(pp*(pp-a)*(pp-b)*(pp-c));
	printf("\nArea = %f\n", s);
}
void perimeter(void)
{
	float p;
	p=pp*2;
	printf("\nPerimeter = %f\n", p);
}
void height(void)
{
	float ha, hb, hc;
	ha=(2*s)/a;
	hb=(2*s)/b;
	hc=(2*s)/c;
	printf("\nHeight a = %f\nHeight b = %f\nHeight c = %f\n", ha, hb, hc);
}
void median(void)
{
	float ma, mb, mc;
	ma=sqrt((2*b*b)+(2*c*c)-(a*a))/2;
	mb=sqrt((2*a*a)+(2*c*c)-(b*b))/2;
	mc=sqrt((2*a*a)+(2*b*b)-(c*c))/2;
	printf("\nMedian a = %f\nMedian b = %f\nMedian c = %f\n", ma, mb, mc);
}
void bisector(void)
{
	float ba, bb, bc;
	ba=(sqrt(b*c*pp*(pp-a))*2)/(b+c);
	bb=(sqrt(a*c*pp*(pp-b))*2)/(a+c);
	bc=(sqrt(a*b*pp*(pp-c))*2)/(a+b);
	printf("\nBisector a = %f\nBisector b = %f\nBisector c = %f\n", ba, bb, bc);
}
int main(void)
{
	char x;
	
	printf("Enter sides.\n");
	printf("Results will be rounded to six decimal places.\n");

	printf("\nSide a = ");
	scanf("%f%c", &a, &x);
	if ((x!='\n')||(a<=0))
	{
		printf("Enter only positive numbers.\n");
		getch();
		return 0;
	}
	
	printf("Side b = ");
	scanf("%f%c", &b, &x);
	if ((x!='\n')||(b<=0))
	{
		printf("Enter only positive numbers.\n");
		getch();
		return 0;
	}

	printf("Side c = ");
	scanf("%f%c", &c, &x);
	if ((x!='\n')||(c<=0))
	{
		printf("Enter only positive numbers.\n");
		getch();
		return 0;
	}

	if ((a+b<=c)||(a+c<=b)||(b+c<=a))
	{
		printf("This triangle doesn\'t exist\n");
		getch();
		return 0;
	}
	
	pperimeter();
	area();
	perimeter();
	height();
	median();
	bisector();
	getch();

	return 0;
}