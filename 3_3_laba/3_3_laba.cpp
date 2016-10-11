#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

char symbol, exitchar;
float a, b, c, p, q, d, u, v, ut, j, phi, pi=3.14159265359, r;
float yo, yt, yth, ytt, ythth, xo, xt, xth;


	enter_number_a()
{
do
{	symbol=0;

	printf ("Enter 'a'\n\n");
	scanf ("%f%c", &a, &symbol);
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


	enter_number_b()
{
do
{	symbol=0;

	printf ("\nEnter 'b'\n\n");
	scanf ("%f%c", &b, &symbol);
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

	enter_number_c()
{
do
{	symbol=0;

	printf ("\nEnter 'c'\n\n");
	scanf ("%f%c", &c, &symbol);
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

	calculating_p()	//OK
{
	p=(3*b-a*a)/3;
//	p=b-(a*a/3);	
}

	calculating_q()	//OK
{
	q=(2*a*a*a-9*a*b+27*c)/27;
	//q=( (2*a*a*a)/27)-(a*b)/3+c ;
}

	calculating_d()	//OK
{
	d=(p*p*p)/27 + (q*q)/4;
}

	if_d_more_0()
{	
	if( d>0 )
	{
		ut=-1*q/2+sqrt(d);	//OK
		
		(ut>0) ? u=cbrt(ut) : (u=cbrt (fabs(ut)))*-1;	//OK
		
		v=cbrt( (-q/2)-sqrt( (q*q/4)+(p*p*p/27) ) );	//OK
				
		yo= (u+v); ;
		yt= -1*(u+v)/2 ;
		ytt= sqrt(3)*(u-v)/2 ;
		yth= -1*(u+v)/2;
		ythth= -1*sqrt(3)*(u-v)/2;	
		
		xo=yo-(a/3);
		xt=yt-(a/3);
		xth=yth-(a/3);
	}

}

	if_d_ecual_0()
{
	if( d==0 )
	{
		yo=2*cbrt(-q/2);
		yt=-1*cbrt(-q/2);
		ytt=0;
		yth=-1*cbrt(-q/2);
		ythth=0;
		
		xo=yo-(a/3);
		xt=yt-(a/3);
		xth=yth-(a/3);
	}
}

	if_d_under_0()
{
	if( d<0 )
	{
		r=sqrt(-1*p*p*p/27);
		
		phi=acos(-1*q/2*r);
		
		yo=2*fabs(cbrt(r))*cos(phi/3);
		yt=2*fabs(cbrt(r))*cos(phi+2*pi/3);
		yt=0;
		yth=2*fabs(cbrt(r))*cos(phi+4*pi/3);
		ythth=0;
		
		xo=yo-(a/3);
		xt=yt-(a/3);
		xth=yth-(a/3);
	}
}
	


int main ()
{
	do 
	{
		system("cls");
		
		printf ("\nSolve x^3+a*x^2+b*x+c=0\n\n");
			
		enter_number_a();
		
		enter_number_b();
		
		enter_number_c();
		
		printf ("\nInput: x^3+%.1f*x^2+%.1f*x+%.1f=0\n\n", a, b, c);	
		
		calculating_p();
		
		calculating_q();
		
		calculating_d();		
		
		if_d_more_0();
		
		if_d_ecual_0();
		
		if_d_under_0();
		
		printf ("\np=%.4f\n\n", p);
			
		printf ("q=%.4f\n\n", q);
		
		printf ("d=%.4f\n\n", d);
		
		printf ("u=%.4f\n\n", u);
		
		printf ("y1=%.4f\n\n", yo);
		
		printf ("y2=%.4f+i*(%.4f)\n\n", yt,ytt);
		
		printf ("y3=%.4f-i*(%.4f)\n\n", yth,ythth);
		
		printf ("v=%.4f\n\n", v);
		
		printf ("\nut=%.4f\n\n", ut);
		
		printf ("x1=%.4f\n\n", xo);
			
		printf ("x2=%.4f+i*(%.4f)\n\n", xt,ytt);
		
		printf ("x3=%.4f+i*(%.4f)\n\n", xth,ythth);
		
		printf ("\nEnter y to continue\n");
		
		exitchar = getchar();
		
	}
	while ( (exitchar == 'y')||(exitchar == 'Y') );
	 
	return 0;
}

