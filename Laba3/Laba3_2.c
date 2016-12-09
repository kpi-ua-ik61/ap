#include <curses.h> //...of Linuxoid
#include <stdio.h>
#include <stdlib.h> // exit()
char ch;//ch = character checker
int result, chmonth, n;
bool leap_year;

void error(char* errorMsg){
	printf("\nError!\n%s\nPlease try again\n", errorMsg);
}
void crash(char* crashMsg){
	printf("\nCrash!\n%s\nExiting programm\n", crashMsg);
	exit(0);
}
int symbCheck(char* checkMsg){
	printf("\n%s\n", checkMsg);
	if(scanf("%i%c", &result, &ch)  != 2 || ch != '\n'){
		crash("You cannot enter any symbols\n Also it causing infinite loop\n Dont do that again");
	}
	else{ 
		return result;
	}
}
int daycheck(){
	bool looper = true;
	while (looper == true){
		fflush(stdin);
		result = symbCheck("Enter wished day of month");
		if((result >= 1) && (result <= 31)) {
			looper = false;
		}
		else{
			error("  Day of month must be a number from 1 to 31");
		}	
	}
	return result;
}
int monthcheck(){
	bool looper = true;
	while (looper == true){
		fflush(stdin);
		result = symbCheck("Enter wished month of year");
		if((result >= 1) && (result <= 12)) {
			looper = false;
		}
		else{
			error("  Year contains only 12 months\n  Enter number from 1 to 12");
		}
	}
	return result;
}
int yearcheck(){
	bool looper = true;
	while (looper == true){
		fflush(stdin);
		result = symbCheck("Enter wished year, of Anno Domini era");
		if((result >= 1000) && (result <= 9999)){
			looper = false;
		}
		else{
			error("  That's too far!\n  Time period of 1000 to 9999 must be enough for you");
		}
	}
	return result;
}
int identifyer(int day,int month,int year){
	if (month > 2) {chmonth = 1;}
	else {chmonth = 0;}//Month identifying

	if(((year%100 != 0) && (year%4 == 0)) || ((year%100 == 0) && (year%400 == 0))) {leap_year = true;}
	else {leap_year = false;} //Year identifying

	if ((leap_year == true) && (month == 2) && (day > 29)){
		error("  This day cannot to be existing\n  February doesn't have that much days\n  In this year, only 29");
		return 0;
	}
	if ((leap_year == false) && (month == 2) && (day > 28)){
		error("  This day cannot to be existing\n  February doesn't have that much days\n  In this year, only 28");
		return 0;
	}
	if (((month == 4) || (month == 6) || (month == 11)) && (day == 31)){
		error("  This day cannot to be existing\n  This month doesn't have that much days\n  Only 30");
		return 0;
	}
	if (chmonth == 1) {n = 0;}
	if ((chmonth == 0) && (leap_year == 1)) {n = 1;}
	if ((chmonth == 0) && (leap_year == 0)) {n = 2;}

	int yearID = (365.25 * year);
	int monthID = (30.56 * month);
	int weekDay = (yearID + monthID + day + n)%7;

	if (weekDay == 0) {printf("\n This day existing as Monday\n");}
	if (weekDay == 1) {printf("\n This day existing as Tuesday\n");}
	if (weekDay == 2) {printf("\n This day existing as Wednesday\n");}
	if (weekDay == 3) {printf("\n This day existing as Thursday\n");}
	if (weekDay == 4) {printf("\n This day existing as Friday\n");}
	if (weekDay == 5) {printf("\n This day existing as Saturday\n");}
	if (weekDay == 6) {printf("\n This day existing as Sunday\n");}
	return 1;

}

int main(){
	char tempCh;
	bool looper = true;
		while (looper == true){
			fflush(stdin);
			int day = daycheck();
			int month = monthcheck();
			int year = yearcheck();
			int ID = identifyer(day, month, year);
			bool looper2nd = true;
			while (looper2nd == true){
				printf("\n  Do you wish to try again?\nType on your keyboard 'Y' or 'N'\n");
				scanf("%c", &tempCh);
				int tempInt = tempCh;
				if ((tempInt == 121) || (tempInt == 89)) { looper = true; }
				if ((tempInt == 110) || (tempInt == 78)) { looper = false; }
				if (((tempInt != 121) && (tempInt != 89)) && ((tempInt != 110) && (tempInt != 78))){
					error("  Type 'Y' = yes; or 'N' = no; \non your keyboard, and nothing else");
					fflush(stdin);
				}
				else {looper2nd = false;}
			}
			
		}
		printf("\n  Shutting down the programm\n");
		exit(0);

}



