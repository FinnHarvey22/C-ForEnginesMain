// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SwapTexture.h"
#include "GameFramework/Actor.h"
#include "PostProcessingManager.generated.h"

UCLASS()
class CFORENGINES_API APostProcessingManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APostProcessingManager();

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	APostProcessVolume* _PostProcessVolume;

	void FlipTexture();

public:

};
