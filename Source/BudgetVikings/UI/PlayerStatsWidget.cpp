#include "PlayerStatsWidget.h"
#include "BudgetVikings/BVGameInstance.h"
#include "BudgetVikings/UserDataSubsystem.h"


void UPlayerStatsWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	auto GameInstance = GetGameInstance<UBVGameInstance>();
	check(GameInstance);

	auto UserDataSubsystem = GameInstance->GetSubsystem<UUserDataSubsystem>();
	PopulateList(UserDataSubsystem->GetPlayerStats());
}


void UPlayerStatsWidget::DebugSaveStats(FPlayerStats NewPlayerStats)
{
	auto GameInstance = GetGameInstance<UBVGameInstance>();
	check(GameInstance);

	auto UserDataSubsystem = GameInstance->GetSubsystem<UUserDataSubsystem>();
	UserDataSubsystem->UploadPlayerStats(NewPlayerStats);
}
