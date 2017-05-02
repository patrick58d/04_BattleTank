// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing a Tank"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController posseing: %s"), *(ControlledTank->GetName()));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
 return	Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation((HitLocation))) // Has "side-effect, is going to line-trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
	
}
// Get world location of line trace through the cross hair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the Cross hair Position in pixel coordinates 
	int ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY *CrossHairYLocation);
	
	// "De-Project" the screen position of the cross-hair to a world direction
	// Line trace along that direction, and see what we hit(up to a max range)

	OutHitLocation = FVector(1.0);
	return true;
}

