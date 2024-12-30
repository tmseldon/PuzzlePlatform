// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
	SetActiveMotion(bIsThisPlatformActive);
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//Begin Replication
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		//Setting initial position
		InitialLocation = this->GetActorLocation();
		//CurrentLocation = this->GetActorLocation();
		Direction = TargetLocation.GetSafeNormal();
		
	}
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority() && bIsThisPlatformActive)
	{
		//if (CurrentTimeCounter > OneWayRoundSeconds)
		//{
		//	SpeedPlatform *= -1;
		//	CurrentTimeCounter = 0;
		//}
		//else
		//{
		//	CurrentLocation += (SpeedPlatform * DeltaTime) * Direction;
		//	CurrentTimeCounter += DeltaTime;

		//	SetActorLocation(CurrentLocation);
		//}

		if (CurrentLocation.IsZero())
		{
			CurrentLocation = GetActorLocation();
		}

		CurrentLocation += (SpeedPlatform * DeltaTime) * Direction;
		SetActorLocation(CurrentLocation);

		//UE_LOG(LogTemp, Display, TEXT("Diferencia final %f"), (CurrentLocation - (TargetLocation + InitialLocation)).SizeSquared());
		//UE_LOG(LogTemp, Display, TEXT("Diferencia inicial %f"), (CurrentLocation - InitialLocation).SizeSquared());
		if (!bIsInitial)
		{
			if ((CurrentLocation - (TargetLocation + InitialLocation)).SizeSquared() < DifferenceRange
				|| (CurrentLocation - InitialLocation).SizeSquared() < DifferenceRange)
			{
				SpeedPlatform *= -1;
			}
		}
		else
		{
			bIsInitial = false;
		}
	}
}


void AMovingPlatform::SetActiveMotion(bool bIsActive)
{
	bIsThisPlatformActive = bIsActive;
}
