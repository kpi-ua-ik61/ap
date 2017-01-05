#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#include "../lib/inputlib.h"
#include "../lib/rand.h"

#define BLACK 	"\033[0;30m"
#define RED 	"\033[0;31m"
#define GREEN 	"\033[0;32m"
#define ORANGE 	"\033[0;33m"
#define BLUE 	"\033[0;34m"
#define PURPLE 	"\033[0;35m"
#define CYAN 	"\033[0;36m"
#define LGRAY 	"\033[0;37m"

#define DGRAY 	"\033[1;30m"
#define LRED 	"\033[1;31m"
#define LGREEN 	"\033[1;32m"
#define YELLOW 	"\033[1;33m"
#define LBLUE 	"\033[1;34m"
#define LPURPLE	"\033[1;35m"
#define LCYAN 	"\033[1;36m"
#define WHITE 	"\033[1;37m"

#define NC 		"\033[0m"

// Black        0;30     Dark Gray     1;30
// Red          0;31     Light Red     1;31
// Green        0;32     Light Green   1;32
// Brown/Orange 0;33     Yellow        1;33
// Blue         0;34     Light Blue    1;34
// Purple       0;35     Light Purple  1;35
// Cyan         0;36     Light Cyan    1;36
// Light Gray   0;37     White         1;37

// +++ Create file
// +++ Open file
// +++ Close file
// +++ Delete file

// +++ logic
// +++ Read file
// +++ empty handle

// +++ Create record
// +++ Read record
// +++ Edit record
// +++ Sort records
// +++ Insert record
// +++ Delete record

// 13/13

// fopen(filename, mode)
// r - read
// w - write
// b - binary
// ? t - text
// x - after w, fail if the file exists

int file_open = 0;

FILE *fp;
char filename[127] = " ";

struct record{
	char data[100]; 
	double a;
	double b;
};

int check_empty() {
	fseek(fp, 0L, SEEK_END);
	if(ftell(fp) == 0) return 1;
	else return 0;
}

int read_file() {
	int i = 1;
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	struct record *rec = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);

	printf("File %s contains %lld record(s)\n", filename, ent_count);

	while (cur_pos < end_pos/* + sizeof(struct record)*/)
	{
		fread(rec, sizeof(struct record), 1, fp);
		fgetpos(fp, &cur_pos);
		printf("| %d	| %s 	| %f 	| %f 	|\n", i, rec->data, rec->a, rec->b);
		i++;
	}

	getch();

	return 0;
}

int create_file() {

	printf("Enter file name: ");
	scanf("%s", filename);
	fflush(stdin);
	
	if ((fp=fopen(filename, "rb")) != NULL) {
		printf(LRED"Error"NC " Such file already exists!\n");
		getch();
		return 0;
	}

	if ((fp=fopen(filename, "wb")) == NULL) {
		printf(LRED"Error"NC " Unable to create file! Such file already exists!\n");
		getch();     // exit(0);
		return 0;
	}

	if ((fp=fopen(filename, "r+wb")) == NULL) {
		printf(LRED"Error"NC " Unable to create file! Such file already exists!\n");
		getch();
		return 0;
	}

	printf("Empty file "LGREEN"%s"NC" created!\n", filename);

	if(returnBoolInt("Open this file? [y/n]: ") == 1){
		file_open = 1;
		read_file();
	}
	else {
		if (fclose(fp)) {
			printf("\n" LRED"Error"NC " Error while closing file!\n");
			getch();
			return 0;
		}
	}

	return 0;
}

int open_file() {
	// printf("If file does not exist, program will create file and open it\n");
	printf("Enter file name to open: ");
	scanf("%s", filename);
	fflush(stdin);

	if ((fp=fopen(filename, "r+wb")) == NULL) {
		printf(LRED"Error"NC " Unable to open file! File does not exist!\n");
		getch();     // exit(0);
		return 0;
	}

	file_open = 1;
	read_file();
	return 0;
}

int remove_file() {

	printf("Enter file name to delete: ");
	scanf("%s", filename);
	fflush(stdin);

	fclose(fp);

	if (remove(filename))
	{
		printf(LRED"Error"NC " Unable to delete file! Such file doesn't exists!\n");
		getch();
		return 0;
	}
	else
		printf("File "LGREEN"%s"NC" deleted!\n", filename);
		getch();

	return 0;
}

