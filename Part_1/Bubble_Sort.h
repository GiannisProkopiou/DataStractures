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

int * Bubble_Sort(int *array, int n)
{
	int i, d, swap;
	counter = 0;

	for (i = 0; i < (n - 1); i++)
	{
		for (d = 0; d < n - i - 1; d++)
		{
			if (array[d] > array[d + 1]) /* For decreasing order use < */
			{
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
			counter++;
		}
	}

	return array;
}
