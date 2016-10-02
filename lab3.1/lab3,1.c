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
    printf("Do you want to contine?[press y/n]:\n");
    b=getchar();
    if(b=='y'||b=='Y') main();
    else if (b=='n'||b=='N') exit (0);

    else
    {
        while (b!='y' || b!='Y' || b!='n' || b!='N')
      {
         printf("press `Y` or `N`\n");
         Ex(b);
      }
    }
}

double Mn(double q,int k,double y,int e,double x)
{
    q=1,k,y=1,e,x;
    double yk=y;
    int ke=abs(k);
    double eps = pow((0.1),e);
    do
    {

     q=(1.0/abs(k))*(x/pow(y,abs(k)-1)-y);
     y=y+q;
    }
    while(fabs(q)>=eps);
    return y;
}
int main()
{
    char c;
	printf("Enter K:\n");
	scanf("%d%c",&k,&c);
	printf("\nEnter X:\n");
	scanf("%lf%c",&x,&c);
    printf("\nEnter pecision:\n");
    scanf("%d%c",&e,&c);

    if(k!=0 && k<=32767 && k>=-32168 && c=='\n' && e>=0 && e<=16)
    {
        if(k>0 && c=='\n')
	    {
	    if(k%2==0 && c=='\n')
	      {
	     if(x>=0 && c=='\n') printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
         else {
             printf("Incorrect\n if K bigger than 0 and is even number - X must be bigger than 0 or be 0\n");
             Ex(b);}
    }
    else if ((k%2!=0 && x>=0 && c=='\n' )||( x<0 && k%2!=0 && c=='\n')) printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
      }
    else if(k<0 && c=='\n')
    {
        if(k%2==0 && c=='\n')
        {
            if(x>0 && c=='\n') printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
            else {
                printf("Incorrect\n if K lower than 0 and is even number - X must be bigger than 0");
                Ex(b);}
        }
        else if(k%2!=0 && c=='\n')
        {
            if(x!=0 && c=='\n') printf(" Y= %.*f\n",e,Mn(q,k,y,e,x));
            else {
                printf("if K lower than 0 and isn`t even number - X mustn`t be 0");
                Ex(b);}
        }
    }
    else {
        printf("K must be a number");
        Ex(b);}
    }
    else {
        printf("Incorrect \n(K,X,PRECISION-numbers) K must be from -32768 to 32767 but mustn`t be 0\n presicion must be from 0 to 16 \n");
        Ex(b);}

    Ex(b);
}
