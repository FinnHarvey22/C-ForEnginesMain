#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UArrowComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeaponFireSignature, int, ammoCount);
UCLASS(Abstract)
class CFORENGINES_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	UPROPERTY(BlueprintAssignable)
	FWeaponFireSignature OnFire;
	
	void StartFire();
	void StopFire();
	

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USceneComponent> _Root;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> _Mesh;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UArrowComponent> _Muzzle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float _FireDelay = 0.5f;
	FTimerHandle _FireDelayTimer;
	
	UFUNCTION()
	virtual void Fire();
	UFUNCTION()
	void FireDelayFinished();
	int _AmmoCount;

private:
	bool _requestFire;
	
};
