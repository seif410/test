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

#include "RegisterPage.xaml.h"

void ::Chat_uwp::RegisterPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///RegisterPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Chat_uwp::RegisterPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 2:
        {
            this->firstname_txt = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 3:
        {
            this->lastname_txt = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 4:
        {
            this->phoneNumber_txt = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 5:
        {
            this->password_txt = safe_cast<::Windows::UI::Xaml::Controls::PasswordBox^>(__target);
        }
        break;
    case 6:
        {
            this->description_txt = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 7:
        {
            this->create_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->create_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::RegisterPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&RegisterPage::createAcc_btn_Click);
        }
        break;
    case 8:
        {
            this->back_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->back_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::RegisterPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&RegisterPage::back_btn_Click);
        }
        break;
    case 9:
        {
            this->visiblity_check = safe_cast<::Windows::UI::Xaml::Controls::CheckBox^>(__target);
        }
        break;
    case 10:
        {
            this->addImage_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->addImage_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::RegisterPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&RegisterPage::addImage_btn_Click_1);
        }
        break;
    case 11:
        {
            this->load_btn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->load_btn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Chat_uwp::RegisterPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&RegisterPage::addImage_btn_Click);
        }
        break;
    case 12:
        {
            this->image_image = safe_cast<::Windows::UI::Xaml::Controls::Image^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Chat_uwp::RegisterPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)

