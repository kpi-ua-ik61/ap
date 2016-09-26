#include<conio.h>
#include <stdio.h>
#include <math.h>
int e;
int x , k ;
    double  q=1 , eps=1;
    char b;
    double y= 1 ;
main()
{  
	
	printf("Enter X:\n");
	scanf("%lf%c" , &x,&b , "\n");
	printf("Enter K:\n");
	scanf("%lf%c" , &k,&b , "\n");
	printf("Enter Precision:\n");
	scanf("%d%c" , &eps,&b , "\n");
	printf("Enter number of numbers after dot:\n");
	scanf("%d",&e);
	
	if(k!=0 || b!='\n')
	{
	
	   while (abs(q)>= eps)
		{
			q=(1/k)*((x/pow(y,k-1))-y);
			y=y+q;
		}	
			printf("Y= %.*lf\n",e,y);
	}
	     
	else
	{
		printf("incorrect\n");
	}
	return 0;
}
