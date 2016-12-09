#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define n_char 2000

int i, j, n, comp, w;
int n_string;

char *t;
char p;
char q, exitchar;

	enter_n_string()
{
do
{		
		printf ("This programm will sort your strings in lexical concept\n");
		printf ("Enter number of strings (<=100)\n");
			scanf("%d%c", &n_string, &q);
			if( (n_string<=1)||(q!='\n')||(n_string>100) )
				{
					printf ("Enter only integer numbers higher than 1 and less than 100\n");
					j=1;
					fflush(stdin);
				}
			else j=0;
}
while (j!=0);
	printf ("Please, enter %d strings\n", n_string);
}

	input_string()
	
{	int k=1;
	char list[n_string][n_char];
	char *pointer_list[n_string];
		
	printf ("Enter your string (<2000 symbols)\n");
	
	for (i=0; i<n_string; i++)
	{
		gets (list[i]);
		printf ("Your %d string of %d is: ", k, n_string);
		puts (list[i]);
		k++;
	}
		
	for (i=0; i<n_string; i++) 
	{
		pointer_list[i]=list[i];
	}
	
	for (n=0; n<n_string; n++)
	{
		for (i=1; list[n][i]!='\0'; i++)
		{
			while ( i>0 && list[n][i-1]>list[n][i] ) 
			{	
				p=list[n][i];
				list[n][i]=list[n][i-1];
				list[n][i-1]=p;	
				i--;	
			}	
		}
	}
	
	for (i=1; i<n_string; i++)
	{
		while ( i>0 && (strcmp(pointer_list[i-1],pointer_list[i])) > 0 )
		{
				t=pointer_list[i];
				pointer_list[i]=pointer_list[i-1];
				pointer_list[i-1]=t;
				i--;
		}	
	}
	
	printf ("You want to sort you list (in lexical concept) from down to up (1), or from up to down (2)?\n");
	scanf ("%d", &w); 
	
	switch (w)
	{
		case 1:
			{
				for (i=0; i<n_string; i++)
				{
					puts (pointer_list[i]);
				}
			break;
			}
		case 2:
			{
				for (i=n_string-1; i>=0; i--)
				{
					puts (pointer_list[i]);
				}
			break;	
			}
	}
	
}

	main()
{	
do
{
	system("cls");
	enter_n_string();
	input_string();	
	printf ("Enter y to continue\n");		
	exitchar = getch();
	fflush(stdin);		
}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}


