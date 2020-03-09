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
#include "Interpolation_Searching.h"
#include "Interpolation-Search-Improved.h"
#include "TXT-to-ARRAY.h"

int counter = 0;
int n = 100000;

int main()
{	
	int Search_Result = -1;
	int sorted = 1;
	
	int *list;
	list = txt_to_array("C:\\Users\\George Glarakis\\Documents\\CEID\\4th Semester\\Data Structures\\Project 2019\\integers.txt");

	clock_t start, end;
	double cpu_time_used;

	do {
		printf("1. Bubble Sort\n");
		printf("2. Insertion Sort\n");
		printf("3. Selection Sort\n");
		printf("4. Merge Sort\n");
		printf("5. Quick Sort\n");
		printf("6. Heap Sort\n");
		printf("\nChoose a sorting function: ");

		int n;
		scanf("%d", &n);
		while ((getchar()) != '\n'); //clear the input buffer
		switch (n)
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

	
	start = clock();
	list = Insertion_Sort(list, n);
	end = clock();
	/*
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", list[i]);
		if (i % 10 == 0)
		{
			printf("\n");
			system("pause");
		}
	}*/

	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nList sorted!\n");
	printf("Counter: %d\n", counter);
	printf("Time: %lf\n\n", cpu_time_used);

	
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
			printf("3. Binary Interpolation Searching\n");
			printf("4. Improved Binary Interpolation Searching\n");
			printf("\nChooe one of the searching functions: ");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				start = clock();
				Search_Result = Linear_Searching(list, num);
				end = clock();
				break;
			case 2:
				start = clock();
				Search_Result = Binary_Searching(list, num);
				end = clock();
				break;
			case 3:
				start = clock();
				Search_Result = Interpolation_Searching(list, num);
				end = clock();
				break;
			case 4:
				start = clock();
				Search_Result = Interpolation_Searching_Improved(list, num);
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

