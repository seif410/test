﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Media {
                namespace Animation {
                    ref class Storyboard;
                }
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Grid;
                ref class TextBlock;
                ref class TextBox;
                ref class Button;
                ref class Image;
                ref class StackPanel;
            }
        }
    }
}

namespace Chat_uwp
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class NewGroupUC : public ::Windows::UI::Xaml::Controls::UserControl, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        void UnloadObject(::Windows::UI::Xaml::DependencyObject^ dependencyObject);
        void DisconnectUnloadedObject(int connectionId);
    
    private:
        bool _contentLoaded;
    
        class NewGroupUC_obj1_Bindings;
    
        private: ::Windows::UI::Xaml::Media::Animation::Storyboard^ Storyboard1;
        private: ::Windows::UI::Xaml::Controls::Grid^ grid;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ groupName_lbl;
        private: ::Windows::UI::Xaml::Controls::TextBox^ groupName_txt;
        private: ::Windows::UI::Xaml::Controls::Button^ create_btn;
        private: ::Windows::UI::Xaml::Controls::Grid^ image_grid;
        private: ::Windows::UI::Xaml::Controls::Button^ addImage;
        private: ::Windows::UI::Xaml::Controls::Button^ remove;
        private: ::Windows::UI::Xaml::Controls::Image^ image_image;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact1_txt;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ contacts_pnl2;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact2_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact3_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact4_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact5_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact6_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact7_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact8_txt;
        private: ::Windows::UI::Xaml::Controls::TextBox^ contact9_txt;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ title_lbl;
        private: ::Windows::UI::Xaml::Controls::Button^ group_btn;
        private: ::Windows::UI::Xaml::Controls::Button^ private_btn;
        private: ::Windows::UI::Xaml::Controls::Button^ visi;
    };
}
