#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "NamedSlider.generated.h"


class USlider;
class UCommonTextBlock;


UCLASS()
class BUDGETVIKINGS_API UNamedSlider : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	void SetTitleText(const FText& NewTitle) const;

	void SetValueText(const FText& Value) const;

	FORCEINLINE USlider* GetSliderWidget() const { return Slider; }
	
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

	UFUNCTION()
	virtual void OnSliderValueChanged(float Value);	

};
