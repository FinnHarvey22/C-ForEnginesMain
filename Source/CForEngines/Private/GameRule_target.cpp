#include "CForEngines/Public/GameRule_target.h"
#include "CForEngines/Public/Target.h"

UGameRule_target::UGameRule_target()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UGameRule_target::Init()
{
	Super::Init();
	UTarget::OnTargetRegister.AddUniqueDynamic(this, &UGameRule_target::Handle_TargetRegistered);
	OnRequestTargets.Broadcast();
}

void UGameRule_target::Handle_TargetRegistered(UTarget* target)
{
	if(_Targets.Contains(target)){return;}
	_Targets.Add(target);
	target->OnDestroyed.AddUniqueDynamic(this, &UGameRule_target::Handle_TargetDestroyed);
	_AmountRemaining++;
}

void UGameRule_target::Handle_TargetDestroyed(UTarget* target, AController* causer, int targetValue)
{
	_Targets.Remove(target);
	_AmountRemaining--;
	BroadcastPointsScored(causer, targetValue);
	
	if (_AmountRemaining == 0)
	{
		BroadcastComplete();
	}
}




