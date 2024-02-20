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
