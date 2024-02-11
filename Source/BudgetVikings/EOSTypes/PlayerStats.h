#pragma once

#include "CoreMinimal.h"
#include "PlayerStats.generated.h"


USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	int32 TotalExperience;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalCoins;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentCoins;

	UPROPERTY(BlueprintReadWrite)
	int32 Kills;

	UPROPERTY(BlueprintReadWrite)
	int32 Deaths;

	UPROPERTY(BlueprintReadWrite)
	int32 NumRoundsPlayed;
};