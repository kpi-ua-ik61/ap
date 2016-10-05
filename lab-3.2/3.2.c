#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int date;
int month;
int year;
int day;

int Day(int day,int year,int month,int date)
{
    day,year,month,date;
	int n ;
	if(month>2) n=0;
	else if((year%100!=0 && year%4==0 && month>0 && month<=2)||(year%100==0 && year%400==0 && month<=2 && month>0)) n=1;
	else if((year%100==0 && year%4!=0 && month>0 && month<=2)||(year%100!=0 && year%400!=0 && month>0 && month<=2)) n=2;
	day=fmod((floor(365.25*year)+floor(30.56*month)+date+n),7);
	switch (day)
    {
       case 0:
       printf("\nMonday\n");
       break;
       case 1:
       printf("\nTuesday\n");
       break;
       case 2:
       printf("\nWednesday\n");
       break;
       case 3:
       printf("\nThursday\n");
       break;
       case 4:
       printf("\nFriday\n");
       break;
       case 5:
       printf("\nSaturday\n");
       break;
       case 6:
       printf("\nSunday\n");
       break;
	}
	return day;
}

int main()
{
    char c;
    char b;
    printf("Enter date(number):\n");
	scanf("%d%c",&date,&c);
  fflush(stdin);
	printf("\nEnter month(number):\n");
	scanf("%d%c",&month,&c);
  fflush(stdin);
	printf("\nEnter year(like 1959):\n");
	scanf("%d%c",&year,&c);
  fflush(stdin);

  if(date>0 && month>0 && month<=12)
  {
   if(month%2==0 && date<=31 && month!=2) Day(day,year,month,date);
   else if(month%2!=0 && date<=30 && month!=2) Day(day,year,month,date);
   else if((month==2 && date<=29 && year%100==0 && year%400==0 )||(month==2 && date<=29 && year%100!=0 && year%4==0))Day(day,year,month,date);
   else if((month==2 && date<29 && year%100==0 && year%400!=0)||(month==2 && date<29 && year%100!=0 && year%4!=0))Day(day,year,month,date);
   else   printf("\nIncorrect(in one month 30 or 31 day but in february 29(If a leap year) or 28)\n");
  }
  else printf("Incorrect(Date must be from 1 to 31,month from 1 to 12,year from 0 to 32767)");

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
     fflush(stdin);
      if(b=='y'||b=='Y') {
        system("cls");
        main();}
      else if (b=='n'||b=='N') exit (0);
    }
  }
}