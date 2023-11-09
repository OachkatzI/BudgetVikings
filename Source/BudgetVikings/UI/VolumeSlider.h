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

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundMix> SoundMix;
	
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<USoundClass> SoundClass;
	
private:
	
	virtual void OnSliderValueChanged(float Value) override;
};
