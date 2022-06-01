#pragma once
#include <vector>
#include <stack>
#include "Contacts.h"

using namespace Platform;
class Message
{
public:
	Message();
	Message(String^, String^, String^);
	Message(String^ message, int senderId, int receverId);
	Message(String^ message, int senderId, int receiverId, bool isSeen, String^ mesTime);
	String^ message;
	String^ Name;
	String^ Phone;
	String^ Type;
	String^ getTime();
	bool isSeen;
	int senderId;
	int receiverId;
	int GetFileId(String^, String^);
	int GetLastId();
	vector<Contacts*> contacts;
	vector<int> mesTime;
	vector<Message*> read(int, int, String^, String^);
	vector<Message*> ShowChat(String^);
	void send(stack<String^>, String^, String^);
	void CreateChat(String^, String^);
	void ChangeSeen(int, int, String^, String^);
private:
	User c;
	Contacts con;
	stack<String^> copystack;
};