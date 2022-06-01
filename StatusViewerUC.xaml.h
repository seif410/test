//
// StatusViewerUC.xaml.h
// Declaration of the StatusViewerUC class
//

#pragma once

#include "StatusViewerUC.g.h"
#include"Story.h"
#include "StatusUC.xaml.h"
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class StatusViewerUC sealed
	{
	public:
		StatusViewerUC();
		StatusViewerUC(StatusUC^ currentStatusUC, String^ cPhone);
	private:
		Story sto;
		int statNo;
		StatusUC^ currentStatusUC;
		vector<Story*> stories;
		void next_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void back_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void close_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
