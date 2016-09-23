#include <stdio.h>
#include <conio.h>

int roman(int i, int j, char c)
{
	while (i>=j)
	{
		putchar(c);
		i=i-j;
	}
	return(i);
}
int main(void)
{
	int a;
	char x;
	printf("Enter number.\n");
	scanf("%d%c", &a, &x);
	if ((x!='\n')||(a<=0))
	{
		printf("Enter only natural numbers.\n");
		getch();
		return 0;
	}
	
	a=roman(a, 1000, 'M');
	a=roman(a, 500, 'D');
	a=roman(a, 100, 'C');
	a=roman(a, 50, 'L');
	a=roman(a, 10, 'X');
	a=roman(a, 5, 'V');
	a=roman(a, 1, 'I');
	getch();

	return 0;
}