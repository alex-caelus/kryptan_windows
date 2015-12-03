//
// PasswordPage.xaml.h
// Declaration of the PasswordPage class
//

#pragma once

#include "PasswordPage.g.h"
#include "Common\NavigationHelper.h"

#include "PageModels\PasswordPageModel.h"

namespace kryptan_windows
{
	/// <summary>
	/// A basic page that provides characteristics common to most applications.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PasswordPage sealed
	{
	public:
		PasswordPage();

		/// <summary>
		/// Gets the view model for this <see cref="Page"/>. 
		/// This can be changed to a strongly typed view model.
		/// </summary>
		property Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^ DefaultViewModel
		{
			Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^  get();
		}

		/// <summary>
		/// Gets the <see cref="NavigationHelper"/> associated with this <see cref="Page"/>.
		/// </summary>
		property Common::NavigationHelper^ NavigationHelper
		{
			Common::NavigationHelper^ get();
		}

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		void LoadState(Platform::Object^ sender, Common::LoadStateEventArgs^ e);
		void SaveState(Platform::Object^ sender, Common::SaveStateEventArgs^ e);

		static Windows::UI::Xaml::DependencyProperty^ _defaultViewModelProperty;
		static Windows::UI::Xaml::DependencyProperty^ _navigationHelperProperty;

        PasswordPageModel pageModel;
        void CopyDescriptionToClipboard(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void EditDescription(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void CopyUsernameToClipboard(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void EditUsername(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void EditPassword(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void CopyPasswordToClipboard(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void RightTapped(Platform::Object^ sender, Windows::UI::Xaml::Input::RightTappedRoutedEventArgs^ e);
    };

}
