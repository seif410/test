//
// NewGroupUC.xaml.h
// Declaration of the NewGroupUC class
//

#pragma once

#include "NewGroupUC.g.h"
#include "Message.h"
#include "NewGp.h"
#include "User.h"

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NewGroupUC sealed
	{
	public:
		NewGroupUC();
		void animation();
	private:
		Message ms;
		NewGp ng;
		User usre;
		String^ ipath;
		void create_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addImage_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void remove_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void group_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void private_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
