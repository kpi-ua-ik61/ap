#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char exitchar = 'y';
int symbol, j, n, d, i;	// kol-vo simvolov	
float str[100],t ;		// massive iz max 100 elementov, i

int main()
{	
do
{
system("cls");
	
	
	{	
	{	
		do
		{
			printf ("Enter number of elements:\n");
			scanf ("%d%c", &n, &symbol);
			if( (symbol!='\n')||(n<=0)||(n>100) )
			{
				printf ("ERROR (Enter only integer numbers from 0 to 100)\n");
				fflush(stdin);
				j=0;	    	 	
			}
			else (j=1);	
		}
		while(j==0);
		printf ("n=%d\n", n);
	}

	{
		int k=0;
		printf ("Enter %d integers\n", n);
		for (i=0; i<n ; i++)
		{
			scanf ("%f", &str[i]);
			printf ("i%d=%.3f\n",k, str[i]);
			k++;
		}		
		while(j==0);
		k=0;
		printf ("Your array is: ");	
		for (i=0; i<n; i++)
		{				
			printf ("%.3f ", str[i]);
			k++;
		}	
		
	}
	
	{
		for (i=1; i<n; i++)
		{
			d=i;		
			while ( d>0 && str[d]<str[d-1] )
				{
					t=str[d];
					str[d]=str[d-1];
					str[d-1]=t;
					d--;
				}		
		}
	}
	printf ("\nSorted	list:\n");
	
	for (i=0; i<n; i++)
	{
		printf("%.3f\n", str[i]);
	}
	}
	
	
	printf ("\nEnter y to continue\n");		
	exitchar = getch();
	fflush(stdin);		
	}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}

