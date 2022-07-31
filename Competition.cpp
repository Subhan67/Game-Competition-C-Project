#include "Competition.h"
Competition::Competition()
{
	competitionName = new char[100]{ "\0" };
	competitionRule = new char[100]{ "\0" };
	price = 0;
	id = 0;
}

Competition::Competition(char* Name, char* rule, double price)
{
	Copy(competitionName, Name);
	Copy(competitionRule, rule);
	this->price = price;
	srand(time(0));
	id = (89 + (rand() % 1000));
}

void Competition::setCompetitionName(char* Name)
{
	Copy(competitionName, Name);
}

void Competition::setCompetitionRules(char* rule)
{
	Copy(competitionRule, rule);
}

void Competition::setCompetitionfee(double price)
{
	this->price = price;
}

void Competition::setCompetitionId(int id)
{
	this->id = id;
}

void Competition::setCompetitionId()
{
	srand(time(0));
	id = (89 + (rand() % 1000));
}

char* Competition::getCompetitionName()
{
	return competitionName;
}


char* Competition::getCompetitionRules()
{
	return competitionRule;
}

double Competition::getCompetitionfee()
{
	return price;
}

int Competition::getCompetitionId()
{
	return id;
}

int Competition::GetLength(char* arr)
{
	int length = 0;
	for (int i = 0; arr[i] != '\0'; i++, length++);
	return length;
}

void Competition::DisplayCompetitionData()
{
	cout << "\t\t\t\t\t\t______________________________________________________\n";
	cout << "\t\t\t\t\t\tCompetition Name is : " << competitionName<<endl;
	cout << "\t\t\t\t\t\tCompetition Rules are :" << competitionRule<<endl;
	cout << "\t\t\t\t\t\tCompetition Entery Fee is :" << price << endl;
	cout << "\t\t\t\t\t\tCompetition ID is : " << id << endl;
	cout << "\t\t\t\t\t\t______________________________________________________\n";
}

void Competition::storeInFile()
{
	ofstream fout("Competition Detail.txt", ios::app);
	int size = GetLength(competitionName);
	char* name = new char[size + 1]{ '\0' };
	for (int i = 0; competitionName[i]!='\n'; i++)
	{
		name[i] =competitionName[i];
	}
	size = GetLength(competitionRule);
	char* Rules = new char[size + 1]{ '\0' };
	for (int i = 0; competitionRule[i] != '\n'; i++)
	{
		Rules[i] = competitionRule[i];
	}
	fout << name << "," <<Rules<< "," << price << "," << id << endl;
	fout.close();
}

void Competition::Copy(char* arr, char* arr2)
{
	int length = GetLength(arr2);
	for (int i = 0; i < length; i++) {
		arr[i] = arr2[i];
	}
	arr[length] = '\0';
}

istream& operator>>(istream& fin, Competition& other)
{
	char* competitionName = new char[100];

	fin.getline(competitionName, 100, ',');
	other.setCompetitionName(competitionName);
	fin.getline(competitionName, 100, ',');
	other.setCompetitionRules(competitionName);

	fin >> other.price;
	fin.ignore();
	fin >> other.id;
	fin.ignore();
	return fin;
}


ostream& operator<<(ostream& out, Competition& data)
{
	out << "\t\t\t\t\t\t______________________________________________________\n";
	out << "\t\t\t\t\t\tCompetition Name is : " << data.competitionName << endl;
	out << "\t\t\t\t\t\tCompetition Rules are :" << data.competitionRule << endl;
	out << "\t\t\t\t\t\tCompetition Entery Fee is :" << data.price << endl;
	out << "\t\t\t\t\t\tCompetition ID is : " << data.id << endl;
	return out;
}
