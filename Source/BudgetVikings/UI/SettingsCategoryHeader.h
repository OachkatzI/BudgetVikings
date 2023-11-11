#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SettingsCategoryHeader.generated.h"


class UCommonTextBlock;


UCLASS()
class BUDGETVIKINGS_API USettingsCategoryHeader : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	void SetText(const FText& CategoryTitle) const;

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> CategoryTextBlock;
};
