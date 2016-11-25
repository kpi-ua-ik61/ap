#include <stdio.h>
#include <conio.h>

char term;


int roman(int i, int j, char c){
	while (i >= j) {
		putchar(c);
		i = i-j;
	}

	return(i);
}

int main() {
	int a;

	printf("ENTER NUMBER\n");
	scanf("%d", &a);

	if(a < 0){    
		return 0;
	}



	a = roman(a,1000,'M');



	a = roman(a,500,'D');
	a = roman(a,100,'C');
	a = roman(a,50,'L');
	a = roman(a,10,'X');
	a = roman(a,5,'V');
	a = roman(a,1,'I');




	getch();

	return 0;
}



// 2561

// M  1561
// MM  561

// MM   561
// MMD  61
// MMDL 11
// MMDLX 1
// MMDLXI