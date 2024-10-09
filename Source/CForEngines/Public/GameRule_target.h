
#pragma once

#include "CoreMinimal.h"
#include "GameRule.h"
#include "GameRule_target.generated.h"

class UTarget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGRTargetRequestTargetSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CFORENGINES_API UGameRule_target : public UGameRule
{
	GENERATED_BODY()

public:
	UGameRule_target();

	static inline FGRTargetRequestTargetSignature OnRequestTargets;

	virtual void Init() override;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TObjectPtr<UTarget>> _Targets;

	int _AmountRemaining;

private:
	UFUNCTION()
	void Handle_TargetRegistered(UTarget* target);
	UFUNCTION()
	void Handle_TargetDestroyed(UTarget* target, AController* causer, int targetValue);
};
