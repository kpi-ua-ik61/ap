#include <stdio.h>
#include <conio.h>

int y, cy, m, cm, n, j;

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

int calculations (void)
{
	int yd, md, d, day;
	char x;

	printf("\nEnter date, month and year.\n");

	do
	{
		printf("\nEnter date\n");
		scanf("%d%c", &d, &x);
		if ((x!='\n')||(d<1)||(d>31))
		{
			printf("Enter only only numbers from 1 to 31.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	do
	{
		printf("\nEnter month\n");
		scanf("%d%c", &m, &x);
		if ((x!='\n')||(m<1)||(m>12))
		{
			printf("Enter only only numbers from 1 to 12.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
	checkm();

	do
	{
		printf("\nEnter year\n");
		scanf("%d%c", &y, &x);
		if ((x!='\n')||(y<1000)||(y>9999))
		{
			printf("Enter only only numbers from 1000 to 9999.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
	checky();

	if ((cy==1)&&(m==2)&&(d>29))
	{
		printf("This day doesn't exist.\n");
		return 0;
	}
	if ((cy==0)&&(m==2)&&(d>28))
	{
		printf("This day doesn't exist.\n");
		return 0;
	}
	if (((m==4)||(m==6)||(m==9)||(m==10))&&(d==31))
	{
		printf("This day doesn't exist.\n");
		return 0;
	}
	checkn();

	yd=365.25*y;
	md=30.56*m;
	day=(yd+md+d+n)%7;

	if (day==0) {printf("\nThis day is Monday\n");}
	if (day==1) {printf("\nThis day is Tuesday\n");}
	if (day==2) {printf("\nThis day is Wednesday\n");}
	if (day==3) {printf("\nThis day is Thursday\n");}
	if (day==4) {printf("\nThis day is Friday\n");}
	if (day==5) {printf("\nThis day is Saturday\n");}
	if (day==6) {printf("\nThis day is Sunday\n");}
}

int main (void)
{
	char tmp;
	int t;
	int i;
	do
	{
		calculations();
		fflush(stdin);
		do
		{
			printf("\nDo you want to try again? [Y/N]\n");
			scanf("%c", &tmp);
			t=tmp;
			if ((t==121)||(t==89)) {i=1;}
			if ((t==110)||(t==78)) {i=0;}
			if ((i!=0)&&(i!=1))
			{
				printf("Enter Y (Yes) or N (No).\n");
				fflush(stdin);
				j=0;
			}
			else (j=1);
		}
		while (j!=1);
	}
	while (i!=0);

	return 0;
}