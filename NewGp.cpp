#include "pch.h"
#include "NewGp.h"
#include <time.h>
#include "User.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace Concurrency;
using namespace std;
using namespace Windows::Storage;
using namespace Platform;


NewGp::NewGp()
{
	this->Name = "";
	this->Phone2 = "";
	this->Phone3 = "";
	this->Phone4 = "";
	this->Phone5 = "";
	this->Phone6 = "";
	this->Phone7 = "";
	this->Phone8 = "";
	this->Phone9 = "";
	this->Phone10 = "";
	this->Count = 0;
	this->Type = "";
	this->Path = "";
}


//passed const to gui
NewGp::NewGp(String^ Name, String^ Type, String^ Phone2, String^ Phone3, String^ Phone4, String^ Phone5, String^ Phone6, String^ Phone7, String^ Phone8, String^ Phone9, String^ Phone10, int Count, String^ Path) {
	this->Name = Name;
	this->Phone2 = Phone2;
	this->Phone3 = Phone3;
	this->Phone4 = Phone4;
	this->Phone5 = Phone5;
	this->Phone6 = Phone6;
	this->Phone7 = Phone7;
	this->Phone8 = Phone8;
	this->Phone9 = Phone9;
	this->Phone10 = Phone10;
	this->Count = Count;
	this->Type = Type;
	this->Path = Path;
}


//passed const to messages
NewGp::NewGp(String^ message, int senderId1, int receiverId1, int receiverId2, int receiverId3, int receiverId4, int receiverId5,
	int receiverId6, int receiverId7, int receiverId8, int receiverId9, bool isSeen, String^ mesTime) {
	this->message = message;
	this->senderId1 = senderId1;
	this->isSeen = isSeen;
	this->receiverId1 = receiverId1;
	this->receiverId2 = receiverId2;
	this->receiverId3 = receiverId3;
	this->receiverId4 = receiverId4;
	this->receiverId5 = receiverId5;
	this->receiverId6 = receiverId6;
	this->receiverId7 = receiverId7;
	this->receiverId8 = receiverId8;
	this->receiverId9 = receiverId9;
	string temp;
	string all = uu.Convertstring(mesTime);
	for (int i = 0; i < all.size(); i++)
	{
		if (all[i] == ':') {
			this->mesTime.push_back(stoi(temp));
			temp = "";
		}
		else {
			temp.push_back(all[i]);
		}
		if (all[i] == '/') {
			break;
		}
	}
}


String^ NewGp::getTime()
{
	int hour;
	String^ a;
	String^ min;
	if (mesTime[1] == 0)
	{
		hour = 12;
		a = "AM";
	}
	else if (mesTime[1] >= 12) {
		hour = mesTime[1] - 12;
		a = "PM";
	}
	else
	{
		hour = mesTime[1];
		a = "AM";
	}
	if (mesTime[0] < 10) {
		min = "0" + mesTime[0].ToString();
	}
	else {
		min = mesTime[0].ToString();
	}
	return  hour.ToString() + ":" + min + " " + a;
}


