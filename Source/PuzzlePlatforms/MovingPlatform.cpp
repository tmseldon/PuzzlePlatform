// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = this->GetActorLocation();
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentTimeCounter > OneWayRoundSeconds)
	{
		SpeedPlatform *= -1;
		CurrentTimeCounter = 0;
	}
	else
	{
		CurrentLocation.X += SpeedPlatform * DeltaTime;
		CurrentTimeCounter += DeltaTime;

		SetActorLocation(CurrentLocation);
	}
}
