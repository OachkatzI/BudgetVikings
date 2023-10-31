// Copyright Epic Games, Inc. All Rights Reserved.

#include "BudgetVikingsGameMode.h"
#include "BudgetVikingsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABudgetVikingsGameMode::ABudgetVikingsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
