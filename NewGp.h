#pragma once
#include <vector>
#include <stack>
#include "Message.h"

using namespace Platform;
class NewGp
{
public:
	NewGp(void);
	NewGp(String^, int, int, int, int, int, int, int, int, int, int, bool, String^);
	NewGp(String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, int, String^);
	int id;
	int Count;
	String^ Name;
	String^ Type;
	String^ Phone1;
	String^ Phone2;
	String^ Phone3;
	String^ Phone4;
	String^ Phone5;
	String^ Phone6;
	String^ Phone7;
	String^ Phone8;
	String^ Phone9;
	String^ Phone10;
	String^ Path;
	String^ message;
	String^ getTime();
	bool isSeen;
	int senderId1;
	int receiverId1;
	int receiverId2;
	int receiverId3;
	int receiverId4;
	int receiverId5;
	int receiverId6;
	int receiverId7;
	int receiverId8;
	int receiverId9;
	int GetFileId(String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, int);
	int MemberCount(String^, String^, String^, String^, String^, String^, String^, String^, String^, String^);
	void sendMessage(stack<String^> stack, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, int);
	void CreateGP(String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^);
	vector<NewGp*> ShowGroups(String^);
	vector<NewGp*> grpRead(String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, int);
private:
	vector<String^> members;
	stack<String^> copystack;
	vector<int> mesTime;
	User uu;
	Message msgss;
};

