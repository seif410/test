//
// StatusUC.xaml.cpp
// Implementation of the StatusUC class
//

#include "pch.h"
#include "StatusUC.xaml.h"
#include "StatusViewerUC.xaml.h"
#include "ContactUC.xaml.h"

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

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

StatusUC::StatusUC()
{
	InitializeComponent();
	addStatus = ref new AddStatusUC();
	contacts = sto.GetContacts(User::LogedInUser.id);
	for (int i = 0; i < contacts.size(); i++)
	{
		friends_pnl->Children->Append(ref new ContactUC(this, User::LogedInUser.phone, contacts[i]->name, contacts[i]->phone));
	}
}


Chat_uwp::StatusUC::StatusUC(String^ userPhone)
{
	InitializeComponent();
}


void Chat_uwp::StatusUC::contact_clicked(String^ cPhone)
{
	//load status from here
	statusViewer_grid->Children->Clear();
	statusViewer_grid->Children->Append(ref new StatusViewerUC(this, cPhone));
}


void Chat_uwp::StatusUC::close_btn_Clicked()
{
	statusViewer_grid->Children->Clear();
}


void Chat_uwp::StatusUC::addstatus_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	statusViewer_grid->Children->Clear();
	statusViewer_grid->Children->Append(addStatus);
	addStatus->animation();
}