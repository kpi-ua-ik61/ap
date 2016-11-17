#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int a, b, nums, numc, j, k;

void choosing(void) {
	char temp;
	int t;

	do {
		k = 0;
		printf("\nChoose an order of sorting [A/D] (A for ascending and D for descending)\n");
		temp = getch();
		t = temp;
		if ((t == 97) || (t == 65)) {
			k = 1;
		}
		if ((t == 100) || (t == 68)) {
			k = (-1);
		}
		if ((k != (-1)) && (k != 1)) {
			printf("Enter A (ascending) or D (descending).\n");
			fflush(stdin);
			j = 0;
		}
		else {
			j = 1;
		}
	} while (j != 1);
}

void sortinga(char **st) {
	char *tstr;
	for (a = 0; a < (nums - 1); a++) {
		for (b = (a + 1); b < nums; b++) {
			if (strcmp(st[a], st[b]) > 0) {
				tstr = st[a];
				st[a] = st[b];
				st[b] = tstr;
			}
		}
	}
}

void sortingd(char **st) {
	char *tstr;
	for (a = 0; a < (nums - 1); a++) {
		for (b = (a + 1); b < nums; b++) {
			if (strcmp(st[a], st[b]) < 0) {
				tstr = st[a];
				st[a] = st[b];
				st[b] = tstr;
			}
		}
	}
}

void function(void) {
	char **str, symbol;

	printf("\nEnter nuber of strings and symbols, enter strings and choose order of sorting\n");

	do {
		printf("\nEnter number of strings: ");
		if ((scanf("%d%c", &nums, &symbol) != 2) || (symbol != '\n') || (nums <= 0) || (nums > 32767)) {
			printf("Enter only natural numbers from 1 to 32767.\n");
			fflush(stdin);
			j = 0;
		} else {
			j = 1;
		}
	} while(j != 1);

	do {
		printf("\nEnter number of symbols: ");
		if ((scanf("%d%c", &numc, &symbol) != 2) || (symbol != '\n') || (numc <= 0) || (numc > 32767)) {
			printf("Enter only natural numbers from 1 to 32767.\n");
			fflush(stdin);
			j = 0;
		} else {
			j = 1;
		}
	} while(j != 1);

	str = (char**)calloc(nums, sizeof(char*));
	for (a = 0; a < nums; a++) {
		str[a] = (char*)calloc(numc+1, sizeof(char));
	}

	printf("\n");

	for (a = 0; a < nums; a++) {
		printf("Enter line #%d: ", a + 1);
		for (b = 0; b < numc; b++) {
			do {
				str[a][b] = getch();
				if (str[a][b] < 32) {
					printf("\nIncorrect symbol. Continue: ");
					if (str[a][b] < 1) {
						symbol = getch();
					}
					j = 0;
				} else {
					j = 1;
				}
			} while(j != 1);
			printf("%c", str[a][b]);
			if (b == (numc - 1)) {
				printf("\n");
			}
		}
		fflush(stdin);
		str[a][b] = '\0';
	}

	printf("\nYour lines:\n");
	for (a = 0; a < nums; a++) {
		for (b = 0; b < numc; b++) {
			printf("%c", str[a][b]);
		}
		printf("\n");
	}

	choosing();
	if (k == 1) {
		sortinga(str);
	}
	if (k == (-1)) {
		sortingd(str);
	}

	printf("\nSorted lines:\n");
	for (a = 0; a < nums; a++) {
		for (b = 0; b < numc; b++) {
			printf("%c", str[a][b]);
		}
		printf("\n");
	}

	for (a = 0; a < nums; a++) {
		free(str[a]);
	}
	free(str);

}

int main(void) {
	char temp;
	int t, i;
	do {
		function();
		do {
			i = 0;
			printf("\nDo you want to try again? [Y/N]\n");
			temp = getch();
			t = temp;
			if ((t == 121) || (t == 89)) {
				i = 1;
			}
			if ((t == 110) || (t == 78)) {
				i = (-1);
			}
			if ((i != (-1)) && (i != 1)) {
				printf("Enter Y (Yes) or N (No).\n");
				fflush(stdin);
				j = 0;
			} else {
				j = 1;
			}
		} while (j != 1);
	} while (i != (-1));

	return 0;
}
