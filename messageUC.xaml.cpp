//
// messageUC.xaml.cpp
// Implementation of the messageUC class
//

#include "pch.h"
#include <vector>
#include "messageUC.xaml.h"
#include"MainPage.xaml.h"

using namespace Chat_uwp;
using namespace std;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236
messageUC::messageUC(void)
{
	InitializeComponent();

}


messageUC::messageUC(String^ mess)
{
	InitializeComponent();
	this->message_lbl->Text = mess;
}


Chat_uwp::messageUC::messageUC(String^ message, bool sender, String^ time, bool isSeen)
{
	InitializeComponent();
	if (sender) {
		this->HorizontalAlignment = time_lbl->HorizontalAlignment;
		message_grid->Background = ref new SolidColorBrush(ColorHelper::FromArgb(255, 26, 53, 92));
		time_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 90, 107, 120));
	}
	else {
		seen_circle->Fill = message_grid->Background;
	}
	if (isSeen && sender) {
		seen_circle->Fill = ref new SolidColorBrush(ColorHelper::FromArgb(255, 52, 175, 140));
	}
	time_lbl->Text = time;
	this->message_lbl->Text = message;
}
