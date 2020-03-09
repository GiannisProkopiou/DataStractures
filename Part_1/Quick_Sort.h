/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

extern unsigned long int counter;

void quick(int *array, int first, int last);

int * Quick_Sort(int *array, int n)
{
	counter = 0;
	quick(array, 0, n - 1);
	return array;
}

void quick(int *array, int first, int last)
{
	int pivot, j, temp, i;
	if (first<last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i<j)
		{
			while (array[i] <= array[pivot] && i < last)
			{
				i++;
				counter++;
			}
			while (array[j] > array[pivot])
			{
				j--;
				counter++;
			}
			if (i<j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		quick(array, first, j - 1);
		quick(array, j + 1, last);
	}
}
