#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() 
{
 double a; 
 double b;
 double c;
 printf("\t Hello! \n Enter three sides of de triangle:\n");
 scanf("%lf%lf%lf", &a, &b, &c ); // specifikatoru formaty
 printf("A=%lf B=%lf C=%lf \n", a, b, c);
  if ((a+b)>c && (a+c)>b && (b+c)>a && b>0 && a>0 && c>0) 
  {    
    double p=((a+b+c)/2);
    double plosha=sqrt(p*(p-a)*(p-b)*(p-c));
    double perimetr=(a+b+c);
    double visota_a=(2*sqrt(p*(p-a)*(p-b)*(p-c)))/a;
    double visota_b=(2*sqrt(p*(p-a)*(p-b)*(p-c)))/b;
    double visota_c=(2*sqrt(p*(p-a)*(p-b)*(p-c)))/c;
    double bisek_a=2*(sqrt(b*c*p*(p-a)))/(b+c);
    double bisek_b=2*(sqrt(a*c*p*(p-b)))/(a+c);
    double bisek_c=2*(sqrt(b*a*p*(p-c)))/(b+a);
    double med_a=sqrt(2*b*b+2*c*c-a*a)/2;
    double med_b=sqrt(2*a*a+2*c*c-b*b)/2;
    double med_c=sqrt(2*b*b+2*a*a-c*c)/2;  
  printf ("area=%lf \nperimeter=%lf \nheight to A=%lf \nheight to B=%lf \nheight to C=%lf \nbisect to A=%lf \nbisect to B=%lf \nbisect to C=%lf \nmedian to A=%lf \nmedian to B=%lf \nmedian to C=%lf", plosha, perimetr, visota_a, visota_b, visota_c, bisek_a, bisek_b, bisek_c, med_a, med_b, med_c);      
  }
  else printf("WRONG!!"); 
 getch();
 return 0;
}
