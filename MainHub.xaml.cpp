//
// MainHub.xaml.cpp
// Implementation of the MainHub class
//

#include "pch.h"
#include "MainHub.xaml.h"
#include "DecryptPage.xaml.h"
#include "PasswordPage.xaml.h"
#include "Views\SecureTextBlock.xaml.h"

using namespace kryptan_windows;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

Kryptan::Core::PwdLabelVector *MainHub::checkedLabels = NULL;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=390556

MainHub::MainHub()
{
    if (checkedLabels == NULL)
    {
        checkedLabels = new Kryptan::Core::PwdLabelVector();
    }
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.
/// This parameter is typically used to configure the page.</param>
void MainHub::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter
}


void kryptan_windows::MainHub::LabelList_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    ListView^ list = (ListView^)sender;

    labels = pageModel.GetLabels();

    for (unsigned int i = 0; i < labels->Size; i++)
    {
        auto label = labels->GetAt(i);
        label->TextAlignHorizontal = SecureTextHorizontalAlign::LEFT;
        label->TextAlignVertical = SecureTextVerticalAlign::MIDDLE;
    }

    list->ItemsSource = labels;
}

void kryptan_windows::MainHub::PasswordList_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    passwordListView = (ListView^)sender;
    Kryptan::Core::PwdLabelVector vec;

    UpdatePasswordList(vec);
}

void kryptan_windows::MainHub::UpdatePasswordList(Kryptan::Core::PwdLabelVector& l)
{
    pwds = pageModel.GetPasswords(&l);

    for (unsigned int i = 0; i < pwds->Size; i++)
    {
        auto pwd = pwds->GetAt(i);
        pwd->TextAlignHorizontal = SecureTextHorizontalAlign::LEFT;
        pwd->TextAlignVertical = SecureTextVerticalAlign::MIDDLE;
    }

    passwordListView->ItemsSource = pwds;
}

void kryptan_windows::MainHub::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    this->Frame->Navigate(DecryptPage::typeid);
}


void kryptan_windows::MainHub::CheckBox_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto box = (CheckBox^)(sender);
    auto image = (SecureTextBlock^)box->Content;
    auto text = image->TextOptions;
    checkedLabels->push_back(text->Text);
    UpdatePasswordList(*checkedLabels);
}


void kryptan_windows::MainHub::CheckBox_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto box = (CheckBox^)(sender);
    auto image = (SecureTextBlock^)box->Content;
    auto text = image->TextOptions;
    checkedLabels->erase(std::remove(checkedLabels->begin(), checkedLabels->end(), text->Text), checkedLabels->end());
    UpdatePasswordList(*checkedLabels);
}


void kryptan_windows::MainHub::SecureTextBlock_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e)
{
    SecureTextBlock^ textBlock = (SecureTextBlock^)sender;
    this->Frame->Navigate(PasswordPage::typeid, textBlock->TextOptions);
}
