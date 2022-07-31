#include "Result.h"

Result::Result()
{
	player_1=nullptr;
	player_2 = nullptr;
	player_1_ID = nullptr;
	player_2_ID = nullptr;
	result_of_one=0;
	result_of_second=0;
	total_amount=0.0;
}

Result::Result(char* p_1, char* p_2, char* p_1_ID, char* p_2_ID)
{
	int size = getLength(p_1); 
	player_1 = new char[size + 1];
	copy(player_1, p_1);

	size = getLength(p_2);
	player_2 = new char[size + 1];
	copy(player_2, p_2);

	size = getLength(p_1_ID);
	player_1_ID = new char[size + 1];
	copy(player_1_ID, p_1_ID);

	size = getLength(p_2_ID);
	player_2_ID = new char[size + 1];
	copy(player_1_ID, p_2_ID);

}

void Result::set_player_1(char* p_1)
{
	int size = getLength(p_1);
	player_1 = new char[size + 1];
	copy(player_1, p_1);
}

void Result::set_player_2(char* p_2)
{
	int size = getLength(p_2);
	player_2 = new char[size + 1];
	copy(player_2, p_2);
}

void Result::set_player_1_ID(char* p_1_ID)
{
	int size = getLength(p_1_ID);
	player_1_ID = new char[size + 1];
	copy(player_1_ID, p_1_ID);
}

void Result::set_player_2_ID(char* p_2_ID)
{
	int size = getLength(p_2_ID);
	player_2_ID = new char[size + 1];
	copy(player_1_ID, p_2_ID);
}

bool Result::letsPlay(Competition& com_obj)
{
	srand(time(0));
	result_of_second = (50 + (rand() % 100));
	result_of_one = (50 + (rand() % 100));
	total_amount = com_obj.getCompetitionfee() * 3;
	if (result_of_one > result_of_second)
	{
		cout << "\t\t\t\t\t\t|_Player [1] ******************************[" << player_1 <<
			"]|\n\t\t\t\t\t\t|_***************__Is Winner___***********_|\n";
		cout << "\t\t\t\t\t\t*****************__Have score__*************[" << result_of_one << "]\n";
		cout << "\t\t\t\t\t\t*****************__WIN_________*************[" << total_amount << "  Rs.]\n";
		cout << "\n\t\t\t\t\t\t|*_*_*_*_*_*_Congratulations*_*_*_*_*_*_|\n";
	}
	else
	{
		cout << "\t\t\t\t\t\t|_Player [2] ******************************[" << player_2 <<
			"]|\n\t\t\t\t\t\t|_***************__Is Winner___***********_|\n";
		cout << "\t\t\t\t\t\t*****************__Have score__*************[" << result_of_second << "]\n";
		cout << "\t\t\t\t\t\t*****************__WIN_________*************[" << total_amount << "  Rs.]\n";
		return false;
	}
}
Result::~Result()
{
	delete[]player_1;
	player_1 = nullptr;
	delete[]player_2;
	player_2 = nullptr;
	delete[]player_1_ID;
	player_1_ID = nullptr;
	delete[]player_2_ID;
	player_2_ID = nullptr;
}
