#include <stdexcept>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>

bool isbnIsValid(std::string input, size_t panjang_isbn) {
	if (input.length() != panjang_isbn) {
		throw std::runtime_error("Invalid Input");
	}

	int sum = 0;
	for(int i = 0; i < input.length(); i++) {

		if (i == panjang_isbn-1) {
			int lastdigit = 0;
			switch(input.at(i)) {
				case 'x': case 'X':
					lastdigit = 10;
					break;
				case '?':
					lastdigit = 11;
					break;
				default:
					if (input.at(i) >= '0' && input.at(i) <= '9') {
						lastdigit = input.at(i) - '0';
					} else {
						throw std::runtime_error("Invalid Input");
					}
				}

			return (sum % (panjang_isbn+1) == lastdigit);
		}

		if (input.at(i) >= '0' && input.at(i) <= '9') {
			sum += (input.at(i) - '0') * (i + 1);
		} else {
			throw std::runtime_error("Invalid Input");
		}
	}

	return false;
}

int main()
{
	bool status = isbnIsValid("080442957X", 10);

	std::cout << "ISBN: " << (status ? "VALID" : "TIDAK VALID") << '\n';
	std::cout << '\n';
	return 0;
}
