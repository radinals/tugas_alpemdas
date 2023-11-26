
#include <iostream>

using namespace std;

int 
main()
{
	float celcius;

	cout << "Inputkan suhu dalam satuan celcius: ";
	cin >> celcius;
	
	printf("Suhu dalam fahrenheit: %.2f°F\n", ((1.8f * celcius ) + 32.0f));

	return 0;
}
