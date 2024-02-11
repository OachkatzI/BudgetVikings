#pragma once

#include "CoreMinimal.h"
#include "EOSTypes/PlayerStats.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UserDataSubsystem.generated.h"


///
/// Handles interaction with Epic Online Services for PlayerStats, Loadouts and Progression
///
UCLASS()
class BUDGETVIKINGS_API UUserDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	void UploadPlayerStats(FPlayerStats& InPlayerStats);

	void FetchPlayerStats(FPlayerStats& OutPlayerStats);
};
