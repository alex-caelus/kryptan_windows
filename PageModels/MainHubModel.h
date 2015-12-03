#pragma once

#include "BaseModel.h"
#include "Views\SecureTextBlock.xaml.h"
#include "PageModels\MainHubModel.h"


namespace kryptan_windows
{


    class MainHubModel :
        public BaseModel
    {
    public:
        MainHubModel();
        ~MainHubModel();

        Windows::Foundation::Collections::IObservableVector<SecureTextImageSourceDrawLayout^>^ GetLabels();
        Windows::Foundation::Collections::IObservableVector<SecureTextImageSourceDrawLayout^>^ GetPasswords(Kryptan::Core::PwdLabelVector* labels=NULL);
    };

}
