#include "Weapon_Hitscan.h"

#include "BaseGizmos/GizmoElementShared.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"





TArray<AActor*> ActorsToIgnore;

void AWeapon_Hitscan::BeginPlay()
{
	ActorsToIgnore.Add(GetOwner()); 
	Super::BeginPlay();
}
void AWeapon_Hitscan::Fire()
{
	UWorld* const world = GetWorld();
	if(world == nullptr) { return; }

	FHitResult hit(ForceInit);
	FVector start = _Muzzle->GetComponentLocation();
	
	
	if (m_AmmoAmount > 0 && !_reloading)
	{
		for (int a = 0; a < m_NumberOfProjectiles; a++)
		{
			FVector ConedDirection =  FMath::VRandCone(_Muzzle->GetForwardVector(), FMath::DegreesToRadians(_ConeDegrees ) * 0.5);
			FVector end = ConedDirection * 10000000;
			if (UKismetSystemLibrary::LineTraceSingle(world,start,end,UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2),false,ActorsToIgnore,EDrawDebugTrace::ForDuration,hit,true,FLinearColor::Red,FLinearColor::Green,5))
			{
				UGameplayStatics::ApplyDamage(hit.GetActor(), _Damage, GetOwner()->GetInstigatorController(),GetOwner(), UDamageType::StaticClass());
				UGameplayStatics::SpawnEmitterAtLocation(world, _HitRegister,hit.ImpactPoint,hit.ImpactPoint.Rotation(), FVector(1,1,1),true,EPSCPoolMethod::None, true);
				UE_LOG(LogTemp, Display, TEXT("Hit Position:  %s"), *hit.ImpactPoint.ToString());

			
				
			}
		}
		
	}
	
	Super::Fire();
}




