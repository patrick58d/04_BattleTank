// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the Barrel the right about this frame
	// Given a max elevation speed, and the frame time
	auto RelativeSpeedClamped = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto RotationChange = RelativeSpeedClamped * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}

