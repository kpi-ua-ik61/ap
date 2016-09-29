#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float x, y, yk, d;
int k, j;

void exponent (void)
{
	int ke;
	ke=abs(k);
	yk=y;
	while (ke>2)
	{
		yk=yk*y;
		ke=ke-1;
	}
}
void root (void)
{
	int kr;
	kr=abs(k);
	d=(1.0/kr)*((x/yk)-y);
	y=y+d;
}

int calculations (void)
{
	int eo;
	float e;
	char c;

	printf("\nEnter number, root and accuracy.\n");
	printf("Result will be rounded to entered accuracy.\n");

	do
	{
		printf("\nEnter number\n");
		if ((scanf("%f%c", &x, &c)!=2)||(c!='\n'))
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
		printf("\nEnter root\n");
		if ((scanf("%d%c", &k, &c)!= 2)||(c!='\n')||(k==0))
		{
			printf("Enter only positive and negative integer numbers.\n");
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

	y=1;

	if ((k==1)&&(x==0)) {y=0;}
	if ((k==1)&&(x!=0)) {y=x;}
	if ((k==-1)&&(x==0)) 
	{
		printf("This root doesn\'t exist.\n");
		return 0;
	}
	if ((k==-1)&&(x!=0)) {y=1/x;}
	if ((k>1)&&(k%2==0)&&(x<0))
	{
		printf("This root doesn\'t exist.\n"); 
		return 0;
	}
	if ((k>1)&&(k%2==0)&&(x==0)) {y=0;}
	if ((k>1)&&(k%2==0)&&(x>0))
	{
		do
		{
			exponent();
			root();
		}
		while (fabs(d)>=e);
	}
	if ((k>1)&&(k%2==1)&&(x==0)) {y=0;}
	if ((k>1)&&(k%2==1)&&(x!=0))
	{
		do
		{
			exponent();
			root();
		}
		while (fabs(d)>=e);
	}
	if ((k<-1)&&(abs(k)%2==0)&&(x<=0))
	{
		printf("This root doesn\'t exist.\n"); 
		return 0;
	}
	if ((k<-1)&&(abs(k)%2==0)&&(x>0))
	{
		do
		{
			exponent();
			root();
		}
		while (fabs(d)>=e);
		y=(1/y);
	}
	if ((k<-1)&&(abs(k)%2==1)&&(x==0))
	{
		printf("This root doesn\'t exist.\n"); 
		return 0;
	}
	if ((k<-1)&&(abs(k)%2==1)&&(x!=0))
	{
		do
		{
			exponent();
			root();
		}
		while (fabs(d)>=e);
		y=(1/y);
	}
	
	printf("\nYour result - %.*f\n", eo, y);
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