#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BudgetVikings/EOSTypes/PlayerStats.h"
#include "EOSLoginWidget.generated.h"


class UButton;
class UUserDataSubsystem;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoginFinished);


UCLASS()
class BUDGETVIKINGS_API UEOSLoginWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Init(UUserDataSubsystem* InUserDataSubsystem);
	
	virtual void RemoveFromParent() override;

protected:

	UPROPERTY(BlueprintAssignable)
	FOnLoginFinished OnLoginFinished;
	
	UPROPERTY(EditDefaultsOnly)
	float SuccessVisualizeTime;

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayLoginSuccess(bool bShow);

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayLoadingInProgress(bool bShow);

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayErrorBox(bool bShow);

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> RetryButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> ExitButton;

private:
	
	UFUNCTION()
	void HandleOnUserDataLoadFinished(bool bSuccess, FEOSPlayerData PlayerData);

	UPROPERTY()
	TWeakObjectPtr<UUserDataSubsystem> UserDataSubsystem;

	FTimerHandle SuccessVisualizeTimer;

	UFUNCTION()
	void OnRetryClicked();
	
	UFUNCTION()
	void OnQuitGameClicked();
};


