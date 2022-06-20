// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterClass.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehaivior)
	{
		RunBehaviorTree(AIBehaivior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());		
	}
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	// // FBlackboard::FKey PlayerLocKey = GetBlackboardComponent()->GetKeyID(TEXT("PlayerLocation"));

	// if (LineOfSightTo(PlayerPawn))
	// {
	// 	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	// 	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
	// }
	// else
	// {
		//Bug for UE5
	// 	//GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	// }

}

bool AShooterAIController::isDead() const
{
	AShooterClass* ControlledCharacter = Cast<AShooterClass>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}

	return true;
}