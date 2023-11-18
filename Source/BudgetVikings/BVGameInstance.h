#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSessionSettings.h"
#include "BVGameInstance.generated.h"


class UMultiplayerSessionsSubsystem;


UCLASS()
class BUDGETVIKINGS_API UBVGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	virtual void Init() override;
	
	void SetupOnlineSession();

protected:
	
	void AutoJoinFirstSession();
	
	virtual void OnStart() override;
	
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);

	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);

private:
	
	TObjectPtr<UMultiplayerSessionsSubsystem>  MultiplayerSessionsSubsystem;
};
