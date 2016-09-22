#include <stdio.h>
#include <curses.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char input_buffer[100];

void input_promt_checker();
void zadanie1();
float powerof(float,int);
void zadanie2();
void zadanie3();

int main(){
	while (true){
		printf("Выберите подпрограмму для выполнения.\n");
		printf("Для подтверждения выбора введите номер подпрограммы и нажмите enter.\n");
		printf("Для выхода введите '0' и нажмите enter.\n");
		printf("Итак ваш выбор (0-3) : ");
		scanf("%s", &input_buffer);
		if (strpbrk(input_buffer, forbiden) != NULL){
			printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели текст! Надо ввести число!\n");
		} else {
			if (atof(input_buffer)==0) return 0; else
			if (atof(input_buffer)==1) {printf("\nВыбрана подпрограмма № %d.\n\n", 1);zadanie1();} else
			if (atof(input_buffer)==2) {printf("\nВыбрана подпрограмма № %d.\n\n", 2);zadanie2();} else
			if (atof(input_buffer)==3) {printf("\nВыбрана подпрограмма № %d.\n\n", 3);zadanie3();} else 
			printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Введено неверный номер подпрограммы! Попробуйте ещё раз!\n\n");
		}
	}
}

void zadanie1(){
	//блок ввода данных и их проверка
	float sigma = 1;
	float y = 1;
	float x;
	int k;
	int to;
	bool k_state_zero; //0 если меньше нуля, 1 если больше
	bool k_state_mod2; //0 если парное, 1 если не парное
	printf("Введите аргумент степень и точность вычислений.\n");
	for (int i =0;i<3;i++){
		if (i==0) {
			printf("Введите степень 'k' (Это должно быть целое число и не может равняться нулю!): ");
			scanf("%s", &input_buffer);
			if (strpbrk(input_buffer, forbiden) != NULL){
				printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели текст! Надо ввести число!\n");
				printf("\e[1;31m\e[1mОШ ИБКА!\e[0m Подпрограмма прервана! Причина - неверный ввод.\n\n");
				break;
			} else {
				if (k=0) {
					printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели 0! Надо ввести число не равное нулю!\n");
					break;
				}
				k = atof(input_buffer);
				if (k>0) k_state_zero=1; else k_state_zero=0;
				if ((k%2)==0) k_state_mod2=0; else k_state_mod2=1;
				printf("zero %d, mod2 %d\n", k_state_zero,k_state_mod2);
				printf("k=%d\n", x);
			}
		}
		if (i==1) {
			printf("Исходя из введеной ранее степени, \n");
			//ввод если k парное и меньше нуля
			if (k_state_zero=0&&k_state_mod2=0) {
				printf("Введите аргумент 'х' (Это должно быть число строго больше нуля!): ");
				scanf("%s", &input_buffer);
				if (strpbrk(input_buffer, forbiden) != NULL){
					printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели текст! Надо ввести число!\n");
					printf("\e[1;31m\e[1mОШ ИБКА!\e[0m Подпрограмма прервана! Причина - неверный ввод.\n\n");
					break;
				} else {
					if (x<=0) {
						printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели неверное число! Надо ввести число строго больше нулю!\n");
						break;
					}
					x = atof(input_buffer);
					printf("x=%f\n", x);
				}
			}
			//ввод если k парное и больше нуля
			if (k_state_zero=1&&k_state_mod2=0) {
				printf("Введите аргумент 'х' (Это должно быть число больше или равное нулю!): ");
				scanf("%s", &input_buffer);
				if (strpbrk(input_buffer, forbiden) != NULL){
					printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели текст! Надо ввести число!\n");
					printf("\e[1;31m\e[1mОШ ИБКА!\e[0m Подпрограмма прервана! Причина - неверный ввод.\n\n");
					break;
				} else {
					if (x<0) {
						printf("\n\e[1;31m\e[1mОШ ИБКА!\e[0m Вы ввели отрицательное число! Надо ввести число больше или равное нулю!\n");
						break;
					}
					x = atof(input_buffer);
					printf("x=%f\n", x);
				}
			}
			
		}
		
		//блок ошибки
		//printf("\e[1;31m\e[1mОШ ИБКА!\e[0m Программа прервана.\n");
		//printf("Причина : ____________________________________\n");
	}
	float a = powerof(x,k);
	printf("return %f\n", a);
	//Блок вычислений
	for (sigma=1;sigma<to;sigma++){
		sigma=(1/k)*((x/powerof(y, k-1))-y);
		y = y + sigma;
		printf("%f\n", y);
	}
	//printf("%f\n", y);
	//блок успешного завершения подпрограммы
	//printf("Подпрограмма выполнена!\n\n");

}

float powerof(float number, int powerto){
	int number_o = 1;
	for (int i = 0; i<powerto; i++){
		number_o = number_o * number;
		//printf("number_o %f\n", number_o);
	}
	return number_o;
}

void zadanie2(){
	printf("Подпрограмма выполнена!\n\n");
}

void zadanie3(){
	printf("Подпрограмма выполнена!\n\n");
}

//ввод и его проверка
void input_promt_checker(){
	while (true){
		
	}
	puts("\nВвод верный. Начинаю вычисление...\n");
}