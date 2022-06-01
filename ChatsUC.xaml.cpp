//
// ChatsUC.xaml.cpp
// Implementation of the ChatsUC class
//

#include "pch.h"
#include "ChatsUC.xaml.h"
#include"TextSpace.xaml.h"
#include "ContactUC.xaml.h"
#include "NewGroupUC.xaml.h"

using namespace Chat_uwp;
using namespace Windows::UI::Popups;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;


// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

ChatsUC::ChatsUC()
{
	InitializeComponent();
}


Chat_uwp::ChatsUC::~ChatsUC()
{
	chat_grid->Children->Clear();
}


void Chat_uwp::ChatsUC::destruct()
{
	chat_grid->Children->Clear();
}


Chat_uwp::ChatsUC::ChatsUC(String^ userPhone)
{
	InitializeComponent();
	newGroup = ref new NewGroupUC();
	message = msgs.ShowChat(userPhone);
	Groups = nh.ShowGroups(userPhone);
	for (int i = 0; i < message.size(); i++)
	{
		friends_pnl->Children->Append(ref new ContactUC(this, userPhone, message[i]->Name, message[i]->Phone, message[i]->Type));
	}
	for (int i = 0; i < Groups.size(); i++)
	{
		friends_pnl->Children->Append(ref new ContactUC(this, userPhone, Groups[i]->Name, Groups[i]->Phone2, Groups[i]->Phone3, Groups[i]->Phone4, Groups[i]->Phone5, Groups[i]->Phone6
			, Groups[i]->Phone7, Groups[i]->Phone8, Groups[i]->Phone9, Groups[i]->Phone10, Groups[i]->Type, Groups[i]->Count, Groups[i]->Path));
	}
}


void Chat_uwp::ChatsUC::contact_clicked(String^ cPhone, String^ cName, String^ Type)
{
	chat_grid->Children->Clear();
	chat_grid->Children->Append(ref new TextSpace(cPhone, cName, user.GetIDByPh(cPhone), Type));
}


void Chat_uwp::ChatsUC::contact_clicked(String^ cName, String^ Type, String^ user1, String^ user2, String^ user3, String^ user4, String^ user5, String^ user6, String^ user7, String^ user8, String^ user9, String^ user10, int count, String^ Path)
{
	chat_grid->Children->Clear();
	chat_grid->Children->Append(ref new TextSpace(cName, Type, user1, user2, user3, user4, user5, user6, user7, user8, user9, user10, count, Path));
}


void Chat_uwp::ChatsUC::newGroup_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat_grid->Children->Clear();
	chat_grid->Children->Append(newGroup);
	newGroup->animation();
}