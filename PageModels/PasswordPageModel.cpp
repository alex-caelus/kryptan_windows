#include "pch.h"
#include "PasswordPageModel.h"
#include "Views\SecureTextImageSource\SecureTextImageSourceDrawLayout.h"
#include "kryptan_core\core.h"

using namespace kryptan_windows;
using namespace Platform::Collections;

PasswordPageModel::PasswordPageModel()
{
}


PasswordPageModel::~PasswordPageModel()
{
}

void PasswordPageModel::SetPwd(Caelus::Utilities::SecureString pwdDesc)
{
    if (pwdDesc.length() == 0)
    {
        throw std::runtime_error("No password set!");
    }

    auto list = pwdFile->GetPasswordList()->Filter(pwdDesc);
    if (list.size() == 1)
    {
        pwd = list.front();
    }
    else if (list.size() == 0)
    {
        throw std::runtime_error("No matching password found!");
    }
    else
    {
        Kryptan::Core::PwdList::PwdVector sList;
        auto it = list.begin();
        for (; it != list.end(); it++)
        {
            if ((*it)->GetDescription().length() == pwdDesc.length())
            {
                sList.push_back((*it));
            }
        }

        if (sList.size() == 1)
        {
            pwd = list.front();
        }
        else if (list.size() == 0)
        {
            throw std::runtime_error("No matching password found!");
        }
        else
        {
            throw std::runtime_error("Multiple matching passwords found!");
        }
    }
}


SecureTextImageSourceDrawLayout^ PasswordPageModel::GetDescription()
{
    auto descriptionLayout = ref new SecureTextImageSourceDrawLayout();
    descriptionLayout->Text = pwd->GetDescription();
    descriptionLayout->BackroundColor = Windows::UI::Colors::Transparent;
    descriptionLayout->TextColor = Windows::UI::Colors::White;
    descriptionLayout->FontName = L"Verdana";
    descriptionLayout->FontSize = 16;
    descriptionLayout->TextAlignHorizontal = SecureTextHorizontalAlign::CENTER;
    descriptionLayout->TextAlignVertical = SecureTextVerticalAlign::MIDDLE;
    return descriptionLayout;
}

SecureTextImageSourceDrawLayout^ PasswordPageModel::GetUsername()
{
    auto descriptionLayout = ref new SecureTextImageSourceDrawLayout();
    descriptionLayout->Text = pwd->GetUsername();
    descriptionLayout->BackroundColor = Windows::UI::Colors::Transparent;
    descriptionLayout->TextColor = Windows::UI::Colors::White;
    descriptionLayout->FontName = L"Verdana";
    descriptionLayout->FontSize = 16;
    descriptionLayout->TextAlignHorizontal = SecureTextHorizontalAlign::CENTER;
    descriptionLayout->TextAlignVertical = SecureTextVerticalAlign::MIDDLE;
    return descriptionLayout;
}

SecureTextImageSourceDrawLayout^ PasswordPageModel::GetPassword()
{
    auto descriptionLayout = ref new SecureTextImageSourceDrawLayout();
    descriptionLayout->Text = pwd->GetPassword();
    descriptionLayout->BackroundColor = Windows::UI::Colors::Transparent;
    descriptionLayout->TextColor = Windows::UI::Colors::White;
    descriptionLayout->FontName = L"Verdana";
    descriptionLayout->FontSize = 16;
    descriptionLayout->TextAlignHorizontal = SecureTextHorizontalAlign::CENTER;
    descriptionLayout->TextAlignVertical = SecureTextVerticalAlign::MIDDLE;
    return descriptionLayout;
}
