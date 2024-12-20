﻿
#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Particles/ParticleSystem.h"
#include "Weapon_Hitscan.generated.h"




UCLASS(Abstract)
class CFORENGINES_API AWeapon_Hitscan : public AWeaponBase
{
	GENERATED_BODY()

public:
	virtual void Fire() override;
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	//float _Damage;
	int m_NumberOfProjectiles = 7;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float _ConeDegrees = 7.5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* _HitRegister;
	
};

