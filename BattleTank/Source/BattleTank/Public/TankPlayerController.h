// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include 

class ATank; // forward declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
private:
	//Start the tank moving the barrel so that a shot would it where
	//the cross hair intersects the world
	void AimTowardsCrossHair();
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
	//Distance Across Horizontal Screen Space
	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;

	//Distance Down Screen Space
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f;
};
