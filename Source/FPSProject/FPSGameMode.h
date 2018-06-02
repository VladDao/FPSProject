// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FPSGameMode.generated.h"
//#include "GameFramework/GameMode.h"
/**
 * 
 */
UCLASS()
class FPSPROJECT_API AFPSGameMode : public AGameMode
{
	GENERATED_BODY()

		AFPSGameMode(const FObjectInitializer& ObjectInitializer);  // Our added constructor

	virtual void StartPlay() override;
};