#pragma once

#include "CoreMinimal.h"
#include "UserSettings/EnhancedInputUserSettings.h"
#include "BVEnhancedInputUserSettings.generated.h"


UENUM(BlueprintType)
enum class EActivationMode : uint8
{
	EAM_Toggle = 0 UMETA(DisplayName = "Toggle"),
	EAM_Hold = 1 UMETA(DisplayName = "Hold"),
};


UCLASS()
class BUDGETVIKINGS_API UBVEnhancedInputUserSettings : public UEnhancedInputUserSettings
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void ResetInputSettings();
	
	UFUNCTION(BlueprintCallable)
	EActivationMode GetSprintMode() const { return SprintMode; }
	UFUNCTION(BlueprintCallable)
	void SetSprintMode(EActivationMode NewValue) { SprintMode = NewValue; }
	UFUNCTION(BlueprintCallable)
	EActivationMode GetDefaultSprintMode() const { return DefaultSprintMode; }

	UFUNCTION(BlueprintCallable)
	EActivationMode GetCrouchMode() const { return CrouchMode; }
	UFUNCTION(BlueprintCallable)
	void SetCrouchMode(EActivationMode NewValue) { CrouchMode = NewValue; }
	UFUNCTION(BlueprintCallable)
	EActivationMode GetDefaultCrouchMode() const { return DefaultCrouchMode; }

	UFUNCTION(BlueprintCallable)
	bool GetInvertHorizontalAxis() const { return bInvertHorizontalAxis; }
	UFUNCTION(BlueprintCallable)
	void SetInvertHorizontalAxis(bool NewValue) { bInvertHorizontalAxis = NewValue; }
	UFUNCTION(BlueprintCallable)
	bool GetDefaultInvertHorizontalAxis() const { return bDefaultInvertHorizontalAxis; }

	UFUNCTION(BlueprintCallable)
	bool GetInvertVerticalAxis() const { return bInvertVerticalAxis; }
	UFUNCTION(BlueprintCallable)
	void SetInvertVerticalAxis(bool NewValue) { bInvertVerticalAxis = NewValue; }
	UFUNCTION(BlueprintCallable)
	bool GetDefaultInvertVerticalAxis() const { return bDefaultInvertVerticalAxis; }

	UFUNCTION(BlueprintCallable)
	double GetAimSensitivityHorizontal() const { return AimSensitivityHorizontal; }
	UFUNCTION(BlueprintCallable)
	void SetAimSensitivityHorizontal(double NewValue) { AimSensitivityHorizontal = NewValue; }
	UFUNCTION(BlueprintCallable)
	double GetDefaultAimSensitivityHorizontal() const { return DefaultAimSensitivityHorizontal; }

	UFUNCTION(BlueprintCallable)
	double GetAimSensitivityVertical() const { return AimSensitivityVertical; }
	UFUNCTION(BlueprintCallable)
	void SetAimSensitivityVertical(double NewValue) { AimSensitivityVertical = NewValue; }
	UFUNCTION(BlueprintCallable)
	double GetDefaultAimSensitivityVertical() const { return DefaultAimSensitivityVertical; }
	
protected:
	
	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	EActivationMode SprintMode = EActivationMode::EAM_Toggle;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	EActivationMode DefaultSprintMode = EActivationMode::EAM_Toggle;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	EActivationMode CrouchMode = EActivationMode::EAM_Toggle;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	EActivationMode DefaultCrouchMode = EActivationMode::EAM_Toggle;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	bool bInvertHorizontalAxis = false;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	bool bDefaultInvertHorizontalAxis = false;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	bool bInvertVerticalAxis = false;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	bool bDefaultInvertVerticalAxis = false;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	double AimSensitivityHorizontal = 1.f;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	double DefaultAimSensitivityHorizontal = 1.f;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	double AimSensitivityVertical = 1.f;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category = "Enhanced Input|User Settings")
	double DefaultAimSensitivityVertical = 1.f;
};
