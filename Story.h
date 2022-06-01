#pragma once
#include <iostream>
#include "Contacts.h"
#include "User.h"

using namespace std;

class Story
{
public:
	Story();
	Story(String^, String^);
	int id = 0;
	string publishtime;
	string imagepath;
	string storytext;
	void checkpublishtime(int);
	void AddStatus(int, String^, String^);
	vector<Contacts*> GetContacts(int);
	vector<Story*> show(int id);
private:
	User usr;
	Contacts cont;
	vector<Contacts*> contcts;
};