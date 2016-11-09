#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float x, y, yk, d;
int k, j;

	 exponent ()
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

	 calculate_d ()
{
	int kr;
	kr=abs(k);
	d=(1.0/kr)*((x/yk)-y);
	y=y+d;
}

	 calculations ()
{
	int eo;//tochnost'
	float e;//tochnost' 0.0001
	char c;//simvol

	printf("\nSolve x^(1/k)\n");
	printf("\nResult will be rounded to entered accuracy\n");

	do
	{
		printf("\nEnter 'x' from -100 to 100\n");
		if ( (scanf("%f%c", &x, &c)!=2)||(c!='\n')||(x<-100)||(x>100) )
		{
			printf("Enter only numbers from -10 to 10\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	do
	{
		printf("\nEnter 'k'\n");
		if ( (scanf("%d%c", &k, &c)!= 2)||(c!='\n')||(k==0)||(k<-100)||(k>100) )
		{
			printf("Enter only integer numbers from -100 to 100\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	do
	{
		printf("\nEnter integer 'epsilon' from 0 to 6\n");
		if ( (scanf("%d%c", &eo, &c)!= 2)||(c!='\n')||((eo!=0)&&(eo!=1)&&(eo!=2)&&(eo!=3)&&(eo!=4)&&(eo!=5)&&(eo!=6)) )
		{
			printf("Enter only integer numbers from 0 to 6\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}	
	while (j!=1);

	printf("\nYou have entered %f^(1/^%d)\n", x, k);
	
	if (eo==0) {e=1;}
	if (eo==1) {e=0.1;}
	if (eo==2) {e=0.01;}
	if (eo==3) {e=0.001;}
	if (eo==4) {e=0.0001;}
	if (eo==5) {e=0.00001;}
	if (eo==6) {e=0.000001;}

	y=1;
	
	if ( (k==1)&&(x==0) ) {y=0;}
	if ( (k==1)&&(x!=0) ) {y=x;}
	if ( (k==-1)&&(x==0) ) 
	{
		printf("\nThis calculate_d doesn\'t exist. (endless)\n");
		return 0;
	}
	if ( (k==-1)&&(x!=0) ) {y=1/x;}
	if ( (k>1)&&(k%2==0)&&(x<0) )
	{
		printf("\nThis root doesn\'t exist. ((evenx)^(-k))\n"); 
		return 0;
	}
	if ( (k>1)&&(k%2==0)&&(x==0) ) {y=0;}
	if ( (k>1)&&(k%2==0)&&(x>0) )
	{
		do
		{
			exponent();
			calculate_d();
		}
		while (fabs(d)>=e);
	}
	if ( (k>1)&&(k%2==1)&&(x==0) ) {y=0;}
	if ( (k>1)&&(k%2==1)&&(x!=0) )
	{
		do
		{
			exponent();
			calculate_d();
		}
		while (fabs(d)>=e);
	}
	if ( (k<-1)&&(abs(k)%2==0)&&(x<=0) )
	{
		printf("\nThis root doesn\'t exist. (1/((evenx)^-k))\n"); 
		return 0;
	}
	if ( (k<-1)&&(abs(k)%2==0)&&(x>0) )
	{
		do
		{
			exponent();
			calculate_d();
		}
		while (fabs(d)>=e);
		y=(1/y);
	}
	if ( (k<-1)&&(abs(k)%2==1)&&(x==0) )
	{
		printf("\nThis root doesn\'t exist. (endless)\n"); 
		return 0;
	}
	if ( (k<-1)&&(abs(k)%2==1)&&(x!=0) )
	{
		do
		{
			exponent();
			calculate_d();
		}
		while (fabs(d)>=e);
		y=(1/y);
	}
	
	printf("\nYour result - %.*f\n", eo, y);
}

	 main()
{
	char tmp;//getch
	int t, i;
	do
	{
		system("cls");
		calculations();
		
		do
		{	
			i=0;
			printf("\nDo you want to try again?\n");
			tmp=getch();
			t=tmp;
			if (t==13)  {i=1;}
			if (t==27)  {i=(-1);}
			if ( (i!=(-1))&&(i!=1) )
			{
				printf("\nEnter Enter or Esc\n");
				fflush(stdin);
				j=0;
			}
			else (j=1);
		}
		while (j==0);
	}
	while (i!=(-1));

	return 0;
}
