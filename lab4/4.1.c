#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float x, x1, x2, dx, e, r;
int eo, j;

/*void function (void)
{
	char temp;
	int te, k;
		
	do
	{
		k=0;
		printf("\nChoose a funtion [S/C] (S for sin and C for cos)\n");
		temp=getch();
		te=temp;
		if ((te==115)||(te==83)) {k=1;}
		if ((te==99)||(te==67)) {k=(-1);}
		if ((k!=(-1))&&(k!=1))
		{
			printf("Enter S (sin) or C (cos).\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
}*/

void enter (void)
{
	char c;

	printf("\nChhose a function and enter beginning and ending of a range, step and accuracy.\n");
	printf("Results will be rounded to six decimal places.\n");

	do
	{
		printf("\nEnter beginning of a range\n");
		if ((scanf("%f%c", &x1, &c)!=2)||(c!='\n'))
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
		printf("\nEnter ending of a range\n");
		if ((scanf("%f%c", &x2, &c)!=2)||(c!='\n'))
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
		printf("\nEnter step\n");
		if ((scanf("%f%c", &dx, &c)!=2)||(c!='\n'))
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
		printf("\nEnter accuracy from 0 to 6.\n");
		if ((scanf("%d%c", &eo, &c)!= 2)||(c!='\n')||((eo!=0)&&(eo!=1)&&(eo!=2)&&(eo!=3)&&(eo!=4)&&(eo!=5)&&(eo!=6)))
		{
			printf("Enter only numbers from 0 to 6.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	if (eo==0) {e=1;}
	if (eo==1) {e=0.1;}
	if (eo==2) {e=0.01;}
	if (eo==3) {e=0.001;}
	if (eo==4) {e=0.0001;}
	if (eo==5) {e=0.00001;}
	if (eo==6) {e=0.000001;}
}

void sinus (void)
{
	float sx, ds, ns;
	x=x1;
	sx=1;
	ds=1;
	ns=1;
	do
	{
		do
		{
			r=(x*M_PI)/180;
			ds=ds*(-(r*r))/((ns+1)*(ns+2));
			sx=sx+ds;
			ns=ns+2;
			printf("%f\n", sx);
			x=x+dx;
		}
		while (fabs(ds)>=e);
	}
	while (x<x2);
	//printf("%f\n", sx);

}

void calculations (void)
{
	enter();
	sinus();
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