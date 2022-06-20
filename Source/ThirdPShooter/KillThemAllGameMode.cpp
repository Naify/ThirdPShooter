// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillThemAllGameMode::PwnKilled(APawn* PawnKilled)
{
    Super::PwnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    for (AShooterAIController* AIController: TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!AIController->isDead())
        {
            return;
        }
    }

    EndGame(true);
}

void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for (AController* Controller: TActorRange<AController>(GetWorld()))
    {
        bool bIsPlayer = Controller->IsPlayerController();

        if (bIsPlayerWinner)
        {
            Controller->GameHasEnded(Controller->GetPawn(), bIsPlayer);
        }
        else 
        {
            Controller->GameHasEnded(Controller->GetPawn(), !bIsPlayer);
        }        
    }
}
