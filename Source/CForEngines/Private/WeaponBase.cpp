#include "WeaponBase.h"

#include "Components/ArrowComponent.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	_FireDelay = 0.5f;


	_Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _Root;

	_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(RootComponent);

	_Muzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("Muzzle"));
	_Muzzle->SetupAttachment(_Mesh);
	
}

void AWeaponBase::StartFire()
{
	
	if (!GetWorldTimerManager().IsTimerActive(_FireDelayTimer))
	{
		UE_LOG(LogTemp, Display, TEXT("Debug is working!"));
		if (_FireDelay != 0.0f)
		{
			GetWorld()->GetTimerManager().SetTimer(_FireDelayTimer,this, &AWeaponBase::Fire, _FireDelay, true);
			Fire();
		}
	}

}

void AWeaponBase::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(_FireDelayTimer);
}

void AWeaponBase::Fire()
{
	OnFire.Broadcast();
}