int NewGp::GetFileId(String^ GroupName, String^ Member1, String^ Member2, String^ Member3, String^ Member4, String^ Member5, String^ Member6, String^ Member7, String^ Member8, String^ Member9, String^ Member10, int count) {
	vector<string> v;
	string line;
	int incounter = 0;
	int counter = 0;
	int id = 0;
	ifstream file;
	string name = uu.GetFileName("Chat_Rooms.txt");
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}
	file.close();
	vector<string> x;
	string store;
	for (int i = 0; i < v.size(); i++)
	{
		if (i < v.size() - 1 && v[i + 1] == "Chat") {
			i += 5;
		}
		else {
			if (i % 6 == 3) {
				store = v[i];
				string temp = "";
				for (int j = 0; j < store.length(); j++) {
					if (store[j] == ',') {
						if (temp == "") {
							x.push_back("*");
						}
						else {
							x.push_back(temp);
							temp = "";
						}
					}
					else {
						if (store[j] != ',') {
							temp.push_back(store[j]);
						}
					}
				}
				x.push_back(temp);
			}
			else {
				x.push_back(v[i]);
			}
		}
	}
	v.clear();
	for (int i = 0; i < x.size(); i++)
	{
		counter = 0;
		if (i % 16 == 1 && x[i].size() != 11 && x[i] != "*" && x[i] == uu.Convertstring(GroupName)) {
			if (stoi(x[i + 12]) == count) {
				counter++;
			}
			counter++;
			for (int j = i + 2; j < i + 12; j++) {
				if (x[j] == uu.Convertstring(Member1) || x[j] == uu.Convertstring(Member2) || x[j] == uu.Convertstring(Member3) || x[j] == uu.Convertstring(Member4) || x[j] == uu.Convertstring(Member5) ||
					x[j] == uu.Convertstring(Member6) || x[j] == uu.Convertstring(Member7) || x[j] == uu.Convertstring(Member8) || x[j] == uu.Convertstring(Member9) || x[j] == uu.Convertstring(Member10)) {
					incounter++;
				}
			}
			if (incounter == count) {
				counter++;
			}
			if (counter == 3) {
				id = stoi(x[i - 1]);
				break;
			}
		}
	}
	x.clear();
	return id;
}


void NewGp::CreateGP(String^ GroupName, String^ Member1, String^ Member2, String^ Member3, String^ Member4, String^ Member5, String^ Member6, String^ Member7, String^ Member8, String^ Member9, String^ Member10, String^ Path)
{
	int counter = MemberCount(Member1, Member2, Member3, Member4, Member5, Member6, Member7, Member8, Member9, Member10);
	string Name = uu.GetFileName("Chat_Rooms.txt");
	int id = 0;
	ofstream Newfile;
	Newfile.open(Name, ios::app);
	if (Newfile.is_open()) {
		id = msgss.GetLastId() + 1;
		Newfile << id << endl << uu.Convertstring(GroupName) << endl << "Group" << endl << uu.Convertstring(Member1) << "," << uu.Convertstring(Member2) << ","
			<< uu.Convertstring(Member3) << "," << uu.Convertstring(Member4) << "," << uu.Convertstring(Member5) << "," << uu.Convertstring(Member6) << ","
			<< uu.Convertstring(Member7) << "," << uu.Convertstring(Member8) << "," << uu.Convertstring(Member9) << "," << uu.Convertstring(Member10) << ","
			<< counter << endl << uu.Convertstring(Path) << endl << endl;
	}
	Newfile.close();
}


vector<NewGp*> NewGp::ShowGroups(String^ Phone)
{
	vector<string> v;
	vector<NewGp*> Chats;
	NewGp* n;
	string line;
	string name = uu.GetFileName("Chat_Rooms.txt");
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
		file.close();
	}
	vector<string> x;
	string store;
	for (int i = 0; i < v.size(); i++)
	{
		if (i < v.size() - 1 && v[i + 1] == "Chat") {
			i += 5;
		}
		else {
			if (i % 6 == 3) {
				store = v[i];
				string temp = "";
				for (int j = 0; j < store.length(); j++) {
					if (store[j] == ',') {
						if (temp == "") {
							x.push_back("*");
						}
						else {
							x.push_back(temp);
							temp = "";
						}
					}
					else {
						if (store[j] != ',') {
							temp.push_back(store[j]);
						}
					}
				}
				x.push_back(temp);
			}
			else {
				x.push_back(v[i]);
			}
		}
	}
	v.clear();
	for (int i = 1; i < x.size(); i += 16)
	{
		for (int j = i + 2; j < i + 12; j++)
		{
			if (x[j] == uu.Convertstring(Phone)) {
				for (int l = i; l < i + 14; l++)
				{
					if (x[l] != "*" && x[l] != uu.Convertstring(Phone)) {
						members.push_back(uu.ConvertToPlatformString(x[l]));
					}
					else if (x[l] == uu.Convertstring(Phone)) {
						continue;
					}
					else {
						members.push_back(" ");
					}
				}
				n = new NewGp(members[0], members[1], members[2], members[3], members[4], members[5], members[6],
					members[7], members[8], members[9], members[10], stoi(uu.Convertstring(members[11])), members[12]);
				Chats.push_back(n);
				members.clear();
				break;
			}
		}
	}
	x.clear();
	members.clear();
	return Chats;
}


