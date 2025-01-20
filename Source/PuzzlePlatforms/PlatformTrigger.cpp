// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"


// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating the component for the trigger
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));

	if (!ensure(TriggerVolume != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("Error, no hay componente para el trigger"));
		return;
	}
	RootComponent = TriggerVolume;
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	if (TriggerVolume != nullptr)
	{
		// Setup delegates
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegins);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnds);
	}
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnOverlapBegins(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
	)
{
	UE_LOG(LogTemp, Warning, TEXT("Activate Overlap"));

	if (ListActivationPlatforms.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("List of movable platform is empty"));
		return;
	}

	for (AMovingPlatform* MovablePlatform : ListActivationPlatforms)
	{
		MovablePlatform->SetActiveMotion(true);
	}
}

void APlatformTrigger::OnOverlapEnds(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
	)
{
	UE_LOG(LogTemp, Warning, TEXT("DeActivate Overlap"));

	if (ListActivationPlatforms.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("List of movable platform is empty"));
		return;
	}

	for (AMovingPlatform* MovablePlatform : ListActivationPlatforms)
	{
		MovablePlatform->SetActiveMotion(false);
	}
}

