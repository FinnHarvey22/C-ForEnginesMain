// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ammo_Pickup.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAmmoPickupUsedSignature, int, AmmoAmount);

UCLASS()
class CFORENGINES_API AAmmo_Pickup : public AActor
{
	GENERATED_BODY()

public:
	AAmmo_Pickup();

	UPROPERTY(BlueprintAssignable)
	FAmmoPickupUsedSignature PickupUsed;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> _Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> _Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> _Collider;

	UFUNCTION()
	void Handle_ColliderHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int m_AmmoPickupAmount = 10;
};
