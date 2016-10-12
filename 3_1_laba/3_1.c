#include <stdio.h>
#include <conio.h>
#include <math.h>

char symbol, exitchar;
float x, root, y=1.0, delt=1.0, eps, h;
int j, k, r;

	enter_number_x()
{
do
{	symbol=0;
	printf ("\nEnter 'x'\n\n");
	scanf ("%f%c", &x, &symbol);
	if(symbol!='\n')
	{
		printf ("\nERROR Enter only numbers\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j!=1);
}

	enter_root_k()
{
do
{	symbol=0;

	printf ("\nEnter 'k'\n\n");
	scanf ("%d%c", &k, &symbol);
	if(symbol!='\n')
	{
		printf ("\nERROR Enter only integer numbers\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j!=1);
}

	enter_eps()
{
do
{	symbol=0;

	printf ("\nEnter precision to solve from 1 to 8\n\n");
	scanf ("%f%c", &eps, &symbol);
	if( (symbol!='\n')||(eps<1)||(eps>8) )
	{
		printf ("\nERROR Enter only integer numbers from 1 to 8\n\n");
		fflush(stdin);
		j=0;	    	 	
	}		
	else (j=1);	
}
while (j!=1);
}

	calculation()
{
	{	 
		r = eps;
		eps = 1/(pow(10,eps));
	}
	if ( k==0 ) 
	{	
		printf("\nThis root doesn\'t exist. (root=1/0)\n");
		return 0;
	}
	if ( (k!=-1)&&(x==0) ) {y=0;}
	if ( (k==1)&&(x!=0) ) {y=x;}	
	if ( (k==-1)&&(x==0) ) 
	{
		printf("This root doesn\'t exist. (y=1/0)\n");
		return 0;
	}	
	if ( (k==-1)&&(x!=0) ) {y=1/x;}		
	if ( (k>1)&&(k%2==0)&&(x<0) )
	{
		printf("This root doesn\'t exist. (y=i)\n"); 
		return 0;
	}	
	if ( (k>1)&&(k%2==0)&&(x>0) )
	{
		do
		{	h=k-1;
			delt=(x/pow(y,abs(h))-y)/abs(k);
			y=y+delt;
		}
		while (fabs(delt)>=eps);
	}
	if ( (k>1)&&(k%2==1) )
	{
		do
		{	h=k-1;
			delt=(x/pow(y,abs(h))-y)/abs(k);
			y=y+delt;
		}
		while (fabs(delt)>=eps);
	}	
	if ( (k<-1)&&(abs(k)%2==1)&&(x==0) )
	{
		printf("This root doesn\'t exist. (y=1/0)\n"); 
		return 0;
	}	
	if ( (k<-1)&&(abs(k)%2==0)&&(x>0) )
	{
		do
		{	h=1-k;
			delt=((x*pow(y,h))-y)/k;
			y=y+delt;
		}
		while (fabs(delt)>=eps);
	}
	if ((k<-1)&&(abs(k)%2==1)&&(x==0))
	{
		printf("This root doesn\'t exist. (y=1/0)\n"); 
		return 0;
	}
	if ((k<-1)&&(abs(k)%2==1)&&(x!=0))
	{
			do
		{	h=1-k;
			delt=((x*pow(y,h))-y)/k;
			y=y+delt;
		}
		while (fabs(delt)>=eps);
	}
	printf ("\ny=%.*f\n",r, y);
}

int main ()
{	
do{
	system("cls");	
	printf ("Solve y=x^(1/k)\n");
	enter_number_x();	
	enter_root_k();	
	enter_eps();	
	calculation();		
	printf ("\nEnter y + ENTER to continue\n");	
	printf ("\nEnter n + ENTER twice to continue\n\n");	
	exitchar = getchar();
}
while ( (exitchar == 'y')||(exitchar == 'Y') );
}
