//
// TextSpace.xaml.h
// Declaration of the TextSpace class
//

#pragma once

#include "TextSpace.g.h"
#include "messageUC.xaml.h"
#include "User.h"
#include <vector>
#include <stack>
#include "NewGp.h"
#include "Message.h"

using namespace std;
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TextSpace sealed
	{
	public:
		TextSpace();
		TextSpace(String^ cPhone, String^ cName, int id, String^ Type);
		TextSpace(String^ cName, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, String^, int, String^);
		virtual ~TextSpace();
	private:
		int ID;
		int count;
		String^ GrpName;
		String^ Phone;
		String^ user1;
		String^ user2;
		String^ user3;
		String^ user4;
		String^ user5;
		String^ user6;
		String^ user7;
		String^ user8;
		String^ user9;
		String^ user10;
		String^ Type;
		String^ Path;
		vector<int> members;
		vector<Message*> msgsLoaded;
		vector<NewGp*> grpmsgsLoaded;
		stack<String^> Messages;
		Message msg;
		NewGp ngrp;
		User usr;
		void send_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void undo_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
