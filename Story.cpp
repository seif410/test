#include "pch.h"
#include "Story.h"
#include <iostream>
#include <stdio.h>
#include <fstream> 
#include<string>
#include<vector>
#include<time.h>
#include<ctime>
#include<cmath>

using namespace std;
using namespace concurrency;
using namespace Windows::Storage;

Story::Story()
{
	imagepath = "";
	storytext = "";
}


Story::Story(String^ imagepath, String^ storytext)
{
	this->imagepath = usr.Convertstring(imagepath);
	this->storytext = usr.Convertstring(storytext);
}


void Story::AddStatus(int id, String^ Path, String^ Text) {
	string path = usr.Convertstring(Path);
	string text = usr.Convertstring(Text);
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	string name = usr.GetFileName("Status.txt");
	vector<string> v;
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	int day = now->tm_mday; int mon = now->tm_mon + 1; int year = now->tm_year + 1900;
	int hour = now->tm_hour; int min = now->tm_min;
	string line;
	ofstream filee;
	filee.open(name, ios::app);
	v.push_back(to_string(id));
	v.push_back(to_string(day) + "/" + to_string(mon) + "/" + to_string(year) + "/" + to_string(hour) + "/" + to_string(min));
	v.push_back(path);
	v.push_back(text);
	v.push_back("");
	for (int i = 0; i < v.size(); i++)
	{
		filee << v[i] << endl;
	}
	filee.close();
	v.clear();
}


void Story::checkpublishtime(int id)
{
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	vector<string>v;
	vector<string>org;
	string name = usr.GetFileName("Status.txt");
	int counter = 0;
	int day = now->tm_mday; int mon = now->tm_mon + 1; int year = now->tm_year + 1900;
	int hour = now->tm_hour; int min = now->tm_min;
	string line;
	ifstream file;
	string store;
	file.open(name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			v.push_back(line);
			org.push_back(line);
		}
		file.close();
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 5 == 1)
			{
				store = v[i];
				string temp = "";
				vector<string>x;
				for (int i = 0; i < store.length(); i++) {
					if (store[i] == '/') {
						x.push_back(temp);
						temp = "";
					}
					else {
						temp.push_back(store[i]);
					}
				}
				if ((day - stoi(x[0]) > 0 && (hour - stoi(x[3]) >= 0)) || (day - stoi(x[0]) > 1 || mon - stoi(x[1]) > 0 || year - stoi(x[2]) > 0))
				{
					counter++;
					v[i - 1] = "";
					v[i] = "";
					v[i + 1] = "";
					v[i + 2] = "";
					break;
				}
				x.clear();
			}
		}
		ofstream newfile;
		newfile.open(name, ios::trunc);
		if (newfile.is_open()) {
			if (counter != 0)
			{
				for (int i = 0; i < v.size(); i++)
				{
					if (i % 5 == 3) {
						if (v[i] != "")
							newfile << v[i] << endl << endl;
					}
					else {
						if (v[i] != "")
							newfile << v[i] << endl;
					}
				}
			}
			else {
				for (int i = 0; i < org.size(); i++)
				{
					newfile << org[i] << endl;
				}
			}
		}
		newfile.close();
	}
}


vector<Contacts*> Story::GetContacts(int id) {
	int counter;
	vector<string> v;
	string line;
	contcts = cont.show(id);
	Contacts* c;
	vector<Contacts*> rturn;
	vector<int> ids;
	vector<int> ids2;
	for (int i = 0; i < contcts.size(); i++)
	{
		ids.push_back(usr.GetIDByPh(contcts[i]->phone));
	}
	for (int i = 0; i < ids.size(); i++)
	{
		if (usr.checknumByid(ids[i], usr.GetPhByid(id))) {
			ids2.push_back(ids[i]);
		}
	}
	string name = usr.GetFileName("Status.txt");
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}
	for (int i = 0; i < v.size(); i += 5)
	{
		counter = 0;
		for (int j = 0; j < ids2.size(); j++)
		{
			if (stoi(v[i]) == ids2[j]) {
				for (int k = 0; k < rturn.size(); k++)
				{
					if (rturn[k]->phone == usr.GetPhByid(ids2[j])) {
						counter++;
					}
				}
				if (counter == 0) {
					c = new Contacts(usr.GetNameByid(ids2[j]), usr.GetPhByid(ids2[j]));
					rturn.push_back(c);
				}
			}
		}
	}
	return rturn;
}


vector<Story*> Story::show(int id)
{
	vector<string>v;
	vector<Story*>ret;
	Story* s;
	string Name = usr.GetFileName("Status.txt");
	string line;
	ifstream file;
	string storepath;
	string storetext;
	vector<string>x;
	file.open(Name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.size() > 0)
				v.push_back(line);
		}
	}
	file.close();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == to_string(id))
		{
			storepath = v[i + 2];
			storetext = v[i + 3];
			x.push_back(storepath);
			x.push_back(storetext);
		}
	}
	v.clear();
	for (int i = 0; i < x.size(); i += 2)
	{
		s = new Story(usr.ConvertToPlatformString(x[i]), usr.ConvertToPlatformString(x[i + 1]));
		ret.push_back(s);
	}

	return ret;
}