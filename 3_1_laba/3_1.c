#include <stdio.h>
#include <conio.h>
#include <math.h>

char symbol, exitchar;
float x, root, y=1.06, d, delt=1.0, eps, h;
int j, k, r;
	enter_number_x()
{
do
{	symbol=0;

	printf ("\nEnter 'x'\n\n");
	scanf ("%f%c", &x, &symbol);
	if(symbol!='\n')
	{
		printf ("\nERROR (Enter only numbers)\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j!=1);
}

	enter_number_k()
{
do
{	symbol=0;

	printf ("\nEnter 'k'\n\n");
	scanf ("%d%c", &k, &symbol);
	if(symbol!='\n')
	{
		printf ("\nERROR (Enter only numbers)\n\n");
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

	printf ("\nEnter 'eps' from 1 to 45\n\n");
	scanf ("%g%c", &eps, &symbol);
	if(symbol!='\n')
	{
		printf ("\nERROR Enter only numbers\n\n");
		fflush(stdin);
		j=0;	    	 	
	}		
	else (j=1);	
	

	if( (eps<1)||(eps>45) )	
	{
	
		printf ("\nERROR (Enter eps from 1 to 45)\n\n");
		fflush(stdin);
		j=0;
	}
		
}
while (j!=1);
}

	calculate_eps()
{	 
	r = eps;
	eps= 1/(pow(10,eps));
		
}

	calculate_delt()
{
	//h=k-1;
	delt=(x/pow(y,abs(h))-y)/abs(k);
	//delt=d;
}

	calculate_y()
{
	y=y+delt;
}


int main ()
{	
do{
	
	enter_number_x();
	
	enter_number_k();
	
	enter_eps();
	
	calculate_eps();
	
	h=k-1;
		
	do
	{	
		calculate_delt();
		calculate_y();
		
	}
	while (fabs(delt)>=eps );
	
	printf ("\nx=%f\n\n", x);
			
	printf ("k=%d\n\n", k);
		
	printf ("eps=%d\n\n", r);
	
	printf ("new eps = %.*f\n\n", r,eps);
	
	printf ("y=%.*f\n\n",r, y);
	
	printf ("delt=%f\n\n", delt);
	
	printf ("\nEnter y + ENTER to continue\n");
	
	printf ("\nEnter n + ENTER twice to continue\n\n");
	
	exitchar = getchar();
}
while ( (exitchar == 'y')||(exitchar == 'Y') );
}
