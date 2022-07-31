#pragma once
#include<iostream>
#include<fstream>
#include "Participant.h"
using namespace std;
class Signup :public Participant
{
	char* participantName;
	char* participantGamingId;
public:
	Signup();
	Signup(char* name, char* GamingID);
	bool StoreInFile();
	~Signup();

};
