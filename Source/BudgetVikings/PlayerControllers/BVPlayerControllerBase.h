#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BVPlayerControllerBase.generated.h"


class UInputMappingContext;


UCLASS()
class BUDGETVIKINGS_API ABVPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SprintHoldContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SprintToggleContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> CrouchHoldContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> CrouchToggleContext;
};
