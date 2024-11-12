#include "WeaponBase.h"

#include "Components/ArrowComponent.h"
#include <chrono>


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	_FireDelay = 0.5f;
	_requestFire = false;
	//_AmmoCount = 10;


	_Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _Root;

	_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	_Mesh->SetupAttachment(RootComponent);

	_Muzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("Muzzle"));
	_Muzzle->SetupAttachment(_Mesh);
	
}

void AWeaponBase::StartFire()
{
	_requestFire = true;	
	if (!GetWorldTimerManager().IsTimerActive(_FireDelayTimer))
	{
		UE_LOG(LogTemp, Display, TEXT("Debug is working!"));
		Fire();
	}

}

void AWeaponBase::StopFire()
{
	_requestFire = false; 
	//GetWorld()->GetTimerManager().ClearTimer(_FireDelayTimer);
}

void AWeaponBase::AmmoUpdated(int AmmoChange)
{
	m_AmmoAmount += AmmoChange;
	AmmoChanged.Broadcast(m_AmmoAmount);
}

void AWeaponBase::Fire()
{
	if (m_AmmoAmount > 0 && !_reloading && m_AmmoInGun > 0)
	{
		AmmoUpdated(-1);
		OnFire.Broadcast();
		m_AmmoInGun--;
		if (_FireDelay != 0.0f)
		{
			GetWorld()->GetTimerManager().SetTimer(_FireDelayTimer,this, &AWeaponBase::FireDelayFinished, _FireDelay, false);
		
		}
	}
	else if (m_AmmoInGun == 0 && !_reloading)
	{
		StartReload();
	}
}

void AWeaponBase::FireDelayFinished()
{
	if (m_AmmoAmount > 0 && m_AmmoInGun > 0)
	{
		if (_requestFire)
		{
		
			Fire();
		
		}
	}
	else if (m_AmmoInGun <= 0 && m_AmmoAmount > 0)
	{
		//if(_requestFire)
		//{
		StartReload();
		//}
	}
}

void AWeaponBase::BeginPlay()
{
	m_AmmoAmount = m_StartingAmmo;
	GetWorldTimerManager().SetTimer(_InitTimer,this,&AWeaponBase::Init,0.2f,false);
	Super::BeginPlay();
	
}
void AWeaponBase::StartReload()
{
	_reloading = true;
	GetWorld()->GetTimerManager().SetTimer(_ReloadTimer,this, &AWeaponBase::Reload, _ReloadDelay, false);

}
void AWeaponBase::Reload()
{
	m_AmmoInGun = 2;
	_reloading = false;
}


void AWeaponBase::Init()
{
	AmmoChanged.Broadcast(m_AmmoAmount);
}
 



