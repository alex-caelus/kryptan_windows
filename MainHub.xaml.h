//
// MainHub.xaml.h
// Declaration of the MainHub class
//

#pragma once

#include "MainHub.g.h"

#include "PageModels\MainHubModel.h"

namespace kryptan_windows
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainHub sealed
	{
	public:
		MainHub();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
    private:
        void LabelList_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

        MainHubModel pageModel;
        Windows::UI::Xaml::Controls::ListView^ passwordListView;

        static Kryptan::Core::PwdLabelVector *checkedLabels;

        void UpdatePasswordList(Kryptan::Core::PwdLabelVector& list);

        Windows::Foundation::Collections::IObservableVector<SecureTextImageSourceDrawLayout^>^ labels;
        Windows::Foundation::Collections::IObservableVector<SecureTextImageSourceDrawLayout^>^ pwds;
        
        void PasswordList_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void CheckBox_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void CheckBox_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void SecureTextBlock_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
    };
}
