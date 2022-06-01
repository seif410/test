//
// AddContact.xaml.h
// Declaration of the AddContact class
//

#pragma once

#include "AddContact.g.h"
#include "User.h"
#include <Contacts.h>

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AddContact sealed
	{
	public:
		AddContact();
		void animation();
	private:
		Contacts c;
		User users;
		void add_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
