#include "CForEngines/Public/P_FPS.h"

 
#include "HealthComponent.h"
#include "WeaponBase.h"
#include "Camera/CameraComponent.h"
 
AP_FPS::AP_FPS()
{
	PrimaryActorTick.bCanEverTick = true;
 
	_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_Camera->SetupAttachment(RootComponent);
 
	_Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));

	_WeaponAttachPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Weapon Attach"));
	_WeaponAttachPoint->SetupAttachment(_Camera);
}
 
void AP_FPS::Input_FirePressed_Implementation()
{
	if(_WeaponRef)
	{
		_WeaponRef->StartFire();
	}
}

 
void AP_FPS::Input_FireReleased_Implementation()
{
	if(_WeaponRef)
	{
		_WeaponRef->StopFire();
	}
}
 
// void AP_FPS::Input_JumpPressed_Implementation()
// {
// 	ACharacter::Jump();
// }
 
// void AP_FPS::Input_JumpReleased_Implementation()
// {
// 	ACharacter::StopJumping();
// }
 
void AP_FPS::Input_Look_Implementation(FVector2D value)
{
	AddActorWorldRotation(FRotator(0.0f, value.X, 0.0f));
	//_Camera->AddLocalRotation(FRotator(value.Y, 0.0f, 0.0f));
}
 
void AP_FPS::Input_Move_Implementation(FVector2D value)
{
	AddMovementInput(FVector::VectorPlaneProject(_Camera->GetForwardVector(), FVector::UpVector).GetSafeNormal(), value.Y);
	AddMovementInput(_Camera->GetRightVector(), value.X);
}



UInputMappingContext* AP_FPS::GetMappingContext_Implementation()
{
	return _InputMapping;
}

void AP_FPS::BeginPlay()
{
	Super::BeginPlay();

	_Health->OnDead.AddUniqueDynamic(this, &AP_FPS::AP_FPS::Handle_HealthDead);
	_Health->OnDamaged.AddUniqueDynamic(this, &AP_FPS::Handle_HealthDamaged);

	if (_DefaultWeapon)
	{
		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Instigator = this;
		_WeaponRef = GetWorld()->SpawnActor<AWeaponBase>(_DefaultWeapon,
		_WeaponAttachPoint->GetComponentTransform(),spawnParams);
		_WeaponRef->AttachToComponent(_WeaponAttachPoint,FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
	_WeaponRef->AmmoChanged.AddUniqueDynamic(this, &AP_FPS::AmmoChanged);
	
}

UBehaviorTree* AP_FPS::GetBehaviorTree_Implementation()
{
	return _BehaviourTree;
}

void AP_FPS::Handle_HealthDead(AController* causer)
{
	OnDeathDelagate.Broadcast();
}

void AP_FPS::Handle_HealthDamaged(float newHealth, float maxHealth, float changeInHealth)
{
	OnHealthChangedDelagate.Broadcast(newHealth,maxHealth,changeInHealth);
	UE_LOG(LogTemp, Display, TEXT("Text"), changeInHealth);

}

void AP_FPS::AmmoChanged(int Amount)
{
	OnAmmoChangedDelagate.Broadcast(Amount);
	
}

void AP_FPS::AddAmmo(int ChangeInAmmo)
{
	_WeaponRef->AmmoUpdated(ChangeInAmmo);
}

