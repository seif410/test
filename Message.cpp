#include "pch.h"
#include "Message.h"
#include <time.h>
#include <ctime>
#include <iostream>
#include <string>
#include <stack>
#include <fstream>


using namespace Concurrency;
using namespace std;
using namespace Windows::Storage;
using namespace Platform;
using namespace Windows::UI::Popups;

Message::Message() {
	this->message = "";
	this->senderId = 0;
	this->isSeen = "";;
	this->receiverId = 0;
}


//Constructor to show Chat
Message::Message(String^ Name, String^ Phone, String^ Type) {
	this->Name = Name;
	this->Phone = Phone;
	this->Type = Type;
}


//loded message from files
Message::Message(String^ message, int senderId, int receiverId, bool isSeen, String^ mesTime)
{
	this->message = message;
	this->senderId = senderId;
	this->isSeen = isSeen;
	this->receiverId = receiverId;
	string temp;
	string all = c.Convertstring(mesTime);
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


//sended message by user
Message::Message(String^ message, int senderId, int receiverId)
{
	this->message = message;
	this->senderId = senderId;
	this->receiverId = receiverId;
	this->isSeen = 0;
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	//0:min , 1:hour , 2:day , 3:month , 4:year
	this->mesTime.push_back(now->tm_min);
	this->mesTime.push_back(now->tm_hour);
	this->mesTime.push_back(now->tm_mday);
	this->mesTime.push_back(now->tm_mon + 1);
	this->mesTime.push_back(now->tm_year + 1900);

}


//time written on message in GUI
String^ Message::getTime()
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


//insert message sent by user to files
void Message::send(stack<String^> stack, String^ member1, String^ member2)
{
	string name = c.GetFileName(c.ConvertToPlatformString(to_string(GetFileId(member1, member2))) + ".txt");
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
		for (int i = 0; i <= copystack.size(); ++i)
		{
			file << c.Convertstring(copystack.top()) << endl;
			copystack.pop();
		}
		if (!copystack.empty()) {
			file << c.Convertstring(copystack.top()) << endl;
			copystack.pop();
			file << c.Convertstring(copystack.top()) << endl;
		}
		file.close();
	}
}


vector<Message*> Message::read(int LoginUser, int User, String^ Member1, String^ Member2) {
	vector<string>v;
	vector<String^>ret;
	vector<Message*> messages;
	Message* m1;
	string name = c.GetFileName(c.ConvertToPlatformString(to_string(GetFileId(Member1, Member2))) + ".txt");
	ChangeSeen(LoginUser, User, Member1, Member2);
	string line;
	ifstream file;
	string store;
	vector<string>x;
	file.open(name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.size() > 0)
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
		ret.push_back(c.ConvertToPlatformString(x[i]));
	}
	for (int i = 0; i < ret.size(); i += 5)
	{
		bool seen;
		if (ret[i + 3] == "False") {
			seen = false;
		}
		else {
			seen = true;
		}
		m1 = new Message(ret[i], stoi(c.Convertstring(ret[i + 1])), stoi(c.Convertstring(ret[i + 2])), seen, ret[i + 4]);
		messages.push_back(m1);
	}
	ret.clear();
	x.clear();
	return messages;
}


void Message::ChangeSeen(int Log_User, int Other_User, String^ member1, String^ member2) {

	vector<string> v;
	vector<string> x;
	string name = c.GetFileName(c.ConvertToPlatformString(to_string(GetFileId(member1, member2))) + ".txt");
	string line;
	string store;
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}
	file.close();
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
		if (x[i] == to_string(Log_User) && i % 5 == 2) {
			x[i + 1] = "True";
		}
	}
	ofstream New_File;
	New_File.open(name, ios::trunc);
	for (int i = 0; i < x.size(); i += 5)
	{
		New_File << x[i] << "," << x[i + 1] << "," << x[i + 2] << "," << x[i + 3] << "," << x[i + 4] << endl;
	}
}


int Message::GetFileId(String^ Member1, String^ Member2) {
	vector<string> v;
	string line;
	int id = 0;
	string Name = c.GetFileName("Chat_Rooms.txt");
	ifstream file;
	file.open(Name);
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
		if (i < v.size() - 2 && v[i + 2] == "Group") {
			i += 5;
		}
		else {
			if (i % 6 == 3) {
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
			else {
				x.push_back(v[i]);
			}
		}
	}
	v.clear();
	for (int i = 0; i < x.size(); i++)
	{
		if ((x[i] == c.Convertstring(Member1) && x[i + 1] == c.Convertstring(Member2))) {
			id = stoi(x[i - 3]);
			break;
		}
		else if (x[i] == c.Convertstring(Member2) && x[i + 1] == c.Convertstring(Member1)) {
			id = stoi(x[i - 3]);
			break;
		}
	}
	return id;
	x.clear();
}


int Message::GetLastId() {
	vector<string> v;
	string line;
	int id = 0;
	string Name = c.GetFileName("Chat_Rooms.txt");
	ifstream file;
	file.open(Name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}
	file.close();

	for (int i = 0; i < v.size(); i += 6)
	{
		id = stoi(v[i]);
	}

	return id;
}


vector<Message*> Message::ShowChat(String^ Phone) {
	int counter = 0;
	vector<string> v;
	vector<Message*> messages;
	contacts = con.show(c.GetIDByPh(Phone));
	Message* m;
	string line;
	string name = c.GetFileName("Chat_Rooms.txt");
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
		if (i < v.size() - 2 && v[i + 2] == "Group") {
			i += 5;
		}
		else {
			if (i % 6 == 3) {
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
			else {
				x.push_back(v[i]);
			}
		}
	}
	v.clear();
	for (int i = 0; i < x.size(); i++)
	{
		counter = 0;
		if (x[i] == c.Convertstring(Phone)) {
			for (int j = 0; j < contacts.size(); j++)
			{
				if (x[i + 1] == c.Convertstring(contacts[j]->phone) || x[i - 1] == c.Convertstring(contacts[j]->phone)) {
					m = new Message(contacts[j]->name, contacts[j]->phone, "Private");
					messages.push_back(m);
					counter++;
					break;
				}
			}
			if (counter == 0) {
				if (x[i - 1] == "Private") {
					m = new Message(c.ConvertToPlatformString(x[i + 1]), c.ConvertToPlatformString(x[i + 1]), "Private");
					messages.push_back(m);
				}
				else if (x[i + 1] == "None") {
					m = new Message(c.ConvertToPlatformString(x[i - 1]), c.ConvertToPlatformString(x[i - 1]), "Private");
					messages.push_back(m);
				}
			}
		}
	}
	return messages;
}


void Message::CreateChat(String^ Contact1, String^ Contact2) {
	int id = 0;
	string Name = c.GetFileName("Chat_Rooms.txt");
	ofstream Newfile;
	Newfile.open(Name, ios::app);
	if (Newfile.is_open()) {
		id = GetLastId() + 1;
		Newfile << id << endl << "Chat" << endl << "Private" << endl << c.Convertstring(Contact1) << "," << c.Convertstring(Contact2) << endl << "None" << endl << endl;
	}
}
