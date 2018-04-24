#include "player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <windows.h>

void createchar();
void statscreen(string);
void display_all();
void deletechar(string);
void intro();

int main(void) {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	int select;
	string cname;
	intro();
	do
	{
		srand((unsigned int)time(NULL));
		system("cls");
		std::cout << "\n\n\n\tMAIN MENU";
		std::cout << "\n\n\t01. NEW CHARACTER";
		std::cout << "\n\n\t02. CHARACTER DETAILS";
		std::cout << "\n\n\t03. CHARACTER LIST";
		std::cout << "\n\n\t04. DELETE CHARACTER";
		std::cout << "\n\n\t05. EXIT";
		std::cout << "\n\n\tChoose Your Option (1-5) ";
		std::cout << endl;
		select = intValid(6);
		system("cls");
		switch (select)
		{
		case 1:
			createchar();
			break;
		case 2:
			std::cout << "Enter name of character: ";
			std::cin.ignore();
			std::getline(std::cin, cname);
			statscreen(cname);
			break;
		case 3:
			std::cin.ignore();
			display_all();
			break;
		case 4:
			std::cout << "Enter name of character: ";
			std::cin.ignore();
			std::getline(std::cin, cname);
			deletechar(cname);
			break;
		default:std::cout << "\a";
		}
		//std::cin.ignore();
		std::cin.get();
	} while (select != 5);
	return 0;
}

void createchar() {
	Player player;
	player.setstats();
	vector<Player> plist;
	ifstream is("players.bin");
	if (is) {
		cereal::BinaryInputArchive iarchive(is);
		iarchive(plist);
	}
	plist.push_back(player);
	ofstream os("players.bin");
	cereal::BinaryOutputArchive oarchive(os);
	oarchive(plist);
	std::cout << "\nPress Enter to return to main menu..";
}
void statscreen(string cname) {
	Player player;
	vector<Player>plist;
	ifstream is("players.bin");
	if (!is) {
		std::cout << "\nCharacter list is empty" << endl;
		std::cout << "\nPress Enter to return to main menu..";
		return;
	}
	cereal::BinaryInputArchive archive(is);
	archive(plist);
	auto it = find_if(plist.begin(), plist.end(), [&cname](const Player& player) {return player.getName() == cname;});
	if (it != plist.end())
	{
		std::cout << "\n  CHARACTER DETAILS" << endl;
		std::cout << "  =================" << endl;
		auto index = std::distance(plist.begin(), it);
		plist[index].displaystats();
		std::cout << "\n  Press Enter to return to main menu..";		
	}
	else {
		std::cout << "\nCharacter does not exist" << endl;
		std::cout << "\nPress Enter to return to main menu..";
	}
}
void deletechar(string cname) {
	Player player;
	vector<Player> plist;
	bool flag = false;
	{
		ifstream is("players.bin");
		if (!is) {
			std::cout << "\nCharacter list is empty" << endl;
			std::cout << "\nPress Enter to return to main menu..";
			return;
		}
		cereal::BinaryInputArchive iarchive(is);
		ofstream os("temp.bin");
		cereal::BinaryOutputArchive oarchive(os);
		iarchive(plist);
		auto it = find_if(plist.begin(), plist.end(), [&cname](const Player& player) {return player.getName() == cname;});
		if (it != plist.end())
		{
			plist.erase(it);
			flag = true;
			std::cout << "\n\n\tCharacter Deleted .." << endl;
		}
		oarchive(plist);
	}
	std::remove("players.bin");
	std::rename("temp.bin", "players.bin");
	if(!flag)
		std::cout << "\nCharacter does not exist" << endl;
	std::cout << "\nPress Enter to return to main menu..";
}
void display_all()
{
	Player player;
	vector<Player> plist;
	bool flag = false;
	ifstream is("players.bin");
	if (!is) {
		std::cout << "\nCharacter list is empty" << endl;
		std::cout << "\nPress Enter to return to main menu..";
		return;
	}
	cereal::BinaryInputArchive archive(is);
	archive(plist);
	std::cout << "\n\n\t\t\t\t\t\tPLAYER CHARACTER LIST\n\n";
	std::cout << "  =================================================================================================================\n";
	std::cout << "  NAME                          LVL     CLASS           RACE            STR     DEX     CON     INT     WIS     CHA\n";
	std::cout << "  =================================================================================================================\n";
	for (Player p : plist) {
		if (!flag)
			flag = p.report();
		else
			p.report();
	}
	if (flag) {
		std::cout << "\n  =================================================================================================================\n";
		std::cout << "  FULL NAMES\n";
		std::cout << "  =================================================================================================================\n";
		for (Player p : plist) {
			p.report(true);
		}
	}
	std::cout << "\n  Press Enter to return to main menu..";
}
void intro()
{
	std::cout << "\n\n\n\tDNDS (5e)";
	std::cout << "\n\n\n\tMade by: Jonathan Ho" << endl;
	std::wcout <<"\n\n\tDNDS is unofficial Fan Content permitted under the Fan Content Policy. Not approved/endorsed by Wizards. Portions of the materials used are property of Wizards of the Coast. "<< (wchar_t)0xA9 <<"Wizards of the Coast LLC."<< endl;
	std::cin.get();
}