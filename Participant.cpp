#include "Participant.h"

Participant::Participant()
{
	participantName = nullptr;
	participantGamingId = nullptr;
	participantPhoneNumber = nullptr;
}

Participant::Participant(char* name, char* GamingID, char* phoneNumber)
{
	//------------------------------------------------------------
	int length = getLength(name);
	participantName = new char[length + 1];
	copy(participantName, name);
	//------------------------------------------------------------
	length = getLength(GamingID);
	participantGamingId = new char[length + 1];
	copy(participantGamingId, GamingID);
	//------------------------------------------------------------
	length = getLength(phoneNumber);
	participantPhoneNumber = new char[length + 1];
	copy(participantPhoneNumber, participantName);
}

void Participant::setParticipantName(char* name)
{
	int length = getLength(name);
	participantName = new char[length + 1];
	copy(participantName, name);
}

void Participant::setParticipantGamingID(char* GamingID)
{
	int length = getLength(GamingID);
	participantGamingId = new char[length + 1];
	copy(participantGamingId, GamingID);
}


void Participant::setParticipantPhoneNumber(char* phoneNumber)
{
	int length = getLength(phoneNumber);
	participantPhoneNumber = new char[length + 1];
	copy(participantPhoneNumber, participantName);
}

char* Participant::getParticipantName()
{
	return participantName;
}

char* Participant::getParticipantGamingID()
{
	return participantGamingId;
}

char* Participant::getParticipantPh()
{
	return participantPhoneNumber;
}

Participant::~Participant()
{
	delete[]participantName;
	participantName = nullptr;
	delete[]participantGamingId;
	participantGamingId = nullptr;
	delete[]participantPhoneNumber;
	participantPhoneNumber = nullptr;
}
