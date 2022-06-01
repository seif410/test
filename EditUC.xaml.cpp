//
// EditUC.xaml.cpp
// Implementation of the EditUC class
//

#include "pch.h"
#include "EditUC.xaml.h"
#include "MainPage.g.h"
#include "Entry.g.h"
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

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

EditUC::EditUC()
{
	InitializeComponent();
	bool x;
	if (User::LogedInUser.Visible == "True") {
		x = true;
	}
	else {
		x = false;
	}
	visiblity_check->IsChecked = x;
}


Chat_uwp::EditUC::EditUC(Entry^ entry)
{
	InitializeComponent();
	bool x;
	if (User::LogedInUser.Visible == "True") {
		x = true;
	}
	else {
		x = false;
	}
	visiblity_check->IsChecked = x;
	this->entry = entry;
}


void Chat_uwp::EditUC::addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	auto picker = ref new FileOpenPicker();
	picker->FileTypeFilter->Append(L".png");
	picker->FileTypeFilter->Append(L".jpg");
	picker->SuggestedStartLocation = PickerLocationId::Desktop;
	auto task = create_task(picker->PickSingleFileAsync()).then(
		[this](StorageFile^ SSfile)
		{
			if (SSfile) {
				pathh = "ms-appx:///Assets/pp/" + SSfile->Name;
				image_image->Source = ref new BitmapImage(ref new Uri(pathh));
			}
		});
}


void Chat_uwp::EditUC::load_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	pathh = "";
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/"));
}


void Chat_uwp::EditUC::edit_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (visiblity_check->IsChecked->Value == true) {
		if (pathh == "") {
			pathh = User::LogedInUser.imagePath;
			userrr.ChangeStatusandPath(User::LogedInUser.id, newDiscription_txt->Text, pathh, "True");
		}
		else {
			userrr.ChangeStatusandPath(User::LogedInUser.id, newDiscription_txt->Text, pathh, "True");
			entry->changeImage(pathh);
		}
	}
	else {
		if (pathh == "") {
			pathh = User::LogedInUser.imagePath;
			userrr.ChangeStatusandPath(User::LogedInUser.id, newDiscription_txt->Text, pathh, "False");
		}
		else {
			userrr.ChangeStatusandPath(User::LogedInUser.id, newDiscription_txt->Text, pathh, "False");
			entry->changeImage(pathh);
		}
	}
	newDiscription_txt->Text = "";
	pathh = "";
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/"));
	MessageDialog^ msg = ref new MessageDialog("Edited Succesfully");
	msg->ShowAsync();
}