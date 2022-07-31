#include "Login.h"

Login::Login()
{
	//default constrctor ...
}

Login::Login(char* name, char* Password)
{
	int size = getLength(name);
	Org_name = new char[size + 1];
	copy(Org_name, name);

	size = getLength(Password);
	Org_password = new char[size + 1];
	copy(Org_password, Password);
}

void Login::set_name(char* n)
{
	int size = getLength(n);
	Org_name = new char[size + 1];
	copy(Org_name, n);
}

void Login::set_password(char* password)
{
	int size = getLength(password);
	Org_password = new char[size + 1];
	copy(Org_password, password);
}

char* Login::get_name()
{
	return Org_name;
}

char* Login::get_password()
{
	return Org_password;
}

bool Login::loginOrganizer()
{
	int count1 = 0, count2 = 0;
	bool flage = true;
	int size1 = strlen(Org_name);
	int size2 = strlen(Org_password);
	char n[50]{ '\0' };
	char passw[50]{ '\0' };
	ifstream fin("login.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			count1 = 0, count2 = 0;
			fin.getline(n, 50, ',');
			fin.getline(passw, 50, ',');
			if (size1 == strlen(n))
			{
				for (int i = 0; i < size1; i++)
				{
					if (Org_name[i] != n[i])
					{

						break;
					}
					else
					{
						count1++;
					}
				}
			}
			if (size2 == strlen(passw))
			{
				for (int i = 0; i < size2; i++)
				{
					if (Org_password[i] != passw[i])
					{
						break;
					}
					else
					{
						count2++;
					}
				}
			}
			if (count1 != 0 && count1 == size1&& count2 != 0 && count2 == size2)
			{
				flage = false;
				fin.close();
				cout << "\t\t\t\t\t\tLogin Successfully!!!\n";
				break;
			}
			else
			{
				cout << "\t\t\t\t\t\tInvaid Name OR Password !!! Please Re-Try\n";
				fin.close();
			}

		}
	}
	
	return flage;
}

Login::~Login()
{
	delete[]Org_name;
	Org_name = nullptr;
	delete[]Org_password;
	Org_password = nullptr;
}
