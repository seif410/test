﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "ContactUC.xaml.h"

void ::Chat_uwp::ContactUC::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///ContactUC.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Chat_uwp::ContactUC::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 2:
        {
            this->name_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->name_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::ContactUC::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&ContactUC::name_btn_Click);
        }
        break;
    case 3:
        {
            this->image_image = safe_cast<::Windows::UI::Xaml::Controls::Image^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Chat_uwp::ContactUC::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