int close_file() {
	if (fclose(fp)) {
		printf("\n" LRED"Error"NC " Error while closing file!\n");
		getch();
		return 0;
	}
	file_open = 0;
	return 0;
}


int create_record() {
	char new[100];

	fseek(fp, 0L, SEEK_END);

	printf("Enter string: ");
	scanf(" %s", new);
	struct record *tmp = malloc(sizeof(struct record));
	strcpy(tmp->data, new);
	tmp->a = returnInputDouble("Enter double 1: ");
	tmp->b = returnInputDouble("Enter double 2: ");
	fwrite(tmp, sizeof(struct record), 1, fp);

	printf(LGREEN"Record created!\n"NC);
	getch();
	return 0;
}

int read_record() {
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *ret = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter record number to show: ", 1, ent_count);
	fseek(fp, sizeof(struct record) * (num-1), SEEK_SET);
	fread(ret, sizeof(struct record), 1, fp);
	printf("| %s 	| %f 	| %f 	|\n", ret->data, ret->a, ret->b);
	
	getch();
	return 0;
}

int edit_record() {
	char new[100];
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *tmp = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter record number to edit: ", 1, ent_count);

	fseek(fp, sizeof(struct record) * (num-1), SEEK_SET);
	fread(tmp, sizeof(struct record), 1, fp);
	printf("| %s 	| %f 	| %f 	|\n", tmp->data, tmp->a, tmp->b);

	printf("Enter new string: ");
	scanf(" %s", new);
	strcpy(tmp->data, new);
	tmp->a = returnInputDouble("Enter new double 1: ");
	tmp->b = returnInputDouble("Enter new double 2: ");

	fseek(fp, sizeof(struct record) * (num-1), SEEK_SET);
	fwrite(tmp, sizeof(struct record), 1, fp);

	printf(LGREEN"Record edited!\n"NC);
	getch();
	return 0;
}

int sort_record() {
	long long cur_pos;
	long long end_pos;
	long long ent_count;

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);

	if(ent_count < 2){
		printf(LRED"Error"NC" You should have 2+ records to sort!\n");
		getch();
		return 0;
	}
	printf("Sort records of double1\n");
	if(returnADInt("Sort ascending/descending [a/d]: ") == 1){
		// asc

		for(int a = 0; a < ent_count-1; a++){
			for(int b = a+1; b < ent_count; b++){
				struct record *olda = malloc(sizeof(struct record));
				struct record *oldb = malloc(sizeof(struct record));

				fseek(fp, sizeof(struct record) * a, SEEK_SET);
				fread(olda, sizeof(struct record), 1, fp);
				
				fseek(fp, sizeof(struct record) * b, SEEK_SET);
				fread(oldb, sizeof(struct record), 1, fp);
			
				double av = olda->a;
				double bv = oldb->a;

				if(av > bv){ 

					fseek(fp, sizeof(struct record) * a, SEEK_SET);			// a = b
					fwrite(oldb, sizeof(struct record), 1, fp);

					fseek(fp, sizeof(struct record) * b, SEEK_SET);			// b = a
					fwrite(olda, sizeof(struct record), 1, fp);
				}
			}
		}
	}
	else{
		for(int a = 0; a < ent_count-1; a++){
			for(int b = a+1; b < ent_count; b++){
				struct record *olda = malloc(sizeof(struct record));
				struct record *oldb = malloc(sizeof(struct record));

				fseek(fp, sizeof(struct record) * a, SEEK_SET);
				fread(olda, sizeof(struct record), 1, fp);
				
				fseek(fp, sizeof(struct record) * b, SEEK_SET);
				fread(oldb, sizeof(struct record), 1, fp);
			
				double av = olda->a;
				double bv = oldb->a;

				if(av < bv){ 

					fseek(fp, sizeof(struct record) * a, SEEK_SET);			// a = b
					fwrite(oldb, sizeof(struct record), 1, fp);

					fseek(fp, sizeof(struct record) * b, SEEK_SET);			// b = a
					fwrite(olda, sizeof(struct record), 1, fp);
				}
			}
		}
	}

	printf(LGREEN"Records sorted!\n"NC);
	read_file();
	return 0;
}

