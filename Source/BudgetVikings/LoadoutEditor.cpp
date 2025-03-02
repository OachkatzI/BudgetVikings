#include "LoadoutEditor.h"


ALoadoutEditor::ALoadoutEditor()
{
	PrimaryActorTick.bCanEverTick = false;
}


void ALoadoutEditor::BeginPlay()
{
	Super::BeginPlay();

	

}


void ALoadoutEditor::SetState(ELoadoutEditorState NewState)
{
	if (NewState == CurrentState)
	{
		return;
	}

	CurrentState = NewState;
	
	// ToDo: Do something?

	OnLoadoutEditorStateChanged.Broadcast(CurrentState);
}

void ALoadoutEditor::Open()
{
	SetState(ELoadoutEditorState::LES_LoadoutSelection);

}

void ALoadoutEditor::Close()
{
}


void ALoadoutEditor::SetCharacter(AMainMenuCharacter* InCharacter)
{
	Character = InCharacter;
}
