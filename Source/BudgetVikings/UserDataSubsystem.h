#pragma once

#include "CoreMinimal.h"
#include "EOSTypes/EOSPlayerData.h"
#include "EOSTypes/PlayerStats.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UserDataSubsystem.generated.h"


class ULoadoutDataAsset;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUserDataLoadFinished, bool, bSuccess, FEOSPlayerData, EOSPlayerData);


///
/// Handles interaction with Epic Online Services for PlayerStats, Loadouts and Progression
///
UCLASS()
class BUDGETVIKINGS_API UUserDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	void UploadPlayerStats(const FPlayerStats& InPlayerStats);

	void UploadPlayerLoadouts(const FPlayerLoadouts& InPlayerLoadouts);
	
	UFUNCTION()
	void DebugDelayedFetchPlayerData();

	FTimerHandle FakeLoadTimer;
	
	UFUNCTION()
	void FetchPlayerStats();

	UFUNCTION()
	void FetchPlayerData();

	UFUNCTION()
	void FetchPlayerLoadouts();

	FOnUserDataLoadFinished OnUserDataLoadFinished;

	FORCEINLINE FPlayerStats& GetPlayerStats() { return LoadedPlayerStats; }

	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<ULoadoutDataAsset>> LoadoutDataAssets;

private:

	int32 DebugLoadFailCounter = 0;

	UPROPERTY()
	FPlayerStats LoadedPlayerStats{};

	UPROPERTY()
	FPlayerLoadouts LoadedPlayerLoadouts{};

	UPROPERTY()
	FEOSPlayerData LoadedEOSPlayerData{};
};
