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

int * Insertion_Sort(int *array, int n)
{
	int i, j, temp;
	counter = 0;

	for (i = 1; i < n; i++)
	{
		j = i;

		while (j > 0 && array[j] < array[j - 1])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
			
			counter++;
		}

	}
	return array;
}
