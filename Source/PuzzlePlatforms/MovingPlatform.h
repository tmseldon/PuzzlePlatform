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

	void SetActiveMotion(bool bIsActive);

	void AddActiveTrigger();

	void RemoveActiveTrigger();


protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setup", meta = (AllowPrivateAccess = "true"))
	float DifferenceRange = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setup", meta = (AllowPrivateAccess = "true"))
	float SpeedPlatform = 5.f;

	// For Movement Activation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setup", meta = (AllowPrivateAccess = "true"))
	bool bIsThisPlatformActive = true;

	UPROPERTY(EditAnywhere, 
		BlueprintReadWrite, 
		Category = "Platform Setup", 
		meta = (AllowPrivateAccess = "true"), 
		meta = (MakeEditWidget = "true"))
	FVector TargetLocation;

	// Caching for initial conditions
	FVector CurrentLocation;
	FVector Direction;
	FVector InitialLocation;
	//float CurrentTimeCounter = 0;

	// Hack to avoid the initial problem that the platform moves in another direction, this is due the substraction
	// on the different positions at init
	bool bIsInitial = true;

	UPROPERTY(EditAnywhere)
	int CurrentTriggersNumber = 1;
};
