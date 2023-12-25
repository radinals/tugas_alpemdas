#include <iostream>
using namespace std;

bool bin_search(int target, size_t& ret_index,  int array[], size_t array_size);
bool sqntial_search(int target, size_t& target_index, int array[], size_t array_size);
void del_item(size_t index, int array[], size_t& array_size);
void edit_item(size_t index, int new_value, int array[], size_t array_size);
void swap_element(size_t from, size_t to, int array[]);
void del_all(int target, int array[], size_t& array_size, bool(*search_algrthm)(int target, size_t& target_index,  int array[], size_t array_size));
void print_array(int array[], size_t array_size);

int
main()
{
	// TODO: Make a menu

	size_t data_size = 9;
	int data[data_size] = {1,2,3,3,3,6,7,8,9};

	// print_array(data, data_size);
	// del_all(3, data, data_size, bin_search);
	size_t i=0;
	bin_search(3, i, data, data_size);
	cout << i;
	// print_array(data, data_size);

	// size_t i;
	// while(true) {
	// 	int target;
	// 	cout << "MASUKAN TARGET ANGKA: ";
	// 	cin >> target;
	// 	if (bin_search(target, i, data, data_size))
	// 		cout << "data[" << i << "] = " << target << endl;
	// 	else
	// 		cout << target << " NOT FOUND" << endl;
	// }

}

// delete all instance of an item, this function takes a search algorithm for the searching
void
del_all(int target, int array[], size_t& array_size, bool(*search_algrthm)(int target, size_t& target_index,  int array[], size_t array_size))
{
	size_t target_index;
	// while the target is found
	while(search_algrthm(target, target_index, array, array_size))
	{
		// delete the target
		del_item(target_index, array, array_size);
	}
}

// returns true if found, and
// target_index is set to the found item's index
// sequential search
bool
sqntial_search(int target, size_t& ret_index, int array[], size_t array_size)
{
	for (size_t i=0; i < array_size; i++)
	{
		if (array[i] == target) {
			ret_index = i;
			return true;
		}
	}
	return false;
}

// FIXME: INFINITE LOOP
// binary search
bool
bin_search(int target, size_t& ret_index,  int array[], size_t array_size)
{
	size_t left=0, right=array_size-1;
	size_t middle=(left+right)/2;

	while(left < right);
	{
		if (array[middle] > target) {
			right = (middle-=1);

		} else if (array[middle] < target) {
			left = (middle+=1);

		} else if (array[middle] == target) {
			ret_index = middle;
			return true;
		}
	}

	return false;
}


void
edit_item(size_t index, int new_value,  int array[], size_t array_size)
{
	if (index < array_size)
		array[index] = new_value;
}

// move the target to the end of array, then 'shrink' the array by 1
void
del_item(size_t index, int array[], size_t& array_size)
{
	array_size--; // shrink element count by 1

	// shift all item to the right, until the last index
	for (size_t i=index; i < array_size; i++)
		swap_element(i, i+1, array);

	// '\0' means end of array
	// the target index is now the new 'end' of the array
	array[array_size] = '\0';
}

void
swap_element(size_t from, size_t to, int array[])
{
	int tmp = array[from];
	array[from] = array[to];
	array[to] = tmp;
}

void
print_array(int array[], size_t size)
{
	cout << "{ ";
	for(size_t i=0; i < size; i++)
		cout << array[i] << " ";
	cout << "}\n";
}
