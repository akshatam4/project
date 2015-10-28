#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cap.h"
int main() {
    int choice;
    //char pwd[10];
    while (1) {
	printf("\n\n\t  CAPS MENU\n");
	printf    ("\t=============\n\n\n");

	printf ("\t1 Public Zone\n\n"
		"\t2 Admin Zone\n\n"
		"\t0 exit\n\n\n");
		
	printf("\tEnter your Zone : ");
	scanf("%d", &choice);
	printf("\n");
	
	switch(choice) {
		case 1 :
			public_menu();
			exit(0);
		case 2 :
			//adminmenu();
			exit(0);
		case 0 :
			exit(0);
	}
    }
}
