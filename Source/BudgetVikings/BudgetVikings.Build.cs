// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BudgetVikings : ModuleRules
{
	public BudgetVikings(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "CommonUI", "UMG", "SlateCore", "Slate", "OnlineSubsystem", "OnlineSubsystemSteam", "OnlineSubsystemUtils" });
	}
}
