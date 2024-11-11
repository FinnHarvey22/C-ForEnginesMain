#pragma once
 
#include "CoreMinimal.h"
#include "Inputable.h"
#include "GameFramework/Character.h"
#include "P_FPS.generated.h"

class AWeaponBase;
class UHealthComponent;
class UCharacterMovementComponent;
class UCameraComponent;
class UCapsuleComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FPlayerOnHealthChangedSignature,float, newHealth, float, maxHealth, float, changeInHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerAmmoChangedSignature, int, AmmoChange);
UCLASS(Abstract)
class CFORENGINES_API AP_FPS : public ACharacter, public IInputable
{
	GENERATED_BODY()
 
public:
	AP_FPS();
 
	virtual void Input_FirePressed_Implementation() override;
	virtual void Input_FireReleased_Implementation() override;
	virtual void Input_JumpPressed_Implementation() override;
	virtual void Input_JumpReleased_Implementation() override;
	virtual void Input_Look_Implementation(FVector2D value) override;
	virtual void Input_Move_Implementation(FVector2D value) override;
    
	virtual UInputMappingContext* GetMappingContext_Implementation() override;
	void BeginPlay();
	UPROPERTY(BlueprintAssignable)
	FPlayerOnHealthChangedSignature OnHealthChangedDelagate;
	UPROPERTY(BlueprintAssignable)
	FPlayerOnDeathSignature OnDeathDelagate;
	UPROPERTY(BlueprintAssignable)
	FPlayerAmmoChangedSignature OnAmmoChangedDelagate;

	virtual UBehaviorTree* GetBehaviorTree_Implementation() override;
	UFUNCTION()
	void AmmoChanged(int Amount);
	UFUNCTION()
	void AddAmmo(int ChangeInAmmo);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> _Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UHealthComponent> _Health;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<USceneComponent> _WeaponAttachPoint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AWeaponBase> _DefaultWeapon;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<AWeaponBase> _WeaponRef;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> _InputMapping;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UBehaviorTree> _BehaviourTree;

private:
	UFUNCTION()
	void Handle_HealthDead(AController* causer);
	UFUNCTION()
	void Handle_HealthDamaged( float newHealth, float maxHealth, float changeInHealth);
	
	
};
