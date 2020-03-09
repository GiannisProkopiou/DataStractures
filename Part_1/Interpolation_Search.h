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

int Interpolation_Search(int array[], int key, int n)
{
	counter = 0;
	int left = 0;
	int right = (n - 1);

	// Since array is sorted, an element present 
	// in array must be in range defined by corner 
	while (left <= right && key >= array[left] && key <= array[right])
	{
		if (left == right) {
			if (array[left] == key) return left;
			return -1;
		}
		// Probing the position with keeping 
		// uniform distribution in mind. 
		int next = left + (((double)(right - left) /
			(array[right] - array[left]))*(key - array[left]));

		// Condition of target found 
		if (array[next] == key)
			return next;

		// If x is larger, x is in upper part 
		if (array[next] < key)
			left = next + 1;

		// If x is smaller, x is in the lower part 
		else
			right = next - 1;
		counter++;
	}
	return -1;
}

