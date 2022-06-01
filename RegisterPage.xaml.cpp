//
// RegisterPage.xaml.cpp
// Implementation of the RegisterPage class
//

#include "pch.h"
#include "RegisterPage.xaml.h"
#include "MainPage.g.h"
#include <stdio.h>
#include <string>


using namespace std;

using namespace Windows::Storage;
using namespace Chat_uwp;
using namespace Platform;
using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Foundation;
using namespace Windows::UI::Popups;


String^ path = "ms-appx:///Assets/pp/Default.png";


// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238
RegisterPage::RegisterPage()
{
	InitializeComponent();
	description_txt->Text = "Hey There, Iam Using Chatto";
	visiblity_check->IsChecked = true;
}


void Chat_uwp::RegisterPage::addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	auto picker = ref new FileOpenPicker();
	picker->FileTypeFilter->Append(L".png");
	picker->FileTypeFilter->Append(L".jpg");
	picker->SuggestedStartLocation = PickerLocationId::Desktop;
	auto task = create_task(picker->PickSingleFileAsync()).then(
		[this](StorageFile^ SSfile)
		{
			if (SSfile) {
				path = "ms-appx:///Assets/pp/" + SSfile->Name;
				image_image->Source = ref new BitmapImage(ref new Uri(path));
			}
		});
}


void Chat_uwp::RegisterPage::addImage_btn_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	path = "";
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/Default.png"));
}


void Chat_uwp::RegisterPage::createAcc_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	//visiblity_switch->IsOn();
	if (users.Register(firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text) == "Error_1") {
		//fill
		MessageDialog^ msg = ref new MessageDialog("Please Fill All The Data");
		msg->ShowAsync();
	}
	else if (users.Register(firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text) == "Error_2") {
		//wrong format
		MessageDialog^ msg = ref new MessageDialog("Phone is In Wrong Format");
		msg->ShowAsync();
	}
	else if (users.Register(firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text) == "Error_3") {
		//User Already Exists
		MessageDialog^ msg = ref new MessageDialog("User Already Exists, Please Try Another Number");
		msg->ShowAsync();
	}
	else if (users.Register(firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text) == "Error_4") {
		//User Already Exists
		MessageDialog^ msg = ref new MessageDialog("First and Last Name Should Contain Letters Only");
		msg->ShowAsync();
	}
	else {
		int id = stoi(users.Register(firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text));
		if (visiblity_check->IsChecked->Value == true) {
			users.Registeration(id, firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text, path, "True");
		}
		else {
			users.Registeration(id, firstname_txt->Text, lastname_txt->Text, phoneNumber_txt->Text, password_txt->Password->ToString(), description_txt->Text, path, "False");
		}
		path = "ms-appx:///Assets/pp/Default.png";
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Chat_uwp::RegisterPage::back_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid));
}


void RegisterPage::OnNavigatedTo(NavigationEventArgs^ e) {
	phoneNumber_txt->Text = e->Parameter->ToString();
}

