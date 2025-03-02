#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadoutEditor.generated.h"


class AMainMenuCharacter;

UENUM()
enum class ELoadoutEditorState : uint8
{
	LES_LoadoutSelection UMETA(DisplayName = "LoadoutSelection"),
	LES_WeaponInspection UMETA(DisplayName = "WeaponInspection"),
	LES_ShieldPainter UMETA(DisplayName = "ShieldPainter"),
	
	LES_MAX UMETA(Hidden)
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadoutEditorStateChanged, ELoadoutEditorState, NewEditorState);


UCLASS()
class BUDGETVIKINGS_API ALoadoutEditor : public AActor
{
	GENERATED_BODY()
	
public:	

	ALoadoutEditor();

	UPROPERTY()
	FOnLoadoutEditorStateChanged OnLoadoutEditorStateChanged;

	void SetState(ELoadoutEditorState NewState);
	void Open();
	void Close();
	void SetCharacter(AMainMenuCharacter* InCharacter);

protected:

	virtual void BeginPlay() override;

	UPROPERTY()
	ELoadoutEditorState CurrentState;

	UPROPERTY()
	TObjectPtr<AMainMenuCharacter> Character;
};
