#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "MainMenuCharacter.generated.h"


UCLASS()
class BUDGETVIKINGS_API AMainMenuCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	
	AMainMenuCharacter();
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	
	virtual void BeginPlay() override;
};
