// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();


protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, Category = "Platform Setup")
	float OneWayRoundSeconds = 5.f;


	UPROPERTY(EditAnywhere, Category = "Platform Setup")
	float SpeedPlatform = 5.f;

	
	FVector CurrentLocation;

	float CurrentTimeCounter = 0;

	
};
