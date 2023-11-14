#include "BVPlayerControllerBase.h"
#include "EnhancedInputSubsystems.h"
#include "BudgetVikings/Settings/BVEnhancedInputUserSettings.h"


void ABVPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	const auto InputSettings = Subsystem->GetUserSettings<UBVEnhancedInputUserSettings>();
	check(InputSettings);

	if (InputSettings->GetSprintMode() == EActivationMode::EAM_Toggle)
	{
		if (!Subsystem->HasMappingContext(SprintToggleContext))
		{
			Subsystem->AddMappingContext(SprintToggleContext, 0);
		}
	}
	else
	{
		if (!Subsystem->HasMappingContext(SprintHoldContext))
		{
			Subsystem->AddMappingContext(SprintHoldContext, 0);
		}
	}

	if (InputSettings->GetCrouchMode() == EActivationMode::EAM_Toggle)
	{
		if (!Subsystem->HasMappingContext(CrouchToggleContext))
		{
			Subsystem->AddMappingContext(CrouchToggleContext, 0);
		}
	}
	else
	{
		if (!Subsystem->HasMappingContext(CrouchHoldContext))
		{
			Subsystem->AddMappingContext(CrouchHoldContext, 0);
		}
	}
}
