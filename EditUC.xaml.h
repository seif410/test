//
// EditUC.xaml.h
// Declaration of the EditUC class
//

#pragma once

#include "EditUC.g.h"
#include "Entry.xaml.h"
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class EditUC sealed
	{
	public:
		EditUC();
		EditUC(Entry^ entry);
	private:
		String^ pathh;
		Entry^ entry;
		User userrr;
		void edit_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^);
		void addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void load_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
