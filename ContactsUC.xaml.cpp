//
// ContactsUC.xaml.cpp
// Implementation of the ContactsUC class
//

#include "pch.h"
#include "ContactsUC.xaml.h"
#include "ContactUC.xaml.h"
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

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

ContactsUC::ContactsUC()
{
	InitializeComponent();
	addContact = ref new AddContact();
	contacts = con.show(User::LogedInUser.id);
	for (int i = 0; i < contacts.size(); i++)
	{
		friends_pnl->Children->Append(ref new ContactUC(this, User::LogedInUser.phone, contacts[i]->name, contacts[i]->phone));
	}
}


Chat_uwp::ContactsUC::ContactsUC(String^ userPhone)
{
	InitializeComponent();
	addContact = ref new AddContact();
}


void Chat_uwp::ContactsUC::contact_clicked(String^ cPhone)
{
	User usr = User::LogedInUser.GetUserByPh(cPhone);
	addContact_grid->Children->Clear();
	// image , name , phone ,des
	if (User::LogedInUser.check_visibilty(cPhone)) {
		addContact_grid->Children->Append(ref new ContactDataView(usr.imagePath, usr.firstname + " " + usr.lastname, usr.phone, usr.discription));
	}
	else {
		addContact_grid->Children->Append(ref new ContactDataView("ms-appx:///Assets/pp/Default.png", usr.firstname + " " + usr.lastname, usr.phone, "HIDDEN :("));
	}
}


void Chat_uwp::ContactsUC::addContact_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	addContact_grid->Children->Clear();
	addContact_grid->Children->Append(addContact);
	addContact->animation();
}
