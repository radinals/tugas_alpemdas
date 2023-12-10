#include <iostream>
using namespace std;

bool search(int target, size_t& target_index, int array[], size_t array_size);
void del_item(size_t index, int array[], size_t& array_size);
void edit_item(size_t index, int new_value, int array[]);
void swap_element(size_t from, size_t to, int array[]);
void del_all(int target, int array[], size_t& array_size);
void print_array(int array[], size_t array_size);

int 
main()
{
	size_t data_size = 9;
	int data[data_size] = {1,2,3,3,3,6,7,8,9};

	print_array(data, data_size);

	edit_item(2, 100, data);
	print_array(data, data_size);

	del_item(9, data, data_size);
	print_array(data, data_size);

	del_all(3, data, data_size);
	print_array(data, data_size);

}

void 
del_all(int target, int array[], size_t& array_size)
{
	size_t target_index;
	// while the target is found
	while(search(target, target_index, array, array_size)) 
	{
		// delete the target
		del_item(target_index, array, array_size);
	}
}

// returns true if found, and 
// target_index is set to the found item's index
bool 
search(int target, size_t& target_index, int array[], size_t array_size)
{
	for (size_t i=0; i < array_size; i++)
	{
		if (array[i] == target) {
			target_index = i;
			return true;
		}
	}
	return false;
}

void
edit_item(size_t index, int new_value,  int array[])
{
	array[index] = new_value;
}

void
del_item(size_t index, int array[], size_t& array_size)
{
	array_size--; // shrink by 1 

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
