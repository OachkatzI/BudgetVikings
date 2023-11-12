#include "VolumeSlider.h"


FString UVolumeSlider::FormatValue(float Value)
{
	return FString::FromInt(FMath::RoundToInt(Value * 100.f));
}
