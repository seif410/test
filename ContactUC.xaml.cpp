//
// ContactUC.xaml.cpp
// Implementation of the ContactUC class
//
#include "pch.h"
#include "ContactUC.xaml.h"
#include "ChatsUC.xaml.h"
using namespace Chat_uwp;
using namespace std;
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

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236
ContactUC::ContactUC()
{
	InitializeComponent();
}


Chat_uwp::ContactUC::ContactUC(ChatsUC^ currentChat)
{
	InitializeComponent();
	this->currentChat = currentChat;
}


Chat_uwp::ContactUC::ContactUC(ChatsUC^ currentChat, String^ userPhone, String^ cName, String^ cPhone, String^ Type)
{
	InitializeComponent();
	this->currentChat = currentChat;
	this->userPhone = userPhone;
	this->cPhone = cPhone;
	this->name_btn->Content = cName;
	this->Type = Type;
	this->pageLoded = 1;
	if (user.check_visibilty(cPhone) == true)
	{
		image_image->Source = ref new BitmapImage(ref new Uri(user.GetImage(cPhone)));
	}
	else
	{
		image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/Default.png"));
	}
}


Chat_uwp::ContactUC::ContactUC(ChatsUC^ currentChat, String^ userPhone, String^ GrpName, String^ userPhone2, String^ userPhone3, String^ userPhone4, String^ userPhone5, String^ userPhone6
	, String^ userPhone7, String^ userPhone8, String^ userPhone9, String^ userPhone10, String^ Type, int count, String^ Path)
{
	InitializeComponent();
	this->currentChat = currentChat;
	this->userPhone = userPhone;
	this->userPhone2 = userPhone2;
	this->userPhone3 = userPhone3;
	this->userPhone4 = userPhone4;
	this->userPhone5 = userPhone5;
	this->userPhone6 = userPhone6;
	this->userPhone7 = userPhone7;
	this->userPhone8 = userPhone8;
	this->userPhone9 = userPhone9;
	this->userPhone10 = userPhone10;
	this->name_btn->Content = GrpName;
	this->Type = Type;
	this->count = count;
	this->Path = Path;
	this->pageLoded = 4;
	image_image->Source = ref new BitmapImage(ref new Uri(Path));
}


Chat_uwp::ContactUC::ContactUC(StatusUC^ statusView, String^ userPhone, String^ cName, String^ cPhone)
{
	InitializeComponent();
	this->statusView = statusView;
	this->userPhone = userPhone;
	this->cPhone = cPhone;
	this->name_btn->Content = cName;
	this->pageLoded = 2;
	if (user.check_visibilty(cPhone) == true)
	{
		image_image->Source = ref new BitmapImage(ref new Uri(user.GetImage(cPhone)));
	}
	else
	{
		image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/Default.png"));
	}
}


Chat_uwp::ContactUC::ContactUC(ContactsUC^ contactsView, String^ userPhone, String^ cName, String^ cPhone)
{
	InitializeComponent();
	this->contactsView = contactsView;
	this->userPhone = userPhone;
	this->cPhone = cPhone;
	this->name_btn->Content = cName;
	this->pageLoded = 3;
	if (user.check_visibilty(cPhone) == true)
	{
		image_image->Source = ref new BitmapImage(ref new Uri(user.GetImage(cPhone)));
	}
	else
	{
		image_image->Source = ref new BitmapImage(ref new Uri("ms-appx:///Assets/pp/Default.png"));
	}
}


void Chat_uwp::ContactUC::name_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (pageLoded == 1) {
		currentChat->contact_clicked(cPhone, this->name_btn->Content->ToString(), Type);
	}
	else if (pageLoded == 2) {
		statusView->contact_clicked(this->cPhone);
	}
	else if (pageLoded == 3) {
		contactsView->contact_clicked(this->cPhone);
	}
	else if (pageLoded == 4) {
		currentChat->contact_clicked(this->name_btn->Content->ToString(), Type, userPhone, userPhone2, userPhone3, userPhone4, userPhone5, userPhone6
			, userPhone7, userPhone8, userPhone9, userPhone10, count, Path);
	}
}