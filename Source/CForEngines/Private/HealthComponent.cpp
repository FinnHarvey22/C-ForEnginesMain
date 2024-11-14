


#include "HealthComponent.h"



UHealthComponent::UHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;
	_MaxHealth = 100.f;

}



void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	_CurrentHealth = _MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddUniqueDynamic(this, &UHealthComponent::DamageTaken);
	


	
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if (!_IFramesActive)
	{
		if (_HasIFrames)
		{
			_IFramesActive = true;
			GetWorld()->GetTimerManager().SetTimer(_IFrameTimer,this, &UHealthComponent::IFrameTimerEnd, 0.5f, false);

		}
		const float change = FMath::Min(_CurrentHealth, Damage);
		_CurrentHealth-=change;
		OnDamaged.Broadcast(_CurrentHealth, _MaxHealth,change);
		if(_CurrentHealth == 0.0f) {OnDead.Broadcast(InstigatedBy);}
	}
}

void UHealthComponent::IFrameTimerEnd()
{
	_IFramesActive = false;
}


