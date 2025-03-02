#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EOSTypes/PlayerLoadout.h"
#include "LoadoutDataAsset.generated.h"


UCLASS(Blueprintable, BlueprintType)
class BUDGETVIKINGS_API ULoadoutDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Set(const FPlayerLoadout& PlayerLoadout);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LoadoutName;
};