void NewGp::sendMessage(stack<String^> stack, String^ GroupName, String^ Member1, String^ Member2, String^ Member3, String^ Member4, String^ Member5, String^ Member6, String^ Member7, String^ Member8, String^ Member9, String^ Member10, int count)
{
	id = GetFileId(GroupName, Member1, Member2, Member3, Member4, Member5, Member6, Member7, Member8, Member9, Member10, count);
	string name = uu.GetFileName(uu.ConvertToPlatformString(to_string(id)) + ".txt");
	ofstream file;
	file.open(name, ios::app);
	for (int i = 0; i <= stack.size(); i++)
	{
		copystack.push(stack.top());
		stack.pop();
	}
	if (!stack.empty()) {
		copystack.push(stack.top());
	}
	if (file.is_open()) {
		for (int i = 0; i <= copystack.size(); i++)
		{
			file << uu.Convertstring(copystack.top()) << endl;
			copystack.pop();
		}
		if (!copystack.empty()) {
			file << uu.Convertstring(copystack.top()) << endl;
			copystack.pop();
			file << uu.Convertstring(copystack.top()) << endl;
		}
		file.close();
	}
}


int NewGp::MemberCount(String^ Member1, String^ Member2, String^ Member3, String^ Member4, String^ Member5, String^ Member6, String^ Member7, String^ Member8, String^ Member9, String^ Member10) {
	int counter = 0;
	vector<String^> Count;
	Count.push_back(Member1);
	Count.push_back(Member2);
	Count.push_back(Member3);
	Count.push_back(Member4);
	Count.push_back(Member5);
	Count.push_back(Member6);
	Count.push_back(Member7);
	Count.push_back(Member8);
	Count.push_back(Member9);
	Count.push_back(Member10);
	for (int i = 0; i < Count.size(); i++)
	{
		if (Count[i] != "") {
			counter++;
		}
	}
	return counter;
}


vector<NewGp*> NewGp::grpRead(String^ GroupName, String^ Member1, String^ Member2, String^ Member3, String^ Member4, String^ Member5, String^ Member6, String^ Member7, String^ Member8, String^ Member9, String^ Member10, int count) {
	string name = uu.GetFileName(uu.ConvertToPlatformString(to_string(GetFileId(GroupName, Member1, Member2, Member3, Member4, Member5, Member6, Member7, Member8, Member9, Member10, count))) + ".txt");
	vector<string> v;
	vector<string>ret;
	vector<NewGp*> Messagess;
	NewGp* mg;
	string line;
	ifstream file;
	string store;
	vector<string>x;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
		file.close();
	}
	for (int i = 0; i < v.size(); i++)
	{
		store = v[i];
		string temp = "";
		for (int j = 0; j < store.length(); j++) {
			if (store[j] == ',') {
				x.push_back(temp);
				temp = "";
			}
			else {
				temp.push_back(store[j]);
			}
		}
		x.push_back(temp);
	}
	v.clear();
	for (int i = 0; i < x.size(); i++)
	{
		ret.push_back(x[i]);
	}
	for (int i = 0; i < ret.size(); i += 13)
	{
		bool seen = true;
		mg = new NewGp(uu.ConvertToPlatformString(ret[i]), stoi(ret[i + 1]), stoi(ret[i + 2]), stoi(ret[i + 3]), stoi(ret[i + 4]), stoi(ret[i + 5]), stoi(ret[i + 6]), stoi(ret[i + 7]),
			stoi(ret[i + 8]), stoi(ret[i + 9]), stoi(ret[i + 10]), seen, uu.ConvertToPlatformString(ret[i + 12]));
		Messagess.push_back(mg);
	}
	ret.clear();
	x.clear();
	return Messagess;
}