#include "KeybindingsSettingsWidget.h"
#include "CommonHierarchicalScrollBox.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "SettingsCategoryHeader.h"
#include "Blueprint/WidgetTree.h"
#include "Components/VerticalBox.h"
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
	TMap<FString, UVerticalBox*> CategoryBoxes;
	
	for (const UInputMappingContext* MappingContext : EnhancedInputSubsystem->GetUserSettings()->GetRegisteredInputMappingContexts())
	{
		for (FEnhancedActionKeyMapping Mapping : MappingContext->GetMappings())
		{
			if (Mapping.Key.IsAxis2D())
			{
				continue;
			}

			if (!CategoryBoxes.Contains(Mapping.GetDisplayCategory().ToString()))
			{
				
				auto CategoryBox = WidgetTree->ConstructWidget<UVerticalBox>();//CreateWidget<UVerticalBox>(GetOwningPlayer(), UVerticalBox::StaticClass());
				ScrollBox_Keybindings->AddChild(CategoryBox);
				auto CategoryHeaderWidget = CreateWidget<USettingsCategoryHeader>(GetOwningPlayer(), CategoryHeaderWidgetClass);
				CategoryHeaderWidget->SetText(Mapping.GetDisplayCategory());
				CategoryBox->AddChild(CategoryHeaderWidget);
				
				CategoryBoxes.Add(Mapping.GetDisplayCategory().ToString(), CategoryBox);
			}

			auto KeybindSetting = CreateWidget<UKeybindSettingWidget>(GetOwningPlayer(), KeybindSettingWidgetClass);
			KeybindSetting->SetOwningPlayer(GetOwningPlayer());
			KeybindSetting->Init(EnhancedInputSubsystem, Mapping);
			DisplayedKeybindingEntries.Add(KeybindSetting);

			CategoryBoxes[Mapping.GetDisplayCategory().ToString()]->AddChild(KeybindSetting);
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
