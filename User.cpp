#include "User.h"
#include"pch.h"
#include <fstream>
#include<string>
#include <locale>
#include <codecvt>
#include <stack>

using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
User User::LogedInUser;


User::User() {
	id = 0;
}


User::~User() {
	id = NULL;
	firstname = "";
	lastname = "";
	phone = "";
	password = "";
	discription = "";
	imagePath = "";
	Visible = "";
}


string User::GetFileName(String^ file) {
	Platform::String^ localfolder = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	wstring folderNameW(localfolder->Begin());
	string folderNameA(folderNameW.begin(), folderNameW.end());
	const char* charStr = folderNameA.c_str();
	wstring namew(file->Begin());
	string namea(namew.begin(), namew.end());
	const char* namee = namea.c_str();
	char fileName[512];
	sprintf_s(fileName, "%s\\%s", charStr, namee);
	return fileName;
}


string User::Convertstring(Platform::String^ g)
{
	std::wstring w_str(g->Begin());
	return std::string(w_str.begin(), w_str.end());
}


String^ User::ConvertToPlatformString(string inputString) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::wstring intermediateForm = converter.from_bytes(inputString);
	Platform::String^ retVal = ref new Platform::String(intermediateForm.c_str());
	return retVal;
}


bool User::CheckUserExist(String^ phone) {

	vector<string> v;
	string Phone = Convertstring(phone);
	string line;
	string Name = GetFileName("Users.txt");
	ifstream file(Name);
	bool x = true;
	while (getline(file, line)) {
		if (line.size() > 0) {
			v.push_back(line);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == Phone) {
			x = false;
			break;
		}
	}
	file.close();
	v.clear();
	return x;
}


string User::CheckUserAndPassword(String^ phone, String^ password) {

	vector<string> v;
	string Phone = Convertstring(phone);
	string Password = Convertstring(password);
	string line;
	string Name = GetFileName("Users.txt");
	ifstream file;
	file.open(Name);
	string ReturnVal = "NoUserExist";

	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.size() > 0) {
				v.push_back(line);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == Phone && v[i + 1] == Password) {
				ReturnVal = "Login";
				break;
			}
			else if (v[i] == Phone && v[i + 1] != Password) {
				ReturnVal = "Wrong_Password";
				break;
			}
		}
		file.close();
	}

	if (ReturnVal == "Login") {
		return "Login";
	}
	else if (ReturnVal == "Wrong_Password") {
		return "Wrong_Password";
	}
	else {
		return ReturnVal;
	}

	v.clear();
}


string User::Register(Platform::String^ firstname, Platform::String^ lastname, Platform::String^ Phone, Platform::String^ password, Platform::String^ discription)
{
	if (firstname->IsEmpty() || lastname->IsEmpty() || Phone->IsEmpty() || password->IsEmpty()) {
		return "Error_1";
	}
	else if (Phone->Length() < 11 || CheckNumber(Phone) == false) {
		return "Error_2";
	}
	else if (CheckUserExist(Phone) == false) {
		return "Error_3";
	}
	else if (CheckLetters(firstname) == false || CheckLetters(lastname) == false) {
		return "Error_4";
	}
	else {
		id = GetLastId() + 1;
		string Id = to_string(id);
		return Id;
	}
}


void User::Registeration(int id, String^ Fn, String^ Ln, String^ Phone, String^ Pw, String^ Status, String^ Path, String^ Visibility) {
	string fn = Convertstring(Fn);
	string ln = Convertstring(Ln);
	string phone = Convertstring(Phone);
	string pw = Convertstring(Pw);
	string status = Convertstring(Status);
	string path = Convertstring(Path);
	string vis = Convertstring(Visibility);
	string Name = GetFileName("Users.txt");
	fstream file;
	file.open(Name, ios::app);
	file << id << endl << fn << endl << ln << endl << phone << endl << pw << endl << status << endl << path << endl << vis << endl << endl;
	file.close();
}


bool User::CheckNumber(String^ Val) {
	string number = Convertstring(Val);
	bool x = true;
	for (int i = 0; i < number.size(); i++)
	{
		if ((!isdigit(number[i]))) {
			x = false;
			break;
		}
	}
	return x;
}


bool User::CheckLetters(String^ Val) {
	string Name = Convertstring(Val);
	bool x = true;
	for (int i = 0; i < Name.size(); i++)
	{
		if ((isdigit(Name[i]))) {
			x = false;
			break;
		}
	}
	return x;
}


string User::LoginUser(String^ Phone, String^ Password) {
	if (Phone->IsEmpty() || Password->IsEmpty()) {
		return "Error_1";
	}
	else if (Phone->Length() < 11 || CheckNumber(Phone) == false) {
		return "Error_2";
	}
	else if (CheckUserAndPassword(Phone, Password) == "NoUserExist") {
		return "Error_3";
	}
	else if (CheckUserAndPassword(Phone, Password) == "Wrong_Password") {
		return "Error_4";
	}
	else {
		return "Login";
	}
}


