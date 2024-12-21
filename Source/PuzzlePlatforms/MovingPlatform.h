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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setup", meta = (AllowPrivateAccess = "true"))
	float DifferenceRange = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setup", meta = (AllowPrivateAccess = "true"))
	float SpeedPlatform = 5.f;

	UPROPERTY(EditAnywhere, 
		BlueprintReadWrite, 
		Category = "Platform Setup", 
		meta = (AllowPrivateAccess = "true"), 
		meta = (MakeEditWidget = "true"))
	FVector TargetLocation;

	//Caching for initial conditions
	FVector InitialLocation;
	FVector CurrentLocation;
	FVector Direction;

	//float CurrentTimeCounter = 0;
};
