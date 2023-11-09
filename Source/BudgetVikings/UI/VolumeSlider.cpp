#include "VolumeSlider.h"
#include "Kismet/GameplayStatics.h"


void UVolumeSlider::OnSliderValueChanged(float Value)
{
	Super::OnSliderValueChanged(Value);
	
	UGameplayStatics::SetSoundMixClassOverride(this, SoundMix, SoundClass, Value, 1.f, 0.f);
}
