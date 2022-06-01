//
// RegisterPage.xaml.h
// Declaration of the RegisterPage class
//

#pragma once

#include "RegisterPage.g.h"
#include "User.h"
#include "MainPage.xaml.h"
using namespace Platform;

namespace Chat_uwp
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]

	public ref class RegisterPage sealed
	{
	public:
		RegisterPage();

	private:
		User users;
		void createAcc_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void back_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addImage_btn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addImage_btn_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	};
}
