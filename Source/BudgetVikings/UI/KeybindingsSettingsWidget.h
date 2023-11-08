#pragma once

#include "CoreMinimal.h"
#include "KeybindSettingWidget.h"
#include "SettingsWidgetBase.h"
#include "KeybindingsSettingsWidget.generated.h"


class UEnhancedInputLocalPlayerSubsystem;
class UCommonHierarchicalScrollBox;


UCLASS()
class BUDGETVIKINGS_API UKeybindingsSettingsWidget : public USettingsWidgetBase
{
	GENERATED_BODY()

protected:
	
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void ResetKeybindings();

	UFUNCTION(BlueprintCallable)
	void SaveKeybindings() const;

	void ClearExistingChildren();

	void PopulateBindingsUI();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonHierarchicalScrollBox> ScrollBox_Keybindings;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UKeybindSettingWidget> KeybindSettingWidgetClass;

	UPROPERTY()
	TArray<TObjectPtr<UKeybindSettingWidget>> DisplayedKeybindingEntries;

	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> EnhancedInputSubsystem;

	UFUNCTION()
	void RefreshWidgets();
};

