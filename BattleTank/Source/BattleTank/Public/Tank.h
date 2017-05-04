// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Must Add any other headers above this

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr; //Pointer to Tank Aiming Component

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; // Find Sensible Starting value
	
};
