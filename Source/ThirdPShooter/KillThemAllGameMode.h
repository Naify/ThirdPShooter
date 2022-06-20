// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPShooterGameModeBase.h"
#include "KillThemAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPSHOOTER_API AKillThemAllGameMode : public AThirdPShooterGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void PwnKilled(APawn* PawnKilled) override;

private:

	void EndGame(bool bIsPlayerWinner);
};
