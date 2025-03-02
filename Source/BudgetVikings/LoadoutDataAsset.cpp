#include "LoadoutDataAsset.h"


void ULoadoutDataAsset::Set(const FPlayerLoadout& PlayerLoadout)
{
	LoadoutName = PlayerLoadout.Name;
}
