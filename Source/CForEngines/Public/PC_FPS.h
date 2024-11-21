// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controlled.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "PC_FPS.generated.h"


class UWidget_HUD;
struct FInputActionValue;
class UInputAction;
 
UCLASS(Abstract)
class CFORENGINES_API APC_FPS : public APlayerController, public IControlled, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	virtual  FGenericTeamId GetGenericTeamId() const override;
protected:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _LookAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _MoveAction;
	//UPROPERTY(EditAnywhere, Category="Input")
	//TObjectPtr<UInputAction> _JumpAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _FireAction;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> _FlipAction;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_HUD> _HUDWidgetClass;
	TObjectPtr<UWidget_HUD> _HUDWidget;
	
 
	virtual void SetupInputComponent() override;
 
	void Look(const FInputActionValue& value);
	void Move(const FInputActionValue& value);
	// void JumpPressed();
	// void JumpReleased();
	void FirePressed();
	void FireReleased();
	void FlipPressed();
	UFUNCTION()
	void HealthChanged(float newHealth, float maxHealth, float changeInHealth);
	UFUNCTION()
	void OnDeath();
	bool Dead = false;
	bool _PostProcessingEnabled;

	UPROPERTY(EditAnywhere, Category = "DataLayer")
	TObjectPtr<const UDataLayerAsset> _InvisibleObjectsDataLayer;
	UPROPERTY(EditAnywhere, Category = "DataLayer")
	TObjectPtr<const UDataLayerAsset> _VisibleObjectsDataLayer;
	


 
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void AddPoints_Implementation(int Score) override;
	UFUNCTION()
	virtual void SetAmmo_Implementation(int count) override;

private:
	
};
