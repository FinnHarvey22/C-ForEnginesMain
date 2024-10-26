#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Weapon_Projectile.generated.h"

class AProjectile;

UCLASS(Abstract)
class CFORENGINES_API AWeapon_Projectile : public AWeaponBase
{
	GENERATED_BODY()

public:
	virtual void Fire() override;
	float _FireDelay = 0.5f;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectile> _ProjectileClass;
	
};
