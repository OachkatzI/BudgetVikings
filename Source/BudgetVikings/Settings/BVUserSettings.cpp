#include "BVUserSettings.h"


UBVUserSettings* UBVUserSettings::Get()
{
	return GEngine ? CastChecked<UBVUserSettings>(GEngine->GetGameUserSettings()) : nullptr;
}


void UBVUserSettings::LoadSettings(bool bForceReload)
{
	Super::LoadSettings(bForceReload);

	UE_LOG(LogTemp, Warning, TEXT("Load Game User Settings"));
}


void UBVUserSettings::ResetToCurrentSettings()
{
	Super::ResetToCurrentSettings();

	ResetAudioSettings();
}


void UBVUserSettings::ResetAudioSettings()
{
	MainVolume = DefaultMainVolume;
	MusicVolume = DefaultMusicVolume;
	AmbienceVolume = DefaultAmbienceVolume;
	EffectsVolume = DefaultEffectsVolume;
	UIVolume = DefaultUIVolume;
	VoiceChatInputVolume = DefaultVoiceChatInputVolume;
	VoiceChatOutputVolume = DefaultVoiceChatOutputVolume;

	ApplySettings(false);
	OnSettingsUINeedsUpdate.Broadcast();
}


float UBVUserSettings::GetMainVolume() const
{
	return MainVolume;
}


void UBVUserSettings::SetMainVolume(float InVolume)
{
	MainVolume = InVolume;

	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetMusicVolume() const
{
	return MusicVolume;
}


void UBVUserSettings::SetMusicVolume(float InVolume)
{
	MusicVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetEffectsVolume() const
{
	return EffectsVolume;
}


void UBVUserSettings::SetEffectsVolume(float InVolume)
{
	EffectsVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetAmbienceVolume() const
{
	return AmbienceVolume;
}


void UBVUserSettings::SetAmbienceVolume(float InVolume)
{
	AmbienceVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetUIVolume() const
{
	return UIVolume;
}


void UBVUserSettings::SetUIVolume(float InVolume)
{
	UIVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetVoiceChatInputVolume() const
{
	return VoiceChatInputVolume;
}


void UBVUserSettings::SetVoiceChatInputVolume(float InVolume)
{
	VoiceChatInputVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetVoiceChatOutputVolume() const
{
	return VoiceChatOutputVolume;
}


void UBVUserSettings::SetVoiceChatOutputVolume(float InVolume)
{
	VoiceChatOutputVolume = InVolume;
	
	// ToDo: Update Mix / Bus or whatever that actually sets the volume
}


float UBVUserSettings::GetDefaultMainVolume() const
{
	return DefaultMainVolume;
}


float UBVUserSettings::GetDefaultMusicVolume() const
{
	return DefaultMusicVolume;
}


float UBVUserSettings::GetDefaultAmbienceVolume() const
{
	return DefaultAmbienceVolume;
}


float UBVUserSettings::GetDefaultEffectsVolume() const
{
	return DefaultEffectsVolume;
}


float UBVUserSettings::GetDefaultUIVolume() const
{
	return DefaultUIVolume;
}


float UBVUserSettings::GetDefaultVoiceChatInputVolume() const
{
	return DefaultVoiceChatInputVolume;
}


float UBVUserSettings::GetDefaultVoiceChatOutputVolume() const
{
	return DefaultVoiceChatOutputVolume;
}
