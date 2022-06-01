//
// messageGroupUC.xaml.cpp
// Implementation of the messageGroupUC class
//

#include "pch.h"
#include "messageGroupUC.xaml.h"

using namespace Chat_uwp;

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

messageGroupUC::messageGroupUC()
{
	InitializeComponent();
}


Chat_uwp::messageGroupUC::messageGroupUC(String^ message, bool sender, String^ time, String^ fName, int fNo)
{
	InitializeComponent();
	if (sender) {
		this->HorizontalAlignment = time_lbl->HorizontalAlignment;
		message_grid->Background = ref new SolidColorBrush(ColorHelper::FromArgb(255, 26, 53, 92));
		time_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 90, 107, 120));
		fName_lbl->Visibility = visi->Visibility;
	}
	else {
		switch (fNo)
		{
		case 0:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 200, 93, 93));
			break;
		case 1:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 93, 96, 200));
			break;
		case 2:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 54, 183, 113));
			break;
		case 3:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 183, 54, 54));
			break;
		case 4:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 183, 115, 54));
			break;
		case 5:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 103, 71, 0));
			break;
		case 6:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 8, 114, 26));
			break;
		case 7:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 131, 91, 108));
			break;
		case 8:
			fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 187, 93, 200));
			break;
		}
	}
	fName_lbl->Text = fName;
	time_lbl->Text = time;
	this->message_lbl->Text = message;
}


Chat_uwp::messageGroupUC::messageGroupUC(String^ message, bool sender, String^ time, String^ fName, int fNo, bool collapseName)
{
	InitializeComponent();
	if (sender) {
		this->HorizontalAlignment = time_lbl->HorizontalAlignment;
		message_grid->Background = ref new SolidColorBrush(ColorHelper::FromArgb(255, 26, 53, 92));
		time_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 90, 107, 120));
		fName_lbl->Visibility = visi->Visibility;
	}
	else {
		if (collapseName) {
			fName_lbl->Visibility = visi->Visibility;
			this->Margin = Windows::UI::Xaml::Thickness(4, 2, 4, 2);
		}
		else {
			this->Margin = Windows::UI::Xaml::Thickness(4, 16, 4, 2);
			switch (fNo)
			{
			case 0:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 200, 93, 93));
				break;

			case 1:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 93, 96, 200));
				break;

			case 2:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 54, 183, 113));
				break;

			case 3:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 183, 54, 54));
				break;

			case 4:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 183, 115, 54));
				break;

			case 5:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 103, 71, 0));
				break;

			case 6:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 8, 114, 26));
				break;

			case 7:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 131, 91, 108));
				break;

			case 8:
				fName_lbl->Foreground = ref new SolidColorBrush(ColorHelper::FromArgb(255, 187, 93, 200));
				break;
			}
		}
	}
	fName_lbl->Text = fName;
	time_lbl->Text = time;
	this->message_lbl->Text = message;
}
