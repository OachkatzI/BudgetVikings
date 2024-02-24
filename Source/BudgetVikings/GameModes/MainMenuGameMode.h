#pragma once

#include "CoreMinimal.h"
#include "BudgetVikings/EOSTypes/PlayerStats.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"


class UUserDataSubsystem;
class UBVGameInstance;


UCLASS()
class BUDGETVIKINGS_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

	void ApplyAudioSettings() const;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundMix> SoundMix;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundClass> MainSoundClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundClass> MusicSoundClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundClass> AmbienceSoundClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundClass> EffectsSoundClass;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundClass> UISoundClass;

	UPROPERTY()
	TObjectPtr<UBVGameInstance> GameInstance;

	UPROPERTY()
	TObjectPtr<UUserDataSubsystem> UserDataSubsystem;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateLoginWidget(UUserDataSubsystem* InUserDataSubsystem);
};
