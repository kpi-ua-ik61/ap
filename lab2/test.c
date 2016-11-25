#include <stdio.h>

float num;
char term;

int main(){
	printf("Enter a number: \n");
	if(scanf("%f%c", &num, &term) != 2 || term != '\n'){
	    printf("failure\n");
	}
	else{
		printf("valid integer followed by enter key\n");
	}
}
