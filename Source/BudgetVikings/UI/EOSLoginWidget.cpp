#include "EOSLoginWidget.h"
#include "BudgetVikings/UserDataSubsystem.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void UEOSLoginWidget::Init(UUserDataSubsystem* InUserDataSubsystem)
{
	check(InUserDataSubsystem);
	UserDataSubsystem = InUserDataSubsystem;
	UserDataSubsystem.Get()->OnUserDataLoadFinished.AddDynamic(this, &ThisClass::HandleOnUserDataLoadFinished);

	RetryButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnRetryClicked);
	ExitButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnQuitGameClicked);
}


void UEOSLoginWidget::OnRetryClicked()
{
	DisplayLoadingInProgress(true);
	if (UserDataSubsystem.IsValid())
	{
		UserDataSubsystem.Get()->DebugDelayedFetchPlayerStats();
	}
	else
	{
		// ToDo: Proper error handling
		OnLoginFinished.Broadcast();
	}
}


void UEOSLoginWidget::HandleOnUserDataLoadFinished(bool bSuccess, FPlayerStats PlayerStats)
{
	DisplayLoadingInProgress(false);

	if (bSuccess)
	{
		DisplayLoginSuccess(true);
		GetWorld()->GetTimerManager().SetTimer(SuccessVisualizeTimer, this, &ThisClass::RemoveFromParent, SuccessVisualizeTime);
	}
	else
	{
		DisplayErrorBox(true);
	}
}


void UEOSLoginWidget::RemoveFromParent()
{
	OnLoginFinished.Broadcast();
	
	Super::RemoveFromParent();

	if (UserDataSubsystem.IsValid())
	{
		UserDataSubsystem.Get()->OnUserDataLoadFinished.RemoveDynamic(this, &ThisClass::HandleOnUserDataLoadFinished);
	}
}


void UEOSLoginWidget::OnQuitGameClicked()
{
	const auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	check(PlayerController);
	
	UKismetSystemLibrary::QuitGame(this, PlayerController, EQuitPreference::Quit, true);
}
