#pragma once
 
#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_FPS.generated.h"

struct FEnvQueryResult;
class UEnvQuery;
struct FAIStimulus;
class UAISenseConfig_Sight;
class UAIPerceptionComponent;
class APawn;

UCLASS(Abstract)
class CFORENGINES_API AAIC_FPS : public AAIController
{
	GENERATED_BODY()
 
public:
	AAIC_FPS();

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
 
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAIPerceptionComponent> _AIPerception;
	TObjectPtr<UAISenseConfig_Sight> _AISense_Sight;

	//UPROPERTY(EditAnywhere)
	//TObjectPtr<UEnvQuery> _EQS_FindWanderTarget;
	TObjectPtr<UBlackboardComponent> _Blackboard;

private:
	UFUNCTION()
	void Handle_TargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	//UFUNCTION()
	//void Handle_FindWanderTargetResult(TSharedPtr<FEnvQueryResult> result);
	
	
};