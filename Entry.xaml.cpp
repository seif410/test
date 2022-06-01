//
// Entry.xaml.cpp
// Implementation of the Entry class
//

#include "pch.h"
#include "Entry.xaml.h"
#include"StatusUC.xaml.h"
#include"ChatsUC.xaml.h"
#include "MainPage.xaml.h"
#include "ContactsUC.xaml.h"

using namespace Chat_uwp;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Media::Imaging;


// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

Entry::Entry()
{
	InitializeComponent();
	status = ref new StatusUC();
	contacts = ref new ContactsUC();
	edit = ref new EditUC(this);
	image_image->Source = ref new BitmapImage(ref new Uri(LoginUser.GetImage(User::LogedInUser.phone)));
}


void Chat_uwp::Entry::changeImage(String^ imagePath)
{
	image_image->Source = ref new BitmapImage(ref new Uri(imagePath));
}


Chat_uwp::Entry::~Entry()
{
	chat->destruct();
}


//Click Events
void Chat_uwp::Entry::status_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat->destruct();
	story.checkpublishtime(User::LogedInUser.id);
	status = ref new StatusUC();
	Content_grid->Children->Clear();
	Content_grid->Children->Append(status);
}


void Chat_uwp::Entry::chat_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat->destruct();
	chat = ref new ChatsUC(User::LogedInUser.phone);
	Content_grid->Children->Clear();
	Content_grid->Children->Append(chat);
}


void Chat_uwp::Entry::contacts_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat->destruct();
	contacts = ref new ContactsUC();
	Content_grid->Children->Clear();
	Content_grid->Children->Append(contacts);
}


void Chat_uwp::Entry::settings_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat->destruct();
	Content_grid->Children->Clear();
	Content_grid->Children->Append(edit);
}


void Chat_uwp::Entry::logout_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	chat->destruct();
	User::LogedInUser.~User();
	this->Frame->Navigate(TypeName(MainPage::typeid));
}


void Entry::OnNavigatedTo(NavigationEventArgs^ e) {
	chat = ref new ChatsUC(User::LogedInUser.phone);
	Content_grid->Children->Append(chat);
}