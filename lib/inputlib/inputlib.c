int inputInt(int *value, char* request){
	int inpcheck = 0;
	char term;

	do{
		printf("%s", request);
		scanf("%d%c", value, &term);

		if ( term != '\n') {
			printf("Please enter an integer number\n");
			printf("Try again or press Ctrl+C to exit\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;

	}
	while (!inpcheck);

	return 0;
}

int returnInputInt(char* request){
	int inpcheck = 0;
	char term;
	int value;

	do{
		printf("%s", request);
		scanf("%d%c", &value, &term);

		if ( term != '\n') {
			printf("Please enter an integer number\n");
			printf("Try again or press Ctrl+C to exit\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;

	}
	while (!inpcheck);

	return value;
}

int inputFloat(float *value, char* request){
	int inpcheck = 0;
	char term;

	do{
		printf("%s", request);

		scanf("%f%c", value, &term);
		if ( term != '\n') {        // || &value / &value != 1
			printf("Please enter a float number\n");
			printf("Try again or press Ctrl+C to exit\n\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;
	}
	while (!inpcheck);

	return 0;
}

float returnInputFloat(char* request){
	int inpcheck = 0;
	char term;
	float value;

	do{
		printf("%s", request);

		scanf("%f%c", &value, &term);
		if ( term != '\n') {        // || &value / &value != 1
			printf("Please enter a float number\n");
			printf("Try again or press Ctrl+C to exit\n\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;
	}
	while (!inpcheck);

	return value;
}

int returnEps(){
	int inpcheck = 0;
	char term;
	int eps;

	do{
		printf("precision: ");

		scanf("%d%c", &eps, &term);
		if ( term != '\n' || eps < 0 || eps > 6 ) {
			printf("Input error, e must be an integer number, 0 < e <= 6\n");
			printf("Try again or press Ctrl+C to exit\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;
	}
	while (!inpcheck);

	return eps;
}

float returnPrecision(int eps){
	float precision = 1;

	for (int i = 0; i < eps; i++)	{
		precision *= 0.1;
	}

	return precision;
}

int randInt(int min, int max){
	int num = min + (rand() % max+1-min);
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
