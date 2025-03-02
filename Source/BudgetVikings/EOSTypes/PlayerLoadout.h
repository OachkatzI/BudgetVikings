#pragma once

#include "CoreMinimal.h"
#include "PlayerLoadout.generated.h"


USTRUCT(BlueprintType)
struct FPlayerLoadout
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString Name;
};


USTRUCT(BlueprintType)
struct FPlayerLoadouts
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FPlayerLoadout> CustomLoadouts;
};