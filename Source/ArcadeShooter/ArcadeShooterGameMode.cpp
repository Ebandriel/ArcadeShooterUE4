// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcadeShooter.h"
#include "ArcadeShooterGameMode.h"
#include "EnemyController.h"

void AArcadeShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AArcadeShooterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;

	if (EnemyTimer <= 0.0f)
	{
		float dificultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);
		EnemyTimer = MAXIMUM_INTERVAL - (MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * dificultyPercentage;
		UWorld* World = GetWorld();
		if (World)
		{
			FVector location = FVector(600.0f, FMath::RandRange(-800.0f, 800.0f), 70.0f);
			World->SpawnActor<AEnemyController>(EnemyBlueprint, location, FRotator::ZeroRotator);
		}
	}
}


