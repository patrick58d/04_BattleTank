// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankAIController.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cant find player tank"));
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Tank found player: %s"), *(PlayerTank->GetName()));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtPlayer();
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::AimAtPlayer() const
{
	if (!GetPlayerTank()) { return; }
		// TODO Move towards the player

		// Aim Towards the player
	
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); //How is AimAt getting the owner name I need to figure this out??
}

