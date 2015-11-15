/*****************************************************************************
 * Copyright (C) AKSHATA MADAVI akshatamadavi@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cap.h"
main() {
int choice, x;
int rollno;

while (1) {
	printf("\n\n\t **** CAPS MENU ****\n");
	printf("\t======================\n");
	printf("1 Registration\n"
		"2 Login\n"
		"3 View college availability\n"
		"4 Choice filling\n"
		"5 Freeze\n"
		"6 View result\n"
		"7 List of eligible students\n"
		"0 Exit\n");
		
printf("\nEnter your choice : ");
	scanf("%d", &choice);
	printf("\n");

	switch(choice) {
		case 1 :
			registration();
			break;
		case 2 :
			rollno = login();
			break;
		case 3 :
			college();
			//branch();
			break;
		case 4 :
			choicefilling();
			break;
		
		case 5 :
			printf("enter roll number : \n");
			scanf("%d", &rollno);
			freezeadmission(rollno);
			break;
		case 6 :
			//printf("enter roll number : \n");
			//scanf("%ld", roll_number);
			result();
			break;
		case 7 :
			students();
			break;
		case 0 :
			exit(0);
			break;
		/*case 6 :
			cancel_admission(roll_number);
			getchar();printf("\nPress a key to continue...");getch();
			break;
		case 7 :
//			result();
			break;
		
		*/
	}
}
}
int choicefilling() {
	/*int rollno;
	char password[10];
	int x, choice;
	struct student st;
	FILE *fp;
	printf("Enter your Roll number and Password\n");
	scanf("%d %s", &rollno, password);
	fp = fopen("student.dat", "rb");
	if(fp == NULL) {
		perror("\nStudent file could not open.\n");
		return(2);
	}
	while(!feof(fp)) {
		fread(&st, sizeof(st), 1, fp);
		x = strcmp(st.password, password);
		if(st.rollno == rollno && x == 0) {*/
		char c[1000];
			FILE *fptr;
			fptr=fopen("program.txt","w");
			if(fptr==NULL){
				printf("Error!");
				exit(1);
			}
			printf("Enter a college name:");
			gets(c);
			fprintf(fptr,"%s",c);
			fclose(fptr);
			return 0;
		//}
	//}
}

int college() {
    FILE *fptr;
    char c;
    // Open file
    fptr = fopen("college.dat", "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}            
freezeadmission(int rollno) {
	struct studentchoice st;
	int x;
	int success = 0;
	FILE *fp = fopen("student.dat", "r+b");
	fread(&st, sizeof(st), 1, fp);
	while(!feof(fp)) {
		if(st.rollno == rollno) {
			if (st.admsts == '1')
				printf("Already Freezed...\n");
			else {
				st.admsts = '1';
				x = ftell(fp);
				fseek(fp, x - sizeof(st), SEEK_SET);
				fwrite(&st, sizeof(st), 1, fp);
				printf("O.K. Freezed.\n");
			}
			success = 1;
			break;
		}
		fread(&st, sizeof(st), 1, fp);
	}
	fclose(fp);
	if(success == 0)
		printf("Roll number not found\n");
}
int students() {
    FILE *fptr;
    char student[100], c;
    // Open file
    fptr = fopen("student.dat", "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}
int login() {
	int rollno;
	char password[10];
	int x, choice;
	struct student st;
	FILE *fp;
	printf("Enter your Roll number and Password\n");
	scanf("%d%s", &rollno, password);
	fp = fopen("student.dat", "rb");
	if(fp == NULL) {
		perror("\nStudent file could not open.\n");
		return(2);
	}
	while(!feof(fp)) {
		fread(&st, sizeof(st), 1, fp);
		x = strcmp(st.password, password);
		if(st.rollno == rollno && x == 0) {
			printf("\nWelcome %s\n", st.name);
			printf("1)Edit Profile\n");
			printf("2) Colleges and branches\n");
			printf("3) Choice Filling Round 1\n"
				"4) Choice Filling Round 2\n"
				"5) Choice Filling Round 3\n"
			       "6) Result\n"
			       "===================="
			       "\nEnter your choice : ");
			scanf("%d", &choice);
			printf("\n");
			switch(choice) {
				/*case 1 : {
					
					break;
				}*/
				case 1 : {
					college();
					//branch();
					break;
				}
				case 2 : {
					choicefilling();
					break;
				}
				case 3 : {
					choicefilling();
					break;
				}
				case 4 : {
					choicefilling();
					break;
				}
				case 5: {
					result();
					break;
				}
				case 6: {
					printf("invalid choice");
					break;
				}
			}
			fclose(fp);
			return st.rollno;
		}
	}
	fclose(fp);
	printf("\nInvalid Roll Number or Password . Try again\n");
	return 1;
}
int registration() {
	int x,i;
	char name[15], password[10];
	struct student st, stud;
	printf("Enter rollno : ");
	scanf("%d", &st.rollno);
	FILE *fp1 = fopen("student.dat","rb");
	if(fp1 == NULL) {
		perror("open failed:");
		return errno;
	}
	fread(&stud, sizeof(stud), 1, fp1);
	while (!feof(fp1)) {
		if (st.rollno == stud.rollno){
			printf("Roll No. %d Already exists",st.rollno); 
			return(1);
		}
		fread(&stud, sizeof(stud), 1, fp1);
	}
	fclose(fp1);
	printf("\nEnter name : ");
	scanf("%s", st.name);
	printf("\nEnter password : ");
	scanf("%s", st.password);
	printf("\nRetype password : ");
	scanf("%s", password);
	if(strcmp(st.password, password) != 0) {
		printf("\nMismatch in password\n");
		return 1 ;
	}		
	FILE *fp2 = fopen("student.dat", "a+b");
	if(fp2 == NULL) {
		perror("Student file could not open:");
		return errno;
	}
	fwrite(&st, sizeof(st), 1, fp2);
	fclose(fp2);
	printf("done registration\n");
	return 0;
}
int result() {
	/*int rollno;
	char password[10];
	int x, choice;
	struct student st;
	FILE *fp;
	printf("Enter your Roll number and Password\n");
	scanf("%d %s", &rollno, password);
	fp = fopen("student.dat", "rb");
	if(fp == NULL) {
		perror("\nStudent file could not open.\n");
		return(2);
	}
	while(!feof(fp)) {
		fread(&st, sizeof(st), 1, fp);
		x = strcmp(st.password, password);
		if(st.rollno == rollno && x == 0) {*/
			    FILE *fptr;
			    char filename[100], c;
			    // Open file
			    fptr = fopen("program.txt", "r");
			    if (fptr == NULL) {
				printf("Cannot open file \n");
				exit(0);
			    }
			    // Read contents from file
			    c = fgetc(fptr);
			    printf("CONGRATULATIONS..! You have been alloted:");
			    while (c != EOF) {
				printf ("%c", c);
				c = fgetc(fptr);
			    }
			    printf("\n");
			    fclose(fptr);
			    return 0;
		//}
	//}
}
int viewresult() {
    /*int rollno;
	char password[10];
	int x, choice;
	struct student st;
	FILE *fp;
	printf("Enter your Roll number and Password\n");
	scanf("%d %s", &rollno, password);
	fp = fopen("student.dat", "rb");
	if(fp == NULL) {
		perror("\nStudent file could not open.\n");
		return(2);
	}
	while(!feof(fp)) {
		fread(&st, sizeof(st), 1, fp);
		x = strcmp(st.password, password);
		if(st.rollno == rollno && x == 0) {*/
    FILE *fptr;
    char c;
    // Open file
    fptr = fopen("viewresult.dat", "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}
