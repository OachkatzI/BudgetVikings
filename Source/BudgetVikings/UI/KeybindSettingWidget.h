#pragma once

#include "CoreMinimal.h"
#include "PlayerMappableKeySettings.h"
#include "Blueprint/UserWidget.h"
#include "KeybindSettingWidget.generated.h"


class UEnhancedInputLocalPlayerSubsystem;
class UCommonTextBlock;
class UInputKeySelector;


UCLASS()
class BUDGETVIKINGS_API UKeybindSettingWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	void Init(UEnhancedInputLocalPlayerSubsystem* Subsystem, const FEnhancedActionKeyMapping& Mapping);

	void ResetKeybinding();
	
	void RefreshDisplayedKey();

protected:
	
	virtual void NativeConstruct() override;
	
	void BindKey(const FKey& NewKey) const;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInputKeySelector> InputKeySelector;

	UPROPERTY()
	TObjectPtr<UCommonTextBlock> TB_KeybindName;

	UFUNCTION()
	void HandleNewKeySelected(FInputChord SelectedKey);

	UFUNCTION()
	void HandleIsWaitingForKey();

	UPROPERTY()
	TObjectPtr<UPlayerMappableKeySettings> MappableKeySettings;

	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> EnhancedInputSubsystem;

private:

	bool bIsRemapping = false;
};
