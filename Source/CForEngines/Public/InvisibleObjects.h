// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvisibleObjects.generated.h"

class UBoxComponent;
class AP_FPS;

UCLASS()
class CFORENGINES_API AInvisibleObjects : public AActor
{
	GENERATED_BODY()

public:
	AInvisibleObjects();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> _Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> _Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> _Collider;
	virtual void BeginPlay() override;

	UFUNCTION()
	void FlipTexture();




public:

};
