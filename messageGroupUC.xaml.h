//
// messageGroupUC.xaml.h
// Declaration of the messageGroupUC class
//

#pragma once
#include "messageGroupUC.g.h"

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class messageGroupUC sealed
	{
	public:
		messageGroupUC();
		messageGroupUC(String^ message, bool sender, String^ time, String^ Name, int fNo);
		messageGroupUC(String^ message, bool sender, String^ time, String^ Name, int fNo, bool);
	};
}
