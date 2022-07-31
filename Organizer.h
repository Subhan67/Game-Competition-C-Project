#pragma once
#include<iostream>
#include<fstream>
#include"Functions.h"
using namespace std;
class Organizer : public Functions
{
protected:
	char* Org_name;
	char* Org_password;
public:
	Organizer();
	Organizer(char* name, char* password);
	void setOrganizerName(char* name);
	void setOrganizerPassword(char* password);
	~Organizer();
};

