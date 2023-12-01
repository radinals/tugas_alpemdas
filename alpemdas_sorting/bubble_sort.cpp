#include <iostream>

using namespace std;

void bubble_sort(int array[], size_t array_size);
void swap_array_item(size_t from, size_t to, int array[]);
void print_array(int array[], size_t array_size);

int
main()
{
	size_t data_count = 15;
	int data[15] = { 5, 4, 3, 2, 1 , -1, 34, 12, 9, 3, 30, -12, -22, 7, 8};

	cout << "BEFORE: ";
	print_array(data, data_count);

	bubble_sort(data, data_count);

	cout << "AFTER:  ";
	print_array(data, data_count);
}

void
bubble_sort(int array[], size_t array_size)
{
	for(size_t n = 0; n < array_size; n++) {
		for(size_t i=0; i < array_size-n; i++) {
			if (array[i] > array[i+1]) {
				swap_array_item(i, i+1, array);
				continue;
			}
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
