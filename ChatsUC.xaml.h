//
// ChatsUC.xaml.h
// Declaration of the ChatsUC class
//

#pragma once

#include "ChatsUC.g.h"
#include "User.h"
#include <vector>
#include "Contacts.h"
#include "Message.h"
#include "NewGroupUC.xaml.h"
#include "NewGp.h"

using namespace Platform;
using namespace std;
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ChatsUC sealed
	{
	private:
		vector<Contacts*> contacts;
		vector<NewGp*> Groups;
		vector<Message*> message;
		User user;
		Contacts con;
		Message msgs;
		NewGroupUC^ newGroup;
		NewGp nh;
		void newGroup_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	public:
		ChatsUC();
		ChatsUC(String^);
		virtual ~ChatsUC();
		void destruct();
		void contact_clicked(String^ cPhone, String^ cName, String^ Type);
		void contact_clicked(String^ cName, String^ Type, String^ user1, String^ user2, String^ user3, String^ user4, String^ user5, String^ user6, String^ user7, String^ user8, String^ user9, String^ user10, int count, String^ Path);
	};
}
