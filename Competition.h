#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Competition {
	char* competitionName;
	char* competitionRule;
	double price;
	int id;
public:
	Competition(); 
	Competition(char* Name, char* rule, double price);
	// Setters
	void setCompetitionName(char* Name); 
	void setCompetitionRules(char* rule); 
	void setCompetitionfee(double price);
	void setCompetitionId(int id);
	void setCompetitionId();
	// Getters
	char* getCompetitionName();
	char* getCompetitionRules();
	double getCompetitionfee();
	int getCompetitionId();
	int GetLength(char* arr);
	void DisplayCompetitionData();
	void storeInFile();
	void Copy(char* arr, char* arr2);
	friend istream& operator >> (istream& in, Competition& other);
	friend ostream& operator<<(ostream& out, Competition& data);
};