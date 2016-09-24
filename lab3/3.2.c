#include <stdio.h>
#include <conio.h>

int y, cy, m, cm, n;

void checky (void)
{
	if (((y%100!=0)&&(y%4==0))||((y%100==0)&&(y%400==0))) {cy=1;}
	else {cy=0;};
}

void checkm (void)
{
	if (m>2) {cm=1;}
	else {cm=0;}
}

void checkn (void)
{
	if (cm==1) {n=0;}
	if ((cm==0)&&(cy==1)) {n=1;}
	if ((cm==0)&&(cy==0)) {n=2;}
}

int main (void)
{
	int yd, md, d, day;
	char x;
	printf("Enter year\n");
	scanf("%d%c", &y, &x);
	if ((x!='\n')||(y<1000)||(y>9999))
	{
		printf("Enter only only numbers from 1000 to 9999.\n");
		getch();
		return 0;
	}
	checky();

	printf("Enter month\n");
	scanf("%d%c", &m, &x);
	if ((x!='\n')||(m<1)||(m>12))
	{
		printf("Enter only only numbers from 1 to 12.\n");
		getch();
		return 0;
	}
	checkm();

	printf("Enter date\n");
	scanf("%d%c", &d, &x);
	if ((x!='\n')||(d<1)||(d>31))
	{
		printf("Enter only only numbers from 1 to 31.\n");
		getch();
		return 0;
	}
	if ((cy==1)&&(m==2)&&(d>29))
	{
		printf("This day doesn't exist.\n");
		getch();
		return 0;
	}
	if ((cy==0)&&(m==2)&&(d>28))
	{
		printf("This day doesn't exist.\n");
		getch();
		return 0;
	}
	if (((m==4)||(m==6)||(m==9)||(m==10))&&(d==31))
	{
		printf("This day doesn't exist.\n");
		getch();
		return 0;
	}
	checkn();

	yd=365.25*y;
	md=30.56*m;
	day=(yd+md+d+n)%7;

	if (day==0) {printf("This day is Monday\n");}
	if (day==1) {printf("This day is Tuesday\n");}
	if (day==2) {printf("This day is Wednesday\n");}
	if (day==3) {printf("This day is Thursday\n");}
	if (day==4) {printf("This day is Friday\n");}
	if (day==5) {printf("This day is Saturday\n");}
	if (day==6) {printf("This day is Sunday\n");}

	getch();

	return 0;
}