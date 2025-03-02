#include "MainMenuPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "MainMenuCameraManager.h"
#include "UserSettings/EnhancedInputUserSettings.h"


void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (const UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->GetUserSettings()->RegisterInputMappingContexts(MappingContexts);
	}

	// ToDo: Set camera state to initial
	MenuCameraManager = Cast<AMainMenuCameraManager>(PlayerCameraManager);
	check(MenuCameraManager);
}
