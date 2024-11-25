// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "WinLevelScript.generated.h"

class UWidget_WinScreen;

UCLASS()
class CFORENGINES_API AWinLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWinLevelScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_WinScreen> _UWidget_WinScreenClass;
	TObjectPtr<UWidget_WinScreen> _UWidget_WinScreen;
};
