#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Participant.h"
#include "Competition.h"
using namespace std;

class Result :public Participant,public Competition
{
protected:
	char* player_1;
	char* player_2;
	char* player_1_ID;
	char* player_2_ID;
	int  result_of_one;
	int  result_of_second;
	double total_amount;
public:
	Result();
	Result(char* p_1, char* p_2, char* p_1_ID, char* p_2_ID);
	void set_player_1(char* p_1);
	void set_player_2(char* p_2);
	void set_player_1_ID(char* p_1_ID);
	void set_player_2_ID(char* p_2_ID);
	bool letsPlay(Competition&com_obj);
	~Result();
};

