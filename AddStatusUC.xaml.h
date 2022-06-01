//
// AddStatusUC.xaml.h
// Declaration of the AddStatusUC class
//

#pragma once

#include "AddStatusUC.g.h"
#include "Story.h"

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AddStatusUC sealed
	{
	public:
		AddStatusUC();
		void animation();
	private:
		String^ spath;
		Story storyy;
		void addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void load_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Add_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};

}
