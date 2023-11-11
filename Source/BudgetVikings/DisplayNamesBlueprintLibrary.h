#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DisplayNamesBlueprintLibrary.generated.h"


UCLASS()
class BUDGETVIKINGS_API UDisplayNamesBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "DisplayNames")
	static FText BoolToDisplayName(bool bInput);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "DisplayNames")
	static FText ResolutionToDisplayName(FIntPoint Resolution);
};
