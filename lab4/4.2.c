#include <stdio.h>
#include <conio.h>

int j, k, s, a, b;

void choosing (void)
{
	char temp;
	int te;

	do
	{
		k=0;
		printf("\nChoose an order of sorting [A/D] (A for ascending and D for descending)\n");
		temp=getch();
		te=temp;
		if ((te==97)||(te==65)) {k=1;}
		if ((te==100)||(te==68)) {k=(-1);}
		if ((k!=(-1))&&(k!=1))
		{
			printf("Enter A (ascending) or D (descending).\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);
}

void sortinga (float *arr)
{
	float da;
	for (a=0; a<s-1; a++)
	{
		for (b=a+1; b<s; b++)
		{
			if (arr[a]>arr[b])
			{
				da=arr[a];
				arr[a]=arr[b];
				arr[b]=da;
			}
		}
	}
}

void sortingd (float *arr)
{
	float dd;
	for (a=0; a<s-1; a++)
	{
		for (b=a+1; b<s; b++)
		{
			if (arr[a]<arr[b])
			{
				dd=arr[a];
				arr[a]=arr[b];
				arr[b]=dd;
			}
		}
	}
}

void calculations (void)
{
	char c;
	int n, m, l;
	
	printf("\nEnter size of array and array and choose order of sorting\n");

	do
	{
		printf("\nEnter size of array: ");
		if ((scanf("%d%c", &s, &c)!=2)||(c!='\n')||(s<=0)||(s>32767))
		{
			printf("Enter only natural numbers from 1 to 32767.\n");
			fflush(stdin);
			j=0;
		}
		else (j=1);
	}
	while (j!=1);

	float array[s];

	for (n=0; n<s; n++)
	{		
		do
		{
			printf("Enter element #%d: ", n+1);
			if ((scanf("%f%c", &array[n], &c)!=2)||(c!='\n')||(array[n]>3.4e38)||(array[n]<(-3.4e38)))
			{
				printf("Enter only numbers from -3.4e38 to 3.4e38.\n");
				fflush(stdin);
				j=0;
			}
			else {(j=1);}
		}
		while (j!=1);
	}

	printf("\nYour array:\n");
	for (l=0; l<s; l++)
	{
		printf("%g\n", array[l]);
	}

	choosing();
	if (k==1) {sortinga(array);}
	if (k==(-1)) {sortingd(array);}
	printf("\nSorted array: \n");
	for (m=0; m<s; m++)
	{
		printf("%g\n", array[m]);
	}
}

int main(void)
{
	char tmp;
	int t, i;
	do
	{
		calculations();
		do
		{
			i=0;
			printf("\nDo you want to try again? [Y/N]\n");
			tmp=getch();
			t=tmp;
			if ((t==121)||(t==89)) {i=1;}
			if ((t==110)||(t==78)) {i=(-1);}
			if ((i!=(-1))&&(i!=1))
			{
				printf("Enter Y (Yes) or N (No).\n");
				fflush(stdin);
				j=0;
			}
			else (j=1);
		}
		while (j!=1);
	}
	while (i!=(-1));

	return 0;
}