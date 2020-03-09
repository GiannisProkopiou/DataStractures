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
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Bubble_Sort.h"
#include "Insertion_Sort.h"
#include "Selection_Sort.h"
#include "Merge_Sort.h"
#include "Quick_Sort.h"
#include "Heap_Sort.h"
#include "Linear_Searching.h"
#include "Binary_Searching.h"
#include "Interpolation_Search.h"
#include "Binary_Interpolation_Search.h"
#include "Improved_Binary_Interpolation_Search.h"
#include "TXT-to-ARRAY.h"

unsigned long int counter = 0;
int n = 100000;

int main()
{	
	int Search_Result = -1; //item found flag
	int sorted = 1; //sorted flag
	int ch; //switch choice variable
	
	int *list;
	list = txt_to_array("integers.txt");

	clock_t start, end;
	double cpu_time_used;

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
		printf("1. Bubble Sort\n");
		printf("2. Insertion Sort\n");
		printf("3. Selection Sort\n");
		printf("4. Merge Sort\n");
		printf("5. Quick Sort\n");
		printf("6. Heap Sort\n");
		printf("\nChoose a sorting function: ");

		scanf("%d", &ch);
		while ((getchar()) != '\n'); //clear the input buffer
		switch (ch)
		{
		case 1:
			start = clock();
			list = Bubble_Sort(list, n);
			end = clock();
			break;

		case 2:
			start = clock();
			list = Insertion_Sort(list, n);
			end = clock();
			break;

		case 3:
			start = clock();
			list = Selection_Sort(list, n);
			end = clock();
			break;

		case 4:
			start = clock();
			list = Merge_Sort(list, n);
			end = clock();
			break;

		case 5:
			start = clock();
			list = Quick_Sort(list, n);
			end = clock();
			break;

		case 6:
			start = clock();
			list = Heap_Sort(list, n);
			end = clock();
			break;

		default:
			printf("\nPlease choose one of the sorting functions!\n\n");
			sorted = 0;
		}

	} while (sorted == 0);
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nList sorted!\n");
	printf("Counter: %d\n", counter);
	printf("Time: %lf\n\n", cpu_time_used);
	printf("%d \n %d \n %d \n", list[0], list[50000], list[n-1]);
	
	if (sorted == 1)
	{
		int num; //the number user is searching
		int wrong_ch = 0; //wrong choice	

		do {
			wrong_ch = 0;
			printf("\nType the number you are searching for: ");
			scanf("%d", &num);

			printf("\n1. Linear Searching\n");
			printf("2. Binary Searching\n");
			printf("3. Interpolation Searching\n");
			printf("4. Binary Interpolation Searching\n");
			printf("5. Improved Binary Interpolation Searching\n");
			printf("\nChooe one of the searching functions: ");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
				start = clock();
				Search_Result = Linear_Searching(list, num, n);
				end = clock();
				break;
			case 2:
				start = clock();
				Search_Result = Binary_Searching(list, num, n);
				end = clock();
				break;
			case 3:
				start = clock();
				Search_Result = Interpolation_Search(list, num, n);
				end = clock();
				break;
			case 4:
				start = clock();
				Search_Result = BIS(list, num, n);
				end = clock();
				break;
			case 5:
				start = clock();
				Search_Result = Imp_BIS(list, num, n);
				end = clock();
				break;

			default:
				printf("\nPlease choose one of the searching functions!\n\n");
				wrong_ch = 1;
				break;
			}
			if (Search_Result == -1 && wrong_ch == 0)
				printf("\nThe number you are searching is not in the list!\n");
		} while (Search_Result == -1);
	}

	printf("The number you are searching is located in position: %d \n", Search_Result);
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("\nCounter: %d\n", counter);
	printf("Time: %lf\n", cpu_time_used);
		
	system("pause");

	return 0;
}