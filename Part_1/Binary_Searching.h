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

int Binary_Searching(int *array, int key, int n)
{
	counter = 0;
	return Binary_Search(array, 0, n, key);
}

int Binary_Search(int *array, int l, int r, int key)
{
	if (r >= l)
	{
		counter++;

		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (array[mid] == key)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (array[mid] > key)
			return Binary_Search(array, l, mid - 1, key);

		// Else the element can only be present 
		// in right subarray 
		return Binary_Search(array, mid + 1, r, key);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
}