// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BudgetVikingsServerTarget : TargetRules
{
	public BudgetVikingsServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("BudgetVikings");
		
		bUseLoggingInShipping = true; 
		
		// The name of your game as you set it on the Steamworks webpage.
		GlobalDefinitions.Add("UE_PROJECT_STEAMPRODUCTNAME=\"BudgetVikings\"");

		// This is what will appear under the "Game" tab in the Steam server browser. Steamworks list this under "Server browser name" in the Dedicated Servers section of your app.
		GlobalDefinitions.Add("UE_PROJECT_STEAMGAMEDESC=\"BudgetVikings\"");

		// I am not entirely sure what this is used for. Changing it seemed to not effect game searches.
		GlobalDefinitions.Add("UE_PROJECT_STEAMGAMEDIR=\"BudgetVikings\"");

		// The steam appID of your project.
		GlobalDefinitions.Add("UE_PROJECT_STEAMSHIPPINGID=2698260");
	}
}
