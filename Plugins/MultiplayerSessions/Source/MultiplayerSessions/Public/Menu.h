#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"


class UButton;
class UMultiplayerSessionsSubsystem;


UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	
	virtual void NativeDestruct() override;
	virtual bool Initialize() override;

	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);

	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);

	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	
public:
	
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));

private:

	UPROPERTY(meta = (BindWidget))
	UButton* B_HostSession;

	UPROPERTY(meta = (BindWidget))
	UButton* B_JoinSession;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();

	TObjectPtr<UMultiplayerSessionsSubsystem>  MultiplayerSessionsSubsystem;
	int32 NumPublicConnections {4};
	FString MatchType {TEXT("FreeForAll")};
	FString PathToLobby{TEXT("")};
};
