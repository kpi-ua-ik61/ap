#include <curses.h> // the curse of Linuxoid
#include <stdio.h> // standart lib
#include <math.h> //  "I've got the POWaaar!!" 
#include <stdlib.h> // still exit
#include <string.h>

void error(char* errorMsg) // Error printer at the end of the proga 
{
	printf("\n %s \nExiting program\n ", errorMsg);
	exit(0);
}

float checker(char* str)
{
	float CkResult;
	char enter;

	printf("\n%s", str);
	if (scanf("%f%c", &CkResult, &enter) != 2 || enter != '\n'){
		error("You cannot enter symbols!");
	}
	if (CkResult == 0){
		error("Your number cannot be 0");
	}
	if (0 < CkResult && CkResult < 1 ){
		error("Your number cannot be lesser than 1, and bigger than 0");
	}	
	return (CkResult);
}

float toPow(float val, int power) 
{
	for (int i = power; i > 1; i--){
		val *= val;
	}
}
float IterFunc(float numX, float rootK, float trueEps) //Итерационная формула, чёто сложное
{
	float Beta = 1;
	float curNumY = 1; //Current NumY

	while (fabsf(Beta) >= trueEps) {
		Beta = ((1 / rootK) * ((numX / (toPow(curNumY, rootK - 1)) - curNumY)));
		curNumY = (curNumY + Beta);
	}
		return (curNumY);

}
float translator(float preE)
{
	float cntrl = 1, trueEps = 1;
	while(!(preE == (cntrl - 1)))  {
		trueEps = (trueEps / 10);
		cntrl = (cntrl + 1);
	}
	return (trueEps);
}
void resulter(float presiceE, float resultY) //Функция для вывода точного результата
{
   char num[20], dest[50], dest2[50];
   
   sprintf(num, "%.0f", presiceE); //Невидимый принтф, который не притнф вовсем, он как я понял, запоминает, то что нужно будет вставить в принтф
   strcpy(dest, "\nAnd the result is: %."); // Стринг создать, создает строку dest 
   strcat(dest, num); //Стринг дополнить, а это уже дополняет созданый 	dest
   strcat(dest, "f \n");
   printf(dest, resultY); //То что склеено, то оно вставленно в принтф и готово печататься
}
int main()
{

		float numX = checker("Enter your number that you wish to check: "); //Собственно процесс проверки
		float rootK = checker("Enter your power of roots: ");
		float presiceE = checker("Enter how many numbers after koma do you wish to see \n  This program can support from 1 to 6 nums \nThat means that you must choose wisely\n ");
		float trueEps = translator(presiceE);
		printf("You have entered theese nums: \nX: %f, K: %f, E: %f, trueEps: %f \n", numX, rootK, presiceE, trueEps); //Это надо будет потом убрать
		float resultY = IterFunc(numX, rootK, trueEps); //Функция, которая Вычисляет результат, и заодно его и присваивает
		resulter(presiceE, resultY); //Ну а это Ресультатор, который пилит результат, большой точности
		
		/*printf("If you wish to restart a program, type ' R '\n else will close the program\n");
		char input;
		if((scanf("%c", &input) == "R" && "r")){
			exit(0);
		}*/	
}	



