#include "MainMenuGameMode.h"
#include "BudgetVikings/BVGameInstance.h"
#include "BudgetVikings/LoadoutEditor.h"
#include "BudgetVikings/UserDataSubsystem.h"
#include "BudgetVikings/Characters/MainMenuCharacter.h"
#include "BudgetVikings/PlayerControllers/MainMenuPlayerController.h"
#include "BudgetVikings/Settings/BVUserSettings.h"
#include "Kismet/GameplayStatics.h"


void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	ApplyAudioSettings();

	GameInstance = GetGameInstance<UBVGameInstance>();
	check(GameInstance);

	MenuPlayerController = Cast<AMainMenuPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	check(MenuPlayerController);
	
	LoadoutEditor = Cast<ALoadoutEditor>(UGameplayStatics::GetActorOfClass(this, LoadoutEditorClass));
	check(LoadoutEditor);

	const auto Character = Cast<AMainMenuCharacter>(UGameplayStatics::GetActorOfClass(this, AMainMenuCharacter::StaticClass()));
	check(Character);
	LoadoutEditor->SetCharacter(Character);
	
	UserDataSubsystem = GameInstance->GetSubsystem<UUserDataSubsystem>();
	check(UserDataSubsystem);

	CreateLoginWidget(UserDataSubsystem);
	UserDataSubsystem->DebugDelayedFetchPlayerData();
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


void AMainMenuGameMode::OpenLoadoutEditor()
{
	check(LoadoutEditor);
	LoadoutEditor->Open();
}


void AMainMenuGameMode::CloseLoadoutEditor()
{
	check(LoadoutEditor);
	LoadoutEditor->Close();
}