#include "NamedSlider.h"
#include "CommonTextBlock.h"
#include "Components/Slider.h"
#include "Kismet/KismetStringLibrary.h"


void UNamedSlider::NativePreConstruct()
{
	Super::NativePreConstruct();

	SetTitleText(Title);
	SetValueText(FText::FromString(FormatValue(Slider->GetValue())));
	Slider->SetMinValue(MinValue);
	Slider->SetMaxValue(MaxValue);
}


void UNamedSlider::NativeConstruct()
{
	Super::NativeConstruct();

	Slider->OnValueChanged.AddDynamic(this, &ThisClass::OnSliderValueChanged);
}


void UNamedSlider::OnSliderValueChanged_Implementation(float Value)
{
	SetValueText(FText::FromString(FormatValue(Value)));
	OnSliderValueChangedEvent.Broadcast(Value);
}


FString UNamedSlider::FormatValue(float Value)
{
	auto AsString = FString::SanitizeFloat(Value);
	FString LeftOfDecimal;
	FString RightOfDecimal;
	if (UKismetStringLibrary::Split(AsString, FString("."), LeftOfDecimal, RightOfDecimal))
	{
		const int NumDecimalPoints = FMath::Min(2, UKismetStringLibrary::Len(RightOfDecimal));
		auto TrimmedDecimalString = UKismetStringLibrary::GetSubstring(RightOfDecimal, 0, NumDecimalPoints);
		return LeftOfDecimal.Append(".").Append(TrimmedDecimalString);
	}
	
	return AsString;
}


void UNamedSlider::SetTitleText(const FText& NewTitle) const
{
	TitleText->SetText(NewTitle);
}


void UNamedSlider::SetValueText(const FText& Value) const
{
	ValueText->SetText(Value);
}
