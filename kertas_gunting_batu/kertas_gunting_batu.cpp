#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

enum opsi { kertas, gunting, batu, invalid };
enum result { player_wins, com_wins, draw };

opsi rng();
void game();
opsi input_user();
void clear_screen();
std::string get_opsi(opsi);
result check_condition(opsi player, opsi computer);

int main()
{
	game();
	return 0;
}

void
game()
{
	int max = 3;

	int user_score, computer_score;
	user_score = computer_score = 0;

	while(true)
	{

		clear_screen();

		std::cout << "SCORES";
		std::cout << "\t* USER : " << user_score << "\n";
		std::cout << "\t* COM  : " << computer_score << "\n";

		opsi player = input_user();

		if (player == opsi::invalid) continue;

		opsi computer = rng();

		std::cout << "  *> USER OPT: " << get_opsi(player) << "\n";
		std::cout << "  *> COM OPT: " << get_opsi(computer) << "\n";

		switch (check_condition(player,computer))
		{
			case result::player_wins:
				std::cout << ">>>> Player Wins! >>>>\n";
				user_score++;
				break;
			case result::com_wins:
				std::cout << ">>>> Computer Wins! >>>>\n";
				computer_score++;
				break;
			case result::draw:
				std::cout << ">>>> Draw! >>>>\n";
				break;
		}

		if (user_score >= max)
		{
			std::cout << "=== GAME OVER: User WINS! === \n";
			break;
		} else if (computer_score >= max)
		{
			std::cout << "=== GAME OVER: Computer WINS! === \n";
			break;
		}

		std::cin.get();
	}
}

std::string
get_opsi(opsi op)
{
	switch (op) {
		case opsi::kertas:
			return "Kertas";
			break;
		case opsi::gunting:
			return "Gunting";
			break;
		case opsi::batu:
			return "Batu";
			break;
		default:
			return  "Invalid";
			break;
	}
}

opsi
input_user()
{
	std::string input;
	std::cout << "1. Kertas\n2. Gunting\n3. Batu\n";
	std::cout << "Pilihan: ";
	getline(std::cin, input);

	if (input.empty()) return opsi::invalid;

	switch(input.at(0))
	{
		case '1':
			return opsi::kertas;
		case '2':
			return opsi::gunting;
		case '3':
			return opsi::batu;
		default:
			return opsi::invalid;
	}
}

void
clear_screen()
{
	system("clear");
}

opsi
rng()
{
    	srand(time(0));
	return opsi(rand() % (opsi::kertas - opsi::batu));
}

result
check_condition(opsi player, opsi computer)
{
	if (player == computer)
		return result::draw;

	else if ((player == opsi::kertas) && (computer == opsi::gunting))
		return result::com_wins;

	else if ((player == opsi::gunting) && (computer == opsi::batu))
		return result::com_wins;

	else if ((player == opsi::batu) && (computer == opsi::kertas))
		return result::com_wins;

	else
		return result::player_wins;
}
