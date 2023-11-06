#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KeybindSettingWidget.generated.h"


class UInputKeySelector;


UCLASS()
class BUDGETVIKINGS_API UKeybindSettingWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInputKeySelector> InputKeySelector;
};