int insert_record() {
	char new[100];
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *rec = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter where to insert: ", 1, ent_count);

	printf("Enter string: ");
	scanf(" %s", new);
	struct record *tmp = malloc(sizeof(struct record));
	strcpy(tmp->data, new);
	tmp->a = returnInputDouble("Enter double 1: ");
	tmp->b = returnInputDouble("Enter double 2: ");

	for(int i = 1; i <= ent_count-num+2; i++){
		fseek(fp, sizeof(struct record) * -i, SEEK_END);  
		fread(rec, sizeof(struct record), 1, fp);
		
		fseek(fp, sizeof(struct record) * 0, SEEK_CUR);
		fwrite(rec, sizeof(struct record), 1, fp);

		// read_file();
	}

	fseek(fp, sizeof(struct record) * (num - 1), SEEK_SET);
	fwrite(tmp, sizeof(struct record), 1, fp);

	printf(LGREEN"Record inserted!\n"NC);
	if(returnBoolInt("Sort records? [y/n]: ")) sort_record();
	getch();

	return 0;
}

int delete_record() {
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *rec = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter record number to delete: ", 1, ent_count);
	
	FILE *ptr2 = fopen("temp","a");
	int foo = 0;


	for(int i = 1; i <= ent_count; i++){
		fread(rec, sizeof(struct record), 1, fp);

		if(i != num) fwrite(rec, sizeof(struct record), 1, ptr2);
		// printf("%d\n", i);
	}

	fclose(fp);
	fclose(ptr2);
	remove(filename);
	rename("temp", filename);
	fp = fopen(filename, "r+b");

	printf(LGREEN"Record deleted!\n"NC);
	getch();
	return 0;
}

int file_menu(){
	system("cls");


	printf("------  File  ------\n\n");

	printf("[1] Create new file\n");
	printf("[2] Open file\n");
	printf("[3] Delete file\n");
	printf("\n");
	printf("[0] Exit\n");


	int check = 1;

	do{
		printf("\nType option: ");
		int option;
		scanf("%d", &option);

		switch(option){
			case 1:	create_file();
					check = 0;
					break;
			case 2:	open_file();
					check = 0;
					break;
			case 3:	remove_file();
					check = 0;
					break;
			case 0:	exit(0);
					check = 0;
					break;
			default: printf(LRED"\nInvalid option!\n"NC);
		}
		fflush(stdin);
	}
	while(check == 1);

	return 0;
}

int edit_menu(){
	system("cls");


	printf("------  Edit  ------\n\n");

	printf("[1] Create new record\n");

	if(check_empty()) printf(ORANGE);

	printf("[2] Read record\n");
	printf("[3] Read all records\n");
	printf("[4] Edit record\n");
	printf("[5] Sort record\n");
	printf("[6] Insert record\n");
	printf("[7] Delete record\n");
	printf(NC);

	printf("\n");
	printf("[9] Close file\n");
	printf("[0] Close file & exit\n");


	int check = 1;

	do{
		printf("\nType option: ");
		int option;
		scanf("%d", &option);

		if(check_empty()) {
			switch(option){
				case 1:	create_record();
						check = 0;
						break;
				case 2:	break;
				case 3:	break;
				case 4:	break;
				case 5:	break;
				case 6:	break;
				case 7:	break;
				case 9:	close_file();
						check = 0;
						break;
				case 0:	close_file();
						exit(0);
						check = 0;
						break;
				default: printf(LRED"\nInvalid option!\n"NC);
			}
		}
		else {
			switch(option){
				case 1:	create_record();
						check = 0;
						break;
				case 2:	read_record();
						check = 0;
						break;
				case 3:	read_file();
						check = 0;
						break;
				case 4:	edit_record();
						check = 0;
						break;
				case 5:	sort_record();
						check = 0;
						break;
				case 6:	insert_record();
						check = 0;
						break;
				case 7:	delete_record();
						check = 0;
						break;
				case 9:	close_file();
						check = 0;
						break;
				case 0:	close_file();
						exit(0);
						check = 0;
						break;
				default: printf(LRED"\nInvalid option!\n"NC);
			}
		}
		fflush(stdin);
	}
	while(check == 1);

	return 0;
}

int main() {

	while(1){
		if(file_open == 1){
			edit_menu();
		}
		else{
			file_menu();
		}
	}

	return 0;
}
