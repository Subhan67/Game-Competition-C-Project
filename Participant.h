#pragma once
#include<iostream>
#include<fstream>
#include "Functions.h"
using namespace std;
class Participant : public Functions
{
	char* participantName;
	char* participantGamingId;
	char* participantPhoneNumber;
public:
	Participant();
	Participant(char* name, char* GamingID,char* phonenumber);
	void setParticipantName(char* name);
	void setParticipantGamingID(char* GamingID);
	void setParticipantPhoneNumber(char* phonenumber);
	char* getParticipantName();
	char* getParticipantGamingID();
	char* getParticipantPh();

	~Participant();
};

