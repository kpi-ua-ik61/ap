#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h> //Нити, они повсюду
#include <string.h>
#include <math.h>

void errMsg(char *errorMsg){ //Мой любимый, мой родной, вызов сообщения об ошибке
	printf("\nERROR\n %s\n Programm will try again, if you wish give up, press Ctrl C\n\n", errorMsg);
}
void line(){
	printf("--------------------------------------------------------------------");
}
void linemenu(){
	printf("\n|Degrees| Sin(x) - (Teylor) | Sin(X) - (Build-in) | Accuracy |\n");
}
float sint(float i, float e){
	float sin, delta, rad;
	int n;
	rad = i * M_PI / 180;
	delta = rad;
	sin = rad;
	n = 1;
	do{
		delta = delta * ((-(rad * rad)) / ( (n + 1) * (n + 2) ));
		sin = sin + delta;
		n = n + 2;
	} while (fabs(delta) >= e);
	return sin;
}
int main()
{
	char lim1[30], lim2[30], lim3[30], step[10], accur[10];
	float x1, x2, e1, x, i, sintx, costx;
	double e, dx, h, g;
	int buf, buf1, a, hh, hd, looper;
	char *error;
	int escape;

	while (looper != 1){
		printf("\nProgramm for computing sin(x)\n")
		fflush(stdin);
		printf("\nEnter the limit 1: ");
		scanf("%s", lim1);
		x1 = strtod(lim1, &error); //Чек на символы
		if (strlen(error) != 0){ //Длину тут проверяет
			errMsg("Incorrect limit 1, looks like someone just entered symbols");
			fflush(stdin);
			continue;
		}
		else {
			printf("\nEnter the limit 2: ");
			scanf("%s", lim2);
			x2 = strtod(lim2, &error); //Ещё один чек на символы
			if (strlen(error) != 0){
				errMsg("Incorrect limit 2, looks like someone just entered symbols");
				fflush(stdin);
				continue;
			}
		}
		buf = 1;
		if (x1 == x2){
			errMsg("Incorrect limits, the limits must be not match");
			fflush(stdin);
			buf = 0;
			continue;
		}

		printf("\nEnter the step: ");
		buf = 1;
		scanf("%s", step);
		dx = strtod(step, &error);
		if (strlen(error) != 0 || dx == 0){
			errMsg("Incorrect step, it cannot be 0, or contain any symbols");
			fflush(stdin);
			buf = 0;
			continue;
		}

		printf("\nEnter accuracy of calculations: ");
		scanf("%s", &accur);
		e = strtod(accur, &error);
		if (strlen(error) != 0 || e > 1 || e < 1e-16){
			errMsg("Incorrect accuracy ");
			fflush(stdin);
			continue;
		}
		else {
			buf = 1;
			buf1 = 0;
			if(x1 < x2){
				if(dx > 0){
		printf("\n                      Table of Sin (X)   \n");
		line();
		linemenu();
		line();
					for(i = x1; i <= x2; i=i + fabs(dx)){
						buf1++;
						if (buf1%11==0){
							printf("\nThere is more than 10 values. \n\n");
		line();
		linemenu();
		line();
						}
						sintx = sint(i, e);
		printf("\n|%5.2f  |%15.9f  |%18.9f  |%9.4e|\n", i, sintx, sin(i * M_PI / 180), fabs(sintx - sin(i * M_PI / 180)));
		line();
					}
					printf("\nProgramm will try again, if you wish give up, press Ctrl C \n");
				}
				else{
					errMsg("Such step doesnt correspond to limits");
				}
			}
			if (x1 > x2){
				if (dx < 0){
		printf("\n                      Table of Sin(X)    \n");
		line();
		linemenu();
		line();
					for (i = x1; i >= x2; i = i - fabs(dx)){
						buf1++;
						if (buf1%10==0){
							printf("\nThere is 10 values. Enter any key to show another. \n\n");
							getchar();
		line();
		linemenu();
		line();
						}
						sintx = sint(i, e);
		printf("\n|%6.2f  |%15.9f  |%18.9f  |%1.11f|\n", i, sintx, sin(i * M_PI / 180), fabs(sintx - sin(i * M_PI / 180)));
		line();
					}
					printf("\nProgramm will try again, if you wish give up, press Ctrl C\n");
				}
				else{
					errMsg("Such step doesnt correspond to limits");
				}
			}
		}
		printf("\nAnd now moving to the beggining")
	}
}