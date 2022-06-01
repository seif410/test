//
// AddStatusUC.xaml.cpp
// Implementation of the AddStatusUC class
//

#include "pch.h"
#include "AddStatusUC.xaml.h"

using namespace Chat_uwp;
using namespace Windows::Storage;
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

AddStatusUC::AddStatusUC()
{
	InitializeComponent();
	Storyboard1->Begin();
}


void Chat_uwp::AddStatusUC::animation()
{
	Storyboard1->Begin();
}


void Chat_uwp::AddStatusUC::addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	auto picker = ref new FileOpenPicker();
	picker->FileTypeFilter->Append(L".png");
	picker->FileTypeFilter->Append(L".jpg");
	picker->SuggestedStartLocation = PickerLocationId::Desktop;

	auto task = create_task(picker->PickSingleFileAsync()).then(
		[this](StorageFile^ SSfile)
		{
			if (SSfile) {
				spath = "ms-appx:///Assets/story/" + SSfile->Name;
				image_image->Source = ref new BitmapImage(ref new Uri(spath));
			}
		});
}


void Chat_uwp::AddStatusUC::load_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	spath = "";
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/story/"));
}


void Chat_uwp::AddStatusUC::Add_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (spath) {
		if (statusTxt_txt->Text == "") {
			statusTxt_txt->Text = "   ";
		}
		storyy.AddStatus(User::LogedInUser.id, spath, statusTxt_txt->Text);
		statusTxt_txt->Text = "";
		image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/"));
		spath = "";
		MessageDialog^ msg = ref new MessageDialog("Status Added");
		msg->ShowAsync();
	}
	else {
		MessageDialog^ msg = ref new MessageDialog("Please add an image");
		msg->ShowAsync();
	}
}