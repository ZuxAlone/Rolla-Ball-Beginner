// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RollBallGameModeBase.generated.h"

class URollBallWidget;
/**
 * 
 */
UCLASS()
class ROLLBALLPROJECT_API ARollBallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

	int32 ItemsCollected = 0;
	int32 ItemsInLevel = 0;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
	URollBallWidget* GameWidget;

	virtual void BeginPlay() override;

	void UpdateItemText();

public: 

	void ItemCollected();
	
};
