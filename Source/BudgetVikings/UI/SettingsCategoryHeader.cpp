#include "SettingsCategoryHeader.h"
#include "CommonTextBlock.h"


void USettingsCategoryHeader::SetText(const FText& CategoryTitle) const
{
	CategoryTextBlock->SetText(CategoryTitle);
}
