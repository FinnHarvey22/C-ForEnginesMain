#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UArrowComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWeaponFireSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeaponAmmoChangedSignature,int, AmountOfAmmo);
UCLASS(Abstract)
class CFORENGINES_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	UPROPERTY(BlueprintAssignable)
	FWeaponFireSignature OnFire;
	UPROPERTY(BlueprintAssignable)
	FWeaponAmmoChangedSignature AmmoChanged;
	
	void StartFire();
	void StopFire();

	UFUNCTION()
	void AmmoUpdated(int AmmoChange);
	
	

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
	int m_AmmoAmount = 5;
	virtual void BeginPlay() override;
	
private:
	bool _requestFire;
	
};
