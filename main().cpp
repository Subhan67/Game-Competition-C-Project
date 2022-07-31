#include "Organizer.h"
#include "Signup.h"
#include "Login.h"
#include "Result.h"
#include "Competition.h"                 // Orgnizer Login User name is ali subhan       
#include "Participant.h"                  // Orgnizer Login Password is 8489,
#include<fstream>
int length = 1;
char* regrow(char* arr, char ch, int length) {
	char* temp = new char[length + 2];
	for (int i = 0; i < length; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = nullptr;
	temp[length] = ch;
	temp[length+1] = '\0';
	return temp;
}
void logo() {
	std::cout << R"(
                                   ____                         ____                           _   _ _   _             
                                  / ___| __ _ _ __ ___   ___   / ___|___  _ __ ___  _ __   ___| |_(_) |_(_) ___  _ __  
                                 | |  _ / _` | '_ ` _ \ / _ \ | |   / _ \| '_ ` _ \| '_ \ / _ \ __| | __| |/ _ \| '_ \ 
                                 | |_| | (_| | | | | | |  __/ | |__| (_) | | | | | | |_) |  __/ |_| | |_| | (_) | | | |
                                  \____|\__,_|_| |_| |_|\___|  \____\___/|_| |_| |_| .__/ \___|\__|_|\__|_|\___/|_| |_|
                                   ___    ___     ____            _     _          |_|_   _                            
                                  ( _ )  ( _ )   |  _ \ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __                 
                                  / _ \/\/ _ \/\ | |_) / _ \/ _` | / __| __| '__/ _` | __| |/ _ \| '_ \                
                                 | (_>  < (_>  < |  _ <  __/ (_| | \__ \ |_| | | (_| | |_| | (_) | | | |               
                                  \___/\/\___/\/ |_| \_\___|\__, |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|               
                                                            |___/
)";
}
void Menu(int i) {
	logo();
	if (i==1) {
		cout << "\t\t\t\t\t\t______________________________________________________\n";
		cout << "\t\t\t\t\t\t*************** WELL COME TO APPLICATION *************";
		cout<<"\n\t\t\t\t\t\t______________________________________________________\n";
		cout << "\t\t\t\t\t\tEnter '1' If you are Orgnizer\n";
		cout << "\t\t\t\t\t\tEnter '2' If you are Participent";
		cout << "\n\t\t\t\t\t\tEnter [0] to Exit--->!^_^!";
		cout<<"\n\t\t\t\t\t\t______________________________________________________\n\t\t\t\t\t\t::";
	}
	else if (i==2) {
		system("cls");
		cout << "\t\t\t\t\t\t______________________________________________________\n";
		cout << "\t\t\t\t\t\t********************* ORGANIZER ********************\n";
		cout << "\t\t\t\t\t\t_*_*_*_*_*_*_*_*_You Have to lOGIN first!!!!\n\n";
	}
	else if (i == 3) {
		system("cls");
		logo();
		cout << "\t\t\t\t\t\t_*_*_*_*_*_*_*_*_You Have to SIGNUP first!!!!\n\n";
		cout << "\t\t\t\t\t\tPlease Signup as a Solo Player....\n";
	}
	else if (i == 4) {

		system("cls");
		logo();
		cout << "\t\t\t\t\t\t______________________________________________________\n";
		cout << "\t\t\t\t\t\tEnter '1' If you want to Play\n";
		cout << "\t\t\t\t\t\tEnter '2' If you want to check Detils about Competition..\n";
//cout << "\t\t\t\t\t\tEnter '3' If you want to check Participant Detils..\n";
		cout << "\t\t\t\t\t\tEnter '0'  to Exit .....\n\t\t\t\t\t\t::";

	}
}
void readFile(Competition* Data,int lengthFile)
{
	ifstream fin;
	fin.open("Competition Detail.txt");
	for (int i = 0; i <lengthFile; i++) {
		fin >> Data[i];
	}
	fin.close();
}
void print(Competition* Data, int length) {
	for (int i = 0; i < length; i++) {
		    cout << "\n\t\t\t\t\t\t______________________________________________________\n";
			cout << "\n\t\t\t\t\t\t\t\t   Competetion [" << i + 1<<"]\n";
			cout << Data[i];
	}
}
Competition* removeData(Competition* Data, int length, int toRemove) {
	Competition* temp = new Competition[length - 1];
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (i == toRemove)
			continue;
		temp[count++] = Data[i];
	}
	delete[] Data;
	Data = nullptr;
	return temp;
}
void writeFile(Competition* Data, int length) {
	std::ofstream out("Competition Detail.txt");
	for (int i = 0; i < length; i++) {
		out << Data[i].getCompetitionName() << ","
			<< Data[i].getCompetitionRules() << ","
			<< Data[i].getCompetitionfee() << ","
			<< Data[i].getCompetitionId() << "\n";
	}
}
int main()
{
	//-----------------------objects declaration here....
	Signup Signupobj[2];
	Competition com_obj;
	//---------------------------------Arrays declaration here....
	char name[4];
	char password[4];
	char* competitionName = new char[1];
	char* competitionRules = new char[1];
	//---------------------------------Variables declaration here....
	char ch;
	char p_name[30], Gender[30], GamingID[30], phoneNumber[30];
	double Entery_fee = 0.0;

	int choice, length = 1, lengthFile = 0, compID = 0;
	//-----------------------------------------------------------------------------
	system("cls");
Start:
	Menu(1); //...............................................................Menu_1
	cin >> choice;
	bool check = false;
	if (choice == 1)
	{
		cin.ignore();
		Menu(2); //...............................................................Menu_2
		cout << "\t\t\t\t\t\tUserName :: ";
		cin.getline(name, 30);
		cout << "\t\t\t\t\t\tPassword :: ";
		cin.getline(password, 30);
		Login obj(name, password);
		{	while (check = obj.loginOrganizer())
		{
			cout << "\t\t\t\t\t\tUserName :: ";
			cin.getline(name, 30);
			cout << "\t\t\t\t\t\tPassword :: ";
			cin.getline(password, 30);
			obj.setOrganizerName(name);
			obj.setOrganizerPassword(password);
		}
		cout<<"\n\t\t\t\t\t\t______________________________________________________\n";
		cout << "\n\t\t\t\t\t\tPress '1' to Orgnize Competition:\n" <<
			    "\n\t\t\t\t\t\tPress '2' to see privious Competition\n" <<
			    "\n\t\t\t\t\t\tPress '3' to Delete Competition\n"
			<<"\n\n\t\t\t\t\t\tEnter any key to 'LOG OUT' PAGE!!!\n\n\t\t\t\t\t\t::";
		cin >> choice; }
		if (choice == 1)
		{
			system("cls");
			cin.ignore();
			cout << "\n\t\t\t\t\t\t______________________________________________________\n";
			cout << "\n\t\t\t\t\t\tEnter Competition Name :: ";
			cin.get(ch);
			competitionName[0] = ch;
			while (ch != '\n'){
				cin.get(ch);
				competitionName = regrow(competitionName, ch, length);
				length++;
			}
			cout << "\n\t\t\t\t\t\tEnter Competition Rules if any! :: ";
			cin.get(ch);
			competitionRules[0] = ch;
			length = 1;
			while (ch != '\n'){
				cin.get(ch);
				competitionRules = regrow(competitionRules, ch, length);
				length++;
			}
			cout << "\n\t\t\t\t\t\tCompetition Entry Fee :: ";
			cin >> Entery_fee;
			com_obj.setCompetitionName(competitionName);
			com_obj.setCompetitionRules(competitionRules);
			com_obj.setCompetitionfee(Entery_fee);
			com_obj.setCompetitionId();
			system("cls");
			 com_obj.DisplayCompetitionData();
			com_obj.storeInFile();
			cout << "\n\t\t\t\t\t\tYou Organize Competition Successfuly...................\n";
			goto Start;
		}
		if (choice == 2) {
			char* arr = new char[100];
			ifstream fin("Competition Detail.txt");
			while (!fin.eof())
			{
				fin.getline(arr, 100);
				if (arr[0] == '\0' || arr[0] == '\n')
					break;
				lengthFile++;
			}
			fin.close();
			Competition* Data = new Competition[lengthFile];
			readFile(Data, lengthFile);
			print(Data, lengthFile);
		}
		else if (choice == 3)
		{
			char* arr = new char[100];
			ifstream fin("Competition Detail.txt");
			while (!fin.eof())
			{
				fin.getline(arr, 100);
				if (arr[0] == '\0' || arr[0] == '\n')
					break;
				lengthFile++;
			}
			fin.close();
			Competition* Data = new Competition[lengthFile];
			readFile(Data, lengthFile);
			cout << "\n\t\t\t\t\t\tTotal : " << lengthFile << " Competetion...\n";
			cout << "\n\t\t\t\t\t\tEnter competetion number to remove\n\n\t\t\t\t\t\t::";
			cin >> choice;
			Data = removeData(Data, lengthFile, choice - 1);
			lengthFile--;
			cout << "\n\t\t\t\t\t\t______________________________________________________\n";
			cout << "\n\n\t\t\t\t\t\tAfter deletion.......\n";
			cout << "\n\t\t\t\t\t\t______________________________________________________\n";
			print(Data, lengthFile);
			for (int i = 0; i < lengthFile; i++)
			{
				Data[i].storeInFile();
			}
		}
		    else 
		    { 
		    	goto Start; 
		    }
		}
	 
	else if (choice == 2)
	{
		cout << "\n\t\t\t\t\t\t______________________________________________________\n";
		cout << "\n\t\t\t\t\t\t********************* PARTICIPENT ********************\n";
	PARTICIPENT:
		Menu(3); //...............................................................Menu_3
		cin.ignore();
		for (int i = 0; i < 2; i++)
		{
			cout << "\n\t\t\t\t\t\t______________________________________________________\n";
			cout << "\t\t\t\t\t\tParticipant " << i + 1 << " Data \n";
			cout << "\t\t\t\t\t\t______________________________________________________\n";
			cout << "\t\t\t\t\t\tEnter Username :: ";
			cin.getline(p_name, 30);
			cout << "\t\t\t\t\t\tUser Gaming ID :: ";
			cin.getline(GamingID, 20);
			cout << "\t\t\t\t\t\tUser Gender :: ";
			cin.getline(Gender, 10);
			cout << "\t\t\t\t\t\tPhone Number :: ";
			cin.getline(phoneNumber, 15);
			Signupobj[i].setParticipantName(p_name);
			Signupobj[i].setParticipantGamingID(GamingID);
			Signupobj[i].setParticipantPhoneNumber(phoneNumber);
		}
		system("cls");
		cout << "\t\t\t\t\t\t______________________________________________________\n";
		cout << "\t\t\t\t\t\tYou Sign up Successfuly......\n";
		cout << "\t\t\t\t\t\t______________________________________________________\n";
	Choice:
		Menu(4);//...............................................................Menu_4
		cin >> choice;
		if (choice == 1)
		{
			Result obj_r;
			obj_r.set_player_1(Signupobj[0].getParticipantName());
			obj_r.set_player_2(Signupobj[1].getParticipantName());
			obj_r.set_player_1_ID(Signupobj[0].getParticipantGamingID());
			obj_r.set_player_2_ID(Signupobj[1].getParticipantGamingID());
		Play_Again:
			obj_r.letsPlay(com_obj);
			cout << "\t\t\t\t\t\t______________________________________________________";
			cout << "\n\n\t\t\t\t\t\t! PLAY AGAIN PREES '1'\n"
				<< "\t\t\t\t\t\tLEAVE PRESS '2'\n\t\t\t\t\t\t:: ";
			cin >> choice;
			if (choice == 1) { goto Play_Again; }
			else { goto Choice; }
		}
		else if (choice == 2)
		{   
			cout << "\t\t\t\t\t\t   Latest Competetion\n";
			cout << "\t\t\t\t\t\t______________________________________________________\n";
			com_obj.DisplayCompetitionData();
			cout << "\t\t\t\t\t\t!Enter [0] to GO Back!.\n\t\t\t\t\t\t:: ";
			cin >> choice;
			if (choice == 0) { goto Choice; }
		}
		else if (choice == 0) {
			system("cls");
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t\t\t\tInvalid input !!!\n\t\t\t\t\t\tSelect From 1 to 2 \n\t\t\t\t\t\t:: ";
			goto Choice;

		}
	}
}
	