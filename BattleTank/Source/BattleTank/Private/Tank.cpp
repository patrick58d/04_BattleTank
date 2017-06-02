// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/Projectile.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankAimingComponent.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankMovementComponent.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankBarrel.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/Tank.h"

// Sets default values

ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);
	if (isReloaded) {


		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

	// Spawn a Projectile at the socket location
}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}