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

#include "StatusViewerUC.xaml.h"

void ::Chat_uwp::StatusViewerUC::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///StatusViewerUC.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Chat_uwp::StatusViewerUC::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 2:
        {
            this->Storyboard1 = safe_cast<::Windows::UI::Xaml::Media::Animation::Storyboard^>(__target);
        }
        break;
    case 3:
        {
            this->Storyboard2 = safe_cast<::Windows::UI::Xaml::Media::Animation::Storyboard^>(__target);
        }
        break;
    case 4:
        {
            this->grid = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
        }
        break;
    case 5:
        {
            this->back_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->back_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::StatusViewerUC::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StatusViewerUC::back_btn_Click);
        }
        break;
    case 6:
        {
            this->visisi = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
        }
        break;
    case 7:
        {
            this->next_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->next_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::StatusViewerUC::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StatusViewerUC::next_btn_Click);
        }
        break;
    case 8:
        {
            this->close_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->close_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::StatusViewerUC::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StatusViewerUC::close_btn_Click);
        }
        break;
    case 9:
        {
            this->grid1 = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
        }
        break;
    case 10:
        {
            this->status_image = safe_cast<::Windows::UI::Xaml::Controls::Image^>(__target);
        }
        break;
    case 11:
        {
            this->status_txt = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Chat_uwp::StatusViewerUC::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


