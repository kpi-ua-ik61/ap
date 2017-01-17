//Lab3,1_v2.c Updated logic
#include <curses.h> // the curse of Linuxoid
#include <stdio.h> // standart lib
#include <math.h> //  "I've got the POWaaar!!" 
#include <stdlib.h> // still exit
#include <string.h>

void error(char* errorMsg) // Error printer at the end of the proga 
{
	printf("\nERROR\n %s \nExiting program\n ", errorMsg);
	exit(0);
}

float checker(char* str) //Та тема которая проверяет ввод на ошибки 
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
	/*if (0 < CkResult && CkResult < 1 ){
		error("Your number cannot be lesser than 1, and bigger than 0\nThat because current formula cannot calculate it");
	}*/
	return (CkResult);
}
void AllInputChecker(float nmX, int rtK){
	bool even_rtK;
	if((rtK / 2) * 2 == rtK){ even_rtK = true; }
	else { even_rtK = false; }
	if ((rtK > 0) && (even_rtK == true) && (nmX < 0)){
		error("When your root is an even number\nyour number X cannot be lesser than 0");
	}
	if ((rtK < 0) && (even_rtK == true) && (nmX <= 0)){
		error("When your root is an even number\nyour number X cannot be lesser than 0");
	}
}

float toPow(float val, int power) 
{
	for (int i = power; i > 1; i--){
		val *= val;
	}
}
float root(float numX, float rootK, float trueEps) //Итерационная формула, чёто сложное
{
	float Beta = 1;
	float curNumY = 1; //Current NumY

	while (fabsf(Beta) >= trueEps) {
		Beta = ((1 / (rootK)) * ((((numX) / (toPow(curNumY, rootK - 1))) - (curNumY))));
		curNumY = ((curNumY) + (Beta));
	}
		return (curNumY);
	if(rootK < 0){
		float funcResultY = (1 / toPow((numX), 1/fabsf(rootK)));
		printf (" from root %f", funcResultY);
		return (funcResultY);
	}
	else{
		float funcResultY = (toPow((numX), 1/rootK));
		printf (" from root %f", funcResultY);
		return (funcResultY);
	}
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
   char num[20], dest[50];
   
   sprintf(num, "%.0f", presiceE); //Невидимый принтф, который не притнф вовсем, он как я понял, запоминает, то что нужно будет вставить в принтф
   strcpy(dest, "\nAnd the result is: %."); // Стринг создать, создает строку dest <--так и должно быть!!! 
   strcat(dest, num); //Стринг дополнить, а это уже дополняет созданый 	dest
   strcat(dest, "f \n");
   printf(dest, resultY); //То что склеено, то оно вставленно в принтф и готово печататься
}
int main()
{

	float numX = checker("Enter your number that you wish to check: "); //Собственно процесс проверки
	int rootK = checker("Enter your power of roots: ");
	int presiceE = checker("Enter how many numbers after koma do you wish to see \n  This program can support accuracy of calculations from 1 to 6 numbers after coma \nThat means that you must choose wisely\n ");
	if((1 > presiceE) && (presiceE > 6)){
		error("Float only have 6 nums after koma, so enter integers from 1 to 6");
		}

	AllInputChecker(numX, rootK); //Проверочки

	float trueEps = translator(presiceE);
	printf("You have entered theese nums: \nX: %f, K: %i, Eps: %f \n", numX, rootK, presiceE); //Это надо будет потом убрать
	float resultY = root(numX, rootK, trueEps); //Функция, которая Вычисляет результат, и заодно его и присваивает
	printf (" from main %f", resultY);
	resulter(presiceE, resultY); //Ну а это Ресультатор, который пилит результат, буквально...
	exit(0);
}	