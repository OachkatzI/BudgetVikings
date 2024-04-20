#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"


UCLASS()
class BUDGETVIKINGS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACharacterBase();
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	virtual void BeginPlay() override;
};
