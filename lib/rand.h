#include <time.h>

int randInit(){
	srand(time(0));
	return 0;
}

int randInt(int min, int max){
	int num = min + (rand() % (max+1-min));
	int sign = rand() % 2; 
	if(min < 0 && sign) num *= -1;
	return num;
}

float randFloat(/*float min, float max*/){
	//float num = ((float)rand()/(float)(RAND_MAX)) * max + min;

	float num = ((float)rand()/(float)(RAND_MAX)) * 100;

	int sign = rand() % 2;
	if(sign) num *= -1;

	return num;
}

float randPosFloat(){
	float num = ((float)rand()/(float)(RAND_MAX)) * 100;
	return num;
}