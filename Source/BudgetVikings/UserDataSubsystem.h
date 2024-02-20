#pragma once

#include "CoreMinimal.h"
#include "EOSTypes/PlayerStats.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UserDataSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUserDataLoadFinished, bool, bSuccess, FPlayerStats, PlayerStats);


///
/// Handles interaction with Epic Online Services for PlayerStats, Loadouts and Progression
///
UCLASS()
class BUDGETVIKINGS_API UUserDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	void UploadPlayerStats(const FPlayerStats& InPlayerStats);
	
	UFUNCTION()
	void DebugDelayedFetchPlayerStats();

	FTimerHandle FakeLoadTimer;
	
	UFUNCTION()
	void FetchPlayerStats();

	FOnUserDataLoadFinished OnUserDataLoadFinished;

private:

	int32 DebugLoadFailCounter = 0;
};
