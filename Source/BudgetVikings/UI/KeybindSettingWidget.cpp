#include "KeybindSettingWidget.h"
#include "CommonTextBlock.h"
#include "EnhancedActionKeyMapping.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputKeySelector.h"
#include "UserSettings/EnhancedInputUserSettings.h"


void UKeybindSettingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InputKeySelector->OnKeySelected.AddDynamic(this, &ThisClass::HandleNewKeySelected);
	InputKeySelector->OnIsSelectingKeyChanged.AddDynamic(this, &ThisClass::HandleIsWaitingForKey);
}


void UKeybindSettingWidget::HandleNewKeySelected(FInputChord SelectedKey)
{
	if (!bIsRemapping)
	{
		return;
	}
	
	bIsRemapping = false;

	BindKey(SelectedKey.Key);
}


void UKeybindSettingWidget::HandleIsWaitingForKey()
{
	bIsRemapping = true;
}


void UKeybindSettingWidget::BindKey(const FKey& NewKey) const
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetOwningPlayer()->GetLocalPlayer());
	check(Subsystem);
	
	FMapPlayerKeyArgs InPlayerKeyArgs;
	InPlayerKeyArgs.MappingName = MappableKeySettings->Name;
	InPlayerKeyArgs.NewKey = NewKey;
	InPlayerKeyArgs.Slot = EPlayerMappableKeySlot::First;
	FGameplayTagContainer OutFailureReason;
	Subsystem->GetUserSettings()->MapPlayerKey(InPlayerKeyArgs, OutFailureReason);
	Subsystem->RequestRebuildControlMappings();
}


void UKeybindSettingWidget::Init(UEnhancedInputLocalPlayerSubsystem* Subsystem, const FEnhancedActionKeyMapping& Mapping)
{
	EnhancedInputSubsystem = Subsystem;
	MappableKeySettings = Mapping.GetPlayerMappableKeySettings();

	check(EnhancedInputSubsystem);
	check(MappableKeySettings);
	
	FMapPlayerKeyArgs InPlayerKeyArgs;
	InPlayerKeyArgs.MappingName = MappableKeySettings->Name;
	InPlayerKeyArgs.Slot = EPlayerMappableKeySlot::First;
	
	FPlayerKeyMapping* KeyMapping = EnhancedInputSubsystem->GetUserSettings()->GetCurrentKeyProfile()->FindKeyMapping(InPlayerKeyArgs);
	
	TB_KeybindName.Get()->SetText(KeyMapping->GetDisplayName());
	RefreshDisplayedKey();
}


void UKeybindSettingWidget::ResetKeybinding()
{	
	FMapPlayerKeyArgs InPlayerKeyArgs;
	InPlayerKeyArgs.MappingName = MappableKeySettings->Name;
	InPlayerKeyArgs.Slot = EPlayerMappableKeySlot::First;
	const FPlayerKeyMapping* KeyMapping = EnhancedInputSubsystem->GetUserSettings()->GetCurrentKeyProfile()->FindKeyMapping(InPlayerKeyArgs);
	
	BindKey(KeyMapping->GetDefaultKey());
	RefreshDisplayedKey();
}


void UKeybindSettingWidget::RefreshDisplayedKey()
{
	FMapPlayerKeyArgs InPlayerKeyArgs;
	InPlayerKeyArgs.MappingName = MappableKeySettings->Name;
	InPlayerKeyArgs.Slot = EPlayerMappableKeySlot::First;
	const FPlayerKeyMapping* KeyMapping = EnhancedInputSubsystem->GetUserSettings()->GetCurrentKeyProfile()->FindKeyMapping(InPlayerKeyArgs);
	InputKeySelector->SetSelectedKey(KeyMapping->GetCurrentKey());
}
