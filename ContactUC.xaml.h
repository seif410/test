//
// ContactUC.xaml.h
// Declaration of the ContactUC class
//

#pragma once

#include "ContactUC.g.h"
#include "ChatsUC.xaml.h"
#include "ContactsUC.xaml.h"
#include "StatusUC.xaml.h"
using namespace std;
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ContactUC sealed
	{
	public:
		ContactUC();
		ContactUC(ChatsUC^ currentChat);
		ContactUC(ChatsUC^ currentChat, String^ userPhone, String^ cName, String^ cPhone, String^ Type);
		ContactUC(ChatsUC^ currentChat, String^ userPhone, String^ GroupName, String^ Cphone2, String^ Cphone3, String^ Cphone4, String^ Cphone5,
			String^ Cphone6, String^ Cphone7, String^ Cphone8, String^ Cphone9, String^ Cphone10, String^ Type, int count, String^ Path);
		ContactUC(StatusUC^ statusView, String^ userPhone, String^ cName, String^ cPhone);
		ContactUC(ContactsUC^ contactsView, String^ userPhone, String^ cName, String^ cPhone);
	private:
		ChatsUC^ currentChat;
		StatusUC^ statusView;
		ContactsUC^ contactsView;
		int pageLoded;
		String^ userPhone;
		String^ userPhone2;
		String^ userPhone3;
		String^ userPhone4;
		String^ userPhone5;
		String^ userPhone6;
		String^ userPhone7;
		String^ userPhone8;
		String^ userPhone9;
		String^ userPhone10;
		String^ cPhone;
		String^ Type;
		String^ Path;
		int count;
		User user;
		void name_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
