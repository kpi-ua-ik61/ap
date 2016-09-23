#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float x, y, yk, d;
int k;

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

int main (void)
{
	int eo;
	float e;
	char c;

	printf("Enter number\n");
	scanf("%f%c", &x, &c);
	if (c!='\n')
	{
		printf("Enter only numbers.\n");
		getch();
		return 0;
	}

	printf("Enter root\n");
	scanf("%d%c", &k, &c);
	if ((c!='\n')||(k==0))
	{
		printf("Enter only positive and negative numbers.\n");
		getch();
		return 0;
	}

	printf("Enter accuracy from 1 to 6.\n");
	scanf("%d%c", &eo, &c);
	if (eo==1) {e=0.1;}
	if (eo==2) {e=0.01;}
	if (eo==3) {e=0.001;}
	if (eo==4) {e=0.0001;}
	if (eo==5) {e=0.00001;}
	if (eo==6) {e=0.000001;}
	if ((eo!=1)&&(eo!=2)&&(eo!=3)&&(eo!=4)&&(eo!=5)&&(eo!=6)) 
	{
		printf("Enter only numbers from 1 to 6.\n");
		getch();
		return 0;
	}
	if ((c!='\n')||(eo==0))
	{
		printf("Enter only numbers from 1 to 6.\n");
		getch();
		return 0;
	}

	y=1;
	if ((k==1)&&(x==0)) {y=0;}
	if ((k==1)&&(x!=0)) {y=x;}
	if ((k==-1)&&(x==0)) 
	{
		printf("This root doesn\'t exist.\n"); 
		getch();
		return 0;
	}
	if ((k==-1)&&(x!=0)) {y=1/x;}
	if ((k>1)&&(k%2==0)&&(x<0))
	{
		printf("This root doesn\'t exist.\n"); 
		getch();
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
		getch();
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
		getch();
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
	
	printf("Your result - %f\n", y);
	getch();

	return 0;
}