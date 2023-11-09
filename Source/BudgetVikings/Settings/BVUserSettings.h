#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "BVUserSettings.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsUINeedsUpdate);


UCLASS()
class BUDGETVIKINGS_API UBVUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	
	static UBVUserSettings* Get();
	
	FOnSettingsUINeedsUpdate OnSettingsUINeedsUpdate;

	virtual void LoadSettings(bool bForceReload) override;

	virtual void ResetToCurrentSettings() override;
	
	void ResetAudioSettings();

	UFUNCTION()
	float GetMainVolume() const;
	
	UFUNCTION()
	void SetMainVolume(float InVolume);

	UFUNCTION()
	float GetMusicVolume() const;
	
	UFUNCTION()
	void SetMusicVolume(float InVolume);

	UFUNCTION()
	float GetEffectsVolume() const;
	
	UFUNCTION()
	void SetEffectsVolume(float InVolume);

	UFUNCTION()
	float GetAmbienceVolume() const;
	
	UFUNCTION()
	void SetAmbienceVolume(float InVolume);

	UFUNCTION()
	float GetUIVolume() const;
	
	UFUNCTION()
	void SetUIVolume(float InVolume);

	UFUNCTION()
	float GetVoiceChatInputVolume() const;

	UFUNCTION()
	void SetVoiceChatInputVolume(float InVolume);

	UFUNCTION()
	float GetVoiceChatOutputVolume() const;
	
	UFUNCTION()
	void SetVoiceChatOutputVolume(float InVolume);

	UFUNCTION()
	float GetDefaultMainVolume() const;

	UFUNCTION()
	float GetDefaultMusicVolume() const;

	UFUNCTION()
	float GetDefaultAmbienceVolume() const;

	UFUNCTION()
	float GetDefaultEffectsVolume() const;

	UFUNCTION()
	float GetDefaultUIVolume() const;

	UFUNCTION()
	float GetDefaultVoiceChatInputVolume() const;

	UFUNCTION()
	float GetDefaultVoiceChatOutputVolume() const;

private:

	UPROPERTY(Config)
	float MainVolume = 1.0f;
	
	UPROPERTY(Config)
	float MusicVolume = 1.0f;

	UPROPERTY(Config)
	float AmbienceVolume = 1.0f;
	
	UPROPERTY(Config)
	float EffectsVolume = 1.0f;
	
	UPROPERTY(Config)
	float UIVolume = 1.0f;
	
	UPROPERTY(Config)
	float VoiceChatInputVolume = 1.0f;

	UPROPERTY(Config)
	float VoiceChatOutputVolume = 1.0f;

	UPROPERTY(Config)
	float DefaultMainVolume = 1.0f;
	
	UPROPERTY(Config)
	float DefaultMusicVolume = 1.0f;

	UPROPERTY(Config)
	float DefaultAmbienceVolume = 1.0f;
	
	UPROPERTY(Config)
	float DefaultEffectsVolume = 1.0f;
	
	UPROPERTY(Config)
	float DefaultUIVolume = 1.0f;
	
	UPROPERTY(Config)
	float DefaultVoiceChatInputVolume = 1.0f;

	UPROPERTY(Config)
	float DefaultVoiceChatOutputVolume = 1.0f;
};
