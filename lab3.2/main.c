#include <stdio.h>
#include <conio.h>
#include <math.h>

int date;
int month;
int year;

int day;

int main()
{
	char term;

	int vysokosn;

	int n;

	printf("Day");
	scanf("%u%c", &date, &term);
	if ( (term != '\n') || (day != 0) ) {
		printf("ERROR");
		return 0;
	}

	printf("Month");
	scanf("%u%c", &month, &term);
	if ( (term != '\n') || (month <= 0) ) {
		printf("ERROR");
		return 0;
	}

	printf("Year");
	scanf("%u%c", &year, &term);
	if ( (term != '\n') || (year <= 0) ) {
		printf("ERROR");
		return 0;
	}

	if(year > 9999 || date > 31 || month > 12){
		printf("error");
	}

	printf("%u.%u.%u\n", date, month, year);

	if((year%100 != 0 && year%4 == 0) || (year%100 == 0 && year%400 == 0)) vysokosn = 1;
	else vysokosn = 0;

	if (month > 2) n = 0;
	else if (month <= 2 && vysokosn) n = 1;
	else if (month <= 2 && !vysokosn) n = 2;

	day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;        //(long)  x64
	printf("%d\n", day);

	switch(day){
		case 0: printf("Mon\n");break;
		case 1: printf("Tue\n");break;
		case 2: printf("Wed\n");break;
		case 3: printf("Thu\n");break;
		case 4: printf("Fri\n");break;
		case 5: printf("Sat\n");break;
		case 6: printf("Sun\n");break;
	}
	return 0;
}