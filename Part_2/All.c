/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Binary_Search_Tree_AM.h"
#include "Binary_Search_Tree_Grade.h"
#include "Hash_Table.h"
#include "Read_Students_Info_A.h"
#include "Read_Students_Info_B.h"
#include "Read_Students_Info_Hash.h"
#include "File_Close_A.h"
#include "File_Close_B.h"
#include "File_Close_Hash.h"
#include "Menu_A.h"
#include "Menu_B.h"
#include "Menu_Hash.h"

const int w = 5; 

void main()
{
	node_A * root_A = NULL;
	node_B * root_B = NULL;
	hash * hash_list = NULL;
	
	int ch = -1;
	int ans = 0;
	int wrong_selection = 0;

	printf("--------------------------------------------------\n\n");
	printf("Computer Engineering and Informatics Department\n");
	printf("		University of Patras	\n\n");
	printf("		Data Structures	\n");
	printf("		Project 2019	\n\n");
	printf("	Glarakis George AM: 1059561	\n");
	printf("	Papadias Epameinondas AM: 1062665 \n");
	printf("	Prokopiou Giannis AM : 1059554 \n\n");
	printf("--------------------------------------------------\n\n");

	do {
		ans = 0;
		wrong_selection = 0;
		printf("\n1. Binary Search Tree (by AM)\n");
		printf("2. Binary Search Tree (by Grade)\n");
		printf("3. Hashing chaining\n");
		printf("\nChoose a function: ");

		scanf("%d", &ch);
		while ((getchar()) != '\n'); //clear the input buffer
		switch (ch)
		{
		case 1:
			printf("\nBinary Search Tree by AM\n");
			root_A = read_file_A(root_A, "Foitites-Vathmologio-DS.txt");
			root_A = menu_A(root_A);
			break;

		case 2:
			printf("\nBinary Search Tree by Grade\n");
			root_B = read_file_B(root_B, "Foitites-Vathmologio-DS.txt");
			root_B = menu_B(root_B);
			break;

		case 3:
			printf("\nHash Table with chains by AM\n");
			hash_list = hash_setup(w);
			hash_list = read_file_C(hash_list, "Foitites-Vathmologio-DS.txt");
			hash_list = menu_C(hash_list);
			break;

		default:
			wrong_selection = 1;
		}

		if (wrong_selection == 1)
		{
			printf("\nPlease choose one of the Menu Numbers!\n");
			ans = 1;
		}
	} while (ans);
}