#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char exitchar = 'y', number;
int symbol, j, n, d, i, q;	// kol-vo simvolov	
float str[100],t ;		// massive iz max 100 elementov, i
int main()
{	
do
{
system("cls");
	{
		printf ("Enter number of elements:\n");	
		do
		{
			
			if( scanf("%d%c", &n, &symbol)!=2||/*(symbol!='\n')||*/(n<=2)||(n>=100) )
			{	
				printf ("ERROR (Enter only integer numbers from 2 to 100)\n");
				fflush(stdin);
				j=0;	    	 	
			}
			else (j=1);	
		}
		while(j==0);
		
	printf ("Number of elements=%d\n", n);
	printf ("Enter %d characters\n", n);
	
	{
		int k=0;
		for (i=0; i<n ; i++)
		{	
			do
			{
				if ( scanf ("%f%c", &str[i], &symbol)!=2 )
				{	
					printf ("ERROR (Enter only numbers)\n");
					fflush(stdin);
					j=0;	    	 	
				}
				else
				{
					printf ("i%d=%.3f\n",k, str[i]);
					k++;
					j=1;
				}
			}
			while(j==0);
		}			
		printf ("Your array is:");	
		for (i=0; i<n-1; i++)
		{				
			printf ("%.3f, ", str[i]);
		}	
		q=i;
		printf ("%.3f. ", str[q])	;	
	}	
	
	for (i=1; i<n; i++)
	{		
		while ( i>0 && str[i-1]>str[i] )
			{
				t=str[i];
				str[i]=str[i-1];
				str[i-1]=t;
				i--;
			}								
	}		
	getch();
	printf ("\nIf you want to sort list from low to hight press '1', for the second press '2'\n");	
	do
	{	
		if( scanf ("%d%c", &number, &symbol)!=2||(number!=1)&&(number!=2) )	
		{
			printf ("\nPlease, enter 1 to see up list & 2 to see down list\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while(j==0);
	switch (number)
	{
		case 1:
			printf ("Your sorted up list:\n");	
			for (i=0; i<n; i++)
			{
				printf("%.3f\n", str[i]);
			}
			break;
		case 2:	
			printf ("Your sorted down list:\n");
			for (i=n-1; i>=0; i--)
			{
				printf("%.3f\n", str[i]);
			}
			break;
	}	
	}	
	printf ("Enter y to continue\n");		
	exitchar = getch();
	fflush(stdin);		
	}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}

