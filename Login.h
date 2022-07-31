#pragma once
#include<iostream>
#include<fstream>
#include "Organizer.h"
using namespace std;
class Login:public Organizer
{
	char* Name_in_file;
	char* Password_in_file;
public:
	Login();
	Login(char* name, char* Password);
	void set_name(char* n);
	void set_password(char* password);
	char* get_name();
	char* get_password();
	bool loginOrganizer();
	~Login();
};

