#include <algorithm>
#include <cstddef>
#include <iostream>

using namespace std;

void swap_array_item(size_t from, size_t to, int array[]);
void find_max(int array[], size_t start_i, size_t array_size,
              size_t* max_index);
void find_min(int array[], size_t start_i, size_t array_size,
              size_t* min_index);
void print_array(int array[], size_t array_size);
void selection_sort(int array[], size_t array_size);

int
main()
{
	size_t arr_size = 15;
	int arr[15] = {5, 4, 3, 2, 1, -1, 34, 12, 9, 3, 30, -12, -22, 7, 8};

	cout << "BEFORE: ";
	print_array(arr, arr_size);

	selection_sort(arr, arr_size);

	cout << "AFTER:  ";
	print_array(arr, arr_size);
}

void
selection_sort(int array[], size_t array_size)
{
	size_t max_index,
	    min_index; // stores the biggest and smallest number indexes

	// while start is smaller than array size do,
	// - find the smallest,
	// - swap the smallest to the start value,
	// - then increment the start value
	for (size_t start = 0; start < array_size; start++) {

		if (start == 0) {
			find_max(array, array_size, start, &max_index);
			// swap the found biggest number to the last index
			swap_array_item(max_index, array_size - 1, array);
		}

		find_min(array, array_size - 1, start, &min_index);
		swap_array_item(min_index, start, array);
	}
}

void
swap_array_item(size_t from, size_t to, int array[])
{
	int tmp = array[to];
	array[to] = array[from];
	array[from] = tmp;
}

void
find_max(int array[], size_t array_size, size_t start_i, size_t* max_index)
{
	int max = array[start_i];
	*max_index = start_i;

	for (size_t i = start_i; i < array_size; i++) {
		if (array[i] > max) {
			*max_index = i;
			max = array[i];
		}
	}
}

void
find_min(int array[], size_t array_size, size_t start_i, size_t* min_index)
{
	int min = array[start_i];
	*min_index = start_i;

	for (size_t i = start_i; i < array_size; i++) {
		if (array[i] < min) {
			*min_index = i;
			min = array[i];
		}
	}
}

void
print_array(int array[], size_t array_size)
{
	for (size_t i = 0; i < array_size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}
