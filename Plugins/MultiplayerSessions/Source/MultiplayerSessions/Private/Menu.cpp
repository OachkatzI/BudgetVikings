#include "Menu.h"
#include "Components/Button.h"
#include "MultiplayerSessionsSubsystem.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"


void UMenu::MenuSetup(int32 NumberPublicConnections, FString TypeOfMatch, FString LobbyPath)
{
	NumPublicConnections = NumberPublicConnections;
	MatchType = TypeOfMatch;
	PathToLobby = FString::Printf(TEXT("%s?listen"), *LobbyPath);
	
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	
	if (const UWorld* World = GetWorld())
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	if (const UGameInstance* GameInstance = GetGameInstance())
	{
		MultiplayerSessionsSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
	}

	ensureAlways(MultiplayerSessionsSubsystem);
	MultiplayerSessionsSubsystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
	MultiplayerSessionsSubsystem->MultiplayerOnFindSessionsComplete.AddUObject(this, &ThisClass::OnFindSessions);
	MultiplayerSessionsSubsystem->MultiplayerOnJoinSessionComplete.AddUObject(this, &ThisClass::OnJoinSession);
	MultiplayerSessionsSubsystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);
	MultiplayerSessionsSubsystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
}


bool UMenu::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	ensureAlways(B_HostSession);
	B_HostSession->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);

	ensureAlways(B_JoinSession);
	B_JoinSession->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);

	return true;
}


void UMenu::OnCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString("Session Created successfully"));
		}
		
		if (const auto World = GetWorld())
		{
			World->ServerTravel(PathToLobby);
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString("Failed to create session"));
		}

		B_HostSession->SetIsEnabled(true);
	}
}


void UMenu::OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful)
{
	if (MultiplayerSessionsSubsystem == nullptr)
	{
		return;
	}
	
	for (auto Result: SessionResults)
	{
		FString SettingsValue;
		Result.Session.SessionSettings.Get(FName("MatchType"), SettingsValue);
		if (SettingsValue == MatchType)
		{
			MultiplayerSessionsSubsystem->JoinSession(Result);
			break;
		}
	}

	if (!bWasSuccessful || SessionResults.Num() == 0)
	{
		B_JoinSession->SetIsEnabled(true);
	}
}


void UMenu::OnJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		const auto SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			FString Address;
			SessionInterface->GetResolvedConnectString(NAME_GameSession, Address);

			if (APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController())
			{
				PlayerController->ClientTravel(Address, TRAVEL_Absolute);
			}
		}
	}

	if (Result != EOnJoinSessionCompleteResult::Success)
	{
		B_JoinSession->SetIsEnabled(true);
	}
}


void UMenu::OnDestroySession(bool bWasSuccessful)
{
	
}


void UMenu::OnStartSession(bool bWasSuccessful)
{
	
}


void UMenu::HostButtonClicked()
{
	B_HostSession->SetIsEnabled(false);
	if (MultiplayerSessionsSubsystem)
	{
		MultiplayerSessionsSubsystem->CreateSession(NumPublicConnections, MatchType);
	}
}


void UMenu::JoinButtonClicked()
{
	B_JoinSession->SetIsEnabled(false);
	if (MultiplayerSessionsSubsystem)
	{
		MultiplayerSessionsSubsystem->FindSessions(10000);
	}
}


void UMenu::MenuTearDown()
{
	RemoveFromParent();
	if (const UWorld* World = GetWorld())
	{
		if (const auto PlayerController = World->GetFirstPlayerController())
		{
			const FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}


void UMenu::NativeDestruct()
{
	MenuTearDown();
	
	Super::NativeDestruct();
}
