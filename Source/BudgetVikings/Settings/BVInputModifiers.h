#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "BVInputModifiers.generated.h"


UCLASS()
class BUDGETVIKINGS_API USensitivityModifier : public UInputModifier
{
	GENERATED_BODY()

protected:
	
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime) override;
};


UCLASS()
class BUDGETVIKINGS_API UAimInversionModifier : public UInputModifier
{
	GENERATED_BODY()

protected:
	
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime) override;
};
