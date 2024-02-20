#pragma once

#include "CoreMinimal.h"
#include "PlayerStats.generated.h"


USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	int32 TotalExperience = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 TotalCoins = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentCoins = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 Kills = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 Deaths = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 NumRoundsPlayed = 0;
};