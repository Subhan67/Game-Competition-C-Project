#include "Signup.h"
Signup::Signup()
{
	cout << "Default constructor of Signup class..." << endl;
}

Signup::Signup(char* name, char* GamingID)
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
}

bool Signup::StoreInFile()
{
	ofstream fout("Signup_Participant.txt", ios::app);
	fout << participantName << "," << participantGamingId<< endl;
	if (fout.is_open())
	{
		cout << "\n\t\t\t\t\t\tYou Sign up Successfuly......\n";
		fout.close();
		return true;
	}
	else
	{
		cout << "\t\t\t\t\t\tUnable to Sign up......";
		return false;
	}
	return false;
}
Signup::~Signup()
{
}
