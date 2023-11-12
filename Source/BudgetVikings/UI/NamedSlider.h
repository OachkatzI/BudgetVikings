#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "NamedSlider.generated.h"


class USlider;
class UCommonTextBlock;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSliderValueChanged, float, Value);


UCLASS()
class BUDGETVIKINGS_API UNamedSlider : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	void SetTitleText(const FText& NewTitle) const;

	void SetValueText(const FText& Value) const;

	UFUNCTION(BlueprintCallable)
	USlider* GetSliderWidget() const { return Slider; }

	UPROPERTY(BlueprintAssignable)
	FOnSliderValueChanged OnSliderValueChangedEvent;
	
protected:
	
	virtual void NativePreConstruct() override;
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> TitleText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> ValueText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> Slider;

	UPROPERTY(EditInstanceOnly)
	FText Title = FText::FromString("Title");

	UPROPERTY(EditInstanceOnly)
	float MinValue = 0.f;

	UPROPERTY(EditInstanceOnly)
	float MaxValue = 1.f;

	UFUNCTION(BlueprintNativeEvent)
	void OnSliderValueChanged(float Value);

	virtual FString FormatValue(float Value);
};
