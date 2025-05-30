// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void Init() override;

	UFUNCTION(Exec)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& IPAddress);

private:

	TSubclassOf<class UUserWidget> MainMenuClass;
	
};
