// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:	
	
	
	void AimAtPlayer() const;
};
