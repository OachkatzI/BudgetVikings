#pragma once

#include "CoreMinimal.h"
#include "UserSettings/EnhancedInputUserSettings.h"
#include "BVEnhancedInputUserSettings.generated.h"


UCLASS()
class BUDGETVIKINGS_API UBVEnhancedInputUserSettings : public UEnhancedInputUserSettings
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(SaveGame, BlueprintReadWrite, Category="Enhanced Input|User Settings")
	bool bHoldSprint;

	UPROPERTY(SaveGame, BlueprintReadWrite, Category="Enhanced Input|User Settings")
	bool bHoldCrouch;
};
