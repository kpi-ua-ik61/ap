int inputInt(int *value, char* request){
	int inpcheck = 0;
	char term;

	do{
		printf("%s: ", request);
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
		printf("%s: ", request);
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
		printf("%s: ", request);

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
		printf("%s: ", request);

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