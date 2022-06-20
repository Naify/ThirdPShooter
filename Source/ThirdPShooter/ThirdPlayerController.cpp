// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPlayerController.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void AThirdPlayerController::BeginPlay()
{
    Super::BeginPlay();

    UUserWidget* HUDW = CreateWidget(this, HUDWidget);
    if (HUDW != nullptr)
    {
        HUD = HUDW;
        HUDW->AddToViewport();
    }
}

void AThirdPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport();

    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenWidget);
        if (WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenWidget);
        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &AThirdPlayerController::RestartLevel, RestartDelay);
}

void AThirdPlayerController::RestartLevel()
{
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
