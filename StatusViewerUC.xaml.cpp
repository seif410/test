//
// StatusViewerUC.xaml.cpp
// Implementation of the StatusViewerUC class
//

#include "pch.h"
#include "StatusViewerUC.xaml.h"

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
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Popups;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

StatusViewerUC::StatusViewerUC()
{
	InitializeComponent();
}


Chat_uwp::StatusViewerUC::StatusViewerUC(StatusUC^ currentStatusUC, String^ cPhone)
{
	InitializeComponent();
	Storyboard1->Begin();
	this->currentStatusUC = currentStatusUC;
	stories = sto.show(User::LogedInUser.GetIDByPh(cPhone));
	statNo = 0;
	back_btn->Visibility = visisi->Visibility;
	if (stories.size() == 1) {
		next_btn->Visibility = visisi->Visibility;
		back_btn->Visibility = visisi->Visibility;
	}
	if (!stories.empty()) {
		status_image->Source = ref new BitmapImage(ref new Uri(User::LogedInUser.ConvertToPlatformString(stories[0]->imagepath)));
		status_txt->Text = User::LogedInUser.ConvertToPlatformString(stories[0]->storytext);
	}
}


void Chat_uwp::StatusViewerUC::next_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (statNo + 1 < stories.size()) {
		Storyboard2->Begin();
		statNo++;
		status_image->Source = ref new BitmapImage(ref new Uri(User::LogedInUser.ConvertToPlatformString(stories[statNo]->imagepath)));
		status_txt->Text = User::LogedInUser.ConvertToPlatformString(stories[statNo]->storytext);
		back_btn->Visibility = status_image->Visibility;
		if (statNo + 1 == stories.size()) {
			next_btn->Visibility = visisi->Visibility;
		}
	}
}


void Chat_uwp::StatusViewerUC::back_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (statNo != 0) {
		Storyboard2->Begin();
		statNo--;
		status_image->Source = ref new BitmapImage(ref new Uri(User::LogedInUser.ConvertToPlatformString(stories[statNo]->imagepath)));
		status_txt->Text = User::LogedInUser.ConvertToPlatformString(stories[statNo]->storytext);
		next_btn->Visibility = status_image->Visibility;
		if (statNo == 0) {
			back_btn->Visibility = visisi->Visibility;
		}
	}
}


void Chat_uwp::StatusViewerUC::close_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentStatusUC->close_btn_Clicked();
}