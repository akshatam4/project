/*****************************************************************************
 * Copyright (C) AKSHATA Madavi akshatamadavi@gmail.com
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
typedef struct student{
	int rollno;
	int rank;
	char name[20];
	//char category;
	char password[10];
}student;

typedef struct college {
	int code;
	char name[20];
}colleges;

typedef struct studentchoice {
	int rollno;
	int choicecode;
	int admsts;
}studentchoice;

typedef struct choice {
	int choicecode;
	int collegecode;
}choices;
