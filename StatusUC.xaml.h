//
// StatusUC.xaml.h
// Declaration of the StatusUC class
//

#pragma once

#include "StatusUC.g.h"
#include "User.h"
#include "AddStatusUC.xaml.h"
#include "Contacts.h"
#include "Story.h"
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class StatusUC sealed
	{
	public:
		StatusUC();
		StatusUC(String^ userPhone);
		void contact_clicked(String^ cPhone);
		void close_btn_Clicked();
	private:
		Story sto;
		AddStatusUC^ addStatus;
		vector<Contacts*> contacts;
		void addstatus_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