User User::GetUserByPh(String^ Phone) {
	User useer;
	vector<string> v;
	string phone = Convertstring(Phone);
	string line;
	string Name = GetFileName("Users.txt");
	ifstream file;
	file.open(Name);
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.size() > 0) {
				v.push_back(line);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == phone) {
				useer.id = stoi(v[i - 3]);
				useer.firstname = ConvertToPlatformString(v[i - 2]);
				useer.lastname = ConvertToPlatformString(v[i - 1]);
				useer.phone = ConvertToPlatformString(v[i]);
				useer.password = ConvertToPlatformString(v[i + 1]);
				useer.discription = ConvertToPlatformString(v[i + 2]);
				useer.imagePath = ConvertToPlatformString(v[i + 3]);
				useer.Visible = ConvertToPlatformString(v[i + 4]);
				break;
			}
		}
	}

	return useer;
	v.clear();
}


int User::GetLastId() {
	vector<string> v;
	string line;
	string Name = GetFileName("Users.txt");
	ifstream file(Name);
	int id = 0;
	while (getline(file, line)) {
		if (line.size() > 0) {
			v.push_back(line);
		}
	}
	for (int i = 0; i < v.size(); i += 8) {
		id = stoi(v[i]);
	}
	return id;
	v.clear();
}


void User::ChangeStatusandPath(int id, String^ status, String^ path, String^ Visibility) {
	string name = GetFileName("Users.txt");
	vector<string> v;
	string line;
	string Status = Convertstring(status);
	string Path = Convertstring(path);
	string vis = Convertstring(Visibility);
	ifstream file;
	file.open(name);

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
				if (Status == "")
				{

					v[i + 6] = Path;
					v[i + 7] = vis;
				}
				else if (Path == "")
				{
					v[i + 5] = Status;
					v[i + 7] = vis;
				}
				else
				{

					v[i + 5] = Status;
					v[i + 6] = Path;
					v[i + 7] = vis;
				}
				break;
			}
		}

		ofstream NewFile;
		NewFile.open(name, ios::trunc);
		if (NewFile.is_open()) {
			for (int i = 0; i < v.size(); i++) {
				if (i % 8 == 0 && i != 0) {
					NewFile << endl;
				}
				NewFile << v[i] << endl;
			}
		}
		NewFile.close();

	}
}


String^ User::GetImage(String^ phone)
{
	string Name = GetFileName("Users.txt");
	ifstream file;
	file.open(Name);
	string line;
	string Phone = Convertstring(phone);
	int counter = 0;
	string store;
	vector<string>v;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			v.push_back(line);
		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == Phone)
		{
			counter++;
			store = v[i + 3];
		}

	}
	if (counter != 0)
	{
		return ConvertToPlatformString(store);
	}
}


int User::GetIDByPh(String^ Phone) {
	vector<string> v;
	string phone = Convertstring(Phone);
	string line;
	string Name = GetFileName("Users.txt");
	int id = 0;
	ifstream file;
	file.open(Name);
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.size() > 0) {
				v.push_back(line);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == phone) {
				id = stoi(v[i - 3]);
				break;
			}
		}
	}

	return id;
	v.clear();
}


bool User::checknumByid(int id, String^ Phone)
{
	vector<string> v;
	vector<string> ret;
	int counter = 0;
	string line;
	string store;
	bool k = false;
	string phone = Convertstring(Phone);
	vector<string>x;
	string Name = GetFileName("Contacts.txt");
	ifstream file(Name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			v.push_back(line);
		}
	}
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
	for (int i = 0; i < x.size(); i++)
	{
		if (i % 2 == 1) {
			ret.push_back(x[i]);
		}
	}
	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] == phone) {
			k = true;
			break;
		}
	}
	return k;
}


bool User::check_visibilty(String^ phone)
{
	string Name = GetFileName("Users.txt");
	ifstream file(Name);
	vector<string>v;
	string line;
	string store;
	string Phone = Convertstring(phone);
	int counter = 0;
	int counterr = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			v.push_back(line);
		}
	}
	int x = GetIDByPh(phone);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == Phone)
		{
			if (v[i + 4] == "True")
			{
				counter++;
			}
			else if (v[i + 4] == "False")
			{
				if (checknumByid(x, LogedInUser.phone) == true) {
					counterr++;
				}
			}
		}

	}
	if (counter != 0 || counterr != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


String^ User::GetPhByid(int id) {
	vector<string>v;
	string name = GetFileName("Users.txt");
	string line;
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == to_string(id)) {
			return ConvertToPlatformString(v[i + 3]);
			break;
		}
	}
}


String^ User::GetNameByid(int id) {
	vector<string>v;
	string name = GetFileName("Users.txt");
	string line;
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == to_string(id)) {
			return ConvertToPlatformString(v[i + 1]);
		}
	}
}


String^ User::GetFullNameByid(int id)
{
	vector<string>v;
	string name = GetFileName("Users.txt");
	string line;
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (getline(file, line)) {
			v.push_back(line);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == to_string(id)) {
			return ConvertToPlatformString(v[i + 1] + " " + v[i + 2]);
		}
	}
}