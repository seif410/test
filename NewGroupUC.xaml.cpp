//
// NewGroupUC.xaml.cpp
// Implementation of the NewGroupUC class
//

#include "pch.h"
#include "Message.h"
#include "NewGroupUC.xaml.h"

using namespace std;

using namespace Windows::Storage;
using namespace Chat_uwp;
using namespace Platform;
using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI;
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

NewGroupUC::NewGroupUC()
{
	InitializeComponent();
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/group_def.png"));
	ipath = "ms-appx:///Assets/pp/group_def.png";
}


void Chat_uwp::NewGroupUC::animation()
{
	Storyboard1->Begin();
}


void Chat_uwp::NewGroupUC::group_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	contacts_pnl2->Visibility = create_btn->Visibility;
	image_grid->Visibility = create_btn->Visibility;
	groupName_lbl->Visibility = create_btn->Visibility;
	groupName_txt->Visibility = create_btn->Visibility;
	title_lbl->Text = "Create new group chat";
	group_btn->Background = private_btn->Background;
	private_btn->Background = ref new SolidColorBrush(ColorHelper::FromArgb(255, 108, 108, 108));
}


void Chat_uwp::NewGroupUC::private_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	contacts_pnl2->Visibility = visi->Visibility;
	image_grid->Visibility = visi->Visibility;
	groupName_lbl->Visibility = visi->Visibility;
	groupName_txt->Visibility = visi->Visibility;
	title_lbl->Text = "Create new private chat";
	private_btn->Background = group_btn->Background;
	group_btn->Background = ref new SolidColorBrush(ColorHelper::FromArgb(255, 108, 108, 108));
}


void Chat_uwp::NewGroupUC::addImage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	auto picker = ref new FileOpenPicker();
	picker->FileTypeFilter->Append(L".png");
	picker->FileTypeFilter->Append(L".jpg");
	picker->SuggestedStartLocation = PickerLocationId::Desktop;
	auto task = create_task(picker->PickSingleFileAsync()).then(
		[this](StorageFile^ SSfile)
		{
			if (SSfile) {
				ipath = "ms-appx:///Assets/pp/" + SSfile->Name;
				image_image->Source = ref new BitmapImage(ref new Uri(ipath));
			}
		});
}


void Chat_uwp::NewGroupUC::remove_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ipath = "";
	image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/group_def.png"));
}


void Chat_uwp::NewGroupUC::create_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (groupName_txt->Text->IsEmpty() && !contact1_txt->Text->IsEmpty()) {
		if (ms.GetFileId(User::LogedInUser.phone, contact1_txt->Text) == 0) {
			ms.CreateChat(User::LogedInUser.phone, contact1_txt->Text);
			MessageDialog^ msg = ref new MessageDialog("A Private Chat With " + contact1_txt->Text + " Is Created");
			contact1_txt->Text = "";
			msg->ShowAsync();
		}
		else {
			MessageDialog^ msg = ref new MessageDialog("There's A Chat Already Exists With This Phone No.");
			contact1_txt->Text = "";
			msg->ShowAsync();
		}
	}
	else {
		int count = ng.MemberCount(User::LogedInUser.phone, contact1_txt->Text, contact2_txt->Text, contact3_txt->Text, contact4_txt->Text, contact5_txt->Text, contact6_txt->Text, contact7_txt->Text, contact8_txt->Text, contact9_txt->Text);
		if (ng.GetFileId(groupName_txt->Text, User::LogedInUser.phone, contact1_txt->Text, contact2_txt->Text, contact3_txt->Text, contact4_txt->Text,
			contact5_txt->Text, contact6_txt->Text, contact7_txt->Text, contact8_txt->Text, contact9_txt->Text, count) == 0)
		{
			ng.CreateGP(groupName_txt->Text, User::LogedInUser.phone, contact1_txt->Text, contact2_txt->Text, contact3_txt->Text, contact4_txt->Text,
				contact5_txt->Text, contact6_txt->Text, contact7_txt->Text, contact8_txt->Text, contact9_txt->Text, ipath);
			MessageDialog^ msg = ref new MessageDialog("Group " + groupName_txt->Text + " is Created");
			groupName_txt->Text = "";
			contact1_txt->Text = "";
			contact2_txt->Text = "";
			contact3_txt->Text = "";
			contact4_txt->Text = "";
			contact5_txt->Text = "";
			contact6_txt->Text = "";
			contact7_txt->Text = "";
			contact8_txt->Text = "";
			contact9_txt->Text = "";
			msg->ShowAsync();
		}
		else {
			MessageDialog^ msg = ref new MessageDialog("This Group Already Exists");
			msg->ShowAsync();
		}
	}
}