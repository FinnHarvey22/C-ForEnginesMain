// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PersistantData.generated.h"

/**
 * 
 */
UCLASS()
class CFORENGINES_API UPersistantData : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int CurrentScore;
};
