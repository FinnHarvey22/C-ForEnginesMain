// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinLevelTrigger.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class CFORENGINES_API AWinLevelTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWinLevelTrigger();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> _Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> _Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> _Collider;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Handle_ColliderHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
									 UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:

};
