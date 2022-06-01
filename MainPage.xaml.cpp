//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "MainPage.g.h"
#include "RegisterPage.g.h"
#include "Entry.g.h"

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
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Popups;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage() {
	InitializeComponent();
	Storyboard1->Begin();
}


void Chat_uwp::MainPage::login_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (user.LoginUser(phoneNumber_txt->Text, password_txt->Password->ToString()) == "Error_1") {
		MessageDialog^ msg = ref new MessageDialog("Please Fill All The Data");
		msg->ShowAsync();
	}
	else if (user.LoginUser(phoneNumber_txt->Text, password_txt->Password->ToString()) == "Error_2") {
		MessageDialog^ msg = ref new MessageDialog("Phone Number is In Wrong Format");
		msg->ShowAsync();
	}
	else if (user.LoginUser(phoneNumber_txt->Text, password_txt->Password->ToString()) == "Error_3") {
		MessageDialog^ msg = ref new MessageDialog("This User Doesn't Exist");
		msg->ShowAsync();
		phoneNumber_txt->Text = "";
	}
	else if (user.LoginUser(phoneNumber_txt->Text, password_txt->Password->ToString()) == "Error_4") {
		MessageDialog^ msg = ref new MessageDialog("Wrong Password");
		msg->ShowAsync();
		password_txt->Password = "";
	}
	else if (user.LoginUser(phoneNumber_txt->Text, password_txt->Password->ToString()) == "Login") {
		User::LogedInUser = User::LogedInUser.GetUserByPh(phoneNumber_txt->Text);
		this->Frame->Navigate(TypeName(Entry::typeid), phoneNumber_txt->Text);
	}
}


void Chat_uwp::MainPage::createAcc_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	this->Frame->Navigate(TypeName(RegisterPage::typeid));
}


void MainPage::OnNavigatedTo(NavigationEventArgs^ e) {
	phoneNumber_txt->Text = e->Parameter->ToString();
}