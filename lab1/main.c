#include <stdio.h>
#include <conio.h>

char term;


int roman(int i, int j, char c){
	while (i >= j) {
		putchar(c);
		i = i-j;
		//printf("%d\n", i);
	}

	return(i);
}

main() {
	int a;

	printf("ENTER NUMBER\n");
	scanf("%d", &a);

	/*if(scanf("%d%c", &a, &term) != 2 || term != '\n'){
	    printf("Input error!\n");
	    return 0;
	}*/

	//printf("%d\n\n", a);

	if(!(a>0)){                    //чому не a<0 ?
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