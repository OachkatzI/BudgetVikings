#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BudgetVikings/EOSTypes/PlayerStats.h"
#include "PlayerStatsWidget.generated.h"


class USingleStatWidget;


UCLASS()
class BUDGETVIKINGS_API UPlayerStatsWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
protected:
	
	virtual void NativeOnActivated() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void PopulateList(FPlayerStats InPlayerStats);

	UFUNCTION(BlueprintCallable)
	void DebugSaveStats(FPlayerStats NewPlayerStats);
};
