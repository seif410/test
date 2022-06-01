#include "pch.h"
#include "Contacts.h"
#include <fstream>

using namespace Windows::Storage;


Contacts::Contacts()
{
	phone = "";
	name = "";
}


Contacts::Contacts(String^ name, String^ phone)
{
	this->name = name;
	this->phone = phone;
}


void Contacts::add(int id, String^ new_mob, String^ new_name)
{
	vector<string> v;
	string line;
	string newname = u.Convertstring(new_name);
	string phone = u.Convertstring(new_mob);
	string Name = u.GetFileName("Contacts.txt");
	bool x = false;
	ifstream file;
	file.open(Name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.size() > 0) {
				v.push_back(line);
			}
		}
		file.close();
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == to_string(id))
			{
				v[i + 1] = v[i + 1] + newname + "," + phone + "*";
				x = true;
				break;
			}
		}
	}
	ofstream newfile;
	newfile.open(Name, ios::trunc);
	if (newfile.is_open())
	{
		if (x == false)
		{
			v.push_back(to_string(id));
			v.push_back(u.Convertstring(new_name + "," + new_mob));
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == v.back()) {
					newfile << v[i] << "*";
				}
				else if (i % 2 == 0 || v[i] == v.front()) {
					newfile << v[i] << endl;
				}
				else if (i % 2 == 1)
					newfile << v[i] << endl;
			}
			v.clear();
		}
		else
		{
			for (int i = 0; i < v.size(); i++) {
				newfile << v[i] << endl;
			}
			v.clear();
		}
	}
	newfile.close();
}


vector<Contacts*> Contacts::show(int id)
{
	vector<string>v;
	vector<Contacts*>ret;
	Contacts* c1;
	string Name = u.GetFileName("Contacts.txt");
	string line;
	ifstream file;
	string store;
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
			store = v[i + 1];
			string temp = "";
			for (int j = 0; j < store.length(); j++) {
				if (store[j] == '*' || store[j] == ',') {
					x.push_back(temp);
					temp = "";
				}
				else {
					temp.push_back(store[j]);
				}
			}
			break;
		}
	}
	v.clear();
	for (int i = 0; i < x.size(); i += 2)
	{
		c1 = new Contacts(u.ConvertToPlatformString(x[i]), u.ConvertToPlatformString(x[i + 1]));
		ret.push_back(c1);
	}
	return ret;
}