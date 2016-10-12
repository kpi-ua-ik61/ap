#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int year, month, lyear, day, n, date, j;
char exitchar, x;

	enter_day()
{
do
{	x=0;

	printf ("\nEnter day from 1 to 31\n\n");
	scanf ("%d%c", &day, &x);
	if( (x!='\n')||(day<1)||(day>31) )
	{
		printf ("\nEnter only numbers from 1 to 31\n\n");
		fflush(stdin);
		j=0;	    	 	
	}		
	else (j=1);	
}
while (j!=1);
}

	enter_month()
{
do
{	x=0;
	printf ("\nEnter month\n\n");
	scanf ("%d%c", &month, &x);
	if ((x!='\n')||(month<1)||(month>12))
	{
		printf ("\nEnter numbers only from 1 to 12\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j==0);
}

	enter_year()
{
do
{	x=0;
	printf ("\nEnter year from 1 to 9999\n\n");
	scanf ("%d%c", &year, &x);
	if(x!='\n')
	{
		printf ("\nEnter only numbers from 1 to 9999\n\n");
		fflush(stdin);
		j=0;	    	 	
	}
	else (j=1);					
}
while (j==0);
}

	calculation()
{
	switch (month)
	{
		case 1:
			printf ("\nYou wrote a JANUARY\n");
		break;
		case 2:
			printf ("\nYou wrote a FEBRUARY\n");
		break;
		case 3:
			printf ("\nYou wrote a MARCH\n");
		break;
		case 4:
			printf ("\nYou wrote a APRIL\n");
		break;
		case 5:
			printf ("\nYou wrote a MAY\n");
		break;
		case 6:
			printf ("\nYou wrote a JUNE\n");
		break;
		case 7:
			printf ("\nYou wrote a JULY\n");
		break;
		case 8:
			printf ("\nYou wrote a AUGUST\n");
		break;
		case 9:
			printf ("\nYou wrote a SEPTEMBER\n");
		break;
		case 10:
			printf ("\nYou wrote a OCTOBER\n");
		break;
		case 11:
			printf ("\nYou wrote a NOVEMBER\n");
		break;
		case 12:
			printf ("\nYou wrote a DECEMBER\n");
		break;	
	}	
	if(((year%100!=0)&&(year%4==0))||((year%100==0)&&(year%400==0))) 
	{lyear=1; // vsokosnii god
	printf("\nYou wrote a leap-year\n");}
	else{lyear=0; // nevisokosnii god
	printf("\nYou wrote a not leap-year\n");}	
	if ( ((month==4)||(month==6)||(month==9)||(month==11))&&(day==31))
	{
		printf("\nThis day does not exist (APRIL, JUNE, SEPTEMBER, NOVEMBER have only 30 days)\n");
		return 0;
	}
	if ((month==2)&&(lyear==0)&&(day>=29))
		{
			printf ("\nThis day does not exist (in not-leap year FEBRUARY have only 28 days)\n");
			return 0;
		}		
	if ((month==2)&&(lyear==1)&&(day>29))
		{
			printf ("\nThis day does not exist (in leap year FEBRUARY have only 29 days)\n");
			return 0;
		}		
	if ( month > 2 ) {n=0;}
	else if ((month <= 2)&&(lyear == 1)) {n=1;}
	else if ((month <= 2)&&(lyear == 0)) {n=2;}	
	//printf("\nn=%d\n", n);	
	date = (long) (365.25*year + 30.56*month + day + n)%7;	
	switch(date)
		{
		    case 0:printf("\nMonday.\n");break;
		    case 1:printf("\nTuesday.\n");break;
		    case 2:printf("\nWednesday.\n");break;
		    case 3:printf("\nThursday.\n");break;
		    case 4:printf("\nFriday.\n");break;
		    case 5:printf("\nSaturday.\n");break;
		    case 6:printf("\nSunday.\n");break;
		}
}
	
int main()
{
do
{
	system("cls");
	printf ("\nWrite down day-month-year to know the weekday\n");	
	enter_day();	
	enter_month();	
	enter_year();	
	calculation();			
	printf ("\nEnter y + ENTER to continue\n");	
	printf ("\nEnter n + ENTER twice to continue\n\n");	
	exitchar = getchar();
}
while ( (exitchar == 'y')||(exitchar == 'Y') );
}
