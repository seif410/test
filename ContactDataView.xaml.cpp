//
// ContactDataView.xaml.cpp
// Implementation of the ContactDataView class
//

#include "pch.h"
#include "ContactDataView.xaml.h"

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
using namespace Windows::UI::Xaml::Media::Imaging;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

ContactDataView::ContactDataView()
{
	InitializeComponent();
}


Chat_uwp::ContactDataView::ContactDataView(String^ imagePath, String^ name, String^ phone, String^ description)
{
	InitializeComponent();
	Storyboard1->Begin();
	this->image_image->Source = ref new BitmapImage(ref new Uri(imagePath));
	this->name_lbl->Text = name;
	this->phone_lbl->Text = phone;
	this->description_lbl->Text = description;
}