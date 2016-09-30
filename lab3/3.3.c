#include <stdio.h>
#include <conio.h>
#include <math.h>

float x1, x2, x3, z1, z2, z3, a, b, c, p, q, d;
int j;

void calcpqd (void)
{
	p=b-((a*a)/3);
	q=(2*(a*a*a)/27)-((a*b)/3)+c;
	d=((p*p*p)/27)+((q*q)/4);
}

void calc1 (void)
{
	float u, v, y2, y3;
	u=cbrtf((-q/2)+sqrtf(d));
	v=cbrtf((-q/2)-sqrtf(d));
	z1=u+v;
	y2=(sqrt(3)*(u-v))/2;
	z2=-(u+v)/2;
	y3=y2;
	z3=z2;
	x1=z1-(a/3);
	x2=z2-(a/3);
	x3=z3-(a/3);
	printf("\nYour results:\n");
	printf("x1 = %f\n", x1);
	printf("x2 = %f+i*%f\n", x2, y2);
	printf("x3 = %f-i*%f\n", x3, y3);
}

int calc2 (void)
{
	z1=3*q/p;
	z2=-(3*q)/(2*p);
	z3=z2;
	x1=z1-(a/3);
	x2=z2-(a/3);
	x3=z3-(a/3);
	printf("\nYour results:\n");
	printf("x1 = %f\n", x1);
	printf("x2 = %f\n", x2);
	printf("x3 = %f\n", x3);
}

int calc3 (void)
{
	float r, f;
	r=sqrtf((-p*p*p)/27);
	f=acos(-q/(2*r));
	z1=2*fabs(cbrtf(r))*cos(f/3);
	z2=2*fabs(cbrtf(r))*cos((f+2*M_PI)/3);
	z3=2*fabs(cbrtf(r))*cos((f+4*M_PI)/3);
	x1=z1-(a/3);
	x2=z2-(a/3);
	x3=z3-(a/3);
	printf("\nYour results:\n");
	printf("x1 = %f\n", x1);
	printf("x2 = %f\n", x2);
	printf("x3 = %f\n", x3);
}

void calculations (void)
{
	char x;

	printf("\nEnter coefficients.\n");
	printf("Results will be rounded to six decimal places.\n");

	do
	{
		printf("\nCoefficient a = ");
		if ((scanf("%f%c", &a, &x)!=2)||(x!='\n'))
		{
			printf("Enter only numbers.\n");
			fflush(stdin);
			j=0;		
		}
		else (j=1);
	}
	while (j!=1);
	
	do
	{
		printf("Coefficient b = ");
		if ((scanf("%f%c", &b, &x)!=2)||(x!='\n'))
		{
			printf("Enter only numbers.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	do
	{
		printf("Coefficient c = ");
		if ((scanf("%f%c", &c, &x)!=2)||(x!='\n'))
		if (x!='\n')
		{
			printf("Enter only numbers.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	if ((a==0)&&(b==0)&&(c==0))
	{
		x1=0;
		x2=0;
		x3=0;
		printf("\nYour results:\n");
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
		printf("x3 = %f\n", x3);
	}

	if ((b==((a*a)/3))&&(c==((a*a*a)/27)))
	{
		x1=-a/3;
		x2=-a/3;
		x3=-a/3;
		printf("\nYour results:\n");
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
		printf("x3 = %f\n", x3);
	}

	else
	{
		calcpqd();

		if (d>0) 
		{
			calc1();
		}

		if (d==0)
		{
			calc2();
		}

		if (d<0)
		{
			calc3();
		}
	}
}

int main(void)
{
	char tmp;
	int t, i;
	do
	{
		calculations();
		do
		{
			i=0;
			printf("\nDo you want to try again? [Y/N]\n");
			tmp=getch();
			t=tmp;
			if ((t==121)||(t==89)) {i=1;}
			if ((t==110)||(t==78)) {i=(-1);}
			if ((i!=(-1))&&(i!=1))
			{
				printf("Enter Y (Yes) or N (No).\n");
				fflush(stdin);
				j=0;
			}
			else (j=1);
		}
		while (j!=1);
	}
	while (i!=(-1));

	return 0;
}