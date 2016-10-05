#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

	int k;
    double x;
    int e;
    double q;
    double y;
    int b;

void Ex(int b)
{
	printf("\nDo you want to contine?[press y/n]:\n");
	b=getchar();
	fflush(stdin);
	if(b=='y'||b=='Y') {
        system("cls");
		main();
	}
	else if (b=='n'||b=='N') exit (0);
	else
	{
		while (b!='y' || b!='Y' || b!='n' || b!='N')
	  {
		 printf("press `Y` or `N`\n");
		 b=getchar();
	     if(b=='y'||b=='Y') {
            system("cls");
	     	main();}
	     else if (b=='n'||b=='N') exit (0);
	  }
	}
}
double Ppo(double y,int k)
{
int ke=k,i=1;
double ye=1;
 if(abs(ke)>1)
 	{
 	for(i=1;i<=ke;i++)
 {
  ye=ye*y;
 }
if(ke>1)  y=ye;
else if(ke<1) y=1/ye;
}
 else if(ke =1)  y;
 else if(ke=0)  y=1;
 else if(ke=-1)  y=1/y;
 return y;
}

double Mn(double q,int k,double y,int e,double x)
{
	q=1,k,y=1,e,x;
	double eps = pow((0.1),e);
	if(k>=2 || k<=-2)
	{
	do
	{
	 q=(1.0/abs(k))*(x/Ppo(y,abs(k)-1)-y);
	 y=y+q;
	}
	while(fabs(q)>=eps);
	if(k<=-2) y=1/y;
    }
    else if(k==1) y=x;
    else if(k==-1)y=1/x;
	return y;
}
int main()
{
    char c;
	printf("Enter K:\n");
	scanf("%d%c",&k,&c);
	fflush(stdin);
	printf("\nEnter X:\n");
	scanf("%lf%c",&x,&c);
	fflush(stdin);
	printf("\nEnter pecision:\n");
	scanf("%d%c",&e,&c);
    fflush(stdin);

	if((k!=0 && k<=32767 && k>=-32768 && c=='\n' && x>0 && e>=0 && e<=16 )|| (k!=0 && k<=32767 && k>=-32768 && c=='\n' && x<0 && e>=0 && e<16))
	{
		if(k>0)
		{
		if(k%2==0)
		  {
		 if(x>=0) printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
		 else printf("Incorrect\n if K bigger than 0 and is even number - X must be bigger than 0 or be 0\n");
			 
	}
	else if ((k%2!=0 && x>=0)||(x<0 && k%2!=0)) printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
	  }
	else if(k<0)
	{
		if(k%2==0)
		{
			if(x>0) printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
			else printf("Incorrect\n if K lower than 0 and is even number - X must be bigger than 0");
		}
		else if(k%2!=0)
		{
			if(x!=0) printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
			else printf("Incorrect \nif K lower than 0 and isn`t even number - X mustn`t be 0\n");
		}
	}
	else printf("K must be a number");
	}
	else printf("Incorrect \n(K,X,PRECISION-numbers) K must be from -32768 to 32767 but mustn`t be 0\n presicion must be from 0 to 16 \n");
	Ex(b);
}
