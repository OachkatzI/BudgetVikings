#pragma once

#include "CoreMinimal.h"
#include "NamedSlider.h"
#include "VolumeSlider.generated.h"


class USoundClass;
class USoundMix;


UCLASS()
class BUDGETVIKINGS_API UVolumeSlider : public UNamedSlider
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USoundMix> SoundMix;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	TObjectPtr<USoundClass> SoundClass;

	virtual FString FormatValue(float Value) override;
};
