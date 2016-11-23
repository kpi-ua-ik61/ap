#include <stdio.h>
#include <conio.h>
#include <math.h>

float x, x1, x2, dx, e, r, d, n, z, v, v2, f=0, b=0, step, sinx, sx, cx, cosx ;
int eo, j, k, t;
char exitchar, c;


	choosing_sin_cos ()
{
	char temp;
	float te;
	printf("Choose a funtion cos (1) or sin (2)\n");
	do
	{
		k=0;
		if ( scanf("%f%c", &te, &temp)!=2||(te!=1)&&(te!=2)||(temp!='\n') )
		{
			printf("Enter (1) for cos or(2) for sin\n");
			fflush(stdin);
			j=0;
		}
		else
		{
			t=te;
			switch (t)
				{
					case 1:
						printf("You choosed cos\n");
						k=1;
						j=1;
						break;
					case 2:
						printf("You choosed sin\n");
						k=2;
						j=1;
						break;
				}
		}	
	}	
	while (j==0);
}


	enter_first_angle ()
{	
//	char c;
	do
	{	
		printf("Enter the first angle\n");
		printf("x1=");
		if ( (scanf("%f%c", &x1, &c)!=2)||(c!='\n')||(x1<=-360)||(x1>=360) )
		{
			printf("Enter only numbers from 0 to 360\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
}


	enter_last_angle ()	
{
	do
	{
	//	char c;
		printf("Enter the last angle\n");
		printf("x2=");
		if ((scanf("%f%c", &x2, &c)!=2)||(c!='\n'))
		{
			printf("Enter only numbers.\n");
			fflush(stdin);
			j=0;
		}						
		else if (x2==x1)
		{
			printf("Beginning and ending of a range must be different\n");
			fflush(stdin);
			j=0;
		}	
		else if ((x2<=-360)||(x2>=360))
			{
			printf("Enter only numbers from 0 to 360\n");
			fflush(stdin);
			j=0;
			}
		else (j=1);
	}
	while (j!=1);
}


	enter_step ()
{	
//	char c;
	do
	{	
		printf("Enter step\n");
		if ((scanf("%f%c", &dx, &c)!=2)||(c!='\n')||(dx==0))
		{
			printf("Enter only numbers expect 0\n");
			fflush(stdin);
			j=0;
		}				
		else if ((x2>x1)&&(dx<0))
		{
			printf("The last angle is higher than the first. Enter only positive numbers.\n");
			fflush(stdin);
			j=0;
		}		
		else if ((x2<x1)&&(dx>0))
		{
			printf("The last angle is lower than the first. Enter only negative numbers.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
}
	
	enter_accuracy ()
{
	do
	{
		printf("Enter accuracy from 0 to 6.\n");
		if ((scanf("%d%c", &eo, &c)!= 2)||(c!='\n')||((eo!=0)&&(eo!=1)&&(eo!=2)&&(eo!=3)&&(eo!=4)&&(eo!=5)&&(eo!=6)))
		{
			printf("Enter only ineger numbers from 0 to 6.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
}

	calculate_accuracy ()
{	
	if (eo==0) {e=1;}
	if (eo==1) {e=0.1;}
	if (eo==2) {e=0.01;}
	if (eo==3) {e=0.001;}
	if (eo==4) {e=0.0001;}
	if (eo==5) {e=0.00001;}
	if (eo==6) {e=0.000001;}
}

	showbs ()
{
	printf("This is your result:\n");
	printf("  _________________________________________\n");
	printf("||     x     | T  sin  | D  sin  |  D - T  ||\n");
	printf("||-----------|---------|---------|---------||\n");
}

	showes ()
{
	printf("||_________________________________________||\n");
	printf("x - angle\n");
	printf("T sin - Tailor\'s sinus\n");
	printf("D sin - default sinus\n");
	printf("D - T - difference between D sin and T sin\n");
}

	showbc ()
{
	printf("This is your result:\n");
	printf("  _________________________________________\n");
	printf("||     x     | T  cos  |  D cos  |  D - T  ||\n");
	printf("||-----------|---------|---------|---------||\n");
}

	showec ()
{
	printf("||_________________________________________||\n");
	printf("x - angle\n");
	printf("T cos - Tailor\'s cosinus\n");
	printf("S. cos - dedault cosinus\n");
	printf("D - T - difference between D cos and T cos\n");
}

	print ()
{
	switch (k)
{
		case 2:
			{	
				x=x1;
				if ( (x1<x2)/*^(abs(step)>(abs(x2-x1)))*/ )
					{		
				//		printf ("entered in if ( (x1<x2)^(abs(step)>(abs(x2)-abs(x1))) )\n");		
						showbs ();
						{
						do
						{sinus ();}					
						while (x<=x2);
						x=x2;
						sinus ();
						showes ();	
						}
					}
				else if ( (x1>x2)/*^(abs(step)>(abs(x2-x1)))*/ )
					{	
						showbs ();
						do						
							{sinus ();}					
						while (x>=x2);
						x=x2;
						sinus ();
						showes ();					
					}
			break;
			}			
		case 1:
			{
				x=x1;
				if ( (x1<x2)/*^(abs(step)>(abs(x2-x1)))*/ )
					{	
						printf ("entered in else if ( (x1<x2)^(abs(step)>(abs(x2-x1))) )");			
						showbc ();
						do
							{cosinus ();}					
						while (x<=x2);
						x=x2;
						cosinus ();
						showec ();	
					}
				else if ( (x1>x2)/*^(abs(step)>(abs(x2-x1)))*/ )
					{
						printf ("entered in else if ( (x1>x2)^(abs(step)>(abs(x2-x1))) )");
						showbc ();
						do
							{cosinus ();}					
						while (x>=x2);
						x=x2;
						cosinus ();
						showec ();					
					}
				break;
			}
}
}

	sinus ()
{
//	float sx, sinx;
//	printf ("entered in sinus");
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
	printf("||%11.*f", eo, x);
	printf("|%9.*f", eo, sx);
	printf("|%9.*f", eo, sinx);
	printf("|%9.*f||\n", eo, fabs(sinx-sx));
	x=x+dx;
}


	cosinus ()
{
//	printf ("entered in cosinus");
//	float cx, cosx;
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
	printf("||%11.6f", x);
	printf("|%9.*f",eo,  cx);
	printf("|%9.6f", cosx);
	printf("|%9.6f||\n", fabs(cosx-cx));	
	x=x+dx;	
}

/*	calculations ()
{
	choosing();
	enter();
	if (k==2)
	{
		showbs();
		if (x2>x1)
		{
			x=x1;
			do {sinus();}
			while (x<=x2);
		}
		if (x2<x1)
		{
			x=x1;
			do {sinus();}
			while (x>=x2);
		}
		showes();
	}
	
	if (k==(1))
	{
		showbc();
		if (x2>x1)
		{
			x=x1;
			do {cosinus();}
			while (x<=x2);
		}
		if (x2<x1)
		{
			x=x1;
			do {cosinus();}
			while (x>=x2);
		}
		showec();
	}
}*/

	main()
{
	char tmp;
	int i;
	do
	{	system ("cls");
		printf("Chose the function and enter the first & the last angle, step and accuracy\n");
		printf("Results will be rounded max to six decimal places.\n");
		choosing_sin_cos ();
		enter_first_angle ();
		enter_last_angle ();
		enter_step ();
		enter_accuracy ();
		calculate_accuracy ();
		print ();
		printf ("Enter y to continue\n");		
		exitchar = getch();
		fflush(stdin);		
	}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}
