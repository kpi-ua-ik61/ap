#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../lib/inputlib/inputlib.c"


int date;
int month;
int year;

int day;


int code() {

	int vysokosn;

	int n;

	date = returnInputInt("Enter date:  ");

	month = returnInputInt("Enter month: ");

	year = returnInputInt("Enter year:  ");

	if(year > 9999 || date > 31 || month > 12){
		printf("error");
	}

	if((year%100 != 0 && year%4 == 0) || (year%100 == 0 && year%400 == 0)) vysokosn = 1;
	else vysokosn = 0;

	if (month > 2) n = 0;
	else if (month <= 2 && vysokosn) n = 1;
	else if (month <= 2 && !vysokosn) n = 2;

	day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;        //(long)  x64
	printf("\n");

	switch(day){
		case 0: printf("Mon, ");break;
		case 1: printf("Tue, ");break;
		case 2: printf("Wed, ");break;
		case 3: printf("Thu, ");break;
		case 4: printf("Fri, ");break;
		case 5: printf("Sat, ");break;
		case 6: printf("Sun, ");break;
	}

	printf("%u.%u.%u\n", date, month, year);

	return 0;
}

int main() {

	char exitchar;

	do {
		code();

		printf("\n");
		printf("Again? [y/n]: ");
		exitchar = getchar();

		printf("\n");
	}
	while( exitchar == 'y' || exitchar == 'Y' );

	return 0;
}


