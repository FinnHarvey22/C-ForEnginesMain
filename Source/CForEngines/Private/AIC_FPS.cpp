#include "AIC_FPS.h"
 
#include "Inputable.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "Kismet/KismetSystemLibrary.h"
//#include "kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AAIC_FPS::AAIC_FPS()
{
	_AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));

	_AISense_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SenseSight"));
	_AISense_Sight->DetectionByAffiliation.bDetectEnemies = true;
	_AISense_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	_AISense_Sight->DetectionByAffiliation.bDetectNeutrals = false;

	_AIPerception->ConfigureSense(*_AISense_Sight);
	_AIPerception->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	PrimaryActorTick.bCanEverTick = true;
	AAIController::SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AAIC_FPS::GetTeamAttitudeTowards(const AActor& Other) const
{
	FGenericTeamId TeamId(FGenericTeamId::GetTeamIdentifier(&Other));
	if (TeamId == FGenericTeamId(1))
	{
		return ETeamAttitude::Friendly;
	}
	if (TeamId == FGenericTeamId(2))
	{
		return ETeamAttitude::Hostile;
	}
	return  ETeamAttitude::Neutral;
}

void AAIC_FPS::BeginPlay()
{
	Super::BeginPlay();
	_Blackboard = GetBlackboardComponent();
	_AIPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AAIC_FPS::Handle_TargetPerceptionUpdated);

	FEnvQueryRequest EQR_FindWanderTarget = FEnvQueryRequest(_EQS_FindWanderTarget, GetPawn());
	EQR_FindWanderTarget.Execute(EEnvQueryRunMode::RandomBest25Pct, this, &AAIC_FPS::Handle_FindWanderTargetResult);
}
 
void AAIC_FPS::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UE_LOG(LogTemp, Display, TEXT("AI Possessed"));
	
	if(UKismetSystemLibrary::DoesImplementInterface(InPawn, UInputable::StaticClass()))
	{
		UE_LOG(LogTemp, Display, TEXT("Behaviour Tree Ran"));
		RunBehaviorTree(IInputable::Execute_GetBehaviorTree(InPawn));
	}
}

void AAIC_FPS::Handle_TargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	switch (Stimulus.Type)
	{
	case 0:

		return;


	default:

		return;
	}
}

 void AAIC_FPS::Handle_FindWanderTargetResult(TSharedPtr<FEnvQueryResult> result)
 {
 	if(result->IsSuccessful())
 	{
 		_Blackboard->SetValueAsVector("TargetLocation", result->GetItemAsLocation(0));
	}
 }
