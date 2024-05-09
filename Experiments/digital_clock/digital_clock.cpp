#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// clang-format off
std::vector<std::vector<std::string>> digital_clock {
	{"      ", " ", "      ", "   ", "      ", " ", "      ", "   ", "      ", " ", "      ", "\n",},
	{"      ", " ", "      ", " * ", "      ", " ", "      ", " * ", "      ", " ", "      ", "\n",},
	{"######", " ", "######", " * ", "######", " ", "######", " * ", "######", " ", "######", "\n",},
	{"######", " ", "######", "   ", "######", " ", "######", "   ", "######", " ", "######", "\n",},
	{"      ", " ", "      ", " * ", "      ", " ", "      ", " * ", "      ", " ", "      ", "\n",},
	{"      ", " ", "      ", " * ", "      ", " ", "      ", " * ", "      ", " ", "      ", "\n",},
	{"      ", " ", "      ", "   ", "      ", " ", "      ", "   ", "      ", " ", "      ", "\n",},
//	    0	    1	   2	    3	    4	    5	    6	    7	     8	    9	    10	   11
};
// clang-format on

typedef struct {
	char hour[std::size("hh")];
	char minute[std::size("mm")];
	char second[std::size("ss")];
} CurTime;

void get_current_time(CurTime& time);
void update_digit(char time, int collumn);
void print_digit();
void wait(int milliseconds);
void clear_screen();

int
main()
{
	CurTime current;
	while (true) {
		get_current_time(current);
		update_digit(current.hour[0], 0);
		update_digit(current.hour[1], 2);

		update_digit(current.minute[0], 4);
		update_digit(current.minute[1], 6);

		update_digit(current.second[0], 8);
		update_digit(current.second[1], 10);

		wait(1000);
		clear_screen();

		print_digit();
	}
	return 0;
}

void
get_current_time(CurTime& time)
{
	std::time_t result = std::time(nullptr);

	std::strftime(std::data(time.hour), std::size(time.hour), "%H",
	              std::localtime(&result));

	std::strftime(std::data(time.minute), std::size(time.minute), "%M",
	              std::localtime(&result));

	std::strftime(std::data(time.second), std::size(time.second), "%S",
	              std::localtime(&result));
}

void
print_digit()
{
	for (std::vector<std::string> line : digital_clock) {
		for (std::string l : line) {
			std::cout << l;
		}
	}
}

void
update_digit(char digit, int collumn)
{
	// clang-format off
	switch (digit) {
		case '0':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "#    #";
			digital_clock[2][collumn] = "#    #";
			digital_clock[3][collumn] = "#    #";
			digital_clock[4][collumn] = "#    #";
			digital_clock[5][collumn] = "#    #";
			digital_clock[6][collumn] = "######";
			break;
		case '1':
			digital_clock[0][collumn] = "   #  ";
			digital_clock[1][collumn] = " ###  ";
			digital_clock[2][collumn] = "   #  ";
			digital_clock[3][collumn] = "   #  ";
			digital_clock[4][collumn] = "   #  ";
			digital_clock[5][collumn] = "   #  ";
			digital_clock[6][collumn] = "######";
			break;
		case '2':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "     #";
			digital_clock[2][collumn] = "     #";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "#     ";
			digital_clock[5][collumn] = "#     ";
			digital_clock[6][collumn] = "######";
			break;
		case '3':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "     #";
			digital_clock[2][collumn] = "     #";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "     #";
			digital_clock[5][collumn] = "     #";
			digital_clock[6][collumn] = "######";
			break;
		case '4':
			digital_clock[0][collumn] = "#    #";
			digital_clock[1][collumn] = "#    #";
			digital_clock[2][collumn] = "#    #";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "     #";
			digital_clock[5][collumn] = "     #";
			digital_clock[6][collumn] = "     #";
			break;
		case '5':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "#     ";
			digital_clock[2][collumn] = "#     ";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "     #";
			digital_clock[5][collumn] = "     #";
			digital_clock[6][collumn] = "######";
			break;
		case '6':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "#     ";
			digital_clock[2][collumn] = "#     ";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "#    #";
			digital_clock[5][collumn] = "#    #";
			digital_clock[6][collumn] = "######";
			break;
		case '7':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "     #";
			digital_clock[2][collumn] = "     #";
			digital_clock[3][collumn] = "     #";
			digital_clock[4][collumn] = "     #";
			digital_clock[5][collumn] = "     #";
			digital_clock[6][collumn] = "     #";
			break;
		case '8':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "#    #";
			digital_clock[2][collumn] = "#    #";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "#    #";
			digital_clock[5][collumn] = "#    #";
			digital_clock[6][collumn] = "######";
			break;
		case '9':
			digital_clock[0][collumn] = "######";
			digital_clock[1][collumn] = "#    #";
			digital_clock[2][collumn] = "#    #";
			digital_clock[3][collumn] = "######";
			digital_clock[4][collumn] = "     #";
			digital_clock[5][collumn] = "     #";
			digital_clock[6][collumn] = "######";
			break;
	}
	// clang-format on
}

void
wait(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void
clear_screen()
{
	system("clear");
}
