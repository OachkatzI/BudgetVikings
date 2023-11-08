#include "KeybindingsSettingsWidget.h"
#include "CommonHierarchicalScrollBox.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "UserSettings/EnhancedInputUserSettings.h"


void UKeybindingsSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetOwningPlayer()->GetLocalPlayer());
	check(EnhancedInputSubsystem);

	EnhancedInputSubsystem->GetUserSettings()->OnSettingsApplied.AddDynamic(this, &ThisClass::RefreshWidgets);
	
	ClearExistingChildren();
	PopulateBindingsUI();
}


void UKeybindingsSettingsWidget::ResetKeybindings()
{
	EnhancedInputSubsystem->GetUserSettings()->GetCurrentKeyProfile()->ResetToDefault();
	SaveKeybindings();
}


void UKeybindingsSettingsWidget::SaveKeybindings() const
{
	EnhancedInputSubsystem->GetUserSettings()->ApplySettings();
	EnhancedInputSubsystem->GetUserSettings()->SaveSettings();
}


void UKeybindingsSettingsWidget::ClearExistingChildren()
{
	ScrollBox_Keybindings.Get()->ClearChildren();
}


void UKeybindingsSettingsWidget::PopulateBindingsUI()
{
	for (const UInputMappingContext* MappingContext : EnhancedInputSubsystem->GetUserSettings()->GetRegisteredInputMappingContexts())
	{
		for (FEnhancedActionKeyMapping Mapping : MappingContext->GetMappings())
		{
			auto KeybindSetting = CreateWidget<UKeybindSettingWidget>(GetOwningPlayer(), KeybindSettingWidgetClass);
			KeybindSetting->SetOwningPlayer(GetOwningPlayer());
			KeybindSetting->Init(EnhancedInputSubsystem, Mapping);
			ScrollBox_Keybindings->AddChild(KeybindSetting);
			DisplayedKeybindingEntries.Add(KeybindSetting);
		}
	}
}


void UKeybindingsSettingsWidget::RefreshWidgets()
{
	for (UKeybindSettingWidget* DisplayedKeybindingEntry : DisplayedKeybindingEntries)
	{
		DisplayedKeybindingEntry->RefreshDisplayedKey();
	}
}
