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

int Linear_Searching(int *array, int key, int n)
{
	counter = 0;
	int i = 0;
	while (i < n) 
	{
		if (array[i] == key)
			return i;
		else 
			i++;

		counter++;
	}
	return -1;
}