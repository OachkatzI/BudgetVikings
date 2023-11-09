#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"


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
};
