#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SettingsWidgetBase.generated.h"


UCLASS()
class BUDGETVIKINGS_API USettingsWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

	USettingsWidgetBase();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SettingsName;


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ApplySettings();
};
