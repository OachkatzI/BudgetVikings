#include "DisplayNamesBlueprintLibrary.h"


FText UDisplayNamesBlueprintLibrary::BoolToDisplayName(bool bInput)
{
	return bInput ? FText::FromString("On") : FText::FromString("Off");
}


FText UDisplayNamesBlueprintLibrary::ResolutionToDisplayName(FIntPoint Resolution)
{
	// Could also override ToString, but that would require engine changes
	return FText::FromString(FString::Printf(TEXT("%s x %s"), *LexToString(Resolution.X), *LexToString(Resolution.Y)));
}
