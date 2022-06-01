//
// messageUC.xaml.h
// Declaration of the messageUC class
//

#pragma once
#include <iostream>
#include "messageUC.g.h"

using namespace Platform;
namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class messageUC sealed
	{

	public:
		messageUC(void);
		messageUC(String^);
		messageUC(String^ message, bool sender, String^ time, bool isSeen);
	};
}
