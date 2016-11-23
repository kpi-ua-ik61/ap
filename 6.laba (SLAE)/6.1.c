#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>



main()
{
char exitchar = 'y';
char c;
int n, m;
int i, j;
int q, k;
float *a;
float x1, x2, x3, x4, x5, x6, x7;	
do
{	

	printf ("Enter numbers of strings: ");
	scanf("%d", &n);
	printf ("Enter numbers of variables + answers: ");
	scanf("%d", &m);
	
	if ( n>m-1 ) {q=1;}
	else (q=2);
	
	
	switch (q)
	{
		case 1:
			{
			printf ("Decision have unlimitet amount of solutions\n");
			break;
			}
		case 2:
			{
				
				a = (float*) malloc(n*m*sizeof(float));
		
				for (i=0; i<n; i++)
				{
					for (j=0; j<m; j++)					
					{
						if ( j<m-1 )
						{
							printf ("a[%d][%d]=", i+1, j+1);
							do
							{						
								if	( scanf ("%f%c", (a+i*m+j), &c)!=2 )
								{
									printf ("Be carefu, nter only numbers\n");
									printf ("a[%d][%d]=", i+1, j+1);
									fflush(stdin);
									k=0;
								}
								else {k=1;}							
							}
							while(k==0);
						}
						else {printf ("b[%d]=", i+1); scanf ("%f", (a+i*m+j));}						
					}
				}
			
			//	printf ("%f", *a+6);
				
				printf ("Your sysiem is:\n");
				
				for(i=0; i<n; i++) 
				{					
						for(j=0; j<m; j++)
						{						
							if (j==m-1)
							{
								printf("=%10g", *(a+i*m+j));
							}	
							else	
							printf("+(%5g*x%d) ", *(a+i*m+j), j+1);					
						}					
				printf("\n");
				}
				
				for (i=1; i<m-1; i++)
				{
					
				}
				x2=( *(a+2) - (((*a) * (*(a+2))/(*(a+4))) )) / (*(a+4));
				
//				x2=( *(a+3) - (((*a) * (*(a+3))/(*(a+5))) + ((*(a+2)) * (*(a+3))/(*(a+5)) ))) / (*(a+5));
				//x2 = *a+3;
				printf ("x2= %f\n", x2);
						
				
				free(a);
				a=0;	
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
