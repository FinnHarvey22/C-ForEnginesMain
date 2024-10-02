#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstActor.generated.h"

class UBoxComponent;
class URotatingMovementComponent;
class UArrowComponent;

UCLASS()
class CFORENGINES_API AFirstActor : public AActor
{
	GENERATED_BODY()

public:
	AFirstActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> _Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> _Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UArrowComponent> _Arrow;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//TObjectPtr<URotatingMovementComponent> _RotatingMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> _Collider;


	virtual void BeginPlay() override;
	
	UFUNCTION()
	void Handle_ColliderHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );


};



