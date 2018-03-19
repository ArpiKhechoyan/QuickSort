#include <iostream>

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int index = left - 1;
	
	for (int j = left; j < right; ++j)
		{
			if (arr[j] <= pivot)
			{
				++index;
				std::swap(arr[index], arr[j]);
			}
		}

	std::swap(arr[index + 1], arr[right]);

	return index + 1;
}

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int p = partition(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " " ;
	std::cout << std::endl;
}

int main()
{
	const int size = 10;
	int array[size];
	for (int i = 0; i < size; i++)
		array[i] = rand();

	printArray(array, size);
	quickSort(array, 0, size - 1);
	printArray(array, size);

	return 0;
}
