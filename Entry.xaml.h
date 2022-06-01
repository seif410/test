//
// Entry.xaml.h
// Declaration of the Entry class
//

#pragma once

#include "Entry.g.h"
#include "ChatsUC.xaml.h"
#include "StatusUC.xaml.h"
#include "ContactsUC.xaml.h"
#include "User.h"
#include "Story.h"
#include "Message.h"
#include "EditUC.xaml.h"
#include "TextSpace.xaml.h"
namespace Chat_uwp
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Entry sealed
	{
	public:
		Entry();
		void changeImage(String^ imagePath);
		virtual ~Entry();
	private:
		ChatsUC^ chat;
		StatusUC^ status;
		ContactsUC^ contacts;
		EditUC^ edit;
		User LoginUser;
		Story story;
		Message msg;
		TextSpace txtspc;
		void status_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void chat_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void contacts_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void settings_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void logout_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	};
}
