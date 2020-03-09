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

void merge(int *array, int min, int mid, int max, int n);
void part(int *array, int min, int max, int n);

int * Merge_Sort(int *array, int n)
{
	counter = 0;
	part(array, 0, n-1, n);
	return array;
}

void part(int *array, int min, int max, int n)
{
	int mid;
	if (min < max)
	{
		mid = (min + max) / 2;
		part(array, min, mid, n);
		part(array, mid + 1, max, n);
		merge(array, min, mid, max, n);
	}
}

void merge(int *arr, int min, int mid, int max, int n)
{
	
	int *tmp;
	tmp = (int*)malloc(n * sizeof(int));

	int i, j, k, m;
	j = min;
	m = mid + 1;
	for (i = min; j <= mid && m <= max; i++)
	{
		if (arr[j] <= arr[m])
		{
			tmp[i] = arr[j];
			j++;
		}
		else
		{
			tmp[i] = arr[m];
			m++;
		}
		counter++;
	}
	if (j>mid)
	{
		for (k = m; k <= max; k++)
		{
			tmp[i] = arr[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			tmp[i] = arr[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
	{
		arr[k] = tmp[k];
	}

	free(tmp);
}