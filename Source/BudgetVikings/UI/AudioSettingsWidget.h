#pragma once

#include "CoreMinimal.h"
#include "SettingsWidgetBase.h"
#include "AudioSettingsWidget.generated.h"


class UVolumeSlider;


UCLASS()
class BUDGETVIKINGS_API UAudioSettingsWidget : public USettingsWidgetBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SaveAudioSettings();

	UFUNCTION(BlueprintCallable)
	void ResetAudioSettings();

protected:
	
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void RefreshUI();

private:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVolumeSlider> VolumeSliderMain;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVolumeSlider> VolumeSliderMusic;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVolumeSlider> VolumeSliderAmbience;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVolumeSlider> VolumeSliderEffects;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVolumeSlider> VolumeSliderUI;
};
