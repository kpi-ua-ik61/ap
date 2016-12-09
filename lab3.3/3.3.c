#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

float a,b,c;
float d,p,q;
int b;

void Ex(int b)
{
	printf("\nDo you want to contine?[press y/n]:\n");
	b=getchar();
	fflush(stdin);
	if(b=='y'||b=='Y') {
        system("cls");
		main();}
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

int main()
{   
	float x1,x2,x3;
	char c;
	printf("Enter a:\n");
	scanf("%f%c",&a,&c);
	fflush(stdin);
	printf("\nEnter b:\n");
	scanf("%f%c",&b,&c);
	fflush(stdin);
	printf("\nEnter c:\n");
	scanf("%f%c",&c,&c);
	fflush(stdin);

  p =b-(pow(a,2)/3);
  q=2*pow(a,3)/27-a*b/3 +c;
  d =pow(p,3)/27+pow(q,2)/4;
 float y1,y2,y3;
     if(d>0){
    float u,v;
    u=cbrt(-q/2+sqrt(d));
    v=-p/(3*u);
    y1=u+v;
    y2=((-u-v)+I*sqrt(3)*(u-v))/2;
    y3=(-u-v-I*sqrt(3)*(u-v))/2;
    }
    else if(d=0)
    {
      y1=3*q/p;
      y2=y3=-3*q/(2*p);
    }
    else if(d<0)
    {
       float r =sqrt(-pow(p,3)/27);
       float f=acos(-q/(2*r));
       y1=2*fabs(cbrt(r))*cos(f/3);
       y2=2*fabs(cbrt(r))*cos((f+2*M_PI)/3);
       y3=2*fabs(cbrt(r))*cos((f+4*M_PI)/3);
    }
   x1=y1-(a/3);
   x2=y2-(a/3);
   x3=y3-(a/3);
   printf("X=%f , %f , %f\n",x1,x2,x3);
   Ex(b);   
}
