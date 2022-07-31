#include "Organizer.h"
Organizer::Organizer()
{
	Org_name = nullptr;
	Org_password = nullptr;
}

void Organizer::setOrganizerName(char* name)
{
	int length = getLength(name);
	Org_name = new char[length+ 1];
	copy(Org_name, name);
}

void Organizer::setOrganizerPassword(char* password)
{
	int length = getLength(password);
	Org_password = new char[length+ 1];
	copy(Org_password, password);
}

Organizer::Organizer(char* name, char* password)
{
	int length = getLength(password);
	Org_password = new char[length + 1];
	copy(Org_password, password);
//--------------------------------------------------------
	length = getLength(password);
	Org_password = new char[length + 1];
	copy(Org_password, password);

}
Organizer::~Organizer()
{
	delete[]Org_name;
	Org_name = nullptr;
	delete[]Org_password;
	Org_password = nullptr;
}
