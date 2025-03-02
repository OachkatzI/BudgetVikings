#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"


class AMainMenuCameraManager;
class UInputMappingContext;


UCLASS()
class BUDGETVIKINGS_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSet<UInputMappingContext*> MappingContexts;

	UPROPERTY()
	TObjectPtr<AMainMenuCameraManager> MenuCameraManager;
};
