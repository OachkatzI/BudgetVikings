#include "MainMenuPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "UserSettings/EnhancedInputUserSettings.h"


void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (const UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->GetUserSettings()->RegisterInputMappingContexts(MappingContexts);
	}
}
