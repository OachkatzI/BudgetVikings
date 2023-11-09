#include "AudioSettingsWidget.h"
#include "VolumeSlider.h"
#include "BudgetVikings/Settings/BVUserSettings.h"
#include "Components/Slider.h"


void UAudioSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	RefreshUI();
}


void UAudioSettingsWidget::RefreshUI()
{
	const UBVUserSettings* UserSettings = UBVUserSettings::Get();
	check(UserSettings);
	
	VolumeSliderMain->GetSliderWidget()->SetValue(UserSettings->GetMainVolume());
	VolumeSliderMusic->GetSliderWidget()->SetValue(UserSettings->GetMusicVolume());
	VolumeSliderAmbience->GetSliderWidget()->SetValue(UserSettings->GetAmbienceVolume());
	VolumeSliderEffects->GetSliderWidget()->SetValue(UserSettings->GetEffectsVolume());
	VolumeSliderUI->GetSliderWidget()->SetValue(UserSettings->GetUIVolume());
}


void UAudioSettingsWidget::SaveAudioSettings()
{
	UBVUserSettings* UserSettings = UBVUserSettings::Get();
	check(UserSettings);
	
	UserSettings->SetMainVolume(VolumeSliderMain->GetSliderWidget()->GetValue());
	UserSettings->SetMusicVolume(VolumeSliderMusic->GetSliderWidget()->GetValue());
	UserSettings->SetAmbienceVolume(VolumeSliderAmbience->GetSliderWidget()->GetValue());
	UserSettings->SetEffectsVolume(VolumeSliderEffects->GetSliderWidget()->GetValue());
	UserSettings->SetUIVolume(VolumeSliderUI->GetSliderWidget()->GetValue());

	UserSettings->ApplySettings(false);
	UE_LOG(LogTemp, Warning, TEXT("Saved game user / Audio Settings"))
}


void UAudioSettingsWidget::ResetAudioSettings()
{
	if (UBVUserSettings* UserSettings = UBVUserSettings::Get())
	{
		UserSettings->ResetAudioSettings();
	}
}