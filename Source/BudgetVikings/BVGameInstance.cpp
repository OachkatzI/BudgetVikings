#include "BVGameInstance.h"
#include "MultiplayerSessionsSubsystem.h"


void UBVGameInstance::Init()
{
	Super::Init();
	
	UE_LOG(LogTemp, Warning, TEXT("GI Init"))
}


void UBVGameInstance::OnStart()
{
	Super::OnStart();

	MultiplayerSessionsSubsystem = GetSubsystem<UMultiplayerSessionsSubsystem>();
	ensureAlways(MultiplayerSessionsSubsystem);

	if (IsDedicatedServerInstance())
	{
		SetupOnlineSession();
	}
	// else
	// {
	// 	AutoJoinFirstSession();
	// }
}


void UBVGameInstance::SetupOnlineSession()
{
	MultiplayerSessionsSubsystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
	MultiplayerSessionsSubsystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
	MultiplayerSessionsSubsystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);

	MultiplayerSessionsSubsystem->CreateSession(32, "FFA");
}


void UBVGameInstance::AutoJoinFirstSession()
{
	MultiplayerSessionsSubsystem->MultiplayerOnFindSessionsComplete.AddUObject(this, &ThisClass::OnFindSessions);
	MultiplayerSessionsSubsystem->FindSessions(10);
}


void UBVGameInstance::OnCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("CREATE SESSION SUCCESS!"));
		
		if (const auto World = GetWorld())
		{
			UE_LOG(LogTemp, Warning, TEXT("Travelling to Multiplayer Map"));

			if (World->ServerTravel("/Game/Maps/ThirdPersonMap"))
			{
				UE_LOG(LogTemp, Warning, TEXT("STARTING SESSION"));

				MultiplayerSessionsSubsystem->StartSession();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CREATE SESSION FAILURE!"));
	}
}


void UBVGameInstance::OnDestroySession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("DESTROY SESSION SUCCESS!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DESTROY SESSION FAILURE!"));
	}
}


void UBVGameInstance::OnStartSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("START SESSION SUCCESS!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("START SESSION FAILURE!"));
	}
}


void UBVGameInstance::OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("Num Found Sessions: %d"), SessionResults.Num());
	
	for (auto Result : SessionResults)
	{
		FString SettingsValue;
		Result.Session.SessionSettings.Get(FName("MatchType"), SettingsValue);
		if (SettingsValue == "FFA")
		{
			MultiplayerSessionsSubsystem->JoinSession(Result);
			return;
		}
	}
}
