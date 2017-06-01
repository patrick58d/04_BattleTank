// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankAIController.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank)
	{
		// Move Toward the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); 
	}
}







