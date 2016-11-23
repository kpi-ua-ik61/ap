#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

char symbol, exitchar;
float x1, x2, x3, z1, z2, z3, a, b, c, p, q, d, y2, y22, y3, y33;
int j;

	enter_number_a()
{
do
{	symbol=0;
	printf ("Enter 'a' from -100 to 100\n\n");
	scanf ("%f%c", &a, &symbol);
	if( (symbol!='\n')||(a<-100)||(a>100) )
	{
		printf ("\nERROR (Enter only numbers from -100 to 100)\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j==0);
}

	enter_number_b()
{
do
{	symbol=0;
	printf ("\nEnter 'b' from -100 to 100\n\n");
	scanf ("%f%c", &b, &symbol);
	if( (symbol!='\n')||(b<-100)||(b>100) )
	{
		printf ("\nERROR (Enter only numbers from -100 to 100)\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j==0);
}

	enter_number_c()
{
do
{	symbol=0;
	printf ("\nEnter 'c' from -100 to 100\n\n");
	scanf ("%f%c", &c, &symbol);
	if( (symbol!='\n')||(c<-100)||(c>100) )
	{
		printf ("\nERROR (Enter only numbers from -100 to 100)\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j==0);
}

	calculating_p()	//OK
{
	p=(3*b-a*a)/3;	
}

	calculating_q()	//OK
{
	q=(2*a*a*a-9*a*b+27*c)/27;
}

	calculating_d()	//OK
{
	d=(p*p*p)/27 + (q*q)/4;
	printf("d=%f\n\n", &d);	
}

	if_d_more_0()
{	
	if( d>0 )
	{	
		float u, v;
		printf("d>0\n\n");
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
	}

}

	if_d_ecual_0()
{
	if( d==0 )
	{	
		printf("d=0\n\n");
		z1=3*q/p;
		z2=-(3*q)/(2*p);
		z3=z2;		
		x1=z1-(a/3);
		x2=z2-(a/3);
		x3=z3-(a/3);
	}
}

	if_d_under_0()
{
	if( d<0 )
	{
		float r, f;
		printf("d<0\n\n");
		r=sqrtf((-p*p*p)/27);
		f=acos(-q/(2*r));
		z1=2*fabs(cbrtf(r))*cos(f/3);
		z2=2*fabs(cbrtf(r))*cos((f+2*M_PI)/3);
		z3=2*fabs(cbrtf(r))*cos((f+4*M_PI)/3);		
		x1=z1-(a/3);
		x2=z2-(a/3);
		x3=z3-(a/3);
	}
}

	chek_a_b_c_0()
{
	if ((a==0)&&(b==0)&&(c==0))
	{
		x1=0;
		x2=0;
		x3=0;
		y2=0;
		y3=0;
	} 

}
		
	chek_a_b_c_1()
{
	if ( (b==((a*a)/3)) && (c==((a*a*a)/27)) )
	{
		x1=-1*(a/3);
		x2=0;
		x3=0;
		y2=0;
		y3=0;
		printf("fferfe\n\n");
	} 
}

	calculation()
{		
	enter_number_a();	
	enter_number_b();		
	enter_number_c();						
	printf ("\nInput: x^3+%f*x^2+%f*x+%f=0\n\n", a, b, c);	
	calculating_p();		
	calculating_q();		
	calculating_d();		
	if_d_more_0();		
	if_d_ecual_0();		
	if_d_under_0();		
	chek_a_b_c_0();		
	chek_a_b_c_1();	
	printf ("x1=%.4f\n\n", x1);			
	printf ("x2=%.4f-i*(%.4f)\n\n", x2,y2);		
	printf ("x3=%.4f+i*(%.4f)\n\n", x3,y3);
}

int main ()
{
	do 
	{
		system("cls");		
		printf ("\nSolve x^3+a*x^2+b*x+c=0\n\n");		
		printf ("Results will be rounded to 4 decimal places.\n\n");		
		calculation();	
		
		printf ("Enter y to continue\n");		
		exitchar = getchar();		
	}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}

