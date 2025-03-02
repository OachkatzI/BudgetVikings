#pragma once

#include "CoreMinimal.h"
#include "PlayerLoadout.h"
#include "PlayerStats.h"
#include "EOSPlayerData.generated.h"


USTRUCT(BlueprintType)
struct FEOSPlayerData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FPlayerStats PlayerStats;

	UPROPERTY(BlueprintReadWrite)
	FPlayerLoadouts PlayerLoadouts;
};