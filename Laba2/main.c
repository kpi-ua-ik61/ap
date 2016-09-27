#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) { //Этому errorMsg будет присваиваться сообщение которое я пропишу при вызове
	printf("\n %s \n ", errorMsg);//Нить, если быть точнее
	exit(0);
}

void showCalculations(float side_A, float side_B, float side_C) { //Стороны там, потому что они принимаються из других функций 
	//Показать подсчёты
    float   per, halfper;//Периметр и полпериметр
    double  S;//Площадь
    double  ht_to_A, ht_to_B, ht_to_C;//Высоты
    float   medi_to_A, medi_to_B, medi_to_C;//Медианы
    double  bisectr_to_A, bisectr_to_B, bisectr_to_C; //Бисектрисы

	per = side_A + side_B + side_C; //Периметр
	printf("\n Perimeter: %f", per); //%f Юзает значения которые за скобочками (полезно)

	halfper = per/2; //Половина периметра
	printf("\n Half Perimeter: %f", halfper);

	S = (sqrt(halfper * (halfper - side_A) * (halfper - side_B) * (halfper - side_C))); //Должна быть площадь
	printf("\n Area: %f \n", S);

	//Heights
	ht_to_A = ((S * 2) / side_A); //Высота к А
	printf("\n Height to side A: %f", ht_to_A);
	ht_to_B = ((S * 2) / side_B); // H to B
	printf("\n Height to side B: %f", ht_to_B);
	ht_to_C = ((S * 2) / side_C); // H to C
	printf("\n Height to side C: %f\n", ht_to_C);

	//Medians
	medi_to_A = (sqrt((2 * (side_B * side_B)) + (2 * (side_C * side_C)) - (side_A * side_A)) * 0.5);//Медиана к А
	printf("\n Median to side A: %f", medi_to_A);
	medi_to_B = (sqrt((2 * (side_A * side_A)) + (2 * (side_C * side_C)) - (side_B * side_B)) * 0.5);
	printf("\n Median to side B: %f", medi_to_B);
	medi_to_C = (sqrt((2 * (side_A * side_A)) + (2 * (side_B * side_B)) - (side_C * side_C)) * 0.5);
	printf("\n Median to side C: %f\n", medi_to_C);

	//Bisectors
	bisectr_to_A = (((sqrt((side_B * side_C * halfper) * (halfper - side_A))) * 2)/(side_B + side_C));//Бисектриса к А
	printf("\n Bisectr to side A: %f", bisectr_to_A);
	bisectr_to_B = (((sqrt((side_A * side_C * halfper) * (halfper - side_B))) * 2)/(side_A + side_C));
	printf("\n Bisectr to side B: %f", bisectr_to_B);
	bisectr_to_C = (((sqrt((side_A * side_B * halfper) * (halfper - side_C))) * 2)/(side_A + side_B));
	printf("\n Bisectr to side C: %f\n", bisectr_to_C);
}

float prompt(char* str) { //Под str имею ввиду string
    char enter; //ENTER, а если точнее то terminate строка (\n)
    float result;//Ну тут и так понятно

    printf("\n %s", str); //%s <- это string (нить)
    if (scanf("%f%c", &result, &enter) != 2 || enter != '\n'){
    	error("You cannot enter symbols");
    }

    if (result < 0) {
        error("Your side cannot be lesser than 0");
    }

    if (result == 0) {
        error("Your side cannot be 0");
    }

    return result; // Теперь результат этой функции будет присвоен той стороне которой нужно
}

int main() {
    float side_A = prompt("Enter any positive number for your side A:"); //Внутренности этого prompt, будут присвоены str
    float side_B = prompt("Enter any positive number for your side B:"); //Тоесть класная такая нить будет
    float side_C = prompt("Enter any positive number for your side C:");

    printf("\n Triangle A: %f B: %f C: %f \n", side_A, side_B, side_C); //%f <- это формат

    if(!((side_A+side_B) > side_C && (side_A+side_C) > side_B && (side_B+side_C) > side_A)) { //Ну это правила существования треугольника
		error("That triangle does not exist!");
	}

    showCalculations(side_A, side_B, side_C); //А тут стороны так прописаны потому-что отдаются в функцию 
}
