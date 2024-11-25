// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "EndLevelScript.generated.h"

class UWidget_EndScreen;

UCLASS()
class CFORENGINES_API AEndLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEndLevelScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_EndScreen> _UWidget_EndScreenClass;
	TObjectPtr<UWidget_EndScreen> _UWidget_EndScreen;
};
