#pragma once

#include "BaseModel.h"
#include "kryptan_core\SecureString\SecureString.h"
#include "Views\SecureTextImageSource\SecureTextImageSourceDrawLayout.h"


namespace kryptan_windows
{


    class PasswordPageModel :
        public BaseModel
    {
    public:
        PasswordPageModel();
        ~PasswordPageModel();
        
        void SetPwd(Caelus::Utilities::SecureString pwdDesc);

        SecureTextImageSourceDrawLayout^ GetDescription();
        SecureTextImageSourceDrawLayout^ GetUsername();
        SecureTextImageSourceDrawLayout^ GetPassword();

        Kryptan::Core::Pwd* pwd;
    };

}
