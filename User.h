#pragma once
#include <iostream>
#include <stack>
using namespace Platform;
using namespace std;

class User
{
public:
	int id;
	String^ firstname;
	String^ lastname;
	String^ phone;
	String^ password;
	String^ discription;
	String^ imagePath;
	String^ Visible;
	static User LogedInUser;
	string Register(String^, String^, String^, String^, String^);
	void Registeration(int, String^, String^, String^, String^, String^, String^, String^);
	string LoginUser(String^, String^);
	string GetFileName(String^);
	bool CheckUserExist(String^);
	bool CheckNumber(String^);
	string CheckUserAndPassword(String^, String^);
	bool CheckLetters(String^);
	User GetUserByPh(String^);
	int GetIDByPh(String^);
	int GetLastId();
	String^ ConvertToPlatformString(string);
	string Convertstring(String^);
	void ChangeStatusandPath(int, String^, String^, String^);
	String^ GetImage(String^);
	bool checknumByid(int id, String^ Phone);
	bool check_visibilty(String^ phone);
	String^ GetPhByid(int id);
	String^ GetNameByid(int id);
	String^ GetFullNameByid(int id);
	User(void);
	~User();
};