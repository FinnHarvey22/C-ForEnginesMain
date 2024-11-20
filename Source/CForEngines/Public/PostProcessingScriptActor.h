// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "PostProcessingScriptActor.generated.h"

UCLASS()
class CFORENGINES_API APostProcessingScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APostProcessingScriptActor();
	UFUNCTION()
	void FlipTexture();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APostProcessVolume* _PostProcessing;


	bool _PostProcessingEnabled = false;

public:
	// Called every frame
	
};
