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
	UFUNCTION()
	void Init();
	UFUNCTION()
	void Reload();
	UFUNCTION()
	void StartReload();
	virtual void BeginPlay() override;
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
	int m_AmmoAmount = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int m_StartingAmmo = 50;
	int m_AmmoInGun = 2;
	float _ReloadDelay = 1.0f;
	bool _reloading;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float _Damage;
	
private:
	bool _requestFire;
	FTimerHandle _InitTimer;
	FTimerHandle _ReloadTimer;
};
