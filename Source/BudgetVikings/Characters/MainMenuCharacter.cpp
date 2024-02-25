#include "MainMenuCharacter.h"


AMainMenuCharacter::AMainMenuCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMainMenuCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AMainMenuCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMainMenuCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
