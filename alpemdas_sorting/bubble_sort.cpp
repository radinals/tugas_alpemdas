#include <iostream>

using namespace std;

void bubble_sort(int array[], size_t array_size);
void swap_array_item(size_t from, size_t to, int array[]);
void print_array(int array[], size_t array_size);

int
main()
{
	size_t arr_size = 15;
	int arr[15] = { 5, 4, 3, 2, 1, -1, 34, 12, 9, 3, 30, -12, -22, 7, 8};

	cout << "BEFORE: ";
	print_array(arr, arr_size);

	bubble_sort(arr, arr_size);

	cout << "AFTER:  ";
	print_array(arr, arr_size);
}

void
bubble_sort(int array[], size_t array_size)
{
	// shift the biggest number increasingly to the right
	for(size_t n = 0; n < array_size; n++) {
		// element at array_size-n is always the biggest,
		// array_size- n - 1 to optimize
		for(size_t i=0; i < array_size-n-1; i++) {
			// the current one is bigger than the one in the right
			// swap the current to the right
			if (array[i] > array[i+1])
				swap_array_item(i, i+1, array);
		}
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
print_array(int array[], size_t array_size)
{
	for (size_t i=0; i < array_size; i++) {
		cout << array[i] << ", ";
	}

	cout << endl;
}
