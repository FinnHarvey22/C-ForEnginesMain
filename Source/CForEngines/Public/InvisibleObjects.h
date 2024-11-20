// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvisibleObjects.generated.h"

UCLASS()
class CFORENGINES_API AInvisibleObjects : public AActor
{
	GENERATED_BODY()

public:
	AInvisibleObjects();

protected:
	virtual void BeginPlay() override;

public:

};
