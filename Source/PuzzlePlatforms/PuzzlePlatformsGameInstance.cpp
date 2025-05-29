// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	
	if (!ensure(MenuBPClass.Class != nullptr)) { return; }
	
	MainMenuClass = MenuBPClass.Class;
	
	UE_LOG(LogTemp, Warning, TEXT("En Construct encontré clase %s"), *MainMenuClass->GetName());
	
}

void UPuzzlePlatformsGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("En Init"));
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!ensure(MainMenuClass != nullptr)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("MainMenu reference has a problem and is null, not loading menu"));
		return;
	}

	UUserWidget* MainMenu = CreateWidget<UUserWidget>(this, MainMenuClass, FName("MainMenuWidget"));

	if (!ensure(MainMenu != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("MainMenu was not created, aborting displaying on viewport"));
		return;
	}

	MainMenu->AddToViewport();
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, TEXT("aqui En Host"));

	UWorld* CurrentWorld = GetWorld();
	if (!ensure(CurrentWorld != nullptr)) return;

	CurrentWorld->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& IPAddress)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, FString::Printf(TEXT("aqui Iniciando en: %s"), *IPAddress));

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
}