#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()



float side_A, side_B, side_C;//Стороны треугольника
float per, halfper;//Периметр и полпериметр
double S;//Площадь
double ht_to_A, ht_to_B, ht_to_C;//Высоты
float medi_to_A, medi_to_B, medi_to_C;//Медианы
double bisectr_to_A, bisectr_to_B, bisectr_to_C; //Бисектрисы


int main()
{
	side_checker(); /* Это заюзать функцию, вроде */
	rule_checker(); // Проверка правил существования треугольников
	calculations(); // А это заюзает подсчёты
}


void side_checker()   /* Чек сторон */
{
	// Side_A 
	printf("\n Enter any positive number for your side A:  ");
	scanf("%f",&side_A);

	// Side_B
	printf("\n Enter any positive number for your side B:  ");
	scanf("%f",&side_B);

	// Side C
	printf("\n Enter any positive number for your side C:  ");
	scanf("%f",&side_C);

	if((side_A < 0)||(side_B < 0)||(side_C <0))
	{
		wrong();
	}
}

void rule_checker()
{
	if(!((side_A+side_B) > side_C && (side_A+side_C) > side_B && (side_B+side_C) > side_A))
	{
		printf("\nThat triangle does not exist!\nExiting programm");
		exit(0);
	}
	
}

void calculations() //Подсчёты 
{
	
	per = side_A+side_B+side_C; //Периметр
	printf("\n Perimeter: %f", per); //%f Юзает значения которые за скобочками (полезно)
	
	halfper = per/2; //Половина периметра
	printf("\n Half Perimeter: %f", halfper);

	S = (sqrt(halfper*(halfper-side_A)*(halfper-side_B)*(halfper-side_C))); //Должна быть площадь
	printf("\n Area: %f \n", S);

	//Heights
	ht_to_A = ((S*2)/side_A); //Высота к А
	printf("\n Height to side A: %f", ht_to_A);
	ht_to_B = ((S*2)/side_B); // H to B
	printf("\n Height to side B: %f", ht_to_B);
	ht_to_C = ((S*2)/side_C); // H to C
	printf("\n Height to side C: %f\n", ht_to_C);

	//Medians
	medi_to_A = (sqrt((2*(side_B*side_B))+(2*(side_C*side_C))-(side_A*side_A))*0.5);//Медиана к А
	printf("\n Median to side A: %f", medi_to_A);
	medi_to_B = (sqrt((2*(side_A*side_A))+(2*(side_C*side_C))-(side_B*side_B))*0.5);
	printf("\n Median to side B: %f", medi_to_B);
	medi_to_C = (sqrt((2*(side_A*side_A))+(2*(side_B*side_B))-(side_C*side_C))*0.5);
	printf("\n Median to side C: %f\n", medi_to_C);

	//Bisectors
	bisectr_to_A = (((sqrt((side_B*side_C*halfper)*(halfper-side_A)))*2)/(side_B+side_C));//Бисектриса к А
	printf("\n Bisectr to side A: %f", bisectr_to_A);
	bisectr_to_B = (((sqrt((side_A*side_C*halfper)*(halfper-side_B)))*2)/(side_A+side_C));
	printf("\n Bisectr to side B: %f", bisectr_to_B);
	bisectr_to_C = (((sqrt((side_A*side_B*halfper)*(halfper-side_C)))*2)/(side_A+side_B));
	printf("\n Bisectr to side C: %f\n", bisectr_to_C);
}


void wrong()
{
	printf("\nWrong input!!!\n Enter only positive numbers\n Exiting programm\n");
	exit(0);
}
