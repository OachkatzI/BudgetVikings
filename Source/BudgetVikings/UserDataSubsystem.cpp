#include "UserDataSubsystem.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"


void UUserDataSubsystem::UploadPlayerStats(const FPlayerStats& InPlayerStats)
{
	LoadedPlayerStats = InPlayerStats;
	FString JsonPayload;
	FJsonObjectConverter::UStructToJsonObjectString(InPlayerStats, JsonPayload, 0, 0);

	FString File = FPaths::ProjectUserDir();
	File.Append(TEXT("DebugEOSData/"));
	File.Append(TEXT("PlayerStats.json"));

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (!FileManager.FileExists(*File))
	{
		UE_LOG(LogTemp, Warning, TEXT("[userDataSubystem]: No user file found. Creating new one."));
	}

	if(FFileHelper::SaveStringToFile(JsonPayload, *File))
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Sucsesfuly Written: \"%s\" to the text file"), *JsonPayload);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
	}
}


void UUserDataSubsystem::UploadPlayerLoadouts(const FPlayerLoadouts& InPlayerLoadouts)
{
	LoadedPlayerLoadouts = InPlayerLoadouts;
	FString JsonPayload;
	FJsonObjectConverter::UStructToJsonObjectString(InPlayerLoadouts, JsonPayload, 0, 0);

	FString File = FPaths::ProjectUserDir();
	File.Append(TEXT("DebugEOSData/"));
	File.Append(TEXT("PlayerLoadouts.json"));

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (!FileManager.FileExists(*File))
	{
		UE_LOG(LogTemp, Warning, TEXT("[userDataSubystem]: No user file found. Creating new one."));
	}

	if(FFileHelper::SaveStringToFile(JsonPayload, *File))
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Sucsesfuly Written: \"%s\" to the text file"), *JsonPayload);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
	}
}


void UUserDataSubsystem::DebugDelayedFetchPlayerData()
{
	GetWorld()->GetTimerManager().SetTimer(FakeLoadTimer, this, &ThisClass::FetchPlayerData, 2.f);
}


void UUserDataSubsystem::FetchPlayerStats()
{
	FString File = FPaths::ProjectUserDir();
	File.Append(TEXT("DebugEOSData/"));
	File.Append(TEXT("PlayerStats.json"));

	FString JsonPayload;
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	
	if (FileManager.FileExists(*File))
	{
		if(FFileHelper::LoadFileToString(JsonPayload, *File))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *JsonPayload);  
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *File);
		UE_LOG(LogTemp, Warning, TEXT("Creating Default Stats"));

		// LoadedPlayerStats is empty/default at this point, because load failed
		FJsonObjectConverter::UStructToJsonObjectString(LoadedPlayerStats, JsonPayload, 0, 0);
		UploadPlayerStats(LoadedPlayerStats);
	}
	
	FJsonObjectConverter::JsonObjectStringToUStruct(JsonPayload, &LoadedPlayerStats, 0, 0);
	LoadedEOSPlayerData.PlayerStats = LoadedPlayerStats;
}


void UUserDataSubsystem::FetchPlayerLoadouts()
{
	FString File = FPaths::ProjectUserDir();
	File.Append(TEXT("DebugEOSData/"));
	File.Append(TEXT("PlayerLoadouts.json"));

	FString JsonPayload;
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	
	if (FileManager.FileExists(*File))
	{
		if(FFileHelper::LoadFileToString(JsonPayload, *File))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *JsonPayload);  
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *File);
		UE_LOG(LogTemp, Warning, TEXT("Creating Default Stats"));

		// LoadedPlayerLoadouts is empty/default at this point, because load failed
		FJsonObjectConverter::UStructToJsonObjectString(LoadedPlayerLoadouts, JsonPayload, 0, 0);
		UploadPlayerLoadouts(LoadedPlayerLoadouts);
	}
	
	FJsonObjectConverter::JsonObjectStringToUStruct(JsonPayload, &LoadedPlayerLoadouts, 0, 0);
	LoadedEOSPlayerData.PlayerLoadouts = LoadedPlayerLoadouts;
}


void UUserDataSubsystem::FetchPlayerData()
{
	FetchPlayerStats();
	FetchPlayerLoadouts();

	OnUserDataLoadFinished.Broadcast(true, LoadedEOSPlayerData);
}
