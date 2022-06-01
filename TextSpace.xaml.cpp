//
// TextSpace.xaml.cpp
// Implementation of the TextSpace class
//

#include "pch.h"
#include "TextSpace.xaml.h"
#include"messageUC.xaml.h"
#include "messageGroupUC.xaml.h"

using namespace Chat_uwp;
using namespace std;
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
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI;
// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236


TextSpace::TextSpace()
{
	InitializeComponent();

}


TextSpace::~TextSpace() {
	if (!Messages.empty()) {
		if (Type != "Group") {
			msg.send(Messages, User::LogedInUser.phone, Phone);
			for (int i = 0; i <= Messages.size(); i++) {
				Messages.pop();
			}
		}
		else {
			ngrp.sendMessage(Messages, GrpName, User::LogedInUser.phone, user2, user3, user4, user5, user6, user7, user8, user9, user10, count);
			for (int i = 0; i <= Messages.size(); i++) {
				Messages.pop();
			}
		}
	}

}


Chat_uwp::TextSpace::TextSpace(String^ cPhone, String^ cName, int id, String^ Type)
{
	InitializeComponent();
	name_lbl->Text = cName;
	this->Type = Type;
	if (usr.check_visibilty(cPhone) == true)
	{
		image_image->Source = ref new BitmapImage(ref new Uri(usr.GetImage(cPhone)));
	}
	else
	{
		image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/Default.png"));
	}
	Phone = cPhone;
	ID = id;
	msgsLoaded = msg.read(User::LogedInUser.id, ID, User::LogedInUser.phone, cPhone);
	if (!msgsLoaded.empty()) {
		for (int i = 0; i < msgsLoaded.size(); i++)
		{
			messages_pnl->Children->Append(ref new messageUC(msgsLoaded[i]->message, msgsLoaded[i]->senderId == User::LogedInUser.id, msgsLoaded[i]->getTime(), msgsLoaded[i]->isSeen));
		}
	}
}


Chat_uwp::TextSpace::TextSpace(String^ cName, String^ Type, String^ user1, String^ user2, String^ user3, String^ user4, String^ user5, String^ user6, String^ user7, String^ user8, String^ user9, String^ user10, int count, String^ Path)
{
	InitializeComponent();
	name_lbl->Text = cName;
	this->GrpName = cName;
	this->Type = Type;
	this->user1 = user1;
	this->user2 = user2;
	this->user3 = user3;
	this->user4 = user4;
	this->user5 = user5;
	this->user6 = user6;
	this->user7 = user7;
	this->user8 = user8;
	this->user9 = user9;
	this->user10 = user10;
	this->count = count;
	this->Path = Path;
	image_image->Source = ref new BitmapImage(ref new Uri(Path));
	grpmsgsLoaded = ngrp.grpRead(GrpName, user1, user2, user3, user4, user5, user6, user7, user8, user9, user10, count);
	for (int i = 0; i < grpmsgsLoaded.size(); i++)
	{
		bool isfound = false;
		for (int j = 0; j < members.size(); j++)
		{
			if (grpmsgsLoaded[i]->senderId1 == members[j]) {
				isfound = true;
				break;
			}
		}
		if (isfound == false)
		{
			members.push_back(grpmsgsLoaded[i]->senderId1);
		}
	}
	if (!grpmsgsLoaded.empty()) {
		for (int i = 0; i < grpmsgsLoaded.size(); i++)
		{
			for (int j = 0; j < members.size(); j++)
			{
				if (grpmsgsLoaded[i]->senderId1 == members[j]) {
					if (i == 0) {
						messages_pnl->Children->Append(ref new messageGroupUC(grpmsgsLoaded[i]->message, grpmsgsLoaded[i]->senderId1 == User::LogedInUser.id,
							grpmsgsLoaded[i]->getTime(), User::LogedInUser.GetFullNameByid(grpmsgsLoaded[i]->senderId1), members[j]));
					}
					else {
						messages_pnl->Children->Append(ref new messageGroupUC(grpmsgsLoaded[i]->message, grpmsgsLoaded[i]->senderId1 == User::LogedInUser.id,
							grpmsgsLoaded[i]->getTime(), User::LogedInUser.GetFullNameByid(grpmsgsLoaded[i]->senderId1), members[j], grpmsgsLoaded[i - 1]->senderId1 == grpmsgsLoaded[i]->senderId1));
					}
					break;
				}
			}
		}
	}
}


void Chat_uwp::TextSpace::send_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (Type != "Group") {
		Message msg(message_txt->Text, User::LogedInUser.id, ID);
		if (!message_txt->Text->IsEmpty()) {
			Messages.push(message_txt->Text + "," + User::LogedInUser.id + "," + ID + "," + "False" + "," + msg.mesTime[0] + ":" + msg.mesTime[1] + ":" + msg.mesTime[2] + "/" + msg.mesTime[3] + "/" + msg.mesTime[4]);
			messages_pnl->Children->Append(ref new messageUC(msg.message, 1, msg.getTime(), msg.isSeen));
			message_txt->Text = "";
		}
	}
	else {
		Message msg(message_txt->Text, User::LogedInUser.id, ID);
		if (!message_txt->Text->IsEmpty()) {
			Messages.push(message_txt->Text + "," + User::LogedInUser.id + "," + usr.GetIDByPh(user2) + "," + usr.GetIDByPh(user3) + "," + usr.GetIDByPh(user4) + "," + usr.GetIDByPh(user5)
				+ "," + usr.GetIDByPh(user6) + "," + usr.GetIDByPh(user7) + "," + usr.GetIDByPh(user8) + "," + usr.GetIDByPh(user9) + "," + usr.GetIDByPh(user10)
				+ "," + "0" + "," + msg.mesTime[0] + ":" + msg.mesTime[1] + ":" + msg.mesTime[2] + "/" + msg.mesTime[3] + "/" + msg.mesTime[4]);
			messages_pnl->Children->Append(ref new messageGroupUC(msg.message, 1, msg.getTime(), "Ana", 0));
			message_txt->Text = "";
		}
	}
}


void Chat_uwp::TextSpace::undo_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (!Messages.empty())
	{
		Messages.pop();
		messages_pnl->Children->RemoveAtEnd();
	}
}


