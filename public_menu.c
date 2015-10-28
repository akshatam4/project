#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cap.h"
long login() {
	long rollno;
	char password[10];
	int x;
	struct student st;
	FILE *fp;
	printf("Enter your Roll number and Password\n");
	scanf("%ld %s", &rollno, password);
	fp = fopen("student.dat", "rb");

	if(fp == NULL) {
		perror("\nStudent file could not open.\n");
		return(2);
	}
	while(!feof(fp)) {
		fread(&st, sizeof(st), 1, fp);
		x = strcmp(st.password, password);
		if(st.roll_number == rollno && x == 0) {
			printf("\nWelcome %s\n", st.name);
			fclose(fp);
			return st.roll_number;
		}
	}
	fclose(fp);
	printf("\nInvalid Roll Number or Password . Try again\n");
	return 1;
}
int main() {
int choice, x;
long roll_number;
int round = 1;

while (1) {
	//clrscr();
	//system("clear");
	printf("\n\n\t  CAPS Menu\n");
	printf    ("\t=============\n");

	printf("1 registration\n"
		"2 login\n"
		"3 view seat availability\n"
		"4 choice filling\n"
		"5 view my choices\n"
		"6 cancellation\n"
		"7 view result\n"
		"8 freeze\n"
		"9 list of round1\n"
		"10  list of round2\n"
		"11  list of round3\n"
		"12  list of final round\n"
		"13  Show All Choices\n"
		"0 exit\n");
printf("\nEnter your choice : ");
	scanf("%d", &choice);
	printf("\n");
	switch(choice) {
		case 1 :
			//printf("enter roll number\n");
			//scanf("%d\n", &roll_number);
			registration();
			break;
		case 2 :
			roll_number = login();
			break;
		case 3 :
			college_wise_vacancy(round);
			/*branch_wise_vacancy(1);
			getchar();printf("\nPress a key to continue...");getch();
			break;
		case 4 :
			//printf("enter roll number : \n");
			//scanf("%ld", roll_number);
			choice_filling(roll_number);
			break;
		case 5 :
			view_choice(roll_number);
			getchar();printf("\nPress a key to continue...");getch();
			break;
		
		case 6 :
			cancel_admission(roll_number);
			getchar();printf("\nPress a key to continue...");getch();
			break;
		case 7 :
//			result();
			break;
		case 8 :
			freeze_admission(roll_number);
			break;
		case 9 :
			system("clear");
			system("gedit result_list1.txt");
			break;
		case 10 :
			system("clear");
			system("cat result_list2.txt");
			break;
		case 11 :
			system("clear");
			system("cat result_list3.txt");
			break;
		case 12 :
			system("clear");
			system("cat result_list4.txt");
			break;
		case 13 :
			show_choices();
			getchar();printf("Press a key to continue...");getch();
			break;
		case 0 :
			exit(0);
//			break;*/
	}
}
}

int registration() {
	int x,i;
	char name[15], password[10];
	struct student st, stud;
	printf("enter rollno : ");
	scanf("%ld", &st.roll_number);
	FILE * fp1 = fopen("student.dat","rb");
	if(fp1 == NULL) {
		perror("open failed:");
		return errno;
	}
	fread(&stud, sizeof(stud), 1, fp1);
	while (!feof(fp1)) {
		if (st.roll_number == stud.roll_number){
			printf("Roll No. %ld Already exists",st.roll_number); 
			return(1);
		}
		fread(&stud, sizeof(stud), 1, fp1);
	}
	fclose(fp1);

	printf("\nEnter name : ");
	scanf("%s", st.name);
	printf("\nEnter rank : ");
	scanf("%ld", &st.rank);//get rank

	/*printf("\nEnter category : ");
	getchar();
	scanf("%c", &st.category);//get category*/

	printf("\nEnter password : ");
	scanf("%s", st.password);//get password1
	printf("\nRetype password : ");
	scanf("%s", password);
	x = strcmp(st.password, password);
	if(x != 0) {
		printf("\nMismatch in password\n");
		return 1 ;
	}
/*	//open file append student info		
	FILE *fp2 = fopen("student.dat", "a+b");
	if(fp2 == NULL) {
		perror("Student file could not open:");
		return errno;
	}

	//strcpy(st.eligible, "Y");
	st.eligible = ' ';
	//strcpy(st.admit_status, " ");
	st.admit_status = ' ';
	for (i=0;i<4;i++){
	//	st.alloc_cat[i] = ' ';
	//	st.alloc_code[i] = 0;
	}
/*
	st.alloc1_cat = ' '; //strcpy(st.alloc1_cat, " ");
	st.alloc1_code = 0;
	st.alloc2_cat = ' '; //strcpy(st.alloc2_cat, " ");
	st.alloc2_code = 0;
	st.alloc3_cat = ' '; //strcpy(st.alloc3_cat, " ");
	st.alloc3_code = 0;
	st.allocf_code = 0;

	fwrite(&st, sizeof(st), 1, fp2);
	//getch();
	fclose(fp2);*/
	printf("done registration\n");
	return 0;
}

