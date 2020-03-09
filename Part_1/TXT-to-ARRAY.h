/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

extern int n;

int * txt_to_array(char file_source[])
{
	int *array;
	array = (int*) malloc(n * sizeof(int));
	FILE *file;

	file = fopen(file_source, "r");

	int i = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &array[i]);
		i++;
	}

	fclose(file);

	return array;
}
