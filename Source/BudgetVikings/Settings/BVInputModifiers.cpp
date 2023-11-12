#include "BVInputModifiers.h"

#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "EnhancedPlayerInput.h"
#include "BudgetVikings/BVLocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "BudgetVikings/Settings/BVEnhancedInputUserSettings.h"


namespace BVInputModifiersHelpers
{
	static UBVLocalPlayer* GetLocalPlayer(const UEnhancedPlayerInput* PlayerInput)
	{
		if (PlayerInput)
		{
			if (APlayerController* PC = Cast<APlayerController>(PlayerInput->GetOuter()))
			{
				return Cast<UBVLocalPlayer>(PC->GetLocalPlayer());
			}
		}
		return nullptr;
	}
}


FInputActionValue USensitivityModifier::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime)
{
	if (ensureMsgf(CurrentValue.GetValueType() == EInputActionValueType::Axis2D, TEXT("Sensitivity modifier only for 2D axis.")))
	{
		if (const UBVLocalPlayer* LocalPlayer = BVInputModifiersHelpers::GetLocalPlayer(PlayerInput))
		{
			if (!LocalPlayer)
			{
				return CurrentValue;
			}

			const UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
			const UBVEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings<UBVEnhancedInputUserSettings>();
			ensure(Settings);

			const FVector2D ScalarToUse = FVector2D(Settings->GetAimSensitivityHorizontal(), Settings->GetAimSensitivityVertical());
			return CurrentValue.Get<FVector2D>() * ScalarToUse;
		}
	}

	return CurrentValue;
}


FInputActionValue UAimInversionModifier::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime)
{
	const UBVLocalPlayer* LocalPlayer = BVInputModifiersHelpers::GetLocalPlayer(PlayerInput);
	if (!LocalPlayer)
	{
		return CurrentValue;
	}

	const UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	const UBVEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings<UBVEnhancedInputUserSettings>();
	ensure(Settings);

	FVector NewValue = CurrentValue.Get<FVector>();

	if (Settings->GetInvertVerticalAxis())
	{
		NewValue.Y *= -1.0f;
	}

	if (Settings->GetInvertHorizontalAxis())
	{
		NewValue.X *= -1.0f;
	}

	return NewValue;
}
