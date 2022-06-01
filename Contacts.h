#pragma once
#include "User.h"
#include <vector>
#include <string>

using namespace Platform;
using namespace std;
using namespace Windows::Storage::Streams;
using namespace Windows::Storage;


class Contacts
{
private:
	User u;
public:
	String^ name;
	String^ phone;
	Contacts();
	Contacts(String^, String^);
	vector<Contacts*> show(int id);
	void add(int id, String^ new_mob, String^ new_name);
};
