//
// ContactDataView.xaml.h
// Declaration of the ContactDataView class
//

#pragma once
#include "ContactDataView.g.h"

namespace Chat_uwp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ContactDataView sealed
	{
	public:
		ContactDataView();
		ContactDataView(String^ imagePath, String^ name, String^ phone, String^ description);
	};
}
