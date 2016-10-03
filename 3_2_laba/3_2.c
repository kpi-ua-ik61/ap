#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int year, month, lyear, day, n, date;
char x, exitchar;

int checkday()
{	char exit;
	do		
	{
		exit='0';
		printf ("Enter day from 1 to 31\n");
		scanf ("%d%c", &day, &x);
			if ((x=="\n")||(day<1)||(day>31))
				{	
					printf("Enter only numbers from 1 to 31\n");
					printf("If you want to restart press \'y\' + ENTER\n");	
					printf("If you want to exit press \'n\' + ENTER twice\n");	
					exit = getchar();
					if (exit == 'n')
               	 	_exit (EXIT_SUCCESS);
				}					
	}
	while ( (exit == 'y')||(exit == 'Y') );
}



int checkmonth()
{	char exit;
	do
	{	
		exit='0';
		printf ("Enter month from 1 to 12\n");
		scanf ("%d%c", &month, &x);
			if ((x=="\n")||(month<1)||(month>12))
				{			
					printf ("Enter numbers only from 1 to 12\n");
					printf("If you want to restart press \'y\' + ENTER\n");	
					printf("If you want to exit press \'n\' + ENTER twice\n");		
					exit = getchar();
					if (exit == 'n')
               	 	_exit (EXIT_SUCCESS);
				}
			else
				{
					switch (month)
						{
							case 1:
								printf ("You wrote a JANUARY\n");
							break;
							case 2:
								printf ("You wrote a FEBRUARY\n");
							break;
							case 3:
								printf ("You wrote a MARCH\n");
							break;
							case 4:
								printf ("You wrote a APRIL\n");
							break;
							case 5:
								printf ("You wrote a MAY\n");
							break;
							case 6:
								printf ("You wrote a JUNE\n");
							break;
							case 7:
								printf ("You wrote a JULY\n");
							break;
							case 8:
								printf ("You wrote a AUGUST\n");
							break;
							case 9:
								printf ("You wrote a SEPTEMBER\n");
							break;
							case 10:
								printf ("You wrote a OCTOBER\n");
							break;
							case 11:
								printf ("You wrote a NOVEMBER\n");
							break;
							case 12:
								printf ("You wrote a DECEMBER\n");
							break;
						}				
				}
		}
	while ( (exit == 'y')||(exit == 'Y') );	
}




int checkyear()
{	char exit;
	do
	{
		exit='0';
		printf ("Enter year from 1 to 9999\n");
		scanf ("%d%c", &year, &x);
		if ((x=="\n")||(year>9999)||(year<=0))
			{
				printf("Enter only numbers from 1 to 9999.\n");
				printf("If you want to restart press \'y\' + ENTER\n");	
				printf("If you want to exit press \'n\' + ENTER twice\n");		
				exit = getchar();
				if (exit == 'n')
               	_exit (EXIT_SUCCESS);
			}
		else
			{
				if(((year%100!=0)&&(year%4==0))||((year%100==0)&&(year%400==0))) 
					{lyear=1; // vsokosnii god
					printf("You wrote a leap-year\n");}
				else{lyear=0; // nevisokosnii god
					printf("You wrote a not leap-year\n");}				
			}
	}
	while ( (exit == 'y')||(exit == 'Y') );		
}
	
	


int main()
{
do
{	
	checkday();
	
	checkmonth();
	
	checkyear();
				
	if ((month==2)&&(lyear==0)&&(day>=29))
		{
			printf ("This day does not exist\n");
			getch ();
			return 0;
		}				
			
	if ( month > 2 ) {n=0;}
	else if ((month <= 2)&&(lyear == 1)) {n=1;}
	else if ((month <= 2)&&(lyear == 0)) {n=2;}
	
	printf("n=%d\n", n);

	date = (long) (365.25*year + 30.56*month + day + n)%7;
	
	if ( ((month==4)||(month==6)||(month==9)||(month==11))&&(day==31))
		{
			printf("This day does not exist\n");
			getch();
			return 0;
		}
	
		switch(date)
		{
		    case 0:printf("Monday.\n");break;
		    case 1:printf("Tuesday.\n");break;
		    case 2:printf("Wednesday.\n");break;
		    case 3:printf("Thursday.\n");break;
		    case 4:printf("Friday.\n");break;
		    case 5:printf("Saturday.\n");break;
		    case 6:printf("Sunday.\n");break;
		}
	printf("If you want to restart press \'y\' + ENTER\n");	
	printf("If you want to exit press \'n\' + ENTER twice\n");	
	exitchar = getchar();
	
}
while ( (exitchar == 'y')||(exitchar == 'Y') );
	return 0;
}
