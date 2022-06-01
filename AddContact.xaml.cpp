//
// AddContact.xaml.cpp
// Implementation of the AddContact class
//

#include "pch.h"
#include "AddContact.xaml.h"

using namespace Chat_uwp;

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
using namespace Windows::UI::Popups;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

AddContact::AddContact()
{
	InitializeComponent();
}


void Chat_uwp::AddContact::animation()
{
	Storyboard1->Begin();
}


void Chat_uwp::AddContact::add_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (phoneNumber_txt->Text != "" && name_txt->Text != "") {
		if (users.CheckUserExist(phoneNumber_txt->Text) == false && phoneNumber_txt->Text != User::LogedInUser.phone) {
			c.add(User::LogedInUser.id, phoneNumber_txt->Text, name_txt->Text);
			phoneNumber_txt->Text = "";
			name_txt->Text = "";
			MessageDialog^ msg = ref new MessageDialog("Contact Added");
			msg->ShowAsync();
		}
		else if (phoneNumber_txt->Text == User::LogedInUser.phone) {
			MessageDialog^ msg = ref new MessageDialog("You Can't Add Your Phone Number As a Contact");
			msg->ShowAsync();
			phoneNumber_txt->Text = "";
		}
		else {
			phoneNumber_txt->Text = "";
			name_txt->Text = "";
			MessageDialog^ msg = ref new MessageDialog("This User Doesn't Exist");
			msg->ShowAsync();
		}
	}
	else {
		MessageDialog^ msg = ref new MessageDialog("Please Fill All The Data");
		msg->ShowAsync();
	}
}
