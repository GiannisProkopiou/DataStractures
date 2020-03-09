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

int Imp_BIS(int *array, int key, int n)
{
	int left = 1; //pointing the first element of sublist
	int right = n; //pointing the last element of sublist
	int size = right - left + 1; //size of sublist
	int next = (size * ((key - array[left]) / (array[right] - array[left]))) + 1; //prediction of position
	int i,j,k = 0;
	int temp = 0;
	int mid, l, r = 0;
	counter = 0;

	// Handling Exception (key greater than max)
	if (key > array[n - 1])
		return -1;

	while (key != array[next])
	{
		i = 0;
		size = right - left + 1;

		// if the sublist is too small it performs linear search
		if (size <= 3)
		{
			while (i < right)
			{
				if (array[left + i] == key)
					return left + i;
				else
					i++;
				counter++;
			}
		}

		// narrow the sublist 
		if (key >= array[next])
		{
			temp = next + ((2 ^ i) * sqrt(size)) - 1;
			if (temp >= n)
				temp = n - 1;
			while (key > array[temp])
			{
				i ++;
				temp = next + ((2 ^ i) * sqrt(size)) - 1;
				if (temp >= n)
					temp = n - 1;
				counter++;
			}
			right = next + ((2 ^ i) * sqrt(size));
			left = next + ((2 ^ (i-1)) * sqrt(size));
		}

		else if (key < array[next])
		{
			temp = next - ((2 ^ i) * sqrt(size)) + 1;
			if (temp < 0)
				temp = 0;
			while (key < array[temp])
			{
				i ++;
				temp = next - ((2 ^ i)* sqrt(size)) + 1;
				if (temp < 0)
					temp = 0;
				counter++;
			}
			right = next - ((2 ^ (i - 1)) * sqrt(size));
			left = next - ((2 ^ i) * sqrt(size));			
		}

		// Binary Search
		j = 0;
		l = 2 ^ (i - 1);
		r = 2 ^ i;
		for (j = l; j <= r; j++)
		{
			mid = (l + r) / 2;
			k = next + (mid * sqrt(size));
			if (key == array[k])
				return k;
			if (key < array[k])
				r = mid - 1;
			else if (key > array[k])
				l = mid + 1;
			counter++;
		}

		// Handling Exception (exceeding array bounds)
		if (left < 0)
			left = 0;
		if (right >= n)
			right = n;
		if (array[left] == key)
			return left;
		if (array[right] == key)
			return right;

		next = left + ((right - left + 1) * ((key - array[left]) / (array[right] - array[left]))) - 1;
	}

	if (key == array[next])
		return next;
	else
		return -1;
}