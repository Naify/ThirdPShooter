// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThirdPShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPSHOOTER_API AThirdPShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void PwnKilled(APawn* PawnKilled);
};
