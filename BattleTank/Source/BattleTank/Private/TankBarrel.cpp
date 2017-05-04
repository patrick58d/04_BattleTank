// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "G:/repos/04_BattleTanks/BattleTank/Source/BattleTank/Public/TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at speed %f"), DegreesPerSecond);
	// Move the Barrel the right about this frame
	// Given a max elevation speed, and the frame time
}

