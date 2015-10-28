#include <stdio.h>
typedef struct student{
	long roll_number;
	long rank;
	char name[20];
	//char category[1];
	char password[6];		
}student;

typedef struct branch{
	int code;
	char name[20];
}branch;

typedef struct college {
	int code;
	char name[30];
}college;

typedef struct student_choice {
	long roll_number;
	int seq_no;
	int choice_code;
}student_choice;

typedef struct choice {
	char name[20];
	int code[10];
}choice;

