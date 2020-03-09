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

int * Selection_Sort(int *array, int n)
{
	counter = 0;
	int i, j, swap, position;

	for (i = 0; i < (n - 1); i++)
	{
		position = i;

		for (j = i + 1; j < n; j++)
		{
			if (array[position] > array[j])
				position = j;

			counter++;
		}
		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
		}
	}

	return array;
}
