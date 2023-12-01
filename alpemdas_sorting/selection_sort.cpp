#include <iostream>

using namespace std;

void swap_array_item(size_t from, size_t to, int array[]);
void find_max(int array[], size_t start_i, size_t array_size, size_t* max_index);
void find_min(int array[], size_t start_i, size_t array_size, size_t* min_index);
void selection_sort(int array[], size_t array_size);
void print_array(int array[], size_t array_size);

int
main()
{
	size_t data_count = 15;
	int data[15] = { 5, 4, 3, 2, 1 , -1, 34, 12, 9, 3, 30, -12, -22, 7, 8};

	cout << "BEFORE: ";
	print_array(data, data_count);

	selection_sort(data, data_count);

	cout << "AFTER: ";
	print_array(data, data_count);
}

void
selection_sort(int array[], size_t array_size)
{
	size_t start = 0; // begin from index 0

	size_t max_index, min_index; // stores the biggest and smallest number indexes

	// find_min(), looks for the smallest number in an array
	// starts from the value set by start.
	// the smallest number index in the array is stored in min_index by pointer
	find_min(array, array_size, start, &min_index);

	// swap the found smallest number to the first index
	swap_array_item(min_index, 0, array);

	// similiar to find_min(), it looks for the biggest index
	find_max(array, array_size, start,  &max_index);

	// swap the found biggest number to the last index
	swap_array_item(max_index, array_size-1, array);

	// while start is smaller than array size, find the smallest,
	// swap to the start value, increment the start value
	for(start+=1 ; start < array_size; start++) {
		find_min(array, start, array_size, &min_index);
		swap_array_item(min_index, start, array);
	}
}

void
swap_array_item(size_t from, size_t to, int array[] )
{
	int tmp = array[from];
	array[from] = array[to];
	array[to] = tmp;
}

void
find_max(int array[], size_t array_size, size_t start_i, size_t* max_index)
{
	*max_index = start_i;
	int max = array[start_i];

	for(size_t i = start_i; i < array_size; i++) {
		if (array[i] > max) {
			*max_index = i;
		}
	}
}

void
find_min(int array[], size_t array_size, size_t start_i, size_t* min_index)
{
	*min_index = start_i;
	int min = array[start_i];

	for(size_t i = start_i; i < array_size; i++) {
		if (array[i] < min) {
			*min_index = i;
		}
	}
}

void
print_array(int array[], size_t array_size)
{
	for (size_t i=0; i < array_size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}
