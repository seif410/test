//
// ContactsUC.xaml.h
// Declaration of the ContactsUC class
//

#pragma once

#include "ContactsUC.g.h"
#include "AddContact.xaml.h"
#include "User.h"
#include "Story.h"

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ContactsUC sealed
	{
	public:
		ContactsUC();
		ContactsUC(String^ userPhone);
		void contact_clicked(String^ cPhone);
	private:
		AddContact^ addContact;
		vector<Contacts*> contacts;
		Contacts con;
		Story stry;
		void addContact_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
