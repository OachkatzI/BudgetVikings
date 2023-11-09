#include "NamedSlider.h"
#include "CommonTextBlock.h"
#include "Components/Slider.h"


void UNamedSlider::NativePreConstruct()
{
	Super::NativePreConstruct();

	SetTitleText(Title);
	SetValueText(FText::FromString(FString::FromInt(FMath::RoundToInt(Slider->GetValue() * 100.f))));
}


void UNamedSlider::NativeConstruct()
{
	Super::NativeConstruct();

	Slider->OnValueChanged.AddDynamic(this, &ThisClass::OnSliderValueChanged);
}


void UNamedSlider::OnSliderValueChanged(float Value)
{
	SetValueText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100.f))));
}


void UNamedSlider::SetTitleText(const FText& NewTitle) const
{
	TitleText->SetText(Title);
}


void UNamedSlider::SetValueText(const FText& Value) const
{
	ValueText->SetText(Value);
}
