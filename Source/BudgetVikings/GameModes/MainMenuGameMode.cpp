#include "MainMenuGameMode.h"

#include "BudgetVikings/BVGameInstance.h"
#include "BudgetVikings/UserDataSubsystem.h"
#include "BudgetVikings/Settings/BVUserSettings.h"
#include "Kismet/GameplayStatics.h"


void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	ApplyAudioSettings();

	GameInstance = GetGameInstance<UBVGameInstance>();
	check(GameInstance);

	UserDataSubsystem = GameInstance->GetSubsystem<UUserDataSubsystem>();
	check(UserDataSubsystem);
}


void AMainMenuGameMode::ApplyAudioSettings() const
{
	const UBVUserSettings* UserSettings = UBVUserSettings::Get();
	check(UserSettings);

	UGameplayStatics::SetBaseSoundMix(this, SoundMix);

	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, MainSoundClass, UserSettings->GetMainVolume(), 1.f, 0.f);
	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, MusicSoundClass, UserSettings->GetMusicVolume(), 1.f, 0.f);
	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, AmbienceSoundClass, UserSettings->GetAmbienceVolume(), 1.f, 0.f);
	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, EffectsSoundClass, UserSettings->GetEffectsVolume(), 1.f, 0.f);
	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, UISoundClass, UserSettings->GetUIVolume(), 1.f, 0.f);
}

