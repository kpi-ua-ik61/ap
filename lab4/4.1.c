#include <stdio.h>
#include <conio.h>
#include <math.h>

float x, xz, x1, x2, dx, e, r, d, n;
int eo, j, k, y;

void choosing (void)
{
	char temp;
	int te;

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
}

void enter (void)
{
	char c;

	printf("\nChoose a function and enter beginning and ending of a range, step and accuracy.\n");
	printf("Note: if an ending is smaller than a beginning, enter negative step.\n");
	printf("Results will be rounded to six decimal places.\n");

	choosing();

	do
	{
		printf("\nEnter beginning of a range\n");
		if ((scanf("%f%c", &x1, &c)!=2)||(c!='\n')||(x1>3.4e38)||(x1<(-3.4e38)))
		{
			printf("Enter only numbers from -3.4e38 to 3.4e38.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
	
	do
	{
		printf("\nEnter ending of a range\n");
		if ((scanf("%f%c", &x2, &c)!=2)||(c!='\n')||(x2>3.4e38)||(x2<(-3.4e38)))
		{
			printf("Enter only numbers from -3.4e38 to 3.4e38.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
		if (x2==x1)
		{
			printf("Beginning and ending of a range must be different.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	do
	{
		printf("\nEnter step\n");
		if ((scanf("%f%c", &dx, &c)!=2)||(c!='\n')||(dx==0)||(dx>3.4e38)||(dx<(-3.4e38)))
		{
			printf("Enter only numbers from -3.4e38 to 3.4e38 without 0.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
		if ((x2>x1)&&(dx<0))
		{
			printf("Ending of a range is bigger than a beginning. Enter only positive numbers.\n");
			fflush(stdin);
			j=0;
		}
		if ((x2<x1)&&(dx>0))
		{
			printf("Ending of a range is smaller than a beginning. Enter only negative numbers.\n");
			fflush(stdin);
			j=0;
		}
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

	switch(eo)
	{
		case 0: e=1; break;
		case 1: e=0.1; break;
		case 2: e=0.01; break;
		case 3: e=0.001; break;
		case 4: e=0.0001; break;
		case 5: e=0.00001; break;
		case 6: e=0.000001; break;
	}
}

void showbs (void)
{
	printf("This is your result:\n");
	printf("  _______________________________________\n");
	printf("||    x    | T. sin  | S. sin  ||S. - T.|||\n");
	printf("||---------|---------|---------|---------||\n");
}

void showes (void)
{
	printf("||_______________________________________||\n");
	printf("x - your angle\n");
	printf("T. sin - sinus, calculated using Tailor\'s method\n");
	printf("S. sin - sinus, calculated using standart method\n");
	printf("|S. - T.| - difference between S. sin and T. sin\n");
}

void showbc (void)
{
	printf("This is your result:\n");
	printf("  _______________________________________\n");
	printf("||    x    | T. cos  | S. cos  ||S. - T.|||\n");
	printf("||---------|---------|---------|---------||\n");
}

void showec (void)
{
	printf("||_______________________________________||\n");
	printf("x - your angle\n");
	printf("T. cos - cosinus, calculated using Tailor\'s method\n");
	printf("S. cos - cosinus, calculated using standart method\n");
	printf("|S. - T.| - difference between S. cos and T. cos\n");
}

void sinus (void)
{
	float sx, sinx;
	r=x*M_PI/180;
	sx=r;
	d=r;
	n=1;
	do
	{
		d=d*(-r*r)/((n+1)*(n+2));
		sx=sx+d;
		n=n+2;
	}
	while (fabs(d)>=e);
	sinx=sin(r);
	printf("||%9g", xz);
	printf("|%9.*f", eo, sx);
	printf("|%9f", sinx);
	printf("|%9f||\n", fabs(sinx-sx));
	xz=xz+dx;
	y=xz/360;
	if ((xz>360)||(xz<-360)) {x=xz-360*y;}
	else {x=xz;}
}

void cosinus (void)
{
	float cx, cosx;
	r=x*M_PI/180;
	cx=1;
	d=1;
	n=1;
	do
	{
		d=d*(-r*r)/(2*n*(2*n-1));
		cx=cx+d;
		n=n+1;
	}
	while (fabs(d)>=e);
	cosx=cos(r);
	printf("||%9g", xz);
	printf("|%9.*f", eo, cx);
	printf("|%9f", cosx);
	printf("|%9f||\n", fabs(cosx-cx));
	xz=xz+dx;
	y=xz/360;
	if ((xz>360)||(xz<-360)) {x=xz-360*y;}
	else {x=xz;}
}

void calculations (void)
{
	enter();
	xz=x1;
	y=xz/360;
	if ((xz>360)||(xz<-360)) {x=xz-360*y;}
	else {x=xz;}
	if (k==1)
	{
		showbs();
		if (x2>x1)
		{
			do {sinus();}
			while (xz<=x2);
		}
		if (x2<x1)
		{
			do {sinus();}
			while (xz>=x2);
		}
		showes();
	}
	if (k==(-1))
	{
		showbc();
		if (x2>x1)
		{
			do {cosinus();}
			while (xz<=x2);
		}
		if (x2<x1)
		{
			do {cosinus();}
			while (xz>=x2);
		}
		showec();
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