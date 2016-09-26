#include<conio.h>
#include <stdio.h>
#include <math.h>
int e;
 double x , k ;
    double  q=1, eps;
    char b;
    double y= 1 ;
	float z=0.1 ;
main()
{  
	
	printf("Enter X:\n");
	scanf("%lf%c" , &x,&b , "\n");
	printf("Enter K:\n");
	scanf("%lf%c" , &k,&b , "\n");
	printf("Enter Precision:\n");
	scanf("%d%c" , &e,&b , "\n");
	eps= pow(z,e);
	
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
